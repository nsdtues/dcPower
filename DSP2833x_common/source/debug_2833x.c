//###############################################################################################################
// 파일명   : debug_2833x.c
// 회사명   : RealSYS
// 작성날짜 : 2008.10.20
// 작성자   : R.N.K
// 설명     : SCI-A 포트을 통해 RealDSP-UT와 통신하면서 데이터 모니터링 기능을 수행하는 코드.
//            사용자께서는 아래 선언된 BAUDRATE 값과 일치하게 RealDSP-UT의 환경 설정에서
// 			  모니터링 속도를 설정하신 후 사용하시길 바랍니다.  
//
// [ 사용한 개발 환경 ]
// 1) TI CCS3.3과 Service Pack v11.0(CCS_v3.3_SR11_81.6.2.exe 파일) - 2008.10.20
// 2) CCS3.3 Setup용 Target Driver Package(setupCCSPlatinum_v30329.exe 파일) - 2008.10.20
// 3) C2000 Code Generation Tools v5.1.1 Release(C2000CodeGenerationTools5.1.1.exe 파일) - 2008.10.20
//
// [ 참조한 Software Developer Kit(SDK) ]
// 1) TI의 SDK인 C/C++ Header Files and Peripheral Examples v1.20 사용 - 2008.10.20
//
// [ Revision History ]
//
//###############################################################################################################

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

// 제공된 예제에서는 인터럽트 서비스 루틴을 "ramfuncs" 이라는 섹션에 할당하고
// "ramfuncs" 섹션은 빠른 응답 처리를 위해 내부 RAM에서 동작하도록 함

// SCI-A Interrupt Service Function 선언
#pragma CODE_SECTION(scia_tx_isr, "ramfuncs");
#pragma CODE_SECTION(scia_rx_isr, "ramfuncs");

interrupt void scia_tx_isr(void);
interrupt void scia_rx_isr(void);

#define	CPUCLK		150000000L				// CPU Main Clock
#define	LSPCLK		(CPUCLK/4)				// Peripheral Low Speed Clock
#define	BAUDRATE	115200L					// 모니터링 속도
#define	BRR_VAL		(LSPCLK/(8*BAUDRATE)-1)	// BaudRate 설정 Register 값

typedef union{ 
	Uint16	w[2];
	Uint32	l;
}L_TYPE;
	
typedef union{ 
	Uint16	w[16];
	Uint32	l[8];
}H_TYPE;

#define	DEBUG_BUF_SIZE	50

// 통신 프로토콜에 사용하는 문자 정의
#define LF				0x0A // Line Feed Character
#define CR				0x0D // Carrage Return Character

#define	ASC_HEX_ERROR	0xff // asc2hex 변환 에러 코드

/* Variables for Serial Communication Debug */
Uint32	debug_rd_addr=0,debug_rd_addr_tmp=0;
Uint32	debug_wr_addr;
H_TYPE	debug_wr_data;
Uint16  debug_sum=0,debug_sum_temp=0;               
char	debug_state=0,debug_cnt=0,debug_wr_size=0;
char	debug_tx_buf[DEBUG_BUF_SIZE+1];
char	debug_tx_pos=0,debug_tx_end=0;
char	debug_wr_sum_flag=1;

#define	DEBUG_TX_START	{	if(SciaRegs.SCICTL2.bit.TXRDY){							\
								SciaRegs.SCICTL2.bit.TXINTENA=1;					\
								SciaRegs.SCITXBUF = debug_tx_buf[debug_tx_pos++];	\
								if(debug_tx_pos >= DEBUG_BUF_SIZE) debug_tx_pos=0;	\
							}														\
							else SciaRegs.SCICTL2.bit.TXINTENA=1;					\
						}

#define	DEBUG_TX_STOP	SciaRegs.SCICTL2.bit.TXINTENA=0

char asc2hex(char asc){
    if((asc >= '0') && (asc <= '9'))    return (asc - '0');
    else if((asc >= 'A') && (asc <= 'F'))   return (asc - 'A' + 0x0a);
    else if((asc >= 'a') && (asc <= 'f'))    return (asc - 'a' + 0x0a);
    else return ASC_HEX_ERROR;
}

char hex2asc(char hex){
char da;
	da = hex & 0x0f;
    if((da >= 0) && (da <= 9))    return  ('0' + da);
    else    return  ('A' + da - 0x0a);
}

void write_txbuf_string(char *p){
char rd;
	while(rd = *p++){             
		debug_tx_buf[debug_tx_end++] = rd;
		if(debug_tx_end >= DEBUG_BUF_SIZE) debug_tx_end = 0;
	}
}

void write_txbuf_asc(char d){
	debug_tx_buf[debug_tx_end++] = d;
	if(debug_tx_end >= DEBUG_BUF_SIZE) debug_tx_end = 0;
}

void write_txbuf_byte(char d){
	debug_tx_buf[debug_tx_end++] = hex2asc(d >> 4);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(d);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
}

