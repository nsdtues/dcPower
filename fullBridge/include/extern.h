#ifndef		__VARIABLES_
#define		__VARIABLES_

extern double IoutScale1st;
extern double IoutOffset1st;

extern double IoutScale2nd;
extern double IoutOffset2nd;

extern double IoutScale3rd;
extern double IoutOffset3rd;

extern double IoutScale4th;
extern double IoutOffset4th;


extern double nativeI_out;
extern double nativeI_pri;
extern double nativeI2nd;
extern double nativeI3rd;

extern double ctrlError;
extern double ctrlIntegral;
extern double preIntegral;
extern double phaseShiftRatio;

extern double Power_out;
extern int code_run_input_select;

extern int adcI_pri;
extern int adcI_out;
extern int adcI2nd;
extern int adcI3rd;

extern double I_pri;
extern double I_out;
extern double I2nd;
extern double I3rd;

extern double OC_Timer;
extern double ovpTimer;		// 2014.1016
extern double Vout;

extern double monitor[5];
extern int debug_count;
extern int test_pulse_count;

extern int convert_state;
extern unsigned int igbt_fault_input;
extern unsigned int digital_input;

extern unsigned int DIGITAL_INPUT_START;
extern double  DCLINK_LIMIT;
extern double  UNDER_DC_LINK_LIMIT;

extern int timer0_count;

// hjkim
//'all pass Filter

//''''''''''''''''''''''''''
#define  DF(x_in, x_in1, x_in2, y_out, y_out1, y_out2, b1, b2, a0, a1, a2) \
            (y_out) = - (b1)*(y_out1) - (b2)*(y_out2) + (a0)*(x_in) + (a1)*(x_in1) + (a2)*(x_in2); \
            (y_out2) = (y_out1); \
            (y_out1) = (y_out); \
            (x_in2) = (x_in1); \
            (x_in1) = (x_in)

extern unsigned int Fault_Code;


extern double Sin_theta;
extern double Cos_theta;
extern double Ude_err;
extern double Ude_integ;
extern double Ude_integ_pre;


extern int init_charge_flag;

//--- DC link Voltage Low Pass
extern double LPF_Vdc_cutoff_freq;
extern double LPF_Vdc_in[3];
extern double LPF_Vdc_out[3];
extern double LPF_Vdc_K[4];
//--- Udq Low Pass
extern double LPF_Udq_cutoff_freq;
extern double LPF_U_d_in[3];
extern double LPF_U_d_out[3];
extern double LPF_U_d_K[4];

extern double LPF_U_q_in[3];
extern double LPF_U_q_out[3];
extern double LPF_U_q_K[4];

//--- Theta Low Pass
extern double LPF_We_E_st_cutoff_freq;
extern double LPF_We_E_st_in[3];
extern double LPF_We_E_st_out[3];
extern double LPF_We_E_st_K[4];

//--- AC source Voltage Low Pass
extern double LPF_V_rst_curoff_freq;
extern double LPF_V_rs_in[3],LPF_V_st_in[3],LPF_V_tr_in[3];
extern double LPF_V_rs_out[3],LPF_V_st_out[3],LPF_V_tr_out[3];
extern double LPF_V_rs_K[4],LPF_V_st_K[4],LPF_V_tr_K[4];

//--- AC Input Current Low Pass
extern double LPF_I_rst_cutoff_freq;
extern double LPF_I_r_in[3],LPF_I_s_in[3],LPF_I_t_in[3];
extern double LPF_I_r_out[3],LPF_I_s_out[3],LPF_I_t_out[3];
extern double LPF_I_r_K[4],LPF_I_s_K[4],LPF_I_t_K[4];

//--- AC Current Low Pass
extern double LPF_I_uvw_cutoff_freq ;

extern double LPF_I_u_in[3], LPF_I_v_in[3], LPF_I_w_in[3];
extern double LPF_I_u_out[3], LPF_I_v_out[3], LPF_I_w_out[3]; 
extern double LPF_I_u_K[4], LPF_I_v_K[4],LPF_I_w_K[4];

extern unsigned int Fault_Code;
extern double * dac_point[200];

extern volatile unsigned int ZONE0_BUF[256];
extern volatile unsigned int ZONE6_BUF[0x10000];		// debug
extern volatile unsigned int ZONE7_BUF[256];

