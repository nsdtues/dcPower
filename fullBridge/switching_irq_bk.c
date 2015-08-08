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
	unsigned int dac_data[4];
	unsigned int temp; 
	static int invt_PWM_Port_Set_flag = 0;

#if TEST_ADC_CENTER
	J8_2_SET;
#endif

	digital_input = ZONE0_BUF[0x0050];   // debug
	if(( protect_reg.bit.EX_TRIP == 1 )&&(( digital_input & 0x0004 ) != 0 )){
		temp = ZONE0_BUF[0x0050]&0x0004;   // debug
		if ( temp != 0 ){
		 	gPWMTripCode = TRIP_EXT_A;
			trip_recording( TRIP_EXT_A, TRIP_EXT_A ,"TRIP EXT A");
		}
	}

	if(gPWMTripCode == 0){ 
		gPWMTripCode = trip_check();		// debug_soonkil
		if(gPWMTripCode != 0 ){
			gMachineState = STATE_TRIP;
			epwmFullBridgeDisable(); // converter PWM gate OFF
			goto _PWM_OUT_END;
		}
	}
	else{ 
		gMachineState = STATE_TRIP; // trip_check½Ã¿¡ ÀúÀåµÊ 
		epwmFullBridgeDisable(); // converter PWM gate OFF
		goto _PWM_OUT_END;
	}

	switch(gMachineState)
	{
		case STATE_POWER_ON:
		case STATE_TRIP:					
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
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

			if( code_ctrl_mode == 1 ) fullBridgeCtrl();
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
			EPwm1Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
			EPwm2Regs.CMPA.half.CMPA = MAX_PWM_CNT >> 1;
			EPwm2Regs.TBPHS.half.TBPHS = 0;
			invt_PWM_Port_Set_flag = 0;
			epwmFullBridgeDisable(); // converter PWM gate OFF
			break;
	}

_PWM_OUT_END:

	dac_data[0] = (unsigned int )(( * (dac_point[code_dac_select_ch1]) - code_dac_offset_ch1 ) * inv_code_dac_scale_ch1 * 204.8 + 2047); 
	dac_data[1] = (unsigned int )(( * (dac_point[code_dac_select_ch2]) - code_dac_offset_ch2 ) * inv_code_dac_scale_ch2 * 204.8 + 2047); 
	dac_data[2] = (unsigned int )(( * (dac_point[code_dac_select_ch3]) - code_dac_offset_ch3 ) * inv_code_dac_scale_ch3 * 204.8 + 2047); 
	dac_data[3] = (unsigned int )(( * (dac_point[code_dac_select_ch4]) - code_dac_offset_ch4 ) * inv_code_dac_scale_ch4 * 204.8 + 2047); 

	ZONE0_BUF[0x60] = 7;	ZONE0_BUF[0x60] = 3;
	ZONE0_BUF[0x30] = dac_data[0]; 	ZONE0_BUF[0x32] = dac_data[1];
	ZONE0_BUF[0x34] = dac_data[2]; 	ZONE0_BUF[0x36] = dac_data[3];
	Nop(); Nop(); Nop(); Nop();		// do not erase !!! waiting for write data 
	ZONE0_BUF[0x60] = 1; 	ZONE0_BUF[0x60] = 7;

//--- digital out
	if(      gMachineState == STATE_TRIP     ){ MAIN_CHARGE_OFF; RUN_OUT_OFF; TRIP_OUT_OFF;}
	else if( gMachineState == STATE_POWER_ON ){ MAIN_CHARGE_OFF; RUN_OUT_OFF; TRIP_OUT_OFF;}
	else if( gMachineState == STATE_INIT_RUN ){ MAIN_CHARGE_ON ; RUN_OUT_OFF; TRIP_OUT_ON;}
	else if( gMachineState == STATE_READY    ){ MAIN_CHARGE_ON ; RUN_OUT_OFF; TRIP_OUT_ON;}
	else if( gMachineState == STATE_RUN      ){ MAIN_CHARGE_ON ; RUN_OUT_ON;  TRIP_OUT_ON;}
	else if( gMachineState == STATE_GO_STOP  ){ MAIN_CHARGE_ON ; RUN_OUT_ON;  TRIP_OUT_ON;}
	else if( gMachineState == STATE_BREAK_OFF){ MAIN_CHARGE_ON ; RUN_OUT_OFF; TRIP_OUT_ON;}
	else                                      {                  RUN_OUT_ON; TRIP_OUT_ON;}

	EPwm1Regs.ETCLR.bit.INT = 1;	
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

#if TEST_ADC_CENTER
	J8_2_CLEAR;	// debug
#endif

}

// end of switching_irq.c 


