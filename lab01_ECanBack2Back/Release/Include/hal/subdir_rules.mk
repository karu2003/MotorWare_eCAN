################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Include/hal/hal.obj: ../Include/hal/hal.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.9/bin/cl2000" -v28 -ml -mt -O2 --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.9/include" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab01_ECanBack2Back/Include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8301_revB/f28x/f2806xF/src" --include_path="C:/ti/motorware/motorware_1_01_00_18" -g --define=FAST_ROM_V1p6 --define=eCAN=1 --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Include/hal/hal.pp" --obj_directory="Include/hal" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


