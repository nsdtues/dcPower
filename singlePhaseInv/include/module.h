#ifndef		__FUNCTION_MODULE_DEFINITION_
#define		__FUNCTION_MODULE_DEFINITION_

// f28069GpioSetup.c
extern void ePwmPortOff();
extern void ePwmEnable();
extern void InitGpio(void);



extern void  EQEP_Initialization(void);
extern void Speed_Calculation();

// low_pass_filter.c
extern void Init_Filters( );

// back2back_control.c

extern void EPwm_ISC_Enable();
extern void EPwm_OSC_Enable();
extern void EPwm_All_Disable();

// switching_irq.c
extern void PLL(void);
extern void Converter_Ctrl(void);
extern void Inverter_Ctrl(void);
extern void fIn_SpaceVectorPWM(void); 
extern void fOut_SpaceVectorPWM(void); 
extern void fault_check(void);
extern void convert_var_init();
extern void MotorControlProc( );

// test_run.c
extern int test_run();

// set_dac_point.c
extern void set_dac_point();

// MonitorProc.c
extern void monitor_proc();		// need_edit

//RefFunc.c
extern void ramp_proc( double set_ref, double * out_ref);

// auto_tuning.c
extern int parameter_estimation( );

// common_module.c
extern void LPF_COEFF_CAL(double cut_freq, double * coeff1, double * coeff2);
extern void LPF_V(double *LPF_out, double *LPF_feed, double LPF_in);
extern void LPF_I(double *LPF_out, double *LPF_feed, double LPF_in);

extern double linear_eq(double x1, double x2, double y1, double y2, double x );
extern int periodic_check(unsigned long  msec);
extern	void 	PI_Damp_Controller(double limit,double Ts,double damp_factor,double Kp,double Ki,double ref,double feedback,double *integral,double *output);

extern void get_adc_offset();
extern void get_adc_vdc_low();
extern void get_adc_vdc_high();

// vf_control.c
extern int vf_loop_control(double);
extern int vf_frequency_control();
extern void vf_simple_control();
extern void slip_comp_scalar_ctrl();

// vector_control.c
extern int vector_control();
extern int vector_control_init();
extern void sl_vector_variable_init();
extern int pwm_regenerat_convert();

// code_proc.c
extern int get_code_information(int address,int cmd , CODE_INFO *  codes);
extern void set_code_default_int( int min, int max, int defaults, int value, int open_level, CODE_INFO * codes );
extern void set_code_default_double(double min, double max, double defaults, double value,int open_level, CODE_INFO * codes );

