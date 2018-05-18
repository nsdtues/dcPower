#include	<header.h>
#include	<extern.h>

void monitorPrint( char * str, float argIn)
{
    float fTemp1;
    int temp;

    if(argIn > 999.9){
        str[0] = str[1] = str[2] = str[4] = '9';
        str[3] = '.';
    }
    else if(argIn < 0){
        str[0] = str[1] = str[2] = str[4] = ' ';
        str[3] = '.'; str[0] = '-';
    }
    else{
        if( argIn < 0.0) fTemp1 = 0.0;
        else  fTemp1 = floor(argIn*10 +0.5);
        temp = (int)( fTemp1 );
        str[4] = temp % 10 + '0';
        str[3] = '.';
        str[2] = ( temp % 100 )  / 10 + '0';
        str[1] = (( temp % 1000) / 100) + '0';
        str[0] = ( temp / 1000 ) + '0';
        if(str[0] == '0'){
            str[0] =' ';
            if(str[1]=='0') str[1] = ' ';
        }
    }
    str[5]=',';
}

void monitor_proc()     // need_edit
{
    int i,j,k,temp;
    Uint32 RunTimeMsec=0 ;
    char str[12]={0};
    static unsigned long StartTimeMsec = 0 ;

    switch(gMachineState){
        case STATE_POWER_ON:    strncpy(MonitorMsg,"[POWON]",7); break;
        case STATE_READY:       strncpy(MonitorMsg,"[READY]",7); break;
        case STATE_RUN:         strncpy(MonitorMsg,"[RUN ] ",7); break;
        case STATE_INIT_RUN:    strncpy(MonitorMsg,"[INIT] ",7); break;
        case STATE_GO_STOP:     strncpy(MonitorMsg,"[GOSTP]",7); break;
        case STATE_TRIP:
            strncpy(MonitorMsg,"[TRIP] ",7);
            temp = TripInfoNow.CODE;
            monitOut[32] = ( temp / 100 ) + '0';
            monitOut[33] = ( (temp % 100)/ 10 ) + '0';
            monitOut[34] = ( temp % 10 ) + '0';
            monitOut[35] = ',';
            strncpy(monitOut + 36,TripInfoNow.MSG,20);
            break;

        default:                strncpy(MonitorMsg,"[SYERR]",7); break;
    }

    strncpy(monitOut,MonitorMsg,7);
    monitor[0] = I_out = 613.2;
    monitor[1] = Vout = 8.23;
    monitor[2] = Power_out = I_out * Vout;
    monitor[2] = monitor[2]/1000;
    monitor[3] = Vdc=512.5;
    monitOut[7]=',';
    for( i = 0; i < 4 ; i ++ ){
        monitorPrint( str, monitor[i]);
        k = 6 * i + 8 ;
        for( j = 0 ; j < 6 ; j++) monitOut[j+k] = str[j];
    }
    monitOut[56] = 0;
}

void GetInputMark(char * str)
{
	strncpy(str,"xxxx",20);			// debug
}
//--- End of file.
