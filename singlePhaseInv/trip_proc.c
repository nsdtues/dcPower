//
// filename 	: trip_proc.c 
// projectname 	: F28035 inverter
// 					PCB --> pag.ls.0503  
// data			; start 2012.11.28 ~		
//					by cheoung soon gil  
// 
#include	<header.h>
#include	<extern.h>

int CheckOverCurrent( )
{

	if(( protect_reg.bit.OVER_I_ADC)&&( abs(adcIuPhase) > 3000)){
		return ERR_OVER_CURRENT_U_PHASE;
	}
	
	if(( protect_reg.bit.OVER_I_ADC)&&( abs(adcIuPhase) < 1000)){
		return ERR_OVER_CURRENT_U_PHASE;
	}

	if(( protect_reg.bit.OVER_I_ADC)&&( abs(adcIvPhase) > 3000)){
		return ERR_OVER_CURRENT_V_PHASE;
	}

	if(( protect_reg.bit.OVER_I_ADC)&&( abs(adcIvPhase) < 1000)){
		return ERR_OVER_CURRENT_V_PHASE;
	}

	return 	0; 
}

//-----------------------------------------------
//  ������ ������ ��ȣ 
//-----------------------------------------------
#define CODE_OC_level 		301
double code_over_volt_set = 350.0;

int CheckOverVolt( )
{
	static int OverVoltCount = 0;

	if( protect_reg.bit.OVER_VOLT == 0 ) return 0;

	if (Vdc > code_over_volt_set ) OverVoltCount++;
	else if( OverVoltCount > 0) OverVoltCount --;

	if (OverVoltCount > 5 )
	{
		OverVoltCount = 6;

		return CODE_OC_level;
	}
	return 0;
}

//-----------------------------------------------
//  ������ ��ȣ 
//-----------------------------------------------
#define code_under_volt_set     180.0

int CheckUndeVolt( )
{
	static int UnderVoltCount = 0;

	if( protect_reg.bit.UNVER_VOLT == 0 ) return 0;

	if (Vdc < code_under_volt_set) 	UnderVoltCount++;
	else if( UnderVoltCount > 0) 	UnderVoltCount--;

	if (UnderVoltCount > 5 )
	{
		UnderVoltCount = 6;

		return CODE_under_volt_set;
	}
	return 0;
}

int CheckIGBTFault( )
{
	if( PWM_FAULT == 0)	return ERR_PWM;
	return 0;
}


