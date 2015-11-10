// project : fullBridge
// filename : main.c
//  2014.08.17 Sunday
// Eunwho Power Electronics
// Cheoung Soon Gil

#pragma DATA_SECTION(ZONE0_BUF,"ZONE0DATA");
#pragma DATA_SECTION(ZONE6_BUF,"ZONE6DATA");

#pragma DATA_SECTION(ZONE7_BUF,"ZONE7DATA");

volatile unsigned int ZONE0_BUF[256];
volatile unsigned int ZONE6_BUF[0x10000];
volatile unsigned int ZONE7_BUF[256];

#include	"header.h"
#include	"extern.h"
#include	"global.h"

extern interrupt void MainPWM(void);

#if ROM_VERSION
	#pragma CODE_SECTION(MainPWM, "ramfuncs");
	#pragma CODE_SECTION(trip_check, "ramfuncs");
	#pragma CODE_SECTION(CheckOverCurrent, "ramfuncs");
	#pragma CODE_SECTION(CheckOverVolt, "ramfuncs");
	#pragma CODE_SECTION(CheckUndeVolt, "ramfuncs");
	#pragma CODE_SECTION(CheckOverHeat, "ramfuncs");
	#pragma CODE_SECTION(CheckOVP, "ramfuncs");
	#pragma CODE_SECTION(CheckIGBTFault, "ramfuncs");
	#pragma CODE_SECTION(Adc_Isr, "ramfuncs");
	#pragma CODE_SECTION(LPF1, "ramfuncs");

	extern Uint16 RamfuncsLoadStart;	// These are defined by the linker (see F28335.cmd)
	extern Uint16 RamfuncsLoadEnd;		// These are defined by the linker (see F28335.cmd)
	extern Uint16 RamfuncsRunStart;		// These are defined by the linker (see F28335.cmd)
#endif

