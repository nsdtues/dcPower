// code_proc.c
//   header file : code_proc.h
//

#include	"header.h"
#include	"extern.h"


int get_code_group0(int addr ,int cmd, CODE_INFO * codes)
{

	switch(addr)
	{
	case CODE_I_out_ref:	
		strncpy(codes->disp, "I Out Set",40);
		if( cmd == CMD_WRITE_RAM ) code_I_out_ref = (codes->code_value).doubles;
		set_code_default_double(10.0,800.0,600.0,code_I_out_ref,0,codes);
		break;

	case CODE_VoutLimit:		// code 3	
		strncpy(codes->disp, "Vout Limit",40);
		if( cmd == CMD_WRITE_RAM ) code_VoutLimit = (codes->code_value).doubles;
		set_code_default_double(0.1,300.0,250.0,code_VoutLimit,0,codes);
		break;

	case CODE_ovpTime:		// code 4	
		strncpy(codes->disp, "OVP time set",40);
		if( cmd == CMD_WRITE_RAM ) code_ovpTime = (codes->code_value).doubles;
		set_code_default_double(0.01,9999.0,60.0,code_ovpTime,0,codes);
		break;

	case CODE_Vout:		// 	
		strncpy(codes->disp, "Set Vout",40);
		if( cmd == CMD_WRITE_RAM ) code_Vout = (codes->code_value).doubles;
		set_code_default_double(0.1,300.0,220.0,code_Vout,0,codes);
		break;

	case CODE_run_input_select:	//
		strncpy(codes->disp, "RUN input select",40);
		if( cmd == CMD_WRITE_RAM ) code_run_input_select = (codes->code_value).ints;
		set_code_default_int(0,9,0,code_run_input_select,1,codes);
		break;

	case CODE_ctrl_mode:	// 
		strncpy(codes->disp, "ctrl_mode",40);
		if( cmd == CMD_WRITE_RAM ) code_ctrl_mode = (codes->code_value).ints;
		set_code_default_int(0,10,0,code_ctrl_mode,0,codes);
		break;
	
	case CODE_PwmPhaseInit:	
		strncpy(codes->disp, "Init Pwm Phase Ratio",40);
		if( cmd == CMD_WRITE_RAM ) codePwmPhaseInit = (codes->code_value).doubles;
		set_code_default_double(0.0,0.9,0.05,codePwmPhaseInit,0,codes);
		break;

	case CODE_InitTime:	
		strncpy(codes->disp, "Init Time [sec]",40);
		if( cmd == CMD_WRITE_RAM ) codeInitTime = (codes->code_value).doubles;
		set_code_default_double(0.0,60.0,3.0,codeInitTime,0,codes);
		break;

	case CODE_SetPulseNumber:	
		strncpy(codes->disp, "Set Pulse Out Count",40);
		if( cmd == CMD_WRITE_RAM ) codeSetPulseNumber = (codes->code_value).ints;
		set_code_default_int(0,30000,1,codeSetPulseNumber,0,codes);
		break;

	case CODE_testPwmPhase:	
		strncpy(codes->disp, "Test Pwm Phase",40);
		if( cmd == CMD_WRITE_RAM ) code_testPwmPhase = (codes->code_value).doubles;
		set_code_default_double(0.0,1.0,0.1,code_testPwmPhase,0,codes);
		break;

	case CODE_set_Vdc_on:	
		strncpy(codes->disp, "Vdc Set On",40);
		if( cmd == CMD_WRITE_RAM )code_set_Vdc_on = (codes->code_value).ints;
		set_code_default_int(0,1,1,code_set_Vdc_on,0,codes);
		break;

	case CODE_Vdc_set_value:	
		strncpy(codes->disp, "Vdc set value(Vdc)",40);
		if( cmd == CMD_WRITE_RAM ) code_Vdc_set_value = (codes->code_value).doubles;
		set_code_default_double(0.0,999.0,520.0,code_Vdc_set_value,0,codes);
		break;

	case CODE_accel_time1:	// code 015
		strncpy(codes->disp, "accel_time1 (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_accel_time1 = (codes->code_value).doubles;
		set_code_default_double(0.0,3000.0,5.0,code_accel_time1,0,codes);
		break;
	
	case CODE_decel_time1:
		strncpy(codes->disp, "decel_time1 (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_decel_time1 = (codes->code_value).doubles;
		set_code_default_double(0.0,3000.0,5.0,code_decel_time1,0,codes);
		break;

	case CODE_accel_time2:	
		strncpy(codes->disp, "accel_time2 (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_accel_time2 = (codes->code_value).doubles;
		set_code_default_double(0.0,3000.0,5.0,code_accel_time2,0,codes);
		break;
	
	case CODE_decel_time2:	
		strncpy(codes->disp, "decel_time2 (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_decel_time2 = (codes->code_value).doubles;
		set_code_default_double(0.0,3000.0,5.0,code_decel_time2,0,codes);
		break;

	case CODE_speed2:		
		strncpy(codes->disp, "speed2 (p.u)",40);
		if( cmd == CMD_WRITE_RAM ) code_speed2 = (codes->code_value).doubles;
		set_code_default_double(0.0,1.0,0.4,code_speed2,0,codes);
		break;

	case CODE_rDeadTime:		
		strncpy(codes->disp, "rDeadTime(uSec)",40);
		if( cmd == CMD_WRITE_RAM ) rDeadTime = (codes->code_value).doubles;
		set_code_default_double(3.0,6.3,4.0,rDeadTime,0,codes);
		break;

	case CODE_allDeadTime:		
		strncpy(codes->disp, "allDeadTime(uSec)",40);
		if( cmd == CMD_WRITE_RAM ) allDeadTime = (codes->code_value).doubles;
		set_code_default_double(3.0,6.3,4.0,allDeadTime,0,codes);
		break;

	case CODE_GROUP0_END:
		return -2;

	default:
		return -1;
	}
	return 0;
}

int get_code_group1(int addr ,int cmd, CODE_INFO * codes)
{
	switch(addr)
	{

	case CODE_analog_cmd_in_zero1:	
		strncpy(codes->disp, "Analog Cmd1 in Zero",40);
		if( cmd == CMD_WRITE_RAM ) analog_cmd_in_zero1 = (codes->code_value).doubles;
		set_code_default_double(0.0,0.2,0.0,analog_cmd_in_zero1,0,codes);
		break;

	case CODE_analog_cmd_in_span1:	
		strncpy(codes->disp, "Analog Cmd1 in Span",40);
		if( cmd == CMD_WRITE_RAM ) analog_cmd_in_span1 = (codes->code_value).doubles;
		set_code_default_double(0.5,2.0,1.0,analog_cmd_in_span1,0,codes);
		break;

	case CODE_analog_cmd_in_zero2:	
		strncpy(codes->disp, "Analog Cmd2 in Zero",40);
		if( cmd == CMD_WRITE_RAM ) analog_cmd_in_zero2 = (codes->code_value).doubles;
		set_code_default_double(0.0,0.2,0.0,analog_cmd_in_zero2,0,codes);
		break;

	case CODE_analog_cmd_in_span2:	
		strncpy(codes->disp, "Analog Cmd2 in Span",40);
		if( cmd == CMD_WRITE_RAM ) analog_cmd_in_span2 = (codes->code_value).doubles;
		set_code_default_double(0.5,2.0,1.0,analog_cmd_in_span2,0,codes);
		break;

	case CODE_AdcOffsetCh6:	//
		strncpy(codes->disp, "Adc Offset Ch6",40);
		if( cmd == CMD_WRITE_RAM ) code_AdcOffsetCh6 = (codes->code_value).ints;
		set_code_default_int(0,4095,2048,code_AdcOffsetCh6,0,codes);
		break;

//-- Ch1 Analog Monitor
	case CODE_analog_out_select1:	
		strncpy(codes->disp, "Analog Select 1",40);
		if( cmd == CMD_WRITE_RAM ) codeAnalogSelect1 = (codes->code_value).ints;
		set_code_default_int(0,10,0,codeAnalogSelect1,0,codes);
		break;

	case CODE_analog_out_zero1:	
		strncpy(codes->disp, "Analog Out Zero1",40);
		if( cmd == CMD_WRITE_RAM ) codeAnalogOutZero1 = (codes->code_value).doubles;
		set_code_default_double(0.8,1.2,1.0,codeAnalogOutZero1,0,codes);
		break;

	case CODE_analog_out_span1:	
		strncpy(codes->disp, "Analog Out Span1",40);
		if( cmd == CMD_WRITE_RAM ) codeAnalogOutSpan1 = (codes->code_value).doubles;
		set_code_default_double(0.5,2.0,1.0,codeAnalogOutSpan1,0,codes);
		break;

//-- Ch2 Analog Monitor
	case CODE_analog_out_select2:	
		strncpy(codes->disp, "Analog Select 2",40);
		if( cmd == CMD_WRITE_RAM ) codeAnalogSelect2 = (codes->code_value).ints;
		set_code_default_int(0,10,0,codeAnalogSelect2,0,codes);
		break;

	case CODE_analog_out_zero2:	
		strncpy(codes->disp, "Analog Out Zero2",40);
		if( cmd == CMD_WRITE_RAM ) codeAnalogOutZero2 = (codes->code_value).doubles;
		set_code_default_double(0.8,1.2,1.0,codeAnalogOutZero2,0,codes);
		break;

	case CODE_analog_out_span2:	
		strncpy(codes->disp, "Analog Out Span2",40);
		if( cmd == CMD_WRITE_RAM ) codeAnalogOutSpan2 = (codes->code_value).doubles;
		set_code_default_double(0.5,2.0,1.0,codeAnalogOutSpan2,0,codes);
		break;

	case CODE_GROUP1_END:
		return -2;
			
	default:
		return -1;
	}
	return 0;
}

//--- protection 
int get_code_group2(int addr ,int cmd, CODE_INFO * codes )
{
	switch(addr){
	case CODE_OCLevel1st:	
		strncpy(codes->disp, "OC Level1st(A)",40);
		if( cmd == CMD_WRITE_RAM ) codeOCLevel1st = (codes->code_value).doubles;
		set_code_default_double(1.0,500.0,20.0,codeOCLevel1st,0,codes);
		break;

	case CODE_OCLevel2nd:	
		strncpy(codes->disp, "OC Level2nd(A)",40);
		if( cmd == CMD_WRITE_RAM ) codeOCLevel2nd = (codes->code_value).doubles;
		set_code_default_double(1.0,2000.0,200.0,codeOCLevel2nd,0,codes);
		break;

	case CODE_OCLevel3rd:	
		strncpy(codes->disp, "OCLevel3rd(A)",40);
		if( cmd == CMD_WRITE_RAM ) codeOCLevel3rd = (codes->code_value).doubles;
		set_code_default_double(1.0,2000.0,200.0,codeOCLevel3rd,0,codes);
		break;

	case CODE_OCLevelOut:	
		strncpy(codes->disp, "OC Level Out(A)",40);
		if( cmd == CMD_WRITE_RAM ) codeOCLevelOut = (codes->code_value).doubles;
		set_code_default_double(1.0,2000.0,800.0,codeOCLevelOut,0,codes);
		break;

	case CODE_over_volt_set:	
		strncpy(codes->disp, "over_volt_set (V)",40);
		if( cmd == CMD_WRITE_RAM ) over_volt_set = (codes->code_value).doubles;
		set_code_default_double(100.0,980.0,740.0,over_volt_set,0,codes);
		break;
		
	case CODE_under_volt_set:	
		strncpy(codes->disp, "under_volt_set(V)",40);
		if( cmd == CMD_WRITE_RAM ) code_under_volt_set = (codes->code_value).doubles;
		set_code_default_double(50.0,780.0,400.0,code_under_volt_set,0,codes);
		break;

	case CODE_OC_time:	
		strncpy(codes->disp, "Over C time (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_OC_time = (codes->code_value).doubles;
		set_code_default_double(0.5,600.0,60.0,code_OC_time,0,codes);
		break;

	//--- protect inhibit set
	case CODE_protect_inhibit_on:	
		strncpy(codes->disp, "protect_inhibit_on[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_inhibit_on = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_inhibit_on,0,codes);
		break;

	case CODE_protect_under_volt_off:	
		strncpy(codes->disp, "protect under volt off[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_uv_off = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_uv_off,0,codes);
		break;

	case CODE_protect_over_volt_off:	
		strncpy(codes->disp, "protect over volt off[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_ov_off = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_ov_off,0,codes);
		break;

	case CODE_protect_I_adc_off:	
		strncpy(codes->disp, "protect over I adc off[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_Iadc_off = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_Iadc_off,0,codes);
		break;

	case CODE_protect_over_I_off:	
		strncpy(codes->disp, "protect over I off[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_over_I_off = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_over_I_off,0,codes);
		break;

	case CODE_protect_IGBT_off:	
		strncpy(codes->disp, "protect IGBT off[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_IGBT_off = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_IGBT_off,0,codes);
		break;

	case CODE_protect_ex_trip_off:	
		strncpy(codes->disp, "protect EX_TRIP off[1]",40);
		if( cmd == CMD_WRITE_RAM ) code_protect_ex_trip_off = (codes->code_value).ints;
		set_code_default_int(0,1,0,code_protect_ex_trip_off,0,codes);
		break;
	
	case CODE_GROUP2_END:
		return -2;

	default:
		return -1;
	}
	return 0;
}

// Inverter protection 
int get_code_group3(int addr ,int cmd, CODE_INFO * codes)
{

	switch(addr)
	{
	case CODE_rate_volt:	
		strncpy(codes->disp, "rate_volt (Vrms)",40);
		if( cmd == CMD_WRITE_RAM ) code_rate_volt = (codes->code_value).doubles;
		set_code_default_double(100.0,500.0,380.0,code_rate_volt,0,codes);
		break;
		
	case CODE_rate_power:	
		strncpy(codes->disp, "rate_power",40);
		if( cmd == CMD_WRITE_RAM ) code_rate_power = (codes->code_value).doubles;
		set_code_default_double(100,2.0e+6,3700,code_rate_power,0,codes);
		break;
		
	case CODE_rate_current:	
		strncpy(codes->disp, "code_rate_current (A)",40);
		if( cmd == CMD_WRITE_RAM ) code_rate_current = (codes->code_value).doubles;
		set_code_default_double(1.0,2000.0,7.6,code_rate_current,0,codes);
		break;
		
	case CODE_rate_hz:	
		strncpy(codes->disp, "rate_hz (Hz)",40);
		if( cmd == CMD_WRITE_RAM ) code_rate_hz = (codes->code_value).doubles;
		set_code_default_double(30.0,120.0,60.0,code_rate_hz,0,codes);
		break;

	case CODE_GROUP3_END:
		return -2;

	default:
		return -1;
	}
	return 0;
}

int get_code_group4(int addr ,int cmd, CODE_INFO * codes)
{
	switch(addr)
	{
	case CODE_ISpan1st:	
		strncpy(codes->disp, "CODE_ISpan1st(p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeISpan1st = (codes->code_value).doubles;
		set_code_default_double(0.5,1.5,1.0,codeISpan1st,0,codes);
		break;
		
	case CODE_ISpan2nd:	
		strncpy(codes->disp, "I Span 2nd(p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeISpan2nd = (codes->code_value).doubles;
		set_code_default_double(0.5,1.5,1.0,codeISpan2nd,0,codes);
		break;
		
	case CODE_ISpan3rd:	
		strncpy(codes->disp, "I Span 3rd(p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeISpan3rd = (codes->code_value).doubles;
		set_code_default_double(0.5,1.5,1.0,codeISpan3rd,0,codes);
		break;
		
	case CODE_ISpanOut:	
		strncpy(codes->disp, "I Span Out(p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeISpanOut = (codes->code_value).doubles;
		set_code_default_double(0.5,1.5,1.0,codeISpanOut,0,codes);
		break;
		
	case CODE_IAdcOffset1st:	
		strncpy(codes->disp, "Adc Offset 1st",40);
		if( cmd == CMD_WRITE_RAM ) codeIAdcOffset1st = (codes->code_value).ints;
		set_code_default_int(1700,2700,2550,codeIAdcOffset1st,0,codes);
		break;
	
	case CODE_IAdcOffset2nd:	
		strncpy(codes->disp, "Adc Offset 2nd",40);
		if( cmd == CMD_WRITE_RAM ) codeIAdcOffset2nd = (codes->code_value).ints;
		set_code_default_int(1700,2700,2550,codeIAdcOffset2nd,0,codes);
		break;
	
	case CODE_IAdcOffset3rd:	
		strncpy(codes->disp, "Adc Offset 3rd",40);
		if( cmd == CMD_WRITE_RAM ) codeIAdcOffset3rd = (codes->code_value).ints;
		set_code_default_int(1700,2700,2550,codeIAdcOffset3rd,0,codes);
		break;
	
	case CODE_IAdcOffsetOut:	
		strncpy(codes->disp, "Adc Offset Out",40);
		if( cmd == CMD_WRITE_RAM ) codeIAdcOffsetOut = (codes->code_value).ints;
		set_code_default_int(1700,2700,2550,codeIAdcOffsetOut,0,codes);
		break;
	
	case CODE_vdc_sense_zero:	
		strncpy(codes->disp, "vdc_sense_zero (p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeVdcOffset = (codes->code_value).doubles;
		set_code_default_double(0.0,0.2,0.0,codeVdcOffset,0,codes);
		break;
		
	case CODE_vdc_sense_span:	
		strncpy(codes->disp, "vdc_sense_span (p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeVdcSpan = (codes->code_value).doubles;
		set_code_default_double(0.5,1.5,1.0,codeVdcSpan,0,codes);
		break;
		
	case CODE_VoutZero:	
		strncpy(codes->disp, "Vout_zero (p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeVoutOffset = (codes->code_value).doubles;
		set_code_default_double(0.0,0.2,0.0,codeVoutOffset,0,codes);
		break;
		
	case CODE_VoutSpan:	
		strncpy(codes->disp, "Vout_span (p.u)",40);
		if( cmd == CMD_WRITE_RAM ) codeVoutSpan = (codes->code_value).doubles;
		set_code_default_double(0.5,1.5,1.0,codeVoutSpan,0,codes);
		break;
		
	case CODE_GROUP4_END:
		return -2;
		
	default:
		return -1;
	}
	return 0;
}

// full bridge Ctrl parameter 
int get_code_group5(int addr ,int cmd, CODE_INFO * codes)
{
	switch(addr)
	{
	case CODE_SwitchFreq:	
		strncpy(codes->disp, "Switching Freq (Hz)",40);
		if( cmd == CMD_WRITE_RAM ) codeSwitFreq = (codes->code_value).doubles;
		set_code_default_double(500.0,25000.0,20000.0,codeSwitFreq,0,codes);
		break;

	case CODE_Ki:	
		strncpy(codes->disp, "Ki [pu]",40);
		if( cmd == CMD_WRITE_RAM ) code_Ki = (codes->code_value).doubles;
		set_code_default_double(1.0, 10000.0, 2500.0, code_Ki,0,codes);
		break;

	case CODE_Kp:	
		strncpy(codes->disp, "Kp [pu]",40);
		if( cmd == CMD_WRITE_RAM ) code_Kp = (codes->code_value).doubles;
		set_code_default_double(0.001, 2.0, 1.0, code_Kp,0,codes);
		break;

	case CODE_integLimit:	
		strncpy(codes->disp, "code_integLimit [pu]",40);
		if( cmd == CMD_WRITE_RAM ) code_integLimit = (codes->code_value).doubles;
		set_code_default_double( 0.0 , 2.0, 1.0, code_integLimit,0,codes);
		break;

	case CODE_phaseMax:	
		strncpy(codes->disp, "Phase Max [pu]",40);
		if( cmd == CMD_WRITE_RAM ) code_phaseMax = (codes->code_value).doubles;
		set_code_default_double( 0.0 , 1.0, 0.7, code_phaseMax,0,codes);
		break;

	case CODE_GROUP5_END:
		return -2;
		
	default:
		return -1;
	}
	return 0;
}

//--- DA set
int get_code_group6(int addr ,int cmd, CODE_INFO * codes)
{
	switch(addr)
	{
// DA Ch1
	case CODE_dac_select_ch1:	
		strncpy(codes->disp, "CODE_dac_select_ch1",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_select_ch1 = (codes->code_value).ints;
		set_code_default_int(0,200,13,code_dac_select_ch1,0,codes);
		break;
	
	case CODE_dac_scale_ch1:	
		strncpy(codes->disp, "CODE_dac_scale_ch1",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_scale_ch1 = (codes->code_value).doubles;
		set_code_default_double(0.0,1.0e6,10.0,code_dac_scale_ch1,0,codes);
		break;

	case CODE_dac_offset_ch1:	
		strncpy(codes->disp, "CODE_dac_offset_ch1",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_offset_ch1 = (codes->code_value).doubles;
		set_code_default_double(-1.0e6,1.0e6,0.0,code_dac_offset_ch1,0,codes);
		break;
// DA ch2
	case CODE_dac_select_ch2:	
		strncpy(codes->disp, "CODE_dac_select_ch2",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_select_ch2 = (codes->code_value).ints;
		set_code_default_int(0,200,13,code_dac_select_ch2,0,codes);
		break;
	
	case CODE_dac_scale_ch2:	
		strncpy(codes->disp, "CODE_dac_scale_ch2",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_scale_ch2 = (codes->code_value).doubles;
		set_code_default_double(0.0,1.0e6,10.0,code_dac_scale_ch2,0,codes);
		break;

	case CODE_dac_offset_ch2:	
		strncpy(codes->disp, "CODE_dac_offset_ch2",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_offset_ch2 = (codes->code_value).doubles;
		set_code_default_double(-1.0e6,1.0e6,0.0,code_dac_offset_ch2,0,codes);
		break;
// DA ch3
	case CODE_dac_select_ch3:	// Vdc
		strncpy(codes->disp, "CODE_dac_select_ch3",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_select_ch3 = (codes->code_value).ints;
		set_code_default_int(0,200,1,code_dac_select_ch3,0,codes);
		break;
	
	case CODE_dac_scale_ch3:	
		strncpy(codes->disp, "CODE_dac_scale_ch3",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_scale_ch3 = (codes->code_value).doubles;
		set_code_default_double(0.0,1.0e6,20.0,code_dac_scale_ch3,0,codes);
		break;

	case CODE_dac_offset_ch3:	
		strncpy(codes->disp, "CODE_dac_offset_ch3",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_offset_ch3 = (codes->code_value).doubles;
		set_code_default_double(-1.0e6,1.0e6,540.0,code_dac_offset_ch3,0,codes);
		break;

// DA ch4
	case CODE_dac_select_ch4:	
		strncpy(codes->disp, "CODE_dac_select_ch4",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_select_ch4 = (codes->code_value).ints;
		set_code_default_int(0,200,4,code_dac_select_ch4,0,codes);
		break;
	
	case CODE_dac_scale_ch4:	
		strncpy(codes->disp, "CODE_dac_scale_ch4",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_scale_ch4 = (codes->code_value).doubles;
		set_code_default_double(0.0,1.0e6,1.0,code_dac_scale_ch4,0,codes);
		break;

	case CODE_dac_offset_ch4:	
		strncpy(codes->disp, "CODE_dac_offset_ch4",40);
		if( cmd == CMD_WRITE_RAM ) code_dac_offset_ch4 = (codes->code_value).doubles;
		set_code_default_double(-1.0e6,1.0e6,0.0,code_dac_offset_ch4,0,codes);
		break;

	case CODE_GROUP6_END:
		return -2;

	default:
		return -1;
	}
	return 0;
}

int get_code_group7(int addr ,int cmd, CODE_INFO * codes)
{

	switch(addr)
	{
	case CODE_IValue1st:	
		strncpy(codes->disp, "I Value 1st (A)",40);
		if( cmd == CMD_WRITE_RAM ) codeIValue1st = (codes->code_value).doubles;
		set_code_default_double(5.0,2000.0,100.0,codeIValue1st ,0,codes);
		break;
		
	case CODE_IValue2nd:	
		strncpy(codes->disp, "I Value 2nd (A)",40);
		if( cmd == CMD_WRITE_RAM ) codeIValue2nd = (codes->code_value).doubles;
		set_code_default_double(5.0,2000.0,100.0,codeIValue2nd ,0,codes);
		break;
		
	case CODE_IValue3rd:	
		strncpy(codes->disp, "I Value 3rd (A)",40);
		if( cmd == CMD_WRITE_RAM ) codeIValue3rd = (codes->code_value).doubles;
		set_code_default_double(5.0,2000.0,100.0,codeIValue3rd ,0,codes);
		break;
		
	case CODE_IValueOut:	
		strncpy(codes->disp, "I Value Out (A)",40);
		if( cmd == CMD_WRITE_RAM ) codeIValueOut = (codes->code_value).doubles;
		set_code_default_double(5.0,2000.0,100.0,codeIValueOut ,0,codes);
		break;

//--- Vdc sense 
	case CODE_adc_vdc_low:	
		strncpy(codes->disp, "adc_vdc_low (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_adc_vdc_low = (codes->code_value).doubles;
		set_code_default_double(0.0,4095.0,1095.0,code_adc_vdc_low,0,codes);	// 500.0, 2000.0, 965.0
		break;

	case CODE_adc_vdc_high:	
		strncpy(codes->disp, "adc_vdc_high (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_adc_vdc_high = (codes->code_value).doubles;
		set_code_default_double(0.0,4010.0,1386.0,code_adc_vdc_high,0,codes);
		break;

	case CODE_Vdc_calc_low:	
		strncpy(codes->disp, "vdc_calc low (Vdc)",40);
		if( cmd == CMD_WRITE_RAM ) code_Vdc_calc_low = (codes->code_value).doubles;
		set_code_default_double(100.0,1.0e3,410.0,code_Vdc_calc_low,0,codes);
		break;

	case CODE_Vdc_calc_high:	
		strncpy(codes->disp, "vdc_calc high (Vdc)",40);
		if( cmd == CMD_WRITE_RAM ) code_Vdc_calc_high = (codes->code_value).doubles;
		set_code_default_double(200.0,1.0e3,519.0,code_Vdc_calc_high,0,codes);
		break;

//--- Vout sense 
	case CODE_adc_Vout_low:	
		strncpy(codes->disp, "adc_Vout_low (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_adc_Vout_low = (codes->code_value).doubles;
		set_code_default_double(0.0,4095.0,2048.0,code_adc_Vout_low,0,codes);	// 500.0, 2000.0, 965.0
		break;

	case CODE_adc_Vout_high:	
		strncpy(codes->disp, "adc_Vout_high (sec)",40);
		if( cmd == CMD_WRITE_RAM ) code_adc_Vout_high = (codes->code_value).doubles;
		set_code_default_double(0.0,4010.0,3000.0,code_adc_Vout_high,0,codes);
		break;

	case CODE_Vout_calc_low:	
		strncpy(codes->disp, "Vout_calc low (Vdc)",40);
		if( cmd == CMD_WRITE_RAM ) code_Vout_calc_low = (codes->code_value).doubles;
		set_code_default_double(0.0,30.0,0.0,code_Vout_calc_low,0,codes);
		break;

	case CODE_Vout_calc_high:	
		strncpy(codes->disp, "Vout_calc high (Vdc)",40);
		if( cmd == CMD_WRITE_RAM ) code_Vout_calc_high = (codes->code_value).doubles;
		set_code_default_double(2.0,20.0,9.17,code_Vout_calc_high,0,codes);
		break;

//--- I_out Calc
	case CODE_adcIout1st:	
		strncpy(codes->disp, "adc Iout1st",40);
		if( cmd == CMD_WRITE_RAM ) code_adcIout1st = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,1932,code_adcIout1st,0,codes);
		break;

	case CODE_adcIout2nd:	
		strncpy(codes->disp, "adc Iout2nd",40);
		if( cmd == CMD_WRITE_RAM ) code_adcIout2nd = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,1836,code_adcIout2nd,0,codes);
		break;

	case CODE_adcIout3rd:	
		strncpy(codes->disp, "adc Iout3rd",40);
		if( cmd == CMD_WRITE_RAM ) code_adcIout3rd = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,1586,code_adcIout3rd,0,codes);
		break;

	case CODE_adcIout4th:	
		strncpy(codes->disp, "adc Iout4th",40);
		if( cmd == CMD_WRITE_RAM ) code_adcIout4th = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,1321,code_adcIout4th,0,codes);
		break;

	case CODE_adcIout5th:	
		strncpy(codes->disp, "adc Iout5th",40);
		if( cmd == CMD_WRITE_RAM ) code_adcIout5th = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,1109,code_adcIout5th,0,codes);
		break;

//--- I_out Calc
	case CODE_calIout1st:	
		strncpy(codes->disp, "Calc Iout1st",40);
		if( cmd == CMD_WRITE_RAM ) code_calIout1st = (codes->code_value).doubles;
		set_code_default_double(5.0,4096.0,113,code_calIout1st,0,codes);
		break;

	case CODE_calIout2nd:	
		strncpy(codes->disp, "Calc Iout2nd",40);
		if( cmd == CMD_WRITE_RAM ) code_calIout2nd = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,193.0,code_calIout2nd,0,codes);
		break;

	case CODE_calIout3rd:	
		strncpy(codes->disp, "Calc Iout3rd",40);
		if( cmd == CMD_WRITE_RAM ) code_calIout3rd = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,395,code_calIout3rd,0,codes);
		break;

	case CODE_calIout4th:	
		strncpy(codes->disp, "Calc Iout4th",40);
		if( cmd == CMD_WRITE_RAM ) code_calIout4th = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,610,code_calIout4th,0,codes);
		break;

	case CODE_calIout5th:	
		strncpy(codes->disp, "Calc Iout5th",40);
		if( cmd == CMD_WRITE_RAM ) code_calIout5th = (codes->code_value).doubles;
		set_code_default_double(100.0,4096.0,780,code_calIout5th,0,codes);
		break;

	case CODE_GROUP7_END:
		return -2;

	default:
		return -1;
	}
	return 0;
}

int get_code_group8(int addr ,CODE_INFO * codes)
{	
	switch(addr)
	{
	case CODE_Data_Check:	
		strncpy(codes->disp, "Backup Data Check",40);
		break;

	case CODE_Data_Backup:	
		strncpy(codes->disp, "Code Data Backup",40);
		break;

	case CODE_Data_Load:	
		strncpy(codes->disp, "Backup Data Load",40);
		break;

	case CODE_Data_Init:	
		strncpy(codes->disp, "Backup Data Init",40);
		break;

	case CODE_get_adc_offset:	
		strncpy(codes->disp, "get_adc_offset",40);
		break;

	case CODE_get_adc_vdc_low:	
		strncpy(codes->disp, "get_adc_vdc_low",40);
		break;

	case CODE_get_adc_vdc_high:	
		strncpy(codes->disp, "get_adc_vdc_high",40);
		break;

	case CODE_GROUP8_END:
		return -2;

	default:
		return -1;
	}
	return 0;
}

// end of file





