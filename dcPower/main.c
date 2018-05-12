/*
 project : dc power supply
 title   : f28069dcPower :  pcb='dcPower G0801'
*/

#define DELAY   50000L
#include	"header.h"
#include	"extern.h"
#include	"global.h"

#if FLASH_RUN
#pragma CODE_SECTION(MainPWM, "ramfuncs");
#pragma CODE_SECTION(adcIsr, "ramfuncs");
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
Uint16 RamfuncsLoadSize;
#endif

void InitWatchDog();
extern interrupt void MainPWM(void);
extern interrupt void adcIsr(void);
extern interrupt void sciaRxFifoIsr(void);
extern interrupt void sciaTxFifoIsr(void);

float Vdc_fnd_data;

void main( void )
{
    int trip_code,loop_ctrl,temp;
	int cmd;
	float ref_in0;

	InitSysCtrl();
	InitGpio();

	gfRunTime = 0.0; 
	protect_reg.all = 0;
	MAIN_CHARGE_OFF;

	init_charge_flag = 0;
//	RESET_DRIVER_CLEAR;

	gMachineState = STATE_POWER_ON; 
	DINT;
#if FLASH_RUN
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);
	InitFlash();
#endif
	InitPieCtrl();
	IER = 0x0000;   IFR = 0x0000;
	InitPieVectTable();

	scia_fifo_init();

	I2CA_Init();	// Initalize I2C serial eeprom and Real Time Clock;
	InitCpuTimers();   // For this example, only initialize the Cpu Timers

	ConfigCpuTimer(&CpuTimer0, 90, 1000);	// debug 2011.10.01
	StartCpuTimer0();

	PieCtrlRegs.PIEIER1.bit.INTx1 = 1; // Enable INT 1.1 in the PIE

	EALLOW;  // This is needed to write to EALLOW protected registers
	  	PieVectTable.TINT0 		= &cpu_timer0_isr;
		PieVectTable.WAKEINT 	= &wakeint_isr;
		PieVectTable.EPWM1_INT 	= &MainPWM;

		PieVectTable.ADCINT1	= &adcIsr;
		PieVectTable.SCIRXINTA = &sciaRxFifoIsr;
		PieVectTable.SCITXINTA = &sciaTxFifoIsr;
  	EDIS;    // This is needed to disable write to EALLOW protected registers

  	InitAdc();
//    AdcOffsetSelfCal();

  	EALLOW;
     SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

  	PieCtrlRegs.PIEIER1.bit.INTx6 = 1;	// Enable Adc irq
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;	// Timer0 irq
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1; // Enable INT 1.1 in the PIE ADCINT1
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;   //

    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block

    IER |= M_INT1;		// Enable CPU INT1 which is connected to CPU-Timer 0:
	IER |= M_INT8;		// scic irq 
	IER |= M_INT9;		//CAN, SCI_A
    IER |= M_INT3;

    EINT;   // Enable Global interrupt INTM
	ERTM;	// Enable Global realtime interrupt DBGM

    InitWatchDog();

    ADC_SOC_CNF();
    strncpy(MonitorMsg,"POWER_ON",20);
    gPWMTripCode = 0;		//

    if( load_code2ram() != 0 ) tripProc();

    initVariFullbridgeCtrl();
    lpf2ndCoeffInit( 1000.0,Ts, lpfVdcIn, lpfVdcOut, lpfVdcK);
    lpf2ndCoeffInit( 100.0, Ts, lpfIoutIn, lpfIoutOut, lpfIoutK);

	IER &= ~M_INT3;      // debug for PWM
    initEpwmFullBridge();   // debug
	EPwm1Regs.ETSEL.bit.INTEN = 1;    		            // Enable INT
	IER |= M_INT3;      // debug for PWM

	gfRunTime = 0.0; 

    delay_msecs(500);
    for(;;){
//        snprintf( gStr1,10," VDC =%4d",temp);
        strncpy(gStr1,"hello workd. /r/n",20);
        load_sci_tx_mail_box(gStr1);
        delay_msecs(1000);
    }

    temp = (int)(floor(codeProtectOff+0.5));

    if( temp != 0 )
	{
		protect_reg.bit.UNVER_VOLT = 0;
		protect_reg.bit.EX_TRIP = 0;
		protect_reg.bit.OVER_VOLT = 0;
		protect_reg.bit.OVER_I_ADC = 0;
		protect_reg.bit.IGBT_FAULT = 0;		
		protect_reg.bit.OVER_I = 0;
	}
	else {
		if(code_protect_uv_off == 0 ) 		protect_reg.bit.UNVER_VOLT = 1;	//
		if(code_protect_ov_off == 0 ) 		protect_reg.bit.OVER_VOLT = 1;
		if(code_protect_Iadc_off == 0 ) 	protect_reg.bit.OVER_I_ADC = 1;
		if(code_protect_over_I_off == 0) 	protect_reg.bit.OVER_I = 1;
		if(code_protect_IGBT_off == 0 ) 	protect_reg.bit.IGBT_FAULT = 1;		
		if(code_protect_ex_trip_off == 0 ) 	protect_reg.bit.EX_TRIP = 1;
	}
	init_charge_flag = 1;	
	while( gfRunTime < 5.0){
		get_command( & cmd, & ref_in0);		monitor_proc();
	}
	gPWMTripCode = 0;	loop_ctrl = 1;	gfRunTime = 0.0;

	if((codeProtectOff == 0 ) & (code_protect_uv_off == 0 )){
		while( loop_ctrl == 1){
			if( Vdc > under_volt_set ) loop_ctrl = 0;
			if( gfRunTime > 5.0) loop_ctrl = 0;
		}
		if( Vdc < under_volt_set ){
			trip_recording( ERR_UV_VDC,Vdc,"Trip Under Volt");
			tripProc();
		}
	}
	else{
		MAIN_CHARGE_ON;		//
		TRIP_OUT_OFF;
	}

	MAIN_CHARGE_ON;
	init_charge_flag=0;
	gMachineState = STATE_READY;

	if( gPWMTripCode !=0 )	tripProc();
	strncpy(MonitorMsg,"READY",20);delay_msecs(20);
	strncpy(gStr1,"READY",20);
	load_sci_tx_mail_box(gStr1); delay_msecs(20);

	GATE_DRIVER_ENABLE;
	for( ; ; )
	{
		if( gPWMTripCode !=0 )	tripProc();
		gPWMTripCode = tripCheck();
		if( gPWMTripCode !=0 )	tripProc();
		get_command( & cmd, & ref_in0);
//		analog_out_proc( );
		if(cmd == CMD_READ_ALL ){
		    readAllCodes();
		}
		monitor_proc();
		if(cmd == CMD_START){	// if( cmd == CMD_START )
		    trip_code = 0;
		    temp = (int)(floor(code_ctrl_mode+0.5));
		    switch(temp)
		    {
		    case 3: trip_code = mode3Current_P_I_LoopCtrl();break;
		    case 8: trip_code = mode8LoopCtrl();break;
		    case 9: pwmPulseTestLoopCtrl();break;
		    }
			if( trip_code !=0 )	tripProc();
		}
	}
}

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

