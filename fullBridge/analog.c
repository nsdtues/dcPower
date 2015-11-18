//
// adc.c
// 2012.04.12
// Eunwho Power Electronics
// by Cheoung Soon Gil

#include	<header.h>
#include	<extern.h>

void InitAdc()
{
	AdcRegs.ADCMAXCONV.all          = 8;     // 16 channel  
	AdcRegs.ADCTRL1.bit.SUSMOD       = 0;
//   AdcRegs.ADCTRL1.bit.ACQ_PS       = 3;		// 68usec
	AdcRegs.ADCTRL1.bit.ACQ_PS       = 1;		// 41usec adc delay time

	AdcRegs.ADCTRL1.bit.CPS         = 1;
	AdcRegs.ADCTRL1.bit.CONT_RUN    = 0;
	AdcRegs.ADCTRL1.bit.SEQ_OVRD    = 0;
	AdcRegs.ADCTRL1.bit.SEQ_CASC    = 1;   // Enable SOCA from ePWM to start SEQ1

	AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0;    // I_U
	AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 1;    // I_V 

	AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 3;    // I_R
	AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 4;    // I_S

	AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 6;    // Ana_CMD_A

	AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 9;    // Vac-V
	AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 12;    // Vac_S
	AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 13;    // Vac_T

	AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 14;    // Vdc

	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;  // Enable SEQ1 interrupt (every EOS)
	AdcRegs.ADCTRL3.all = 0x00FE;  // Power up bandgap/reference/ADC circuits
}

#define adc_const         0.00048828125   // 1/2048

double lpfI_out;
interrupt void  Adc_Isr(void)
{
//	double ftemp1;
	double analog_ref_a0;
	double Vout0;

#if TEST_ADC_CENTER
   J8_1_SET;
#endif

   adc_result[0] = (int)(AdcRegs.ADCRESULT0 >> 4);    // I_pri
   adc_result[1] = (int)(AdcRegs.ADCRESULT1 >> 4);    // I_Out

//   adc_result[2] = (int)(AdcRegs.ADCRESULT2 >> 4);    // AGND
   adc_result[2] = 4445;

   adc_result[3] = (int)(AdcRegs.ADCRESULT2 >> 4);    // Vout
   adc_result[4] = (int)(AdcRegs.ADCRESULT3 >> 4);

//   adc_result[5] = (int)(AdcRegs.ADCRESULT5 >> 4);    // AGND
   adc_result[5] = 4445;

   adc_result[6] = (int)(AdcRegs.ADCRESULT4 >> 4);    // ANA_CMD_A
//   adc_result[7] = (int)(AdcRegs.ADCRESULT7 >> 4);    // ANA_CMD_B
   adc_result[7] = 4445;

//   adc_result[8] = (int)(AdcRegs.ADCRESULT8 >> 4);    // Vac-U
   adc_result[8] = 4445;
   adc_result[9] = (int)(AdcRegs.ADCRESULT5 >> 4);    // Vac-V

//   adc_result[10]= (int)(AdcRegs.ADCRESULT10 >> 4);    // Vac-W 
//   adc_result[11]= (int)(AdcRegs.ADCRESULT11 >> 4);    // Vac_R
   adc_result[10] = 4445;
   adc_result[11] = 4445;

   adc_result[12]= (int)(AdcRegs.ADCRESULT6 >> 4);    // Vac_S
   adc_result[13]= (int)(AdcRegs.ADCRESULT7 >> 4);    // Vac_T
   adc_result[14]= (int)(AdcRegs.ADCRESULT8 >> 4);    // Vdc
// adc_result[15]= (int)(AdcRegs.ADCRESULT15 >> 4);    // Vdc
   adc_result[15]= 4445;


	adcI_pri = adc_result[0];
	adcI_out = adc_result[1];


	nativeI_pri =  - codeIValue1st * (double)(  adc_result[0] -codeIAdcOffset1st) * adc_const * codeISpan1st;
	nativeI_out =  - codeIValueOut * (double)(  adc_result[1] -codeIAdcOffsetOut) * adc_const * codeISpanOut;
	LPF1( Ts,20.0, nativeI_out, &I_out);

	//Vout = VoutScale * phaseShiftRatio  + VoutOffset ;
	Vdc = VdcScale * (double) adc_result[14] + VdcOffset ;  

	Vout0 = VoutScale * (double) adc_result[3] + VoutOffset ;

	LPF1( Ts,20.0, Vout0, &Vout);


	if( gMachineState == STATE_READY){ I_out = 0.0;	Vout = 0.0;}
	if( code_set_Vdc_on ) Vdc = code_Vdc_set_value;	// 2012.11.20

	Power_out = Vout * I_out ;


	analog_ref_a0 = - adc_const * (adc_result[6] - code_AdcOffsetCh6);
	LPF1( Ts,20.0, analog_ref_a0 , &analog_ref_a);

	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;       // Clear INT SEQ1 bit
	AdcRegs.ADCST.bit.INT_SEQ2_CLR = 1;       // Clear INT SEQ1 bit
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE

#if TEST_ADC_CENTER
   J8_1_CLEAR;
#endif
}

void analog_cmd_proc(double * ana_refer)
{
	* ana_refer = analog_ref_a * analog_cmd_in_span1 - analog_cmd_in_zero1;
}

/*
void analog_input_proc( double * referenc)
{
	* referenc = analog_ref_a * analog_cmd_in_span1 - analog_cmd_in_zero1;
}

void analog_input_proc_b( double * referenc)
{
	* referenc = analog_ref_b * analog_cmd_in_span2 - analog_cmd_in_zero2;
}
*/

void analog_out_proc( )
{
}

// end of file

