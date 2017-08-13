################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../28065_RAM_lnk_jsk.cmd \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/cmd/F2806x_Headers_nonBIOS.cmd 

ASM_SRCS += \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_CodeStartBranch.asm \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_usDelay.asm 

C_SRCS += \
../Core_Speed_Calc.c \
../DS1307.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_Adc.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_CpuTimers.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_DefaultIsr.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_EPwm.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/source/F2806x_GlobalVariableDefs.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_PieCtrl.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_PieVect.c \
/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_SysCtrl.c \
../I2C_eeprom.c \
../MonitorProc.c \
../ParameterSet.c \
../RefFunc.c \
../Set_Par.c \
../analog.c \
../code_group_all.c \
../code_proc.c \
../common_control.c \
../common_module.c \
../digital_inout.c \
../f28069GpioSetup.c \
../main.c \
../scia.c \
../serial_com.c \
../set_dac_point.c \
../svm.c \
../switching_irq.c \
../trip_proc.c \
../udd_timer_irq.c \
../vf_contol.c 

C_DEPS += \
./Core_Speed_Calc.d \
./DS1307.d \
./F2806x_Adc.d \
./F2806x_CpuTimers.d \
./F2806x_DefaultIsr.d \
./F2806x_EPwm.d \
./F2806x_GlobalVariableDefs.d \
./F2806x_PieCtrl.d \
./F2806x_PieVect.d \
./F2806x_SysCtrl.d \
./I2C_eeprom.d \
./MonitorProc.d \
./ParameterSet.d \
./RefFunc.d \
./Set_Par.d \
./analog.d \
./code_group_all.d \
./code_proc.d \
./common_control.d \
./common_module.d \
./digital_inout.d \
./f28069GpioSetup.d \
./main.d \
./scia.d \
./serial_com.d \
./set_dac_point.d \
./svm.d \
./switching_irq.d \
./trip_proc.d \
./udd_timer_irq.d \
./vf_contol.d 

OBJS += \
./Core_Speed_Calc.obj \
./DS1307.obj \
./F2806x_Adc.obj \
./F2806x_CodeStartBranch.obj \
./F2806x_CpuTimers.obj \
./F2806x_DefaultIsr.obj \
./F2806x_EPwm.obj \
./F2806x_GlobalVariableDefs.obj \
./F2806x_PieCtrl.obj \
./F2806x_PieVect.obj \
./F2806x_SysCtrl.obj \
./F2806x_usDelay.obj \
./I2C_eeprom.obj \
./MonitorProc.obj \
./ParameterSet.obj \
./RefFunc.obj \
./Set_Par.obj \
./analog.obj \
./code_group_all.obj \
./code_proc.obj \
./common_control.obj \
./common_module.obj \
./digital_inout.obj \
./f28069GpioSetup.obj \
./main.obj \
./scia.obj \
./serial_com.obj \
./set_dac_point.obj \
./svm.obj \
./switching_irq.obj \
./trip_proc.obj \
./udd_timer_irq.obj \
./vf_contol.obj 

ASM_DEPS += \
./F2806x_CodeStartBranch.d \
./F2806x_usDelay.d 

OBJS__QUOTED += \
"Core_Speed_Calc.obj" \
"DS1307.obj" \
"F2806x_Adc.obj" \
"F2806x_CodeStartBranch.obj" \
"F2806x_CpuTimers.obj" \
"F2806x_DefaultIsr.obj" \
"F2806x_EPwm.obj" \
"F2806x_GlobalVariableDefs.obj" \
"F2806x_PieCtrl.obj" \
"F2806x_PieVect.obj" \
"F2806x_SysCtrl.obj" \
"F2806x_usDelay.obj" \
"I2C_eeprom.obj" \
"MonitorProc.obj" \
"ParameterSet.obj" \
"RefFunc.obj" \
"Set_Par.obj" \
"analog.obj" \
"code_group_all.obj" \
"code_proc.obj" \
"common_control.obj" \
"common_module.obj" \
"digital_inout.obj" \
"f28069GpioSetup.obj" \
"main.obj" \
"scia.obj" \
"serial_com.obj" \
"set_dac_point.obj" \
"svm.obj" \
"switching_irq.obj" \
"trip_proc.obj" \
"udd_timer_irq.obj" \
"vf_contol.obj" 

C_DEPS__QUOTED += \
"Core_Speed_Calc.d" \
"DS1307.d" \
"F2806x_Adc.d" \
"F2806x_CpuTimers.d" \
"F2806x_DefaultIsr.d" \
"F2806x_EPwm.d" \
"F2806x_GlobalVariableDefs.d" \
"F2806x_PieCtrl.d" \
"F2806x_PieVect.d" \
"F2806x_SysCtrl.d" \
"I2C_eeprom.d" \
"MonitorProc.d" \
"ParameterSet.d" \
"RefFunc.d" \
"Set_Par.d" \
"analog.d" \
"code_group_all.d" \
"code_proc.d" \
"common_control.d" \
"common_module.d" \
"digital_inout.d" \
"f28069GpioSetup.d" \
"main.d" \
"scia.d" \
"serial_com.d" \
"set_dac_point.d" \
"svm.d" \
"switching_irq.d" \
"trip_proc.d" \
"udd_timer_irq.d" \
"vf_contol.d" 

ASM_DEPS__QUOTED += \
"F2806x_CodeStartBranch.d" \
"F2806x_usDelay.d" 

C_SRCS__QUOTED += \
"../Core_Speed_Calc.c" \
"../DS1307.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_Adc.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_CpuTimers.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_DefaultIsr.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_EPwm.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/source/F2806x_GlobalVariableDefs.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_PieCtrl.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_PieVect.c" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_SysCtrl.c" \
"../I2C_eeprom.c" \
"../MonitorProc.c" \
"../ParameterSet.c" \
"../RefFunc.c" \
"../Set_Par.c" \
"../analog.c" \
"../code_group_all.c" \
"../code_proc.c" \
"../common_control.c" \
"../common_module.c" \
"../digital_inout.c" \
"../f28069GpioSetup.c" \
"../main.c" \
"../scia.c" \
"../serial_com.c" \
"../set_dac_point.c" \
"../svm.c" \
"../switching_irq.c" \
"../trip_proc.c" \
"../udd_timer_irq.c" \
"../vf_contol.c" 

ASM_SRCS__QUOTED += \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_CodeStartBranch.asm" \
"/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_usDelay.asm" 

