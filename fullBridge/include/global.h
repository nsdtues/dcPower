#ifndef		__GLOBAL_VARIABLES_
#define		__GLOBAL_VARIABLES_

double IoutScale1st;
double IoutOffset1st;

double IoutScale2nd;
double IoutOffset2nd;

double IoutScale3rd;
double IoutOffset3rd;

double IoutScale4th;
double IoutOffset4th;



double nativeI_out;
double nativeI_pri;
double nativeI2nd;
double nativeI3rd;

double ctrlError;
double ctrlIntegral;
double preIntegral;
double phaseShiftRatio;

double Power_out;
int code_run_input_select;
double OC_Timer;

double ovpTimer;		// 2014.1016

double Vout;

int adcI_pri;
int adcI_out;
int adcI2nd;
int adcI3rd;

double I_pri;
double I_out;
double I2nd;
double I3rd;

double monitor[5]={0.0};
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

double analog_ref_a;
double analog_ref_b;

//***************************************************
// ������� 
//***************************************************
double * dac_point[200];
double dac_ch0_unit_count_value;
double dac_ch1_unit_count_value;
double dac_ch2_unit_count_value;
double dac_ch3_unit_count_value;

double	inv_code_dac_scale_ch1;
double	inv_code_dac_scale_ch2;
double	inv_code_dac_scale_ch3;
double	inv_code_dac_scale_ch4;

//===================

double phaseVref;

double VdcScale;		
double VdcOffset;	

double VoutScale;		
double VoutOffset;	

double ref_time;

CODE_INFO code_inform = {0,0,0,0,0,0,{0}};

union PROTECT_FLAG protect_reg;

int terminal_input_state;

// PWM
double	DutyRatio[3];
Uint16 DutyCount[3];

// �ð� �� �ε���
double	Ts;
double	inv_Ts;
double 	gfRunTime=0;
int timer0_count;


//=============================================
double	Is_abc[3]={0.0,0.0,0.0};
double	Is_dq[2]={0.0,0.0};

double RMS_Ia = 0.;
double RMS_Ib = 0.;

double	Is_mag=0.0;
double	Is_mag_rms=0.0;

double	Is_max;					// �ִ� ������

double	Vdc=0.0;	
double	Vs_max=0.0;	

double refer_in0;
double	reference_in=0.0;
double	reference_out=0.0;
// ���� �� ���ļ�

double	frequency=0.0;
double	theta=0.0;
double	SinTheta=0.0;
double	CosTheta=1.0;

//====================================
// F28335 
// EwInv ���� ����
//====================================
// Sci.c

char gStr1[50] = {0};
char gStr2[10] = {0};

int gSciInFlag;

char gSciaRxBuf[NUM_SCI_RX_BUF+1];
char gSciaTxBuf[NUM_SCI_TX_BUF+1];

int gMachineState=0;

// Ref. Func
int	gPWMTripCode;

// �Ķ���� �� ����͸� ����Ÿ ������

int adc_result[16]={0};


int	giAdcVdc	;
union DIGITAL_FUNCTION func_flag;	// ������ �Է��� ����� �����Ѵ�.

union DIGITAL_OUT_FUNC relay_flag;

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

double OverCurLimit;


//============================================
//   CODE variable 
//============================================
double code_I_out_ref;			// 0
double code_Vout;				//1

double code_VoutLimit;		// 3
double code_ovpTime;		// 4

double codePwmPhaseInit;		// 6
double codeInitTime;			// 7

int code_run_input_select;      // 8
int code_ctrl_mode;				// 9

int codeSetPulseNumber;			// 10
double code_testPwmPhase;		// 11
int code_set_Vdc_on;			// 12
double code_Vdc_set_value;		// 13

double code_accel_time1;		// 15
double code_decel_time1;		// 16
double code_accel_time2;		// 17
double code_decel_time2;		// 18

double code_speed2;				// 19

double rDeadTime;				// 20
double allDeadTime;				// 21	

// group1

double analog_cmd_in_zero1;		// 100
double analog_cmd_in_span1;		// 101
double analog_cmd_in_zero2;		// 102
double analog_cmd_in_span2;		// 103
int 	code_AdcOffsetCh6;		// 104

double codeAnalogSelect1;		//	110
double codeAnalogOutZero1;		//	111
double codeAnalogOutSpan1;		//	112
double codeAnalogOutOffset1;	//	113

double codeAnalogSelect2;		//	115
double codeAnalogOutZero2;		//	116
double codeAnalogOutSpan2;		//	117
double codeAnalogOutOffset2;	//	118

// group2

double codeOCLevel1st;			// 200
double codeOCLevel2nd;			// 201
double codeOCLevel3rd;			// 202
double codeOCLevelOut;			// 203

double over_volt_set;			// 204
double code_under_volt_set;		// 205
double Is_Max_Coeff;			// 206
double code_OC_time;			// 207

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
double code_rate_volt;			// 400
double code_rate_power;			// 401
double code_rate_current;		// 402
double code_rate_hz;			// 403

//group 4
double codeISpan1st;			// 400
double codeISpan2nd;			// 401
double codeISpan3rd;			// 402
double codeISpanOut;			// 403

double codeIAdcOffset1st;		// 405
double codeIAdcOffset2nd;		// 406
double codeIAdcOffset3rd;		// 407
double codeIAdcOffsetOut;		// 408

double codeVdcOffset;			// 410
double codeVdcSpan;				// 411
double codeVoutOffset;			// 412
double codeVoutSpan;			// 413

// group5 Ctrl Code
double codeSwitFreq;			// 500

double code_Ki;					// 510
double code_Kp;					// 511		
double code_integLimit;			// 512		
double code_phaseMax;			// 513		

// group6
int code_dac_select_ch1;		// 600	
double code_dac_scale_ch1;		// 601
double code_dac_offset_ch1;		// 602

int code_dac_select_ch2;		// 605
double code_dac_scale_ch2;		// 605
double code_dac_offset_ch2;		// 607

int code_dac_select_ch3;		// 610
double code_dac_scale_ch3;		// 611
double code_dac_offset_ch3;		// 612

int code_dac_select_ch4;		// 615
double code_dac_scale_ch4;		// 616
double code_dac_offset_ch4;		// 617

// group7 sensor set

double codeIValue1st;			// 700
double codeIValue2nd;			// 701
double codeIValue3rd;			// 702
double codeIValueOut;			// 703

double code_adc_vdc_low;		// 710
double code_adc_vdc_high;		// 711
double code_Vdc_calc_low;		// 712
double code_Vdc_calc_high;		// 713

double code_adc_Vout_low;		// 715
double code_adc_Vout_high;		// 716
double code_Vout_calc_low;		// 717
double code_Vout_calc_high;		// 718

double code_adcIout1st;			// 720
double code_adcIout2nd;			// 721
double code_adcIout3rd;			// 722
double code_adcIout4th;			// 723
double code_adcIout5th;			// 724

double code_calIout1st;			// 725
double code_calIout2nd;			// 726
double code_calIout3rd;			// 727
double code_calIout4th;			// 728
double code_calIout5th;			// 729

double Data_Check;				// 800
double Data_Backup;				// 801
double Data_Load;				// 802
double Data_Init;				// 803

//=====================================================

float time_t; // hjkim

#endif

