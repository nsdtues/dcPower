#ifndef		__CODE_PROC_H_
#define		__CODE_PROC_H_	

// #define SWITCH_FREQ			2500	// 090920
// #define SWITCH_FREQ			1750	// 090920

#define TYPE_INTEGER		0
#define TYPE_DOUBLE			1

#define CODE_GROUP0_END		99
#define CODE_GROUP1_END		150		// 2010.03.14

#define CODE_GROUP2_END		251
#define CODE_GROUP3_END		351
#define CODE_GROUP4_END		451
#define CODE_GROUP5_END		551
#define CODE_GROUP6_END		651
#define CODE_GROUP7_END		751
#define CODE_GROUP8_END		807


//======================================
// Code address
//======================================
// group 0

#define CODE_run_input_select			0
#define CODE_motor_ctrl_mode			1
#define CODE_motor_direction_change		2
#define CODE_ramp_func_mode				3

#define CODE_accel_time1				10
#define CODE_decel_time1				11
#define CODE_accel_time2				12
#define CODE_decel_time2				13
#define CODE_btn_start_ref				14
#define CODE_jog_speed					15
#define CODE_min_vf_ref					16
	
///////////// TRIP ON & OFF //////////////
#define CODE_protect_inhibit_on			30
#define CODE_protect_under_volt_off		31
#define CODE_protect_over_volt_off		32
#define CODE_protect_I_adc_off			33
#define CODE_protect_over_I_off			34
#define CODE_protect_IGBT_off			35
#define CODE_protect_ex_trip_off		36
#define CODE_protect_IGBT2_off			37
#define CODE_protect_CONVT_adc_off		38
//////////////////////////////////////////

#define CODE_use_binary_input			100
#define CODE_speed1						101
#define CODE_speed2						102
#define CODE_speed3						103
#define CODE_speed4						104
#define CODE_speed5						105
#define CODE_speed6						106
#define CODE_speed7						107
#define CODE_speed8						108
#define CODE_speed9						109
#define CODE_speed10					110
#define CODE_speed11					111
#define CODE_speed12					112
#define CODE_speed13					113
#define CODE_speed14					114
#define CODE_speed15					115
#define CODE_speed16					116

#define CODE_select_in_func0			120
#define CODE_select_in_func1			121
#define CODE_select_in_func2			122
#define CODE_select_in_func3			123
#define CODE_select_in_func4			124
#define CODE_select_in_func5			125
#define CODE_select_in_func6			126
#define CODE_select_in_func7			127

// group2

#define CODE_analog_cmd_in_zero1		200
#define CODE_analog_cmd_in_span1		201
#define CODE_analog_cmd_in_zero2		202
#define CODE_analog_cmd_in_span2		203
#define CODE_analog_out_select1			204
#define CODE_analog_out_zero1			205
#define CODE_analog_out_span1			206
#define CODE_analog_out_offset1			207
#define CODE_analog_out_select2			208
#define CODE_analog_out_zero2			209
#define CODE_analog_out_span2			210
#define CODE_analog_out_offset2			211

#define CODE_dac_select_ch1				213
#define CODE_dac_scale_ch1				214
#define CODE_dac_offset_ch1				215

#define CODE_dac_select_ch2				216
#define CODE_dac_scale_ch2				217
#define CODE_dac_offset_ch2				218

#define CODE_dac_select_ch3				219
#define CODE_dac_scale_ch3				220
#define CODE_dac_offset_ch3				221

#define CODE_dac_select_ch4				222
#define CODE_dac_scale_ch4				223
#define CODE_dac_offset_ch4				224


// group3
#define CODE_over_current_level			300
#define CODE_OC_convt_level				301

#define CODE_over_volt_set				302
#define CODE_under_volt_set				303
#define CODE_over_speed_level			304
#define CODE_e_thermal_level			305
#define CODE_pre_charge_time			306
#define CODE_Is_Max_Coeff				307
#define CODE_over_I_time				308

#define CODE_adc_vdc_low				310	// 
#define CODE_adc_vdc_high				311 // 
#define CODE_Vdc_calc_low				312
#define CODE_Vdc_calc_high				313

#define CODE_adc_Vs_R_low				315
#define CODE_adc_Vs_S_low				316
#define CODE_adc_Vs_T_low				317

#define CODE_adc_Vs_R_high				318
#define CODE_adc_Vs_S_high				319
#define CODE_adc_Vs_T_high				320

#define CODE_Vs_R_calc_low				321
#define CODE_Vs_S_calc_low				322
#define CODE_Vs_T_calc_low				323

#define CODE_Vs_R_calc_high				324
#define CODE_Vs_S_calc_high				325
#define CODE_Vs_T_calc_high				326

