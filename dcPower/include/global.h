#ifndef		__GLOBAL_VARIABLES_
#define		__GLOBAL_VARIABLES_

char monitOut[61];

float under_volt_set;
float nativeI_out;
float nativeI_pri;
//--- PI control
float ctrlError;
float ctrlIntegral;
float preIntegral;
float phaseShiftRatio;

float Power_out;
int code_run_input_select;
float OC_Timer;
float ovpTimer;
float Vout;
int adcI_pri;
int adcI_out;
float I_pri;
float I_out;

float monitor[5]={0.0};
int debug_count;
int test_pulse_count;

unsigned int igbt_fault_input;
unsigned int digital_input;

int timer0_count;

unsigned int debug1;
int init_charge_flag = 0;

int scib_rx_msg_flag = 0;
int scic_rx_msg_flag = 0;

float analog_ref_a;
float analog_ref_b;
//---
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

float	Ts;
float	inv_Ts;
float 	gfRunTime=0;
int timer0_count;
float	Vdc=0.0;
float	Vs_max=0.0;

float refer_in0;
float	reference_in=0.0;
float	reference_out=0.0;
//--- Sci.c
char gStr1[50] = {0};
char gStr2[10] = {0};
int gSciInFlag;
char gSciaRxBuf[SCIA_RX_BUF_MAX+1];
char gSciaTxBuf[SCIA_TX_BUF_MAX+1];
int gMachineState=0;
int	gPWMTripCode;
int adc_result[16]={0};
int	giAdcVdc	;
TRIP_INFO TripInfo = {0,0,0,0,0,"2008:07:24  00:01:23"," No Trip Data       "};
TRIP_INFO TripInfoNow = {0,0,0,0,0,"2008:07:24  00:01:23"," No Trip Data       "};

int gTripFlag = 0;
Uint16	MAX_PWM_CNT;

char MonitorMsg[30]={0};

int gRunFlag=0;
int gTripSaveFlag=0;
int EepromSaveFlag = 0;
int Flag_TripDataBackup = 0;
float OverCurLimit;

float codeVdcOffset;
float codeVdcSpan;
float codeVoutOffset;
float codeVoutSpan;
float codeSwitFreq;

float code_Ki;
float code_Kp;
float code_integLimit;
float code_phaseMax;

float codeVdcOffset;
float codeVdcSpan;
float codeVoutOffset;
float codeVoutSpan;
float codeSwitFreq;

float code_adc_vdc_low;
float code_adc_vdc_high;
float code_Vdc_calc_low;
float code_Vdc_calc_high;

float code_adc_Vout_low;
float code_adc_Vout_high;
float code_Vout_calc_low;
float code_Vout_calc_high;

int codeProtectOff = 0;
int code_protect_uv_off = 0;
int code_protect_ov_off = 0;
int code_protect_Iadc_off = 0;
int code_protect_over_I_off = 0;
int code_protect_IGBT_off =0;
int code_protect_ex_trip_off=0;

float code_under_volt_set = 200.0;
float over_volt_set = 700.0;

//============================================
//   CODE variable 
//============================================
float code_I_out_ref;           // 0
float code_ctrl_mode;			// 1
float code_Vout;
float code_VoutLimit;		    // 3
float code_ovpTime;             // 4
float codeOcTime;
float codePwmPhaseInit;         // 6
float codeInitTime;             // 7

float codeSetPulseNumber;		// 10
float code_testPwmPhase;		// 11
float code_set_Vdc_on;			// 12
float code_Vdc_set_value;		// 13
float code_protect_inhibit_on;  // 14

float Data_Check;				// 800
float Data_Backup;				// 801
float Data_Load;				// 802
float Data_Init;				// 803
//=====================================================
#endif

