//
// filename 	: dual_trip_proc.c 
// pcb			: dfig_dsp_.0104.bk.sch
// data			; 2012.04.17		
//					by cheoung soon gil  
// 
#include	<header.h>
#include	<extern.h>


// �� PWM���� Ȯ���Ѵ�. 
void trip_recording(int trip_code,double trip_data,char * st)
{
	if(gRunFlag)	gTripSaveFlag = 1;
	else			gTripSaveFlag = 0;

	TripInfoNow.CODE	= trip_code;
	TripInfoNow.DATA	= trip_data;
	strncpy( TripInfoNow.MSG,st,20) ;
	gMachineState 		= STATE_TRIP;
	TripInfoNow.CURRENT	= I_out;
	TripInfoNow.VDC 	= Vdc;
	TripInfoNow.VOUT 	= Vout;
//	TripInfoNow.HZ 		= Freq_out;
}	

int CheckOverCurrent( )
{
//--- OC I_pri check
	if(( protect_reg.bit.OVER_I_ADC)&&( adcI_pri > 4000)){
		trip_recording( ERR_OC_I_PRI_ADC_P, (double)(adcI_pri),"I_pri adc + over");
		return ERR_OC_I_PRI_ADC_P;
	}

	if(( protect_reg.bit.OVER_I_ADC)&&( adcI_pri  < 100)){ 
		trip_recording( ERR_OC_I_PRI_ADC_N, (double)(adcI_pri),"I_pri adc - over");
		return ERR_OC_I_PRI_ADC_N;
	}

//--- OC I_out check
	if(( protect_reg.bit.OVER_I_ADC)&&( adcI_out > 4000)){
		trip_recording( ERR_OC_I_OUT_ADC_P, (double)(adcI_out),"I_out adc +over ");
		return ERR_OC_I_OUT_ADC_P;
	}

	if(( protect_reg.bit.OVER_I_ADC)&&( adcI_out  < 100)){ 
		trip_recording( ERR_OC_I_OUT_ADC_N, (double)(adcI_pri),"I_out adc -over");
		return ERR_OC_I_OUT_ADC_N;
	}

	if( protect_reg.bit.OVER_I){
		if(I_out > OverCurLimit )	OC_Timer += Ts;
		else if(OC_Timer > Ts)		OC_Timer -= Ts;

		if (OC_Timer > code_OC_time ){
			trip_recording( CODE_OC_time,I_out,"OC Time out");
			return	CODE_OC_time;
		}
	} 

	return 	0; 
}
//-----------------------------------------------
//  ����� ����� ��ȣ 
//-----------------------------------------------

int CheckOverVolt( )
{
	static int OverVoltCount = 0;

	if( protect_reg.bit.OVER_VOLT == 0 ) return 0;

	if (Vdc > over_volt_set ) OverVoltCount++;
	else if( OverVoltCount > 0) OverVoltCount --;

	if (OverVoltCount > 5 )
	{
		OverVoltCount = 6;
		// trip_recording( CODE_over_current_level,Vdc,"Trip Over Volt");

		return CODE_over_volt_set;
	}
	return 0;
}

int CheckOVP( )
{
	if( Vout > code_VoutLimit )	ovpTimer += Ts;
	else if(ovpTimer > Ts)		ovpTimer -= Ts;

	if (ovpTimer > code_ovpTime ){
		trip_recording( CODE_ovpTime,Vout,"OVP Time out");
		return	CODE_ovpTime;
	}
	return 0;
}

//-----------------------------------------------
//  ����� ��ȣ 
//-----------------------------------------------

int CheckUndeVolt( )
{
	static int UnderVoltCount = 0;

	if( protect_reg.bit.UNVER_VOLT == 0 ) return 0;

	if( gMachineState == STATE_POWER_ON ) return 0;	// 2014.0901 by soongil

	if (Vdc < code_under_volt_set) 	UnderVoltCount++;
	else if( UnderVoltCount > 0) 	UnderVoltCount--;

	if (UnderVoltCount > 5 )
	{
		UnderVoltCount = 6;
		trip_recording( CODE_under_volt_set,Vdc,"Trip Under Volt");

		return CODE_under_volt_set;
	}
	return 0;
}

