#include	<header.h>
#include	<extern.h>

#define DAC_I_U				0
#define DAC_I_V				1

#define DAC_Vdc				5
#define DAC_reference_in	6
#define DAC_reference_out	7

#define DAC_Is_mag			15
#define DAC_Is_mag_rms		16


#define DAC_Vo				50


// 회전수 출력 
void set_dac_point()
{
	dac_point[DAC_reference_in]= & reference_in;
	dac_point[DAC_reference_out]= & reference_out;

// 전류 
	dac_point[DAC_Is_mag]= & Is_mag;
	dac_point[DAC_Is_mag_rms]= & Is_mag_rms;
//	dac_point[DAC_LPF_Ia_in]= & LPF_Ia_in;

	dac_point[DAC_Vdc]= & Vdc;	

// 전류
}


