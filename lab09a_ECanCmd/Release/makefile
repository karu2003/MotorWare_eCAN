################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
-l"rts2800_fpu32.lib" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2806x/2806xRevB_FastSpinROMSymbols_fpu32.lib" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/iqmath/lib/f28x/float/IQmath_fpu32.lib" \
"./CodeStartBranch.obj" \
"./adc.obj" \
"./clarke.obj" \
"./clk.obj" \
"./cpu.obj" \
"./ctrl.obj" \
"./drv8305.obj" \
"./filter_fo.obj" \
"./flash.obj" \
"./fw.obj" \
"./gpio.obj" \
"./ipark.obj" \
"./offset.obj" \
"./osc.obj" \
"./park.obj" \
"./pid.obj" \
"./pie.obj" \
"./pll.obj" \
"./proj_lab09a.obj" \
"./pwm.obj" \
"./pwr.obj" \
"./spi.obj" \
"./svgen.obj" \
"./svgen_current.obj" \
"./timer.obj" \
"./traj.obj" \
"./usDelay.obj" \
"./user.obj" \
"./wdog.obj" \
"./include/hal/hal.obj" \
"./include/can/can.obj" \
"C:/ti/motorware/motorware_1_01_00_18/sw/ide/ccs/cmd/f2806x/f28069F_ram_lnk.cmd" \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include include/hal/subdir_vars.mk
-include include/can/subdir_vars.mk
-include subdir_rules.mk
-include include/hal/subdir_rules.mk
-include include/can/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
lab09a_ECanCmd.out \

EXE_OUTPUTS__QUOTED += \
"lab09a_ECanCmd.out" \

BIN_OUTPUTS += \
lab09a_ECanCmd.hex \

BIN_OUTPUTS__QUOTED += \
"lab09a_ECanCmd.hex" \


# All Target
all: lab09a_ECanCmd.out

# Tool invocations
lab09a_ECanCmd.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -O2 --define=FAST_ROM_V1p6 --define=ECAN_API=1 -g --diag_warning=225 --display_error_number -z -m"lab09a_ECanCmd.map" --stack_size=0x3B0 --warn_sections -i"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/lib" -i"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/include" --priority --reread_libs --disable_auto_rts --diag_suppress=16002 --xml_link_info="lab09a_ECanCmd_linkInfo.xml" --rom_model -o "lab09a_ECanCmd.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

lab09a_ECanCmd.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"D:/ti/ccsv6/tools/compiler/ti-cgt-c2000_17.3.0.STS/bin/hex2000"  -o "lab09a_ECanCmd.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "adc.pp" "clarke.pp" "clk.pp" "cpu.pp" "ctrl.pp" "drv8305.pp" "filter_fo.pp" "flash.pp" "fw.pp" "gpio.pp" "ipark.pp" "offset.pp" "osc.pp" "park.pp" "pid.pp" "pie.pp" "pll.pp" "proj_lab09a.pp" "pwm.pp" "pwr.pp" "spi.pp" "svgen.pp" "svgen_current.pp" "timer.pp" "traj.pp" "user.pp" "wdog.pp" "include\hal\hal.pp" "include\can\can.pp" 
	-$(RM) "CodeStartBranch.obj" "adc.obj" "clarke.obj" "clk.obj" "cpu.obj" "ctrl.obj" "drv8305.obj" "filter_fo.obj" "flash.obj" "fw.obj" "gpio.obj" "ipark.obj" "offset.obj" "osc.obj" "park.obj" "pid.obj" "pie.obj" "pll.obj" "proj_lab09a.obj" "pwm.obj" "pwr.obj" "spi.obj" "svgen.obj" "svgen_current.obj" "timer.obj" "traj.obj" "usDelay.obj" "user.obj" "wdog.obj" "include\hal\hal.obj" "include\can\can.obj" 
	-$(RM) "CodeStartBranch.pp" "usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