extern int init_charge_flag;
extern unsigned int xcon_data;		// expansion board xcon0,1,2,3 out data

extern char TimeInput[13]; // ="101020123000";

extern int scib_rx_msg_flag;
extern int scic_rx_msg_flag;

extern double analog_ref_a;
extern double analog_ref_b;

//*******************************************************
// ���� ���� 
//*******************************************************
extern double phaseVref;
extern double VdcScale;		
extern double VdcOffset;	

extern double VoutScale;		
extern double VoutOffset;	

extern double dac_ch0_unit_count_value;
extern double dac_ch1_unit_count_value;
extern double dac_ch2_unit_count_value;
extern double dac_ch3_unit_count_value;

extern double ref_time;	// 2009.10.28

extern CODE_INFO code_inform;
extern union PROTECT_FLAG protect_reg;

// codes

// --- digital_inout.h

extern union DIGITAL_OUT_FUNC relay_flag;
extern union DIGITAL_FUNCTION func_flag;	// ������ �Է��� ����� �����Ѵ�.


extern int scic_rx_start_addr;
extern int scic_rx_end_addr;

extern int scic_tx_start_addr;
extern int scic_tx_end_addr;

extern int terminal_input_state;
extern char TripMessage[25];


// PWM
extern double	DutyRatio[3];
extern Uint16 DutyCount[3];

// �ð� �� �ε���
extern double 	gfRunTime;
extern double	Ts;
extern double	inv_Ts;
extern int timer0_count;

// Ref.

extern double   refer_in0;
extern double	reference_in;
extern double	reference_out;


// ���
extern double	Is_abc[3];
extern double	Is_dq[2];

extern double RMS_Ia;
extern double RMS_Ib;

extern double	Is_mag;
extern double	Is_mag_rms;

extern double I_r;
extern double I_s;
extern double I_t;

extern double	Vdc;	


// Motor Name Plate Parameter

extern double	Vs_rat;
extern double	Is_rat;
extern double	inv_Is_rat;
extern double	we_rat;
extern double	inv_motor_rate_hz;

// �ι��� �Ķ����
extern double	Is_max;					// �ִ� ������

//====================================
// F28335 
// EwInv ���� ����
//====================================
// Sci.c

extern char gStr1[50];
extern char gStr2[10];

extern int gSciInFlag;
extern int scia_rx_msg_flag;

extern char gSciaRxBuf[NUM_SCI_RX_BUF+1];
extern char gSciaTxBuf[NUM_SCI_TX_BUF+1];

extern int gMachineState;
	// Ref. Func

extern int	gPWMTripCode;

extern int adc_result[16];
extern int giAdcVdc	;
extern TRIP_INFO TripInfo;
extern TRIP_INFO TripInfoNow;

extern int gTripFlag;
extern Uint16	MAX_PWM_CNT;
extern char MonitorMsg[30];
extern int gRunFlag;
extern int gTripSaveFlag;
extern double OverCurLimit;
extern int EepromSaveFlag;
extern int Flag_TripDataBackup;

//============================================
//   Auto_tunning variable
//============================================
extern double	GainUpdateTimer;
extern double	Vs_Coeff_Leq_Req;

extern double LPF_Is;
extern double LPF_Is_Square;
extern double LPF_Vs_Square;

extern double	inv_code_dac_scale_ch1;
extern double	inv_code_dac_scale_ch2;
extern double	inv_code_dac_scale_ch3;
extern double	inv_code_dac_scale_ch4;

//============================================
//   CODE variable 
//============================================

extern double code_I_out_ref;			// 0
extern int code_ctrl_mode;				// 1

extern double code_Vout;
extern double code_VoutLimit;		// 3
extern double code_ovpTime;			// 4

extern double codePwmPhaseInit;			// 6 
extern double codeInitTime;				// 7

extern int	  codeSetPulseNumber;		// 10
extern double code_testPwmPhase;		// 11
extern int code_set_Vdc_on;				// 12
extern double code_Vdc_set_value;		// 13

extern double code_accel_time1;		// 15
extern double code_decel_time1;		// 16
extern double code_accel_time2;		// 17
extern double code_decel_time2;		// 18
extern double code_speed2;			// 19

extern double rDeadTime;			// 20
extern double allDeadTime;			// 21	

// group1

