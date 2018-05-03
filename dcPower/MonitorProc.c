#include	<header.h>
#include	<extern.h>
void monitorPrint( char * strIn , char * charOut, double argIn)
{
    char * str;
    char str1[20]={0};

    double dtemp1;
    int temp;

    str = charOut;

    * str   = * strIn;
    * (str+1) = * (strIn +1);
    * (str+2) = * (strIn +2);

    * (str+3) = ' ';
    * (str+4) = * (str+5) = *(str+6) = '9';

    * (str+7) =  * (strIn + 5);
    * (str+8) =  * (strIn + 6);
    * (str+9) =  * (strIn + 7);
    * (str+10) = 0;
    * (str+11) = 0;


    if( argIn < 0.0) dtemp1 = 0.0;
    else  dtemp1 = floor(argIn*10 +0.5);

    temp = (int)( dtemp1 );

    if( temp < 10000){

        * (str1+4) = temp % 10 + '0';
        * (str1+3) = '.';
        * (str1+2) = ( temp % 100 )  / 10 + '0';
        * (str1+1) = (( temp % 1000) / 100) + '0';
        * (str1+0) = ( temp / 1000 ) + '0';

        if( str1[0]== '0' ){
            * (str+3) = *(str1+1);
            * (str+4) = *(str1+2);
            * (str+5) = *(str1+3);
            * (str+6) = *(str1+4);
        }
        else{
            * (str+3) = *(str1+0);
            * (str+4) = *(str1+1);
            * (str+5) = *(str1+2);
            * (str+6) = ' ';
        }
    }
}

void monitor_proc()     // need_edit
{
    int temp;
    Uint32 RunTimeMsec=0 ;
    static unsigned long StartTimeMsec = 0 ;

    RunTimeMsec = ulGetTime_mSec( StartTimeMsec);

    if(RunTimeMsec < 500) return;   // 500msec ¸¶´Ù ÇÑ¹ø¾¿

    StartTimeMsec = ulGetNow_mSec( );

    if( gMachineState == STATE_POWER_ON ){

//      GetTimeAndDateStr(gStr1);   gStr1[20] =0;
//      load_sci_tx_mail_box(gStr1); delay_msecs(20);

        temp = (int)(floor(Vdc +0.5));
        snprintf( gStr1,10," VDC =%4d",temp);
        load_sci_tx_mail_box(gStr1);delay_msecs(20);
    }
}

void GetInputMark(char * str)
{
	strncpy(str,"xxxx",20);			// debug

/*
	char str2[30]= "TEST";
	str2[0] = 'I';
	str2[1] = 'N';
	str2[2] = 'P';
	str2[3] = 'U';
	str2[4] = 'T';
	str2[5] = '[';

	if(terminal_input_state & 0x0001 ) 	str2[6] = 'I';
	else								str2[6] = 'O';

	if(terminal_input_state & 0x0002 ) 	str2[7] = 'I';
	else								str2[7] = 'O';

	if(terminal_input_state & 0x0004 ) 	str2[8] = 'I';
	else								str2[8] = 'O';

	if(terminal_input_state & 0x0008 ) 	str2[9] = 'I';
	else								str2[9] = 'O';

	if(terminal_input_state & 0x0010 ) 	str2[10] = 'I';
	else								str2[10] = 'O';

	if(terminal_input_state & 0x0020 ) 	str2[11] = 'I';
	else								str2[11] = 'O';

	if(terminal_input_state & 0x0040 ) 	str2[12] = 'I';
	else								str2[12] = 'O';

	if(terminal_input_state & 0x0080 ) 	str2[13] = 'I';
	else								str2[13] = 'O';

	str2[18] = ']';
	str2[19] = '_'; 
	str2[20] = 0; 
	strncpy(str,str2,20);
*/
}

//==================================
// End of file.
//==================================

