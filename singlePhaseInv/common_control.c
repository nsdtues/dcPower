// udd world 
// common_control.c
// 2009.08.30
//  udd vector inverter

#include	<header.h>
#include	<extern.h>

#define max_I_ratio    1.5
#define over_current_level    2.0

void common_variable_init()
{

	Ts = 1.0 / igbt_pwm_freq;	// pwm switching frequency
	inv_Ts = igbt_pwm_freq;

	Freq_rat = codeMotorRateHz;
    inv_Freq_rat=1.0/Freq_rat;
    inv_motor_rate_hz = 1.0 / codeMotorRateHz; //   csk_check 2009.10.30.

    we_rat=PI_2*codeMotorRateHz;
    wr_rat=PI_2*codeMotorPole * codeMotorRateRpm/120.0;         // rpm -> rad/sec
    wm_rat=wr_rat*(2.0/codeMotorPole);

	Vs_rat = sqrt(2.0)/sqrt(3.0) * codeMotorRateVolt;			// �������� ��ũ ��

	Is_rat=sqrt(2.0) * codeMotorRateCurrent;
    inv_Is_rat=1.0/Is_rat;
    Is_max = Is_rat * max_I_ratio;
    OverCurLimit = Is_max * 2.0;            // added 2009.11.01  _debug

    Te_rat=codeMotorRatePower/wm_rat;
    inv_Te_rat=1.0/Te_rat;

    Fs_rat=Vs_rat/we_rat;
    Kt=(3.0/2.0)*(codeMotorPole/2.0);
    inv_Kt=1.0/Kt;
    P_pair=(codeMotorPole/2.0);
    inv_P_pair=1.0/P_pair;
    rpm_Coeff=60.0*inv_P_pair/PI_2;

    S_rat=(we_rat-wr_rat)/we_rat;
    S_lin=(codeMotorPole/PI)*(S_rat*Freq_rat)/Te_rat;               // ==> V/f ���� : ���� ����
    Freq_slip_rat=S_rat*Freq_rat;

	// PreChargeLevel = 0.85*(1.35*motor_rate_volt);	// ���� ������ 85%
	C_ce_nF=(3.5-0.8)/(1000.0-100.0)*(2.0*Is_rat-100.0)+0.8;	// 1000A -> 3.5nF, 100A -> 0.8nF
	C_ce=1.0e-9*C_ce_nF;
	inv_C_ce=1.0/C_ce;	

//-----------------------

	Freq_ref=0.0;
	wr_ref=0.0;											// �ӵ� ��� -> 0	
	rpm_ref=0.0;				

//------
// reference
	reference_in=0.0;
	
	we_in=0.0;
	we=0.0;
	we0=0.0;

	wr_m0=0.0;
	wr_m=0.0;				// ���� �ӵ��� ���͸� �ʱⰪ = ���� �ӵ� 
	wr=0.0;

	wr_ref=0.0;
	wr_err=0.0;
	wr_ErrInt=0.0;				// �ӵ�������� ���з� 
	w_sl=0.0;
	w_sl0=0.0;

	frequency=0.0;
	rpm=0.0;
	rpm_m=0.0;
	theta_m=0.0;
	rpm_ref=0.0;
	rpm_err=0.0;

	theta=0.0;
	SinTheta=0.0;
	CosTheta=1.0;
	CosDeltaTheta=0.0;
	SinDeltaTheta=1.0;

	// ����
	Is_dq[ds]=Is_dq[qs]=0.0;
	Is_mag=0.0;
	Is_mag_rms=0.0;
	sgn_Is[as]=sgn_Is[bs]=sgn_Is[cs]=0.0;
	
	Is_DQ[DS]=Is_DQ[QS]=0.0;
	Is_DQ_max[DS]=Is_DQ_max[QS]=0.0;
	Is_DQ_ref[DS]=Is_DQ_ref[QS]=0.0;
	
	prev_I_QS=0.0;
	Is_DQ_ErrInt[DS]=Is_DQ_ErrInt[QS]=0.0;			// ����������� ���з�
	
	// ����
	Vs_max=0.0;	
	Vs_abc[as]=Vs_abc[bs]=Vs_abc[cs]=0.0;
	Vs_abc_ref[as]=Vs_abc_ref[bs]=Vs_abc_ref[cs]=0.0;
	Vs_dq_ref[ds]=Vs_dq_ref[qs]=0.0;
	Vs_dq[ds]=Vs_dq[qs]=0.0;
	Vo=0.0;			
	Us_dq[ds]=Us_dq[qs]=0.0;
	Vs_DQ[DS]=Vs_DQ[QS]=0.0;
	Vs_DQ_max[DS]=Vs_DQ_max[QS]=0.0;
	Vs_DQ_ref[DS]=Vs_DQ_ref[QS]=0.0;
	Vs_DQ_comp[DS]=Vs_DQ_comp[QS]=0.0;
	Vs_max_FW=0.0;
	Vs_DQ_ref_P[DS]=Vs_DQ_ref_P[QS]=0.0;
	Vs_DQ_ref_PI[DS]=Vs_DQ_ref_PI[QS]=0.0;
	
	// ��ũ
	Te_max=0.0;
	Te_ref=0.0;
	Te=0.0;
	
	// �ڼ�
	Fs_ref0=0.0;
	Fs_ref=0.0;
	inv_Fs_ref=0.0;
	Fs_dq[ds]=Fs_dq[qs]=0.0;
	Fs=0.0;
	inv_Fs=0.0;
	Fr_ref=0.0;
	Fr_ref0=0.0;
	inv_Fr_ref=0.0;
	Fr=0.0;
	inv_Fr=0.0;
	Fr_Err=0.0;
	Fr_ErrInt=0.0;

	Vs_ref=0.0;
	Freq_ref=0.0;
	Freq_slip=0.0;
	Freq_out=0.0;
	Slip=0.0;
	Power_core=0.0;
	Power_core_rat=0.0;
	Power_gap=0.0;
	Vs_IR_comp=0.0;
	del_Vs_comp=0.0;

	// V/F Control Parameter
	VF_DeadTimeGain=1.0;
	VF_ExcitationTime=2.0;					// DC���� �ð� = 0.5��
	VF_Fs_Coeff=1.0;
	VF_Freq_TrqBoost=1.5;
	VF_Vs_Coeff_TrqBoost=1.5*(VF_Freq_TrqBoost / codeMotorRateHz );
	VF_Rs_ThermalCoeff=1.05;			
	VF_IR_Comp_FilterPole=100.0;		
	VF_Slip_Comp_FilterPole=20.0;	
	VF_Rs=0.0;								// ����Ʈ ���� �� --> 0
	//---------------------------
	gfRunTime = 0.0;
}
// end of file

