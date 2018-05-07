//
// analog.c  project : dcPower
// Eunwho Power Electronics by Cheoung Soon Gil
#include	<header.h>
#include	<extern.h>

void ADC_SOC_CNF( )
{
    extern void DSP28x_usDelay(Uint32 Count);

    EALLOW;
    AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1; // Enable non-overlap mode
    AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    AdcRegs.INTSEL1N2.bit.INT1E = 1;        // enable ADC interrupt 1
    AdcRegs.INTSEL1N2.bit.INT1CONT = 0; // set ADCInterrupt 1 to auto clr

    AdcRegs.INTSEL1N2.bit.INT1SEL = 1;      // IntChSel causes ADCInterrupt 1

    AdcRegs.ADCSOC0CTL.bit.CHSEL= 0;        // I_u
    AdcRegs.ADCSOC1CTL.bit.CHSEL= 1;        // I_v
    AdcRegs.ADCSOC2CTL.bit.CHSEL= 8;        // Vdc
    AdcRegs.ADCSOC3CTL.bit.CHSEL= 9;        // V_out  IGBT_Temp

    AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 5;
    AdcRegs.ADCSOC1CTL.bit.TRIGSEL = 5;
    AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 5;
    AdcRegs.ADCSOC3CTL.bit.TRIGSEL = 5;
    AdcRegs.ADCSOC4CTL.bit.TRIGSEL = 5;
    AdcRegs.ADCSOC5CTL.bit.TRIGSEL = 5;

    AdcRegs.ADCSOC0CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC1CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC2CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC3CTL.bit.ACQPS = 6;
//    AdcRegs.ADCSAMPLEMODE.all = 0;      // Simultaneous sample mode
    EDIS;
}
#define adcIuOffset     2585
#define adcIvOffset     2578
//--- 전류의 계산 : 66mV / A  :  3.3V -> 50A, 1 count = 50 / 4096 = 0.012207
#define I_RATIO         0.012207
__interrupt void adcIsr(void)
{
//    int temp;

    adc_result[0] = adcI_out   = AdcResult.ADCRESULT0;
    adc_result[1] = adcI_pri   = AdcResult.ADCRESULT1;
//    adc_result[2] = adcVdc  = AdcResult.ADCRESULT2;
//    adc_result[3] = adcVout = AdcResult.ADCRESULT3;

    Vout = VoutScale * phaseShiftRatio  + VoutOffset ;

//    nativeI_out =  - codeIValueOut * (double)(  adc_result[0] -codeIAdcOffsetOut) * adc_const * codeISpanOut;
//    nativeI_pri =  - codeIValue1st * (double)(  adc_result[1] -codeIAdcOffset1st) * adc_const * codeISpan1st;

    Vdc = VdcScale * (float) adc_result[14] + VdcOffset ;

//    LPF1( Ts,20.0, (double)(adcI_out), & lpfI_out);

    if( gMachineState == STATE_READY){ I_out = 0.0; Vout = 0.0;}
    if( code_set_Vdc_on ) Vdc = code_Vdc_set_value; // 2012.11.20

    Power_out = Vout * I_out ;

    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;       //Clear ADCINT1 flag reinitialize for next SOC
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
    return;
}

void analog_input_proc( float * referenc)
{
//	* referenc = analog_ref_a * analog_cmd_in_span1 - analog_cmd_in_zero1;
}

void analog_out_proc( )
{
}

int check_sensor_trip()
{
	int TripCode;

	Nop();

	if( ( TripCode = CheckOverCurrent()) != 0 ) return TripCode ;	// debug
	if( ( TripCode = CheckOverVolt()   ) != 0 ) return TripCode ;
	if( ( TripCode = CheckUndeVolt()   ) != 0 ) return TripCode ;	//
	return 0;
}
	
// end of file

