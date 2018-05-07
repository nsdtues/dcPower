// Company 	: Eunwho Power Electonics  
// FILE		: switching_irq.c
// Project 	: back2back inverter
// PCB		: regen_dsp_110513 & regen_sen_110513
// rev data : 2013.0111  cheoung soon gil

#include        <header.h>
#include        <extern.h>

double phase_ratio=0.0;

interrupt void MainPWM(void)
{
//	unsigned int temp;
	static int invt_PWM_Port_Set_flag = 0;

	if ( EX_TRIP_INPUT == 0 ){
	    gPWMTripCode = TRIP_EXT_A;
		trip_recording( TRIP_EXT_A, TRIP_EXT_A ,"TRIP EXT A");
	}

	if(gPWMTripCode == 0){ 
		gPWMTripCode = tripCheck();		// debug_soonkil
		if(gPWMTripCode != 0 ){
			gMachineState = STATE_TRIP;
			epwmFullBridgeDisable(); // converter PWM gate OFF
			goto _PWM_OUT_END;
		}
	}
	else{ 
		gMachineState = STATE_TRIP; // trip_check�ÿ� ����� 
		epwmFullBridgeDisable(); // converter PWM gate OFF
		goto _PWM_OUT_END;
	}

	switch(gMachineState)
	{
		case STATE_POWER_ON:
		case STATE_TRIP:					
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT;
			invt_PWM_Port_Set_flag = 0;
			EPwm2Regs.TBPHS.half.TBPHS = 0;
			epwmFullBridgeDisable(); //inverter  PWM gate OFF
			break;

		case STATE_READY:
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
			invt_PWM_Port_Set_flag = 0;
			EPwm2Regs.TBPHS.half.TBPHS = 0;
			break;

		case STATE_INIT_RUN:
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;

			if( invt_PWM_Port_Set_flag == 0 ){
				epwmFullBridgeEnable();
				EPwm2Regs.TBPHS.half.TBPHS = (Uint16)(MAX_PWM_CNT * codePwmPhaseInit * 0.5)  ;
				invt_PWM_Port_Set_flag = 1;
			}
			else if( code_ctrl_mode == 9 ){
			    if( test_pulse_count < codeSetPulseNumber){
					EPwm2Regs.TBPHS.half.TBPHS = (Uint16)( MAX_PWM_CNT * codePwmPhaseInit * 0.5 );
					test_pulse_count++;
				}
				else{ 
					EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
					EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
					gMachineState = STATE_READY;
					epwmFullBridgeDisable();
				}
			}
			else{
				EPwm2Regs.TBPHS.half.TBPHS = (Uint16)( MAX_PWM_CNT * codePwmPhaseInit * 0.5 );
			}
			break;

		case STATE_RUN:
//		case STATE_BREAK_OFF:
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;

			if( code_ctrl_mode == 3 ){ 

				ctrlError =  reference_out -  I_out * 0.001; // 1000 Amp Max�� ����� 
				ctrlIntegral = preIntegral + (Ts * code_Ki * ctrlError);
				ctrlIntegral = (ctrlIntegral > code_integLimit) ? code_integLimit : ( ctrlIntegral < -code_integLimit) ? -code_integLimit : ctrlIntegral;

				phaseShiftRatio = (ctrlError * code_Kp) + ctrlIntegral;

				// Vout = VoutScale * reference_out  + VoutOffset ;  

				if     ( phaseShiftRatio < 0.0 ) 	phaseShiftRatio = 0.0;
				else if( phaseShiftRatio > phaseVref ) 	phaseShiftRatio = phaseVref; 

				preIntegral = ctrlIntegral;

				EPwm2Regs.TBPHS.half.TBPHS = (Uint16)( MAX_PWM_CNT * phaseShiftRatio * 0.5 );

			}
			else if( code_ctrl_mode == 8 ){ // mode8LoopCtrl mode
				EPwm2Regs.TBPHS.half.TBPHS = (Uint16)( MAX_PWM_CNT * reference_out * 0.5 );
			}
			else if( code_ctrl_mode == 2 ){ // mode2LoopCtrl mode
				EPwm2Regs.TBPHS.half.TBPHS =(Uint16)( MAX_PWM_CNT * code_testPwmPhase * 0.5 );
			}
			else{
				EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
				EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
				EPwm2Regs.TBPHS.half.TBPHS = 0;
			}
			break;

		case STATE_GO_STOP:

			if ( reference_out < 0.10){
				reference_out = 0.0;
				EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
				EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1 ;
				EPwm2Regs.TBPHS.half.TBPHS = 0 ;
				invt_PWM_Port_Set_flag = 0;
				epwmFullBridgeDisable();
				gMachineState = STATE_READY;
			}
			else{ // mode2LoopCtrl mode
				EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;
				EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT>>1;
				EPwm2Regs.TBPHS.half.TBPHS = (Uint16)( MAX_PWM_CNT * reference_out * 0.5 );
			}
			break;

 		default: 
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT;
			EPwm2Regs.TBPHS.half.TBPHS = 0;
			invt_PWM_Port_Set_flag = 0;
			epwmFullBridgeDisable(); // converter PWM gate OFF
			break;
	}

_PWM_OUT_END:


//--- digital out
    digitalOutProc();

	EPwm1Regs.ETCLR.bit.INT = 1;	
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

// end of switching_irq.c 


