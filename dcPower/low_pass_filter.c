//
// project	: back to back inverter 
// pcb		: dfig_dsp.0104.BK.sch ~pcb
// work dir : d:\dspBack2back\InvCon\src
// date		: 2013.0111 Friday
// 			by Soonkil Cheoung. CEO Eunwho Power Electronics

#include	<header.h>
#include	<extern.h>

#define LPF_ZETA 0.707

//--- DC link Voltage Low Pass
float LPF_Vdc_cutoff_freq = 1000.0;
float LPF_Vdc_in[3];
float LPF_Vdc_out[3];
float LPF_Vdc_K[4];

//--- AC Current Low Pass
float LPF_I_uvw_cutoff_freq = 4000.0;
float LPF_I_u_in[3], LPF_I_v_in[3], LPF_I_w_in[3];
float LPF_I_u_out[3], LPF_I_v_out[3], LPF_I_w_out[3];
float LPF_I_u_K[4], LPF_I_v_K[4],LPF_I_w_K[4];

// end of define LPF vari

void LPF_2nd_INIT( float cutoff_freq, float T_sample, float *x, float *y, float *k)
{	
	float omega_n;

	omega_n = 2.0 * PI * cutoff_freq ;

	* x = * (x + 1) = *(x + 2 ) = 0.0 ;
	* y = * (y + 1) = *(y +2) = 0.0 ;

	* k = 1./ (4.+4.* LPF_ZETA * omega_n * T_sample + omega_n * omega_n * T_sample * T_sample);
	*(k+1) = 8.0 - 2.0 * omega_n * omega_n * T_sample * T_sample;
	*(k+2) = 4.0 * LPF_ZETA * omega_n * T_sample - omega_n * omega_n * T_sample * T_sample -4.0;
	*(k+3) = omega_n * omega_n * T_sample * T_sample;
}

void LPF_2nd(float * x,float * y, float * K)
{
	int i;
	float k[4];

	for ( i = 0 ; i< 4; i++)	k[i] = *(K + i);
    
    *y = k[0]*( k[1]*( *(y+1)) + k[2]*( *(y+2)) + k[3]*( (*x) + 2.*(*(x+1)) + (*(x+2))) );

	*(y+2) = *(y+1); 
	*(y+1) = * y; 	
	*(x+2) = *(x+1);
	*(x+1) = * x;
}

void Init_Filters( )
{
   // DC-Link Voltage
   LPF_2nd_INIT( LPF_Vdc_cutoff_freq,Ts, LPF_Vdc_in, LPF_Vdc_out, LPF_Vdc_K);

   // 3-phase phase output current
   LPF_2nd_INIT( LPF_I_uvw_cutoff_freq, Ts, LPF_I_u_in, LPF_I_u_out, LPF_I_u_K);
   LPF_2nd_INIT( LPF_I_uvw_cutoff_freq, Ts, LPF_I_v_in, LPF_I_v_out, LPF_I_v_K);
}
// end of low_pass_filter