#define CODE_Vs_R_scale					330
#define CODE_Vs_S_scale					331
#define CODE_Vs_T_scale					332

#define CODE_Vs_R_offset				333
#define CODE_Vs_S_offset				334
#define CODE_Vs_T_offset				335

#define CODE_Ude_Ki						336
#define CODE_Ude_Kp						337
#define CODE_Vdc_link_Ki				338
#define CODE_Vdc_link_Kp				339

//group 4
#define CODE_motor_rate_power			400
#define CODE_motor_rate_volt			401
#define CODE_motor_rate_current			402
#define CODE_motor_rate_hz				403
#define CODE_motor_rate_rpm				404
#define CODE_motor_pole					405
#define CODE_motor_rate_effiency		406	

#define CODE_Rs							407
#define CODE_Rr							408
#define CODE_Ls							409
#define CODE_Lr							410
#define CODE_Lm							411
#define CODE_Jm							412

// group5
#define CODE_I_sense_value				500
#define CODE_u_phase_I_sense_span		502
#define CODE_v_phase_I_sense_span		504

#define CODE_vdc_sense_zero				505
#define CODE_vdc_sense_span				506
#define CODE_encoder_pulse_one_turn		507
#define CODE_igbt_pwm_freq				508

#define CODE_adc_u_offset				510
#define CODE_adc_v_offset				511
#define CODE_adc_R_offset				512
#define CODE_adc_S_offset				513

#define CODE_R_phase_I_sense_span		515
#define CODE_S_phase_I_sense_span		517

// group6
#define CODE_VF_DeadTimeGain			600
#define CODE_VF_ExcitationTime			601
#define CODE_VF_Fs_Coeff				602
#define CODE_VF_Freq_TrqBoost			603
#define CODE_VF_Vs_Coeff_TrqBoost		604
#define CODE_VF_Rs_ThermalCoeff			605
#define CODE_VF_IR_Comp_FilterPole		606
#define CODE_VF_Slip_Comp_FilterPole	607
#define CODE_VF_Rs						608

#define CODE_AT_Freq_Leq_Req			610
#define CODE_AT_Time_Leq_Req			611
#define CODE_AT_Is_Coeff_Leq_Req		612

#define CODE_AT_Is_Coeff_Rs				613
#define CODE_AT_Time_Rs					614

#define CODE_AT_DeadTimeGain			615
#define CODE_AT_Ls_Vs_RAMP				616
#define CODE_AT_Freq_Ls					617
#define CODE_AT_Time_Ls					618
#define CODE_AT_Ls_DMB_OpenTime			619				

#define CODE_AT_Te_Coeff_Jm				620
#define CODE_AT_Time_Jm					621
#define CODE_Jm_ID_ENABLE				622

#define CODE_posi_duration_time			624	
#define CODE_zero_duration_time			625
#define CODE_nega_duration_time			626
#define CODE_test_accel_time			627	
#define CODE_test_decel_time			628

#define CODE_Ki_Is_Coeff				630
#define CODE_Kp_Is_Coeff				631


// group 7 advance control vaiable 

#define	CODE_wr_FilterPoleCoeff				700
#define	CODE_wn_wr_Coeff					701
#define	CODE_Max_wn_wr						702
#define	CODE_K_Damp_wr						703
#define	CODE_wr_DampingRatio				704
#define CODE_wr_CntlPeriodIndex				705
// �ڼ� ����
#define	CODE_FW_VoltageCoeff				706
#define	CODE_Base_Flux_Coeff				707
#define	CODE_ExcitationTime					708
#define	CODE_K_Damp_Fr						709
#define	CODE_GM_Fr							710
#define	CODE_PM_Fr							711

#define	CODE_K_Damp_Is						715
#define	CODE_GM_Is							716
#define	CODE_PM_Is							717

// �������� ���� ����
#define	CODE_Default_wr_FilterPole			720
#define	CODE_SlipCompCoeff					721
#define	CODE_GammaLambda					722
#define	CODE_GammaLambda_R_Constant			723	
#define	CODE_Max_DeltaLambda				724
#define	CODE_GammaTheta_M					725
#define	CODE_GammaTheta_R					726
#define	CODE_Max_DeltaTheta					727
#define	CODE_Delta_wr_FilterPoleCoeff_L		728
#define	CODE_Delta_wr_FilterPoleCoeff_U		729

#define CODE_Data_Check						800
#define CODE_Data_Backup					801
#define CODE_Data_Load						802
#define CODE_Data_Init						803
#define CODE_get_adc_offset					804

#define CODE_get_adc_vdc_low				805
#define CODE_get_adc_vdc_high				806

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