int CheckIGBTFault( )
{
	unsigned int xbus_in, temp,temp2;
//	static int trip_count=0;

	if( protect_reg.bit.IGBT_FAULT == 0 ) return 0;

	xbus_in = ZONE0_BUF[0x0040];   // 

	temp = (xbus_in | 0xc0c0);		// 0x3f3f

	if( temp != 0xffff ){

		temp = ZONE0_BUF[0x0040] | 0xC0C0 ;   // 0x3f3f
		temp |= 0xff00 ;

		if( temp == 0xffff ) return 0;

		temp2 = temp & 0x0001;
		if( temp2 == 0 ){
			trip_recording( ERR_IGBT_UH,Is_abc[as],"ERR_IGBT_UH"); 
			return ERR_IGBT_UH;
		}

		temp2 = temp & 0x0002;
		if( temp2 == 0 ){
			trip_recording( ERR_IGBT_UL,Is_abc[as],"ERR_IGBT_UL"); 
			return ERR_IGBT_UL;
		}
		temp2 = temp & 0x0004;
		if( temp2 == 0 ){
			trip_recording( ERR_IGBT_VH,Is_abc[bs],"ERR_IGBT_VH"); 
			return ERR_IGBT_VH;
		}
		temp2 = temp & 0x0008;
		if( temp2 == 0 ){
			trip_recording( ERR_IGBT_VL,Is_abc[bs],"ERR_IGBT_VL"); 
			return ERR_IGBT_VL;
		}
	}

	return 0;

}

int CheckOverHeat( )
{
	static int OverHeatCount = 0;

	if( protect_reg.bit.OVER_HEAT == 0 ) return 0;


//	if( OVER_HEAT )					OverHeatCount ++;
//	else if( OverHeatCount > 0) 	OverHeatCount--;

	if( OverHeatCount > 10 )	// debug// Low --> High
	{
		OverHeatCount = 11;
		trip_recording( ERR_OVER_HEAT,Is_mag_rms,"TRIP Over Heat");
		return ERR_OVER_HEAT;
	}
	return 0 ;
}

//-----------------------------------------------
//
//  ��ȣ ��� 
//		�� ����Ī ���� �̸� ���� �Ѵ�. 
//----------------------------------------------
int trip_check()
{
	int TripCode;

	TripCode = 0;
	if( ( TripCode = CheckOverCurrent()) != 0 ) return TripCode ;	// debug
	if( ( TripCode = CheckOverVolt()   ) != 0 ) return TripCode ;
	if( ( TripCode = CheckUndeVolt()   ) != 0 ) return TripCode ;	// ���������� ������ �Ѵ�. 
	if( ( TripCode = CheckOverHeat()   ) != 0 ) return TripCode ;
	if( ( TripCode = CheckIGBTFault()  ) != 0 ) return TripCode ;
	if( ( TripCode = CheckOVP( )       ) != 0 ) return TripCode ;
	return TripCode;
}

//-----------------------------------
// Ʈ�� �߻� �����̸� On �ϰ� 
// Reset�� ��ٸ���. 
//-----------------------------------
// Trip Message�� Ʈ���� �߻�� �� ������ �Ѵ�. 
//