extern int get_code_group0(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group1(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group2(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group3(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group4(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group5(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group6(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group7(int addr ,int cmd, CODE_INFO * codes );
extern int get_code_group8(int addr ,int cmd, CODE_INFO * codes );

extern int check_backup_data();
extern void save_backup_data();
extern void backup_data_load();
extern int init_eprom_data();
extern int Check_Eeprom_Error();
extern double CheckSum();

extern int SaveDataProc(int addr, double data);

// digital_inout.c

extern void digital_out_proc();
extern void	digital_input_proc( int * cmd, double * ref);
extern void input_ext_fault_a_proc();


extern void serial_com_proc( int * sci_cmd, double * sci_reference );
extern void load_sci_tx_mail_box(char *st);

// scia.c
extern void scia_cmd_proc(int * scic_cmd, double * scic_ref);
extern interrupt void sciaTxFifoIsr(void);
extern interrupt void sciaRxFifoIsr(void);
extern void scia_fifo_init(void);
extern void load_scia_tx_mail_box(char *st);

interrupt void cpu_timer0_isr(void);
interrupt void MainPWM(void);


// analog.c
extern void analog_input_proc( double * analog_referenc);
extern void analog_out_proc( );
extern int check_sensor_trip();

__interrupt void adcIsr(void);
interrupt void wakeint_isr(void);

// ParameterSet.c
extern void VariInit();

//******************************************************
// File : "DataPtr.c" &  "Set_Par.c"
//extern	int 	motor_name_plate_check();
extern int HardwareParameterVerification();
extern	int 	VF_Cntl_Parameter();
extern	int 	COMMON_VECT_CNTL_ParameterVerification();			// ���� ���� ����
extern	int 	COMMON_SL_VECT_CNTL_ParameterVerification();			// �������� ���� ���� ����
extern	int 	SL_TORQUE_CNTL_Parameter();

extern	int 	AUTO_TUNING_Parameter();

//******************************************

// File : "svm.c"
extern	void SpaceVectorModulation(double *Vs_dq );
extern	void VoltageEstimation();

//***************************************

// File : "control.c"
extern	void 	LPF1(double Ts,double pole,double in,double *out);
	
// File : ""SL_Vect.c""
extern	void 	SL_VectCntl_SFRF();
extern	void 	SL_SpeedCntl_SFRF();
extern	void 	DirTorqueLimitSpeedCntl_SFRF();
extern	void 	SL_TorqueCntl_SFRF();
extern int SL_SPEED_CNTL_Parameter();	


// File : "RefFunc.c"
extern void GetAnaMonitCount(unsigned int * piChA, unsigned * piChB);

//******************************************

// File : "auto_tuning.c"
extern void estim_ReqLeq_pwm();
extern void estim_Rs_pwm();
extern void	estim_Ls_pwm( );
extern void estim_Jm_pwm();


// FILE:	F28335_Gpio.c

// SCI.C

extern void GetInputMark(char * str);

// main.c

extern void InitEPwm_ACIM_Inverter();
extern void Start_CheckSum();

// EwInv.C

extern void Nop();
extern void SetSensorOffset();
extern void PowerOnReset();
extern unsigned long ulGetTime_mSec(unsigned long Start_mSec);
extern unsigned long ulGetNow_mSec( );
extern void delay_msecs( unsigned long ulmSec);
extern void GetSensorValue( );

// refunc.c

extern void RefFunc( double CommandRef,double * OutRef);

// I2C_eeprom.c
extern int check_code_data(int address, UNION32 u32data );
// extern int check_code_data(UNION32 u32data,CODE_INFO CodeInfo );
extern void I2CA_Init(void);

extern void write_code_2_eeprom(int address,UNION32 data);
extern void read_eprom_data(int address, UNION32 * u32data);

extern Uint16 I2CA_ReadData(int iSlaveAddr, int iMemAddr, int * data);
extern Uint16 I2CA_WriteData(int iSlaveAddr,int iMemAddr,int iData);
extern int load_code2ram();

//*****************************************
// DS1307.c

extern void DS1307WriteData(int iMemAddr,int iData);
extern void DS1307ReadData(int iMemAddr, int * data);
extern void GetTimeAndDateStr(char * StrIn);
extern void WriteTimeToDS1307( );


// interrupt void i2c_int1a_isr(void);

// CommandProc.c
extern void get_command(int * command, double * ref );

//TripProc.c
extern void trip_recording(int trip_code,double trip_data,char * st);
extern void GetTripInfo(int Point, TRIP_INFO * TripData );
extern void WriteTripString(int StartAddr, char * str);
extern void ReadTripString(int StartAddr, char * str);
extern void SaveTripDataToEeprom();
extern void ClearTripDataToEeprom();

extern int CheckOverCurrent( );
extern int chk_invt_OC();
extern int chk_convt_OC();
extern int CheckOverVolt( );
extern int CheckUndeVolt( );
extern int CheckOverSpeed( );
extern int CheckIGBTFault( );
extern int CheckOverHeat( );

extern int trip_check();
extern void tripProc( );
extern void TripRecorder();

// hyd_unit.c
extern int hyd_unit_loop_proc();
extern void hyd_unit_control( );

#endif

