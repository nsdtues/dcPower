################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Core_Speed_Calc.obj: ../Core_Speed_Calc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="Core_Speed_Calc.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

DS1307.obj: ../DS1307.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="DS1307.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_Adc.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_Adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_Adc.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_CodeStartBranch.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_CodeStartBranch.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_CpuTimers.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_CpuTimers.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_DefaultIsr.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_DefaultIsr.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_DefaultIsr.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_EPwm.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_EPwm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_EPwm.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_GlobalVariableDefs.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/source/F2806x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_GlobalVariableDefs.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_PieCtrl.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_PieCtrl.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_PieVect.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_PieVect.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_SysCtrl.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_SysCtrl.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

F2806x_usDelay.obj: /home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/source/F2806x_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="F2806x_usDelay.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

I2C_eeprom.obj: ../I2C_eeprom.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="I2C_eeprom.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MonitorProc.obj: ../MonitorProc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="MonitorProc.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ParameterSet.obj: ../ParameterSet.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="ParameterSet.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

RefFunc.obj: ../RefFunc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="RefFunc.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

Set_Par.obj: ../Set_Par.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="Set_Par.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

analog.obj: ../analog.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="analog.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

code_group_all.obj: ../code_group_all.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="code_group_all.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

code_proc.obj: ../code_proc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="code_proc.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

common_control.obj: ../common_control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="common_control.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

common_module.obj: ../common_module.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="common_module.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

digital_inout.obj: ../digital_inout.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="digital_inout.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

f28069GpioSetup.obj: ../f28069GpioSetup.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="f28069GpioSetup.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

scia.obj: ../scia.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="scia.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

serial_com.obj: ../serial_com.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="serial_com.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

set_dac_point.obj: ../set_dac_point.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="set_dac_point.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

svm.obj: ../svm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="svm.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

switching_irq.obj: ../switching_irq.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="switching_irq.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

trip_proc.obj: ../trip_proc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="trip_proc.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

udd_timer_irq.obj: ../udd_timer_irq.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="udd_timer_irq.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

vf_contol.obj: ../vf_contol.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="/home/eunwho/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/headers/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/device_support/f2806x/common/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/IQmath/c28/include" --include_path="/home/eunwho/ti/c2000/C2000Ware_1_00_01_00/libraries/math/FPUfastRTS/c28/include" --include_path="/home/eunwho/f28069/singlePhaseInv/include" --define="_DEBUG" --define="LARGE_MODEL" -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --preproc_with_compile --preproc_dependency="vf_contol.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


