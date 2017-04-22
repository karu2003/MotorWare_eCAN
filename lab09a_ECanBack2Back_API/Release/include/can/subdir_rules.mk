################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
include/can/can.obj: ../include/can/can.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanBack2Back_API/include/can" --include_path="D:/Users/Andrew/Documents/Proj/workspace_v6_0/MotorWare_eCAN/lab09a_ECanBack2Back_API/include/hal" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8305_revA/f28x/f2806xF/src" --include_path="D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --include_path="C:/ti/motorware/motorware_1_01_00_18" --define=FAST_ROM_V1p6 --define=ecan_test=1 -g --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="include/can/can.pp" --obj_directory="include/can" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