void TripProc( )
{
	int iCommand;
	int LoopCtrl;
	// int temp;
	double fReference;
	// double dbtemp;
	char str[30];

	str[29] = 0;
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 	= 0;  // GPIO0 = PWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 	= 0;  // GPIO1 = PWM1B
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 	= 0;  // GPIO2 = PWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 	= 0;  // GPIO3 = PWM2B
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 	= 0;  // GPIO4 = PWM3A
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 	= 0;  // GPIO5 = PWM3B

	GpioCtrlRegs.GPAMUX1.bit.GPIO6 	= 0;  // GPIO4A
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 	= 0;  // GPIO4B
	GpioCtrlRegs.GPAMUX1.bit.GPIO8 	= 0;  // GPIO5A
	GpioCtrlRegs.GPAMUX1.bit.GPIO9 	= 0;  // GPIO5B
	GpioCtrlRegs.GPAMUX1.bit.GPIO10	= 0;  // GPIO6A
	GpioCtrlRegs.GPAMUX1.bit.GPIO11	= 0;  // GPIO6B

	GpioCtrlRegs.GPADIR.bit.GPIO0 	= 1;  // GPIO0 = Output
	GpioCtrlRegs.GPADIR.bit.GPIO1 	= 1;  // GPIO1 = Output
	GpioCtrlRegs.GPADIR.bit.GPIO2 	= 1;  // GPIO2 = Output
	GpioCtrlRegs.GPADIR.bit.GPIO3 	= 1;  // GPIO3 = Output
	GpioCtrlRegs.GPADIR.bit.GPIO4 	= 1;  // GPIO4 = Output
	GpioCtrlRegs.GPADIR.bit.GPIO5 	= 1;  // GPIO5 = Output

	GpioCtrlRegs.GPADIR.bit.GPIO6 	= 1;  // GPIO4A
	GpioCtrlRegs.GPADIR.bit.GPIO7 	= 1;  // GPIO4B
	GpioCtrlRegs.GPADIR.bit.GPIO8 	= 1;  // GPIO5A
	GpioCtrlRegs.GPADIR.bit.GPIO9 	= 1;  // GPIO5B
	GpioCtrlRegs.GPADIR.bit.GPIO10 	= 1;  // GPIO6A
	GpioCtrlRegs.GPADIR.bit.GPIO11 	= 1;  // GPIO6B


	GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;  // Set Output

	GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO8 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;  // Set Output
	GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;  // Set Output

	EDIS;

	gMachineState = STATE_TRIP;

	MAIN_CHARGE_OFF;					// Main Charge Relay Off
	init_charge_flag=0;
	INIT_CHARGE_CLEAR;
	TRIP_OUT_ON;
		
	GetTimeAndDateStr(str);
	strncpy( TripInfoNow.TIME,str,20);

	if( gTripSaveFlag )
		SaveTripDataToEeprom();  // debug_jsk

	LoopCtrl = CMD_NULL;
	while( LoopCtrl != CMD_RESET)
	{
		get_command( & iCommand, & fReference);	// Command�� �Է� ���� 				
		if( iCommand == CMD_RESET) LoopCtrl = CMD_RESET;
		Nop();
	}

	delay_msecs(50);
	while( LoopCtrl == CMD_RESET)
	{
		get_command( & iCommand, & fReference);	// Command�� �Է� ���� 				
		if( iCommand == CMD_STOP) LoopCtrl = CMD_STOP;
		Nop();
	}

	for( ; ; ) // system reset 
	{
		gMachineState = STATE_TRIP;
		Nop();
		asm (" .ref _c_int00"); // ;Branch to start of boot.asm in RTS library
		asm (" LB _c_int00"); // ;Branch to start of boot.asm in RTS library
	}
}

void GetTripInfo(int Point,TRIP_INFO * TripData )
{
	int TripDataPoint;
	int TripBaseAddr;
	int iTemp;
	char str[30]={0};
	UNION32 u32data;

	strncpy(TripData->MSG ,NULL,41);
	strncpy(TripData->TIME ,NULL,31);

	I2CA_ReadData(ADDR_24LC32,EPROM_ADDR_TRIP_POINT,&TripDataPoint);

// erased  
	if( ( 0 > Point ) || ( Point > 10) || (TripDataPoint == 0x00ff))
	{
		TripData->CURRENT = 0.0;
		TripData->DATA = 0.0;
		TripData->VOUT = 0.0;
		TripData->CODE = 0.0;
		TripData->VDC = 0.0;
		strncpy(TripData->MSG  ," Invalid Trip Code  ",20);
		strncpy(TripData->TIME ,"2014:10:16  17:00:00",20);
		return ;
	}

	if( (TripDataPoint<1)||(TripDataPoint>10)){
		I2CA_WriteData(ADDR_24LC32, EPROM_ADDR_TRIP_POINT,0);
		TripDataPoint = 0;
	}
	EepromSaveFlag = 1;
// ����� �� �����͸� ���Ѵ�. 
	iTemp = TripDataPoint - Point;		// iPoint = 1~10;

	if( iTemp < 0 ) iTemp += 10;

	TripBaseAddr = TRIP_BACKUP_ADDR + iTemp * 100;

	// Code
	read_eprom_data( TripBaseAddr+ 0, & u32data);
		TripData->CODE =  u32data.dword;

	// Data
	read_eprom_data( TripBaseAddr+ 4, & u32data);
		TripData->CURRENT =  u32data.dword;

	// Current
	read_eprom_data( TripBaseAddr+ 8, & u32data);
	TripData->CURRENT =  u32data.dword;

	// HZ
	read_eprom_data( TripBaseAddr+ 12, & u32data);
	TripData->VOUT =  u32data.dword;

	// VDC
	read_eprom_data( TripBaseAddr+16, & u32data);
	TripData->VDC =  u32data.dword;

	ReadTripString( TripBaseAddr+20,str);
	strncpy(TripData->MSG,str,20);

	// Time
	ReadTripString( TripBaseAddr+40,str);
	strncpy(TripData->TIME,str,20);

	// start Time
	ReadTripString( TripBaseAddr+60,str);
	strncpy(TripData->START_TIME,str,20);

	EepromSaveFlag = 0;
}

