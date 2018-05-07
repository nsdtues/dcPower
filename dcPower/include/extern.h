#ifndef		__VARIABLES_
#define		__VARIABLES_

extern float nativeI_out;
extern float nativeI_pri;
extern float nativeI2nd;
extern float nativeI3rd;

//--- PI control variable
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

extern int init_charge_flag;
extern float lpfVdcIn[3],lpfVdcOut[3],lpfVdcK[4];
extern float lpfIoutIn[3], lpfIoutOut[3],lpfIoutK[4];

extern unsigned int Fault_Code;
extern float * dac_point[200];

extern int scib_rx_msg_flag;
extern int scic_rx_msg_flag;

extern float analog_ref_a;
extern float analog_ref_b;

extern float phaseVref;
extern float VdcScale;
extern float VdcOffset;

extern float VoutScale;
extern float VoutOffset;

extern float ref_time;	// 2009.10.28

extern CODE_INFO code_inform;
extern union PROTECT_FLAG protect_reg;
extern char TripMessage[25];
// PWM
extern float	DutyRatio[3];
extern Uint16 DutyCount[3];
extern float 	gfRunTime;
extern float	Ts;
extern float	inv_Ts;
extern int timer0_count;
// Ref.
extern float   refer_in0;
extern float	reference_in;
extern float	reference_out;
extern float	Vdc;
// Sci.c
extern char gStr1[50];
extern char gStr2[10];
extern int gSciInFlag;
extern int scia_rx_msg_flag;
extern char gSciaRxBuf[SCIA_RX_BUF_MAX+1];
extern char gSciaTxBuf[SCIA_TX_BUF_MAX+1];

extern int gMachineState;
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

extern float	inv_code_dac_scale_ch1;
extern float	inv_code_dac_scale_ch2;
extern float	inv_code_dac_scale_ch3;
extern float	inv_code_dac_scale_ch4;

extern float code_adc_vdc_low;          // 710
extern float code_adc_vdc_high;     // 711
extern float code_Vdc_calc_low;     // 712
extern float code_Vdc_calc_high;        // 713

extern float code_adc_Vout_low;     // 715
extern float code_adc_Vout_high;        // 716
extern float code_Vout_calc_low;        // 717
extern float code_Vout_calc_high;       // 718

extern float codeVdcOffset;         // 410
extern float codeVdcSpan;               // 411
extern float codeVoutOffset;            // 412
extern float codeVoutSpan;          // 413
extern float codeSwitFreq;              // 500

extern float code_under_volt_set;
extern float over_volt_set;
//============================================
//   CODE variable 
//============================================
extern float code_I_out_ref;	    // 0
extern float code_ctrl_mode;		    // 1
extern float code_Vout;
extern float code_VoutLimit;	    // 3
extern float code_ovpTime;		    // 4
extern float codeOcTime;            // 5

extern float codePwmPhaseInit;	    // 6
extern float codeInitTime;		    // 7

extern float codeSetPulseNumber;	// 10
extern float code_testPwmPhase;		// 11
extern float code_set_Vdc_on;			// 12
extern float code_Vdc_set_value;	// 13
extern float code_protect_inhibit_on;   // 14

extern float rDeadTime;			    // 20
extern float allDeadTime;			// 21

extern float over_volt_set;			// 204
extern float code_under_volt_set;		// 205
extern float Is_Max_Coeff;				// 206
extern float code_OC_time;				// 207

///////////////////////////


extern float code_Ki;					// 510
extern float code_Kp;					// 511
extern float code_integLimit;			// 512
extern float code_phaseMax;			// 513


extern float Data_Check;				// 800
extern float Data_Backup;				// 801
extern float Data_Load;				// 802
extern float Data_Init;				// 803
//***********************************************************
#endif

