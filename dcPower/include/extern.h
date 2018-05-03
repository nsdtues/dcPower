#ifndef		__VARIABLES_
#define		__VARIABLES_

extern float nativeI_out;
extern float nativeI_pri;
extern float nativeI2nd;
extern float nativeI3rd;

extern float ctrlError;
extern float ctrlIntegral;
extern float preIntegral;
extern float phaseShiftRatio;

extern float Power_out;
extern int code_run_input_select;

extern int adcI_pri;
extern int adcI_out;

extern float I_pri;
extern float I_out;

extern float OC_Timer;
extern float ovpTimer;		// 2014.1016
extern float Vout;

extern float monitor[5];
extern int debug_count;
extern int test_pulse_count;

extern int convert_state;
extern unsigned int igbt_fault_input;
extern unsigned int digital_input;

extern unsigned int DIGITAL_INPUT_START;
extern float  DCLINK_LIMIT;
extern float  UNDER_DC_LINK_LIMIT;

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

extern float Sin_theta;
extern float Cos_theta;
extern float Ude_err;
extern float Ude_integ;
extern float Ude_integ_pre;


extern int init_charge_flag;

//--- DC link Voltage Low Pass
extern float LPF_Vdc_cutoff_freq;
extern float LPF_Vdc_in[3];
extern float LPF_Vdc_out[3];
extern float LPF_Vdc_K[4];
//--- Udq Low Pass
extern float LPF_Udq_cutoff_freq;
extern float LPF_U_d_in[3];
extern float LPF_U_d_out[3];
extern float LPF_U_d_K[4];

extern float LPF_U_q_in[3];
extern float LPF_U_q_out[3];
extern float LPF_U_q_K[4];

//--- Theta Low Pass
extern float LPF_We_E_st_cutoff_freq;
extern float LPF_We_E_st_in[3];
extern float LPF_We_E_st_out[3];
extern float LPF_We_E_st_K[4];

//--- AC source Voltage Low Pass
extern float LPF_V_rst_curoff_freq;
extern float LPF_V_rs_in[3],LPF_V_st_in[3],LPF_V_tr_in[3];
extern float LPF_V_rs_out[3],LPF_V_st_out[3],LPF_V_tr_out[3];
extern float LPF_V_rs_K[4],LPF_V_st_K[4],LPF_V_tr_K[4];

//--- AC Input Current Low Pass
extern float LPF_I_rst_cutoff_freq;
extern float LPF_I_r_in[3],LPF_I_s_in[3],LPF_I_t_in[3];
extern float LPF_I_r_out[3],LPF_I_s_out[3],LPF_I_t_out[3];
extern float LPF_I_r_K[4],LPF_I_s_K[4],LPF_I_t_K[4];

//--- AC Current Low Pass
extern float LPF_I_uvw_cutoff_freq ;

extern float LPF_I_u_in[3], LPF_I_v_in[3], LPF_I_w_in[3];
extern float LPF_I_u_out[3], LPF_I_v_out[3], LPF_I_w_out[3];
extern float LPF_I_u_K[4], LPF_I_v_K[4],LPF_I_w_K[4];

extern unsigned int Fault_Code;
extern float * dac_point[200];

extern volatile unsigned int ZONE0_BUF[256];
extern volatile unsigned int ZONE6_BUF[0x10000];		// debug
extern volatile unsigned int ZONE7_BUF[256];

extern int init_charge_flag;
extern unsigned int xcon_data;		// expansion board xcon0,1,2,3 out data

extern char TimeInput[13]; // ="101020123000";

extern int scib_rx_msg_flag;
extern int scic_rx_msg_flag;

extern float analog_ref_a;
extern float analog_ref_b;

//*******************************************************
// ���� ���� 
//*******************************************************
extern float phaseVref;
extern float VdcScale;
extern float VdcOffset;

extern float VoutScale;
extern float VoutOffset;

extern float ref_time;	// 2009.10.28

extern CODE_INFO code_inform;
extern union PROTECT_FLAG protect_reg;

// codes

// --- digital_inout.h

extern char TripMessage[25];


// PWM
extern float	DutyRatio[3];
extern Uint16 DutyCount[3];

// �ð� �� �ε���
extern float 	gfRunTime;
extern float	Ts;
extern float	inv_Ts;
extern int timer0_count;

// Ref.

extern float   refer_in0;
extern float	reference_in;
extern float	reference_out;

extern float	Vdc;


// Motor Name Plate Parameter

extern float	Vs_rat;
extern float	Is_rat;
extern float	inv_Is_rat;
extern float	we_rat;
extern float	inv_motor_rate_hz;

// �ι��� �Ķ����
extern float	Is_max;					// �ִ� �������

//====================================
// F28335 
// EwInv ���� ����
//====================================
// Sci.c

extern char gStr1[50];
extern char gStr2[10];

extern int gSciInFlag;
extern int scia_rx_msg_flag;

extern char gSciaRxBuf[SCIA_RX_BUF_MAX+1];
extern char gSciaTxBuf[SCIA_TX_BUF_MAX+1];

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
extern float OverCurLimit;
extern int EepromSaveFlag;
extern int Flag_TripDataBackup;

//============================================
//   Auto_tunning variable
//============================================
extern float	GainUpdateTimer;
extern float	Vs_Coeff_Leq_Req;

extern float LPF_Is;
extern float LPF_Is_Square;
extern float LPF_Vs_Square;

extern float	inv_code_dac_scale_ch1;
extern float	inv_code_dac_scale_ch2;
extern float	inv_code_dac_scale_ch3;
extern float	inv_code_dac_scale_ch4;

//============================================
//   CODE variable 
//============================================

extern float code_I_out_ref;			// 0
extern int code_ctrl_mode;				// 1

extern float code_Vout;
extern float code_VoutLimit;		// 3
extern float code_ovpTime;			// 4

extern float codePwmPhaseInit;			// 6
extern float codeInitTime;				// 7

extern int	  codeSetPulseNumber;		// 10
extern float code_testPwmPhase;		// 11
extern int code_set_Vdc_on;				// 12
extern float code_Vdc_set_value;		// 13

extern float rDeadTime;			// 20
extern float allDeadTime;			// 21


extern float over_volt_set;			// 204
extern float code_under_volt_set;		// 205
extern float Is_Max_Coeff;				// 206
extern float code_OC_time;				// 207

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
extern float code_rate_volt;			// 400
extern float code_rate_power;			// 401
extern float code_rate_current;		// 402
extern float code_rate_hz;			// 403

extern float codeVdcOffset;			// 410
extern float codeVdcSpan;				// 411
extern float codeVoutOffset;			// 412
extern float codeVoutSpan;			// 413

// group5 Ctrl Code
extern float codeSwitFreq;				// 500

extern float code_Ki;					// 510
extern float code_Kp;					// 511
extern float code_integLimit;			// 512
extern float code_phaseMax;			// 513

extern float code_adc_vdc_low;			// 710
extern float code_adc_vdc_high;		// 711
extern float code_Vdc_calc_low;		// 712
extern float code_Vdc_calc_high;		// 713

extern float code_adc_Vout_low;		// 715
extern float code_adc_Vout_high;		// 716
extern float code_Vout_calc_low;		// 717
extern float code_Vout_calc_high;		// 718

extern float code_adcIout1st;			// 720
extern float code_adcIout2nd;			// 721
extern float code_adcIout3rd;			// 722
extern float code_adcIout4th;			// 723
extern float code_adcIout5th;			// 724

extern float Data_Check;				// 800
extern float Data_Backup;				// 801
extern float Data_Load;				// 802
extern float Data_Init;				// 803
//***********************************************************
#endif

