#ifndef		__CODE_PROC_H_
#define		__CODE_PROC_H_	

// #define SWITCH_FREQ			2500	// 090920
// #define SWITCH_FREQ			1750	// 090920

#define TYPE_INTEGER		0
#define TYPE_DOUBLE			1

#define CODE_GROUP0_END		30
#define CODE_GROUP1_END		130		// 2010.03.14

#define CODE_GROUP2_END		230
#define CODE_GROUP3_END		330
#define CODE_GROUP4_END		430
#define CODE_GROUP5_END		530
#define CODE_GROUP6_END		630
#define CODE_GROUP7_END		730
#define CODE_GROUP8_END		807


//======================================
// Code address
//======================================
// group 0

#define CODE_I_out_ref					0
#define CODE_Vout						1

#define CODE_VoutLimit					3
#define CODE_ovpTime					4

#define CODE_PwmPhaseInit				6
#define CODE_InitTime					7
#define CODE_ctrl_mode					9

#define CODE_SetPulseNumber				10
#define CODE_testPwmPhase				11
#define CODE_set_Vdc_on					12
#define CODE_Vdc_set_value				13

#define CODE_accel_time1				15
#define CODE_decel_time1				16
#define CODE_accel_time2				17
#define CODE_decel_time2				18
#define CODE_speed2						19

#define CODE_rDeadTime					20
#define CODE_allDeadTime				21

// group 1 anlog In/ Out

#define CODE_analog_cmd_in_zero1		100
#define CODE_analog_cmd_in_span1		101
#define CODE_analog_cmd_in_zero2		102
#define CODE_analog_cmd_in_span2		103

#define CODE_analog_out_select1			110
#define CODE_analog_out_zero1			111
#define CODE_analog_out_span1			112
#define CODE_analog_out_offset1			113

#define CODE_analog_out_select2			115
#define CODE_analog_out_zero2			116
#define CODE_analog_out_span2			117
#define CODE_analog_out_offset2			118

// group2
#define CODE_OCLevel1st					200
#define CODE_OCLevel2nd					201
#define CODE_OCLevel3rd					202
#define CODE_OCLevelOut					203

#define CODE_over_volt_set				204
#define CODE_under_volt_set				205
#define CODE_Is_Max_Coeff				206
#define CODE_OC_time					207

//--- TRIP ON & OFF 
#define CODE_protect_inhibit_on			210
#define CODE_protect_under_volt_off		211
#define CODE_protect_over_volt_off		212
#define CODE_protect_I_adc_off			213
#define CODE_protect_over_I_off			214
#define CODE_protect_IGBT_off			215
#define CODE_protect_ex_trip_off		216

//group 3 system parameter
#define CODE_rate_volt					300
#define CODE_rate_power					301
#define CODE_rate_current				302
#define CODE_rate_hz					303

// group 4 sense zero span offset
#define CODE_ISpan1st					400
#define CODE_ISpan2nd					401
#define CODE_ISpan3rd					402
#define CODE_ISpanOut					403

#define CODE_IAdcOffset1st				405
#define CODE_IAdcOffset2nd				406
#define CODE_IAdcOffset3rd				407
#define CODE_IAdcOffsetOut				408

#define CODE_vdc_sense_zero				410
#define CODE_vdc_sense_span				411
#define CODE_VoutZero					412
#define CODE_VoutSpan					413

// group 5 ctrl parameter

#define CODE_SwitchFreq					500


#define CODE_Ki							510				
#define CODE_Kp							511				
#define CODE_integLimit					512

#define CODE_phaseMax					513
		

// group 6 DA setting

#define CODE_dac_select_ch1				600
#define CODE_dac_scale_ch1				601
#define CODE_dac_offset_ch1				602

#define CODE_dac_select_ch2				605
#define CODE_dac_scale_ch2				606
#define CODE_dac_offset_ch2				607

#define CODE_dac_select_ch3				610
#define CODE_dac_scale_ch3				611
#define CODE_dac_offset_ch3				612

#define CODE_dac_select_ch4				615
#define CODE_dac_scale_ch4				616
#define CODE_dac_offset_ch4				617

// group7 sensor set

#define CODE_IValue1st					700
#define CODE_IValue2nd					701
#define CODE_IValue3rd					702
#define CODE_IValueOut					703

#define CODE_adc_vdc_low				710	// 
#define CODE_adc_vdc_high				711 // 
#define CODE_Vdc_calc_low				712
#define CODE_Vdc_calc_high				713

#define CODE_adc_Vout_low				715	// 
#define CODE_adc_Vout_high				716 // 
#define CODE_Vout_calc_low				717
#define CODE_Vout_calc_high				718

#define CODE_adcIout1st					720	// 
#define CODE_adcIout2nd					721	// 
#define CODE_adcIout3rd					722	// 
#define CODE_adcIout4th					723	// 
#define CODE_adcIout5th					724	// 

#define CODE_calIout1st					725	// 
#define CODE_calIout2nd					726	// 
#define CODE_calIout3rd					727	// 
#define CODE_calIout4th					728	// 
#define CODE_calIout5th					729	// 

#define CODE_Data_Check					800
#define CODE_Data_Backup				801
#define CODE_Data_Load					802
#define CODE_Data_Init					803
#define CODE_get_adc_offset				804

#define CODE_get_adc_vdc_low			805
#define CODE_get_adc_vdc_high			806

//--- end of code address


union CODE_MIN{
	int 	ints;
	double 	doubles;
};

union CODE_MAX {
	int 	ints;
	double 	doubles;
};

union CODE_DEFAULT {
	int 	ints;
	double 	doubles;
};

union CODE_VALUE {
	int 	ints;
	double 	doubles;
};

struct CODE_INFO_DEFINE {
	int		type;	
	int	  	open_level	;
	union CODE_MIN 		code_min ;
	union CODE_MAX 		code_max ;
	union CODE_DEFAULT 	code_default;
	union CODE_VALUE	code_value;
	char   disp[40];
};
typedef struct CODE_INFO_DEFINE CODE_INFO;

#endif