int CheckOverHeat( )
{
	static int OverHeatCount = 0;

	if( protect_reg.bit.OVER_HEAT == 0 ) return 0;


	if( adcIgbtTemperature < 1000 )					OverHeatCount ++;
	else if( OverHeatCount > 0) 	OverHeatCount--;

	if( OverHeatCount > 10 )	// debug// Low --> High
	{
		OverHeatCount = 11;
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
	return TripCode;
}

//-----------------------------------
// Ʈ�� �߻� �����̸� On �ϰ� 
// Reset�� ��ٸ���. 
//-----------------------------------
// Trip Message�� Ʈ���� �߻��� ������ ������ �Ѵ�. 
//
void trip_recording(int trip_code,double trip_data,char * st)
{
	if(gRunFlag)	gTripSaveFlag = 1;
	else			gTripSaveFlag = 0;

	TripInfoNow.CODE	= trip_code;
	TripInfoNow.DATA	= trip_data;
	strncpy( TripInfoNow.MSG,st,20) ;

	gMachineState 		= STATE_TRIP;
	TripInfoNow.CURRENT	= Is_mag_rms;
	TripInfoNow.VDC 	= Vdc;
//	TripInfoNow.HZ 		= Freq_out;
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

	if( Point == 0){

//		* TripData = &TripInfoNow;
		TripData->CURRENT 	= TripInfoNow.CURRENT;
		TripData->DATA 		= TripInfoNow.DATA;
		TripData->HZ 		= TripInfoNow.HZ;
		TripData->CODE 		= TripInfoNow.CODE;
		TripData->VDC 		= TripInfoNow.VDC;
		strncpy(TripData->MSG  ,TripInfoNow.MSG,20);
		strncpy(TripData->TIME ,TripInfoNow.TIME,20);
		return ;
	}

	I2CA_ReadData(ADDR_24LC32,EPROM_ADDR_TRIP_POINT,&TripDataPoint);

// erased  
	if( ( 1 > Point ) || ( Point > 10) || (TripDataPoint == 0x00ff))
	{
		TripData->CURRENT = 0.0;
		TripData->DATA = 0.0;
		TripData->HZ = 0.0;
		TripData->CODE = 0.0;
		TripData->VDC = 0.0;
		if( TripDataPoint == 0x00ff){
			strncpy(TripData->MSG  ," NO TRIP DATA       ",20);
			strncpy(TripData->TIME ,"2008:07:24  00:57:00",20);
		}
		else {
			strncpy(TripData->MSG  ," Invalid Trip Code  ",20);
			strncpy(TripData->TIME ,"2008:07:24  00:57:00",20);
		}
		return ;
	}

	if( (TripDataPoint<1)||(TripDataPoint>10)){
		I2CA_WriteData(ADDR_24LC32, EPROM_ADDR_TRIP_POINT,1);
		TripDataPoint = 1;
	}
	EepromSaveFlag = 1;
// ����� �� �����͸� ���Ѵ�. 
	iTemp = TripDataPoint - Point + 1;		// iPoint = 1~10;

	if( iTemp <= 0 ) iTemp += 10;

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
	TripData->HZ =  u32data.dword;

	// VDC
	read_eprom_data( TripBaseAddr+16, & u32data);
	TripData->VDC =  u32data.dword;

	// Time
	ReadTripString( TripBaseAddr+20,str);
	strncpy(TripData->TIME,str,20);

	ReadTripString( TripBaseAddr+40,str);
	strncpy(TripData->MSG,str,20);

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

	if( TripDataPoint == 0x00FF) TripDataPoint = 1;
	else TripDataPoint ++;

	if( TripDataPoint > 10 ) TripDataPoint = 1;
	
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

// HZ
	u32data.dword = TripInfoNow.HZ;
	write_code_2_eeprom( TripBaseAddr+ 12, u32data);

// VDC
	u32data.dword = TripInfoNow.VDC;
	write_code_2_eeprom( TripBaseAddr+16, u32data);

// Time
	strncpy(str,TripInfoNow.TIME,20);
	WriteTripString( TripBaseAddr+20,str);

// Msg
	strncpy(str,TripInfoNow.MSG,20);
	WriteTripString( TripBaseAddr+40,str);

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

	for(TripPointCount = 1; TripPointCount <= 10; TripPointCount++)
	{
		I2CA_ReadData(ADDR_24LC32,EPROM_ADDR_TRIP_POINT,&TripDataPoint);

		if( TripDataPoint == 0x00FF) TripDataPoint = 1;
		else TripDataPoint ++;
		if( TripDataPoint > 10 ) TripDataPoint = 1;
	
		I2CA_WriteData(ADDR_24LC32, EPROM_ADDR_TRIP_POINT, TripDataPoint);
		TripBaseAddr = TRIP_BACKUP_ADDR + TripDataPoint * 100;
		write_code_2_eeprom( TripBaseAddr+ 0, u32data);
		write_code_2_eeprom( TripBaseAddr+ 4, u32data);
		write_code_2_eeprom( TripBaseAddr+ 8, u32data);
		write_code_2_eeprom( TripBaseAddr+ 12, u32data);
		write_code_2_eeprom( TripBaseAddr+16, u32data);
		strncpy(str,"2010:01:01  00:00:00",20);
		WriteTripString( TripBaseAddr+20,str);
		strncpy(str," NO TRIP DATA       ",20);
		WriteTripString( TripBaseAddr+40,str);
	}
	EepromSaveFlag = 0;
	load_sci_tx_mail_box("CLEAR COMPLETE !!   ");
}

void tripProc()
{

	GATE_DRIVER_CLEAR;
	MAIN_CHARGE_OFF;
	ePwmPortOff();

	/*
	while( RESET_INPUT==0)Nop();
	delay_msecs(50);
	while( RESET_INPUT)Nop();
	delay_msecs(50);
	while( RESET_INPUT==0)Nop();
*/
}


//------------------------------
// End
//------------------------------
