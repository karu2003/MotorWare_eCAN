################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
CodeStartBranch.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/CodeStartBranch.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="CodeStartBranch.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

adc.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2806x/adc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="adc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

clarke.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/clarke/src/32b/clarke.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="clarke.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

clk.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2806x/clk.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="clk.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cpu.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/cpu.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="cpu.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctrl.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/ctrl/src/32b/ctrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="ctrl.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drv8305.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8305/src/32b/f28x/f2806x/drv8305.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="drv8305.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

filter_fo.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/filter/src/32b/filter_fo.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="filter_fo.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

flash.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2806x/flash.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="flash.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

fw.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/fw/src/32b/fw.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="fw.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

gpio.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2806x/gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="gpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ipark.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/ipark/src/32b/ipark.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="ipark.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

offset.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/offset/src/32b/offset.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="offset.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

osc.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2806x/osc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="osc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

park.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/park/src/32b/park.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="park.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pid.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/pid/src/32b/pid.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="pid.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pie.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2806x/pie.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="pie.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pll.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2806x/pll.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="pll.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

proj_lab09a.obj: ../proj_lab09a.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="proj_lab09a.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pwm.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2806x/pwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="pwm.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pwr.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2806x/pwr.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="pwr.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

spi.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2806x/spi.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="spi.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

svgen.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="svgen.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

svgen_current.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen_current.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="svgen_current.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2806x/timer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="timer.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

traj.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/traj/src/32b/traj.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="traj.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

usDelay.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="usDelay.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

user.obj: C:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="user.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

wdog.obj: C:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2806x/wdog.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/fifo" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanCmd/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="wdog.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


