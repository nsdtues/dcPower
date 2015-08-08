#include	<header.h>
#include	<extern.h>

void ramp_proc( double SetRef,double * pOutRef)
{
	static unsigned long ulCount;

	double OutRef;
	double accel_time,decel_time;

	double accel_time1,decel_time1;
	double accel_time2,decel_time2;
	double digital_speed2;

	digital_speed2 = code_speed2;
	
	accel_time1 = code_accel_time1;
	accel_time2 = code_accel_time2;
	decel_time1 = code_decel_time1;
	decel_time2 = code_decel_time2;

	OutRef = * pOutRef;

 	if( ulGetNow_mSec( )== ulCount ) return;
	
	ulCount = ulGetNow_mSec( );

	if(accel_time1 <= 0.0) accel_time1 = 0.01;			// debug
	if(decel_time1 <= 0.0) decel_time1 = 0.01;			// debug
	if(accel_time2 <= 0.01) accel_time2 = accel_time1;	// debug
	if(decel_time2 <= 0.01) decel_time2 = decel_time1;	// debug

	if( fabs(OutRef) <= digital_speed2 )	{ accel_time = accel_time1; decel_time = decel_time1; }
	else 								{ accel_time = accel_time2; decel_time = decel_time2; }

	if (SetRef > OutRef){ 
		OutRef += 0.001 / accel_time; 
		if( OutRef > SetRef ) OutRef = SetRef;
	}
	else if (SetRef < OutRef){
		OutRef -=  0.001 / decel_time ;
		if( OutRef < SetRef ) OutRef = SetRef;
	}
	* pOutRef = OutRef; 
}	
//----------------------------------
// End of File
//----------------------------------
