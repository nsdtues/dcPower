#ifndef		__CODE_PROC_H_
#define		__CODE_PROC_H_	

// #define SWITCH_FREQ			2500	// 090920
// #define SWITCH_FREQ			1750	// 090920

#define CODE_I_out_ref					0
#define CODE_Vout						1
#define CODE_VoutLimit					3
#define CODE_ovpTime					4

#define CODE_PwmPhaseInit				6
#define CODE_InitTime					7
#define CODE_ctrl_mode					9

#define CODE_SetPulseNumber				10
#define CODE_testPwmPhase				11
#define CODE_set_Vdc_on					12
#define CODE_Vdc_set_value				13

#define CODE_rDeadTime					20
#define CODE_allDeadTime				21
#define CODE_END                        22

//--- end of code address


struct CODE_INFO_DEFINE {
	int		type;	
	int	  	open_level	;
	float	code_min ;
	float	code_max ;
	float 	code_default;
	float	code_value;
	char   disp[40];
};
typedef struct CODE_INFO_DEFINE CODE_INFO;

#endif