void WriteTripString(int StartAddr, char * str)
{
	int i;
	int Addr;
	int string[21]={0};
	
	for(i=0;i<20;i++) string[i] = (int)(*(str ++));

	Addr = StartAddr;

	for(i=0;i<20;i++) I2CA_WriteData(ADDR_24LC32,Addr+i,string[i]);
}

void ReadTripString(int StartAddr, char * str)
{
	int i;
	int Addr;
	int iTemp;	
	char StrBuf[30];

	Addr = StartAddr;

	for(i=0;i<20;i++){
		I2CA_ReadData(ADDR_24LC32,Addr+i,&iTemp);
		StrBuf[i] = (char)(iTemp);
	}
	StrBuf[20] =0;
	strncpy(str,StrBuf,20);
}

void SaveTripDataToEeprom()
{
	int TripDataPoint,TripBaseAddr;
	char str[30];
	UNION32 u32data;

	I2CA_ReadData(ADDR_24LC32,EPROM_ADDR_TRIP_POINT,&TripDataPoint);

	if(( TripDataPoint < 0 ) ||( TripDataPoint > 8)) TripDataPoint = 0;
	else TripDataPoint ++;

	I2CA_WriteData(ADDR_24LC32, EPROM_ADDR_TRIP_POINT, TripDataPoint);			
	 
	TripBaseAddr = TRIP_BACKUP_ADDR + TripDataPoint * 100;

	EepromSaveFlag = 1;
// Code
	u32data.dword = TripInfoNow.CODE;
	write_code_2_eeprom( TripBaseAddr+ 0, u32data);

// Data
	u32data.dword = TripInfoNow.DATA;
	write_code_2_eeprom( TripBaseAddr+ 4, u32data);

// Current
	u32data.dword = TripInfoNow.CURRENT;
	write_code_2_eeprom( TripBaseAddr+ 8, u32data);

// Vout
	u32data.dword = TripInfoNow.VOUT;
	write_code_2_eeprom( TripBaseAddr+ 12, u32data);

// VDC
	u32data.dword = TripInfoNow.VDC;
	write_code_2_eeprom( TripBaseAddr+16, u32data);

// Msg
	strncpy(str,TripInfoNow.MSG,20);
	WriteTripString( TripBaseAddr+20,str);
// Time
	strncpy(str,TripInfoNow.TIME,20);
	WriteTripString( TripBaseAddr+40,str);
// start Time
	strncpy(str,TripInfoNow.START_TIME,20);
	WriteTripString( TripBaseAddr+60,str);

	EepromSaveFlag = 0;
}

void ClearTripDataToEeprom()
{
	int TripBaseAddr = 0;
	int TripDataPoint;
	int TripPointCount;
	char str[30];
	UNION32 u32data;

	EepromSaveFlag = 1;

	u32data.dword = 0.0;

	load_sci_tx_mail_box("WAIT FOR CLEAR DATA!");

	for(TripPointCount = 0; TripPointCount < 10; TripPointCount++)
	{

		I2CA_WriteData(ADDR_24LC32, EPROM_ADDR_TRIP_POINT, TripDataPoint);

		TripBaseAddr = TRIP_BACKUP_ADDR + TripDataPoint * 100;
		write_code_2_eeprom( TripBaseAddr+ 0, u32data);
		write_code_2_eeprom( TripBaseAddr+ 4, u32data);
		write_code_2_eeprom( TripBaseAddr+ 8, u32data);
		write_code_2_eeprom( TripBaseAddr+ 12, u32data);
		write_code_2_eeprom( TripBaseAddr+16, u32data);
		strncpy(str," NO TRIP DATA       ",20);
		WriteTripString( TripBaseAddr+20,str);

		strncpy(str,"2010:01:01  00:00:00",20);
		WriteTripString( TripBaseAddr+40,str);

		strncpy(str,"2010:01:01  00:00:00",20);
		WriteTripString( TripBaseAddr+60,str);
	}
	EepromSaveFlag = 0;
	load_sci_tx_mail_box("CLEAR COMPLETE !!   ");
}

//------------------------------
// End
//------------------------------