extern double analog_cmd_in_zero1;		// 100
extern double analog_cmd_in_span1;		// 101
extern double analog_cmd_in_zero2;		// 102
extern double analog_cmd_in_span2;		// 103
extern int 	  code_AdcOffsetCh6;		// 104

extern double codeAnalogSelect1;		//	110
extern double codeAnalogOutZero1;		//	111
extern double codeAnalogOutSpan1;		//	112
extern double codeAnalogOutOffset1;		//	113

extern double codeAnalogSelect2;		//	115
extern double codeAnalogOutZero2;		//	116
extern double codeAnalogOutSpan2;		//	117
extern double codeAnalogOutOffset2;		//	118

// group2

extern double codeOCLevel1st;			// 200
extern double codeOCLevel2nd;			// 201
extern double codeOCLevel3rd;			// 202
extern double codeOCLevelOut;			// 203

extern double over_volt_set;			// 204
extern double code_under_volt_set;		// 205
extern double Is_Max_Coeff;				// 206

extern double code_OC_time;				// 207

///////////////////////////
extern int code_protect_inhibit_on;	// 210
extern int code_protect_uv_off;		// 211
extern int code_protect_ov_off;		// 212
extern int code_protect_Iadc_off;		// 213
extern int code_protect_over_I_off;	// 214
extern int code_protect_IGBT_off;		// 215
extern int code_protect_ex_trip_off;	// 216
///////////////////////////

// group3
extern double code_rate_volt;			// 400
extern double code_rate_power;			// 401
extern double code_rate_current;		// 402
extern double code_rate_hz;			// 403

//group 4
extern double codeISpan1st;			// 400
extern double codeISpan2nd;			// 401
extern double codeISpan3rd;			// 402
extern double codeISpanOut;			// 403

extern double codeIAdcOffset1st;	// 405
extern double codeIAdcOffset2nd;	// 406
extern double codeIAdcOffset3rd;	// 407
extern double codeIAdcOffsetOut;	// 408

extern double codeVdcOffset;			// 410
extern double codeVdcSpan;				// 411
extern double codeVoutOffset;			// 412
extern double codeVoutSpan;			// 413

// group5 Ctrl Code
extern double codeSwitFreq;				// 500

extern double code_V_Ki;				// 505
extern double code_V_Kp;				// 506
extern double code_V_integLimit;		// 507
extern double code_feedforward;			// 508

extern double code_Ki;					// 510
extern double code_Kp;					// 511		
extern double code_integLimit;			// 512		
extern double code_phaseMax;			// 513		


// group6
extern int code_dac_select_ch1;		// 600	
extern double code_dac_scale_ch1;		// 601
extern double code_dac_offset_ch1;		// 602

extern int code_dac_select_ch2;		// 605
extern double code_dac_scale_ch2;		// 605
extern double code_dac_offset_ch2;		// 607

extern int code_dac_select_ch3;		// 610
extern double code_dac_scale_ch3;		// 611
extern double code_dac_offset_ch3;		// 612

extern int code_dac_select_ch4;		// 615
extern double code_dac_scale_ch4;		// 616
extern double code_dac_offset_ch4;		// 617

// group7 sensor set

extern double codeIValue1st;			// 700
extern double codeIValue2nd;			// 701
extern double codeIValue3rd;			// 702
extern double codeIValueOut;			// 703

extern double code_adc_vdc_low;			// 710
extern double code_adc_vdc_high;		// 711
extern double code_Vdc_calc_low;		// 712
extern double code_Vdc_calc_high;		// 713

extern double code_adc_Vout_low;		// 715
extern double code_adc_Vout_high;		// 716
extern double code_Vout_calc_low;		// 717
extern double code_Vout_calc_high;		// 718

extern double code_adcIout1st;			// 720
extern double code_adcIout2nd;			// 721
extern double code_adcIout3rd;			// 722
extern double code_adcIout4th;			// 723
extern double code_adcIout5th;			// 724

extern double code_calIout1st;			// 725
extern double code_calIout2nd;			// 726
extern double code_calIout3rd;			// 727
extern double code_calIout4th;			// 728
extern double code_calIout5th;			// 729

extern double Data_Check;				// 800
extern double Data_Backup;				// 801
extern double Data_Load;				// 802
extern double Data_Init;				// 803
//***********************************************************
#endif

