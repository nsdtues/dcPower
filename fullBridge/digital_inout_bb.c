#include	<header.h>
#include	<extern.h>

void digital_input_proc(int * cmd, double * ref )
{
	unsigned int xbus_in,temp;

	xbus_in = ZONE0_BUF[0x0050];   // debug

	temp = xbus_in;

	if( (temp & 0x0001) == 0 ){
	 	* cmd = CMD_START; //FWD LOW
	}
	else { * cmd = CMD_STOP; * ref = 0.0;}

	if((gMachineState==STATE_TRIP)&&(( temp & 0x0008) == 0)){
		* cmd = CMD_RESET;
		* ref = 0.0;
	}
}

//---------------------------------
// end of file
//----------------------------------
