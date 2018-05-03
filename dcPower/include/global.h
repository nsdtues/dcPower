#ifndef		__GLOBAL_VARIABLES_
#define		__GLOBAL_VARIABLES_

float under_volt_set;

float IoutScale1st;
float IoutOffset1st;

float IoutScale2nd;
float IoutOffset2nd;

float IoutScale3rd;
float IoutOffset3rd;

float IoutScale4th;
float IoutOffset4th;



float nativeI_out;
float nativeI_pri;
float nativeI2nd;
float nativeI3rd;

float ctrlError;
float ctrlIntegral;
float preIntegral;
float phaseShiftRatio;

float Power_out;
int code_run_input_select;
float OC_Timer;

float ovpTimer;		// 2014.1016

float Vout;

int adcI_pri;
int adcI_out;
int adcI2nd;
int adcI3rd;

float I_pri;
float I_out;
float I2nd;
float I3rd;

float monitor[5]={0.0};
int debug_count;
int test_pulse_count;

unsigned int igbt_fault_input;
unsigned int digital_input;

int timer0_count;

unsigned int debug1;
int init_charge_flag = 0;
unsigned int xcon_data;		// expansion board xcon0,1,2,3 out data

//=============================================

char TimeInput[13]="101020123000";
int scib_rx_msg_flag = 0;
int scic_rx_msg_flag = 0;

float analog_ref_a;
float analog_ref_b;

//***************************************************
// ������� 
//***************************************************
float * dac_point[200];
float dac_ch0_unit_count_value;
float dac_ch1_unit_count_value;
float dac_ch2_unit_count_value;
float dac_ch3_unit_count_value;

float	inv_code_dac_scale_ch1;
float	inv_code_dac_scale_ch2;
float	inv_code_dac_scale_ch3;
float	inv_code_dac_scale_ch4;

//===================

float phaseVref;

float VdcScale;
float VdcOffset;

float VoutScale;
float VoutOffset;

float ref_time;

CODE_INFO code_inform = {0,0,0,0,0,0,{0}};

union PROTECT_FLAG protect_reg;

int terminal_input_state;

// PWM
float	DutyRatio[3];
Uint16 DutyCount[3];

// �ð� �� �ε���
float	Ts;
float	inv_Ts;
float 	gfRunTime=0;
int timer0_count;


//=============================================
float	Is_abc[3]={0.0,0.0,0.0};
float	Is_dq[2]={0.0,0.0};

float RMS_Ia = 0.;
float RMS_Ib = 0.;

float	Is_mag=0.0;
float	Is_mag_rms=0.0;

float	Is_max;					// �ִ� �������

float	Vdc=0.0;
float	Vs_max=0.0;

float refer_in0;
float	reference_in=0.0;
float	reference_out=0.0;
// ���� �� ���ļ�

float	frequency=0.0;
float	theta=0.0;
float	SinTheta=0.0;
float	CosTheta=1.0;

//====================================
// F28335 
// EwInv ���� ����
//====================================
// Sci.c

char gStr1[50] = {0};
char gStr2[10] = {0};

int gSciInFlag;

char gSciaRxBuf[SCIA_RX_BUF_MAX+1];
char gSciaTxBuf[SCIA_TX_BUF_MAX+1];

int gMachineState=0;

// Ref. Func
int	gPWMTripCode;

// �Ķ���� �� ����͸� ����Ÿ ������

int adc_result[16]={0};


int	giAdcVdc	;


TRIP_INFO TripInfo = {0,0,0,0,0,"2008:07:24  00:01:23"," No Trip Data       "};

//TRIP_INFO TripInfoNow={0,0,0,0,0,"01234567890123456789","01234567890123456789"};
TRIP_INFO TripInfoNow = {0,0,0,0,0,"2008:07:24  00:01:23"," No Trip Data       "};

int gTripFlag = 0;
Uint16	MAX_PWM_CNT;

char MonitorMsg[30]={0};

int gRunFlag=0;
int gTripSaveFlag=0;
int EepromSaveFlag = 0;
int Flag_TripDataBackup = 0;

float OverCurLimit;


//============================================
//   CODE variable 
//============================================
float code_I_out_ref;			// 0
int code_ctrl_mode;				// 1

float code_Vout;
float code_VoutLimit;		// 3
float code_ovpTime;		// 4

float codePwmPhaseInit;		// 6
float codeInitTime;			// 7

int codeSetPulseNumber;			// 10
float code_testPwmPhase;		// 11
int code_set_Vdc_on;			// 12
float code_Vdc_set_value;		// 13

float code_accel_time1;		// 15
float code_decel_time1;		// 16
float code_accel_time2;		// 17
float code_decel_time2;		// 18

float code_speed2;				// 19

float rDeadTime;				// 20
float allDeadTime;				// 21

//float over_volt_set;			// 204
//float code_under_volt_set;		// 205
//float Is_Max_Coeff;			// 206
//float code_OC_time;			// 207

///////////////////////////
int code_protect_inhibit_on;	// 210
int code_protect_uv_off;		// 211
int code_protect_ov_off;		// 212
int code_protect_Iadc_off;		// 213
int code_protect_over_I_off;	// 214
int code_protect_IGBT_off;		// 215
int code_protect_ex_trip_off;	// 216
///////////////////////////

// group3
//float code_rate_volt;			// 400
//float code_rate_power;			// 401
//float code_rate_current;		// 402
//float code_rate_hz;			// 403


//float codeIAdcOffset1st;		// 405
//float codeIAdcOffsetOut;		// 408

float codeVdcOffset;			// 410
float codeVdcSpan;				// 411
float codeVoutOffset;			// 412
float codeVoutSpan;			// 413

// group5 Ctrl Code
float codeSwitFreq;			// 500

float code_Ki;					// 510
float code_Kp;					// 511
float code_integLimit;			// 512
float code_phaseMax;			// 513

/*
float code_adc_vdc_low;		// 710
float code_adc_vdc_high;		// 711
float code_Vdc_calc_low;		// 712
float code_Vdc_calc_high;		// 713

float code_adc_Vout_low;		// 715
float code_adc_Vout_high;		// 716
float code_Vout_calc_low;		// 717
float code_Vout_calc_high;		// 718
*/

float Data_Check;				// 800
float Data_Backup;				// 801
float Data_Load;				// 802
float Data_Init;				// 803

//=====================================================
#endif