void main( void )
{
	int trip_code,i,loop_ctrl,cmd;
	double ref_in0;

	InitSysCtrl(); InitXintf(); InitGpio();

#if ROM_VERSION
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
	InitFlash();	// Call Flash Initialization to setup flash waitstates
#endif

	gfRunTime = 0.0; protect_reg.all = 0;
	MAIN_CHARGE_OFF; INIT_CHARGE_CLEAR;

	init_charge_flag = 0;

	RESET_DRIVER_CLEAR;

	gMachineState = STATE_POWER_ON; 

	DINT;	IER = 0x0000; 	IFR = 0x0000;

	InitPieCtrl();

#if USE_SCI_B
	scib_fifo_init();
#endif
#if USE_SCI_C
	scic_fifo_init();
#endif
	I2CA_Init();	// Initalize I2C serial eeprom and Real Time Clock;
	InitCpuTimers();   // For this example, only initialize the Cpu Timers

	ConfigCpuTimer(&CpuTimer0, 150, 250);	// debug 2011.10.01
	StartCpuTimer0();
 
	InitAdc();	
	
	EALLOW;  // This is needed to write to EALLOW protected registers
	  	PieVectTable.TINT0 		= &cpu_timer0_isr;
		PieVectTable.WAKEINT 	= &wakeint_isr;
		PieVectTable.EPWM1_INT 	= &MainPWM;
		PieVectTable.ADCINT		= &Adc_Isr;

#if USE_SCI_B
		PieVectTable.SCIRXINTB = &scibRxFifoIsr;
		PieVectTable.SCITXINTB = &scibTxFifoIsr;
#endif
#if USE_SCI_C
		PieVectTable.SCIRXINTC = &scicRxFifoIsr;
		PieVectTable.SCITXINTC = &scicTxFifoIsr;
#endif
  	EDIS;    // This is needed to disable write to EALLOW protected registers

	PieCtrlRegs.PIEIER1.bit.INTx6 = 1;	// Enable Adc irq
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;	// Timer0 irq
	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block   

	IER |= M_INT1;		// Enable CPU INT1 which is connected to CPU-Timer 0:
	IER |= M_INT8;		// scic irq 
	IER |= M_INT9;		//CAN, SCI_A
	EINT;   // Enable Global interrupt INTM
	ERTM;	// Enable Global realtime interrupt DBGM

	gPWMTripCode = 0;		// ������ �ʱ�ȭ 

	i = load_code2ram();
	if( i !=0 ) TripProc();

	initVariFullbridgeCtrl();

	RESET_DRIVER_SET;
	delay_msecs(10);
	RESET_DRIVER_CLEAR;

	IER &= ~M_INT3;      // debug for PWM
	initEpwmFullBridge(); 	// debug
	EPwm1Regs.ETSEL.bit.INTEN = 1;    		            // Enable INT
	IER |= M_INT3;      // debug for PWM

	gfRunTime = 0.0; 

 	if( code_set_Vdc_on ) Vdc = code_Vdc_set_value;	// 2014.0909
 	 
	if( code_protect_inhibit_on == 1)
	{
		protect_reg.bit.UNVER_VOLT = 0;			// udd �߰� 
		protect_reg.bit.EX_TRIP = 0;
		protect_reg.bit.OVER_VOLT = 0;
		protect_reg.bit.OVER_I_ADC = 0;
		protect_reg.bit.IGBT_FAULT = 0;		
		protect_reg.bit.OVER_I = 0;
	}
	else {
		if(code_protect_uv_off == 0 ) 		protect_reg.bit.UNVER_VOLT = 1;			// udd �߰� 
		if(code_protect_ov_off == 0 ) 		protect_reg.bit.OVER_VOLT = 1;
		if(code_protect_Iadc_off == 0 ) 	protect_reg.bit.OVER_I_ADC = 1;
		if(code_protect_over_I_off == 0) 	protect_reg.bit.OVER_I = 1;
		if(code_protect_IGBT_off == 0 ) 	protect_reg.bit.IGBT_FAULT = 1;		
		if(code_protect_ex_trip_off == 0 ) 	protect_reg.bit.EX_TRIP = 1;
	}

	init_charge_flag = 1;	
	while( gfRunTime < 3.0){
		get_command( & cmd, & ref_in0);
		monitor_proc();
		Nop();
	}

	gPWMTripCode = 0;
	loop_ctrl = 1;
	gfRunTime = 0.0;

	if((code_protect_inhibit_on == 0 ) && (code_protect_uv_off == 0 )){
		while( loop_ctrl == 1){
			if( Vdc > code_under_volt_set ) loop_ctrl = 0;
			if( gfRunTime > 5.0) loop_ctrl = 0;
		}
		if( Vdc < code_under_volt_set ){
			trip_recording( CODE_under_volt_set,Vdc,"Trip Under Volt");
			TripProc();
		}
	}
	else{
		MAIN_CHARGE_ON;		// ���� ��� on 
		TRIP_OUT_OFF;
	}
  	


	MAIN_CHARGE_ON;		// ���� ��� on 
	init_charge_flag=0;
	gMachineState = STATE_READY; 

	INIT_CHARGE_CLEAR;

//--- ���� �ڵ� ������ ���� �ð� 
	gfRunTime = 0.0;
	while( gfRunTime < 2.0 ){
		get_command( & cmd, & ref_in0);
		monitor_proc();
		Nop();
	}
	gfRunTime = 0.0;

	GetTimeAndDateStr(gStr1);	gStr1[20] =0;
	load_sci_tx_mail_box(gStr1); delay_msecs(20);

	if( gPWMTripCode !=0 )	TripProc();		
	strncpy(MonitorMsg,"OK READY",20);
	strncpy(gStr1,"OK READY",20);
	load_sci_tx_mail_box(gStr1); delay_msecs(20);


	for( ; ; )
	{
		if( gPWMTripCode !=0 )	TripProc();		
		gPWMTripCode = trip_check();
		if( gPWMTripCode !=0 )	TripProc();		
		get_command( & cmd, & ref_in0);
		analog_out_proc( );
		monitor_proc();

		if(cmd == CMD_READ_ALL){
			sendAllCodeData();
		}			
		else if(cmd == CMD_START)	// if( cmd == CMD_START )
		{
			GetTimeAndDateStr(gStr1);
			strncpy(TripInfoNow.START_TIME,gStr1,20);

			trip_code = 0;
			switch( code_ctrl_mode ) // Control Method
			{
			case 2 : trip_code = mode2LoopCtrl();break;				// 11. code_testPwmPhase conti output
			case 3 : trip_code = mode3Current_P_I_LoopCtrl();break;
			case 8 : trip_code = mode8LoopCtrl();break;
			case 9 : pwmPulseTestLoopCtrl( ); break;
			}
			if( trip_code !=0 )	TripProc();		
		}
	}
}

//	MAX_PWM_CNT =	30000;		// 2.5kHz
//	MAX_PWM_CNT =	15000;		// 5kHz

interrupt void wakeint_isr(void)
{
	static int WakeCount = 0; 

	WakeCount++;
	
	// Acknowledge this interrupt to get more from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void InitWatchDog()
{
	// Enable watch dog
// Write to the whole SCSR register to avoid clearing WDOVERRIDE bit

   EALLOW;
   SysCtrlRegs.SCSR = BIT1;
   EDIS;

// Enable WAKEINT in the PIE: Group 1 interrupt 8
// Enable INT1 which is connected to WAKEINT:
   PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
   PieCtrlRegs.PIEIER1.bit.INTx8 = 1;   // Enable PIE Gropu 1 INT8
   IER |= M_INT1;                       // Enable CPU int1
   EINT;                                // Enable Global Interrupts

   ServiceDog();

   EALLOW;
   SysCtrlRegs.WDCR = 0x0028;   
   EDIS;
}


//=========================================
// No more.
//=========================================

