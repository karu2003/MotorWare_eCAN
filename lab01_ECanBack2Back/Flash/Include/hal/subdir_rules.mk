################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Include/hal/hal.obj: ../Include/hal/hal.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_6.2.9/bin/cl2000" -v28 -ml -mt -O2 --include_path="C:/ti/ccsv6/tools/compiler/c2000_6.2.9/include" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/modules/hal/boards/drv8301kit_revD/f28x/f2806x/src/" --include_path="C:/ti/motorware/motorware_1_01_00_18/sw/solutions/instaspin_foc/boards/boostxldrv8301_revB/f28x/f2806xF/src" --include_path="C:/ti/motorware/motorware_1_01_00_18" -g --define=FAST_ROM_V1p6 --define=eCAN=1 --define=FLASH --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Include/hal/hal.pp" --obj_directory="Include/hal" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


