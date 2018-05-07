#ifndef		__FUNCTION_MODULE_DEFINITION_
#define		__FUNCTION_MODULE_DEFINITION_

extern int CheckOVP( );
extern void monitorPrint( char * strIn , char * charOut, float argIn);
//--- fullBridgeCtrl.c
extern void epwmFullBridgeEnable();
extern void epwmFullBridgeDisable();
extern void initVariFullbridgeCtrl();
extern void initEpwmFullBridge();
extern void pwmPulseTest();
extern int mode3Current_P_I_LoopCtrl( );
extern int mode8LoopCtrl();
extern int pwmPulseTestLoopCtrl( );

// low_pass_filter.c
extern void lpf2ndCoeffInit( float cutoff_freq, float T_sample, float *x, float *y, float *k);
extern void lpf2nd(float * x,float * y, float * K);

// MonitorProc.c
extern void monitor_proc();		// need_edit

//RefFunc.c
extern void ramp_proc( float set_ref, float * out_ref);

extern float linear_eq(float x1, float x2, float y1, float y2, float x );
extern int periodic_check(unsigned long  msec);
extern	void 	PI_Damp_Controller(float limit,float Ts,float damp_factor,float Kp,float Ki,float ref,float feedback,float *integral,float *output);

extern void get_adc_offset();
extern void get_adc_vdc_low();
extern void get_adc_vdc_high();


// code_proc.c
extern void readAllCodes();
extern int get_code_information(int address,int cmd , CODE_INFO *  codes);
extern void set_code_default(float min, float max, float defaults, float value,int open_level, CODE_INFO * codes );

extern int check_backup_data();
extern void save_backup_data();
extern void backup_data_load();
extern int init_eprom_data();
extern float CheckSum();

extern int SaveDataProc(int addr, float data);

// digital_inout.c
extern void digitalOutProc();
extern void	digital_input_proc( int * cmd, float * ref);
extern void input_ext_fault_a_proc();
extern void serial_com_proc( int * sci_cmd, float * sci_reference );
extern void load_sci_tx_mail_box(char *st);
extern void load_scia_tx_mail_box( char * st);

// uart_c.c 
extern void sendAllCodeData(void);
extern void scia_cmd_proc(int * scic_cmd, float * scic_ref);
interrupt void sciaTxFifoIsr(void);
interrupt void sciaRxFifoIsr(void);
extern void scia_fifo_init(void);
extern void load_scia_tx_mail_box(char *st);
interrupt void cpu_timer0_isr(void);
interrupt void MainPWM(void);

// analog.c
extern void ADC_SOC_CNF();
extern void AD2LPF(void);
extern void analog_input_proc( float * analog_referenc);
extern void analog_input_proc_b( float * referenc);
extern void analog_out_proc( );
interrupt void Adc_Isr(void);
interrupt void wakeint_isr(void);
extern void VariInit();
extern void GetAnaMonitCount(unsigned int * piChA, unsigned * piChB);
extern void GetInputMark(char * str);
// main.c
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
extern void RefFunc( float CommandRef,float * OutRef);
// I2C_eeprom.c
extern int check_code_data(int address, UNION32 u32data );
extern void I2CA_Init(void);
extern void write_code_2_eeprom(int address,UNION32 data);
extern void read_eprom_data(int address, UNION32 * u32data);

extern Uint16 I2CA_ReadData(int iSlaveAddr, int iMemAddr, int * data);
extern Uint16 I2CA_WriteData(int iSlaveAddr,int iMemAddr,int iData);
extern int load_code2ram();
// CommandProc.c
extern void get_command(int * command, float * ref );

//TripProc.c
extern void trip_recording(int trip_code,float trip_data,char * st);
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

extern int tripCheck();
extern void tripProc( );
extern void tripRecorder();

#endif