void write_txbuf_word(Uint16 d){
	debug_tx_buf[debug_tx_end++] = hex2asc(d >> 12);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(d >> 8);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(d >> 4);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(d);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
}

void write_txbuf_long(Uint32 d){
L_TYPE l;
	l.l = d;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[1]>>12);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[1]>>8);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[1]>>4);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[1]);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[0]>>12);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[0]>>8);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[0]>>4);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
	debug_tx_buf[debug_tx_end++] = hex2asc(l.w[0]);
	if(debug_tx_end >= DEBUG_BUF_SIZE)	debug_tx_end = 0;
}

void state0_proc(char rxd){                              
L_TYPE	d;
int		i;
	switch(rxd){
	case '!':
		write_txbuf_asc('!');		/* for BPS & Exist check */
		DEBUG_TX_START;
		break;                             
	case '@': 
		debug_cnt=0;
		debug_rd_addr_tmp=0;
		debug_state=1;
		break;
	case 'R': 
	case 'r':
		d.w[0] = *(Uint16 *)(debug_rd_addr);
		write_txbuf_word(d.w[0]);
		write_txbuf_asc(CR);
		if(rxd =='r') debug_rd_addr++;
		DEBUG_TX_START;
		break;
	case 'L': 
	case 'l': 
		d.l = *(Uint32 *)(debug_rd_addr);
		write_txbuf_long(d.l);
		write_txbuf_asc(CR);
		if(rxd == 'l') debug_rd_addr += 2;
		DEBUG_TX_START;
		break;
	case 'O':
	case 'o':
		for(i=0; i<8; i+=2){
			d.l = *(Uint16 *)(debug_rd_addr + i);
			write_txbuf_long(d.l);
		}
		write_txbuf_asc(CR);	 
		if(rxd == 'o') debug_rd_addr += 8;
		DEBUG_TX_START;
		break;
	case '?':
		write_txbuf_long(debug_rd_addr);
		write_txbuf_string("_DSP28x");
		write_txbuf_asc(CR);
		DEBUG_TX_START;
		break;
	case 'W':
		debug_sum_temp=0;         
		debug_sum='W';
		debug_wr_sum_flag=1;
		debug_state=3;               	
	    debug_wr_data.l[0]=0;
	    debug_wr_data.l[1]=0;
	    debug_wr_data.l[2]=0;
	    debug_wr_data.l[3]=0;
	    debug_wr_addr=0;
	    debug_cnt=0;
		break;                 
	case 'w':
		debug_sum_temp=0;         
		debug_sum='w';
		debug_wr_sum_flag=0;
		debug_state=3;               	
	    debug_wr_data.l[0]=0;
	    debug_wr_data.l[1]=0;
	    debug_wr_data.l[2]=0;
	    debug_wr_data.l[3]=0;
	    debug_wr_addr=0;
	    debug_cnt=0;
		break;                 
	default: 
		break;
	}
}     

void state1_proc(char rxd){                           
char temp ;
	temp = asc2hex(rxd);
	if(temp == ASC_HEX_ERROR ){
		 debug_state=0;	
		 return;
	}
	debug_rd_addr_tmp = (debug_rd_addr_tmp<<4) + (temp & 0xf);
	debug_cnt++;    
	if(debug_cnt >= 6) debug_state=2;
}

void state2_proc(char rxd){
	debug_state=0;
	switch(rxd){
	case CR:
		debug_rd_addr=debug_rd_addr_tmp;
		write_txbuf_asc('!');
		DEBUG_TX_START;
		break;
	case 'R':
	case 'r':
	case 'L':
	case 'l':
	case 'O':
	case 'o':
		debug_rd_addr=debug_rd_addr_tmp;
		state0_proc(rxd);
		break;
	default:
		write_txbuf_string("X");
		DEBUG_TX_START;
		break;
	}
}		
			
void state3_proc(char rxd){                     
	if((rxd == '1') || (rxd == '2')){
		 debug_wr_size = asc2hex(rxd)*4;
		 debug_state=4;
	}
	else debug_state=0;
	
	debug_cnt = 0;                             
	debug_sum += rxd;
}                                      

void state4_proc(char rxd){
char temp ;
	temp = asc2hex(rxd);
	if(temp == ASC_HEX_ERROR){
		 debug_state=0;	
		 return;
	}
	
	debug_wr_addr = (debug_wr_addr<<4) + (temp & 0xf);
	debug_cnt++;    
	if(debug_cnt >= 6){
		debug_state = 5;
		debug_cnt = 0;
	}
	debug_sum += rxd;
}
	
void state5_proc(char rxd){
char hex,i;
	hex = asc2hex(rxd);
	if(hex == ASC_HEX_ERROR){
		 debug_state=0;	
		 return;
	}                                                 
	
	i = debug_cnt >> 3;
	debug_cnt++;
	debug_wr_data.l[i] = (debug_wr_data.l[i] << 4) + hex;
	if(debug_cnt >= debug_wr_size){
		debug_cnt = 0;
		debug_state=6;
	}
	debug_sum += rxd;
}	
	            
