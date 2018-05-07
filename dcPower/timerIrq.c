//	Project Name 	: dcPower
//	File Name	 	: timerIrq.c
//  Start 			: 2018.0504
#include	<header.h>
#include	<extern.h>

interrupt void cpu_timer0_isr(void)
{
    ServiceDog();
    CpuTimer0.InterruptCount++;
    if( ref_time < 1.0e+30) ref_time += 0.001;
    if( gfRunTime < 1.0e+30 ) gfRunTime += 0.001;
    GpioDataRegs.GPATOGGLE.bit.GPIO7 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