void state6_proc(char rxd){
char temp ;
	temp = asc2hex(rxd);
	if(temp == ASC_HEX_ERROR ){
		 debug_state=0;	
		 return;
	}
	
	debug_sum_temp = (debug_sum_temp << 4) + temp;
	debug_cnt++;
	if(debug_cnt >= 2)	debug_state=7;
}                         

void state7_proc(char rxd){
	if(rxd != CR) write_txbuf_string("X");
	else if((debug_sum & 0xff) != (debug_sum_temp & 0xff)){
		if(debug_wr_sum_flag){
			write_txbuf_string("X");
			DEBUG_TX_START;
		    debug_state=0;
		    return;
		}
	}

   	if(debug_wr_size == 4){
   		*(Uint16 *)(debug_wr_addr) = debug_wr_data.l[0];
   	}
   	else if(debug_wr_size == 8){
   		*(Uint32 *)(debug_wr_addr) = debug_wr_data.l[0];
   	}
   	write_txbuf_asc('!');
	DEBUG_TX_START;

    debug_state=0;
}

interrupt void scia_tx_isr(void){
	if(debug_tx_pos != debug_tx_end){
		SciaRegs.SCITXBUF = debug_tx_buf[debug_tx_pos++];
		if(debug_tx_pos >= DEBUG_BUF_SIZE)	debug_tx_pos = 0;
	}
	else{                              
		DEBUG_TX_STOP;
	}

	// Acknowledge this interrupt to recieve more interrupts from group 9
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	
}
	
interrupt void scia_rx_isr(void){
char rxd;            
	rxd = SciaRegs.SCIRXBUF.all;
	
	switch(debug_state){
	case 0: state0_proc(rxd); break;
	case 1:	state1_proc(rxd); break;
	case 2:	state2_proc(rxd); break;
	case 3:	state3_proc(rxd); break;
	case 4:	state4_proc(rxd); break;
	case 5:	state5_proc(rxd); break;
	case 6:	state6_proc(rxd); break;
	case 7:	state7_proc(rxd); break;
	default: debug_state = 0; break;
	}
	
	// Acknowledge this interrupt to recieve more interrupts from group 9
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;	
}

void sci_debug_init(void){
    // Note: Clocks were turned on to the SCI-A peripheral
    // in the InitSysCtrl() function
    SciaRegs.SCIFFTX.all = 0x8000;		// FIFO reset
 	SciaRegs.SCIFFCT.all = 0x4000;		// Clear ABD(Auto baud bit)
 	
 	SciaRegs.SCICCR.all = 0x0007;  		// 1 stop bit,  No loopback 
                                   		// No parity,8 char bits,
                                   		// async mode, idle-line protocol
	SciaRegs.SCICTL1.all = 0x0003; 		// enable TX, RX, internal SCICLK, 
                                   		// Disable RX ERR, SLEEP, TXWAKE

	SciaRegs.SCICTL2.bit.RXBKINTENA = 1;// RX/BK INT ENA=1,
	SciaRegs.SCICTL2.bit.TXINTENA = 1;	// TX INT ENA=1,

    SciaRegs.SCIHBAUD = BRR_VAL >> 8;	// High Value
    SciaRegs.SCILBAUD = BRR_VAL & 0xff;	// Low Value

	SciaRegs.SCICTL1.all = 0x0023; 		// Relinquish SCI from Reset  
    
	// User specific functions, Reassign vectors (optional), Enable Interrupts:
	
    // Initialize SCI_A RX interrupt
    // Reassign SCI_A RX ISR. 
    // Reassign the PIE vector for RXAINT to point to a different ISR then
    // the shell routine found in DSP28_DefaultIsr.c.
    // This is done if the user does not want to use the shell ISR routine
    // but instead wants to use their own ISR.  This step is optional:
    
	EALLOW;	// This is needed to write to EALLOW protected registers
	PieVectTable.SCIRXINTA = &scia_rx_isr;
    PieVectTable.SCITXINTA = &scia_tx_isr;
   
    /* Enable internal pull-up for the selected pins */
	// Pull-ups can be enabled or disabled disabled by the user.  
	// This will enable the pullups for the specified pins.
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0; // Enable pull-up for GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;	// Enable pull-up for GPIO29 (SCITXDA)

	/* Set qualification for selected pins to asynch only */
	// Inputs are synchronized to SYSCLKOUT by default.  
	// This will select asynch (no qualification) for the selected pins.
	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)

	/* Configure SCI-A pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be SCI functional pins.
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation
	EDIS;       // This is needed to disable write to EALLOW protected registers

    // Enable CPU INT9 for SCI-A
	IER |= M_INT9;
	
    // Enable SCI-A RX INT in the PIE: Group 9 interrupt 1
	PieCtrlRegs.PIEIER9.bit.INTx1 = 1;

    // Enable SCI-A TX INT in the PIE: Group 9 interrupt 2
	PieCtrlRegs.PIEIER9.bit.INTx2 = 1;
}
