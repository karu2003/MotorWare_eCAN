################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/ide/ccs/cmd/f2806x/f28069F_ram_lnk.cmd 

LIB_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2806x/2806xRevB_FastSpinROMSymbols_fpu32.lib \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/iqmath/lib/f28x/float/IQmath_fpu32.lib 

ASM_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/CodeStartBranch.asm \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm 

C_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2806x/adc.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/clarke/src/32b/clarke.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2806x/clk.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/cpu.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/ctrl/src/32b/ctrl.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8305/src/32b/f28x/f2806x/drv8305.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/filter/src/32b/filter_fo.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2806x/flash.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/fw/src/32b/fw.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2806x/gpio.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/ipark/src/32b/ipark.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/offset/src/32b/offset.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2806x/osc.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/park/src/32b/park.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/pid/src/32b/pid.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2806x/pie.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2806x/pll.c \
../proj_lab09a.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2806x/pwm.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2806x/pwr.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2806x/spi.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen_current.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2806x/timer.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/traj/src/32b/traj.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2806x/wdog.c 

OBJS += \
./CodeStartBranch.obj \
./adc.obj \
./clarke.obj \
./clk.obj \
./cpu.obj \
./ctrl.obj \
./drv8305.obj \
./filter_fo.obj \
./flash.obj \
./fw.obj \
./gpio.obj \
./ipark.obj \
./offset.obj \
./osc.obj \
./park.obj \
./pid.obj \
./pie.obj \
./pll.obj \
./proj_lab09a.obj \
./pwm.obj \
./pwr.obj \
./spi.obj \
./svgen.obj \
./svgen_current.obj \
./timer.obj \
./traj.obj \
./usDelay.obj \
./user.obj \
./wdog.obj 

ASM_DEPS += \
./CodeStartBranch.pp \
./usDelay.pp 

C_DEPS += \
./adc.pp \
./clarke.pp \
./clk.pp \
./cpu.pp \
./ctrl.pp \
./drv8305.pp \
./filter_fo.pp \
./flash.pp \
./fw.pp \
./gpio.pp \
./ipark.pp \
./offset.pp \
./osc.pp \
./park.pp \
./pid.pp \
./pie.pp \
./pll.pp \
./proj_lab09a.pp \
./pwm.pp \
./pwr.pp \
./spi.pp \
./svgen.pp \
./svgen_current.pp \
./timer.pp \
./traj.pp \
./user.pp \
./wdog.pp 

C_DEPS__QUOTED += \
"adc.pp" \
"clarke.pp" \
"clk.pp" \
"cpu.pp" \
"ctrl.pp" \
"drv8305.pp" \
"filter_fo.pp" \
"flash.pp" \
"fw.pp" \
"gpio.pp" \
"ipark.pp" \
"offset.pp" \
"osc.pp" \
"park.pp" \
"pid.pp" \
"pie.pp" \
"pll.pp" \
"proj_lab09a.pp" \
"pwm.pp" \
"pwr.pp" \
"spi.pp" \
"svgen.pp" \
"svgen_current.pp" \
"timer.pp" \
"traj.pp" \
"user.pp" \
"wdog.pp" 

OBJS__QUOTED += \
"CodeStartBranch.obj" \
"adc.obj" \
"clarke.obj" \
"clk.obj" \
"cpu.obj" \
"ctrl.obj" \
"drv8305.obj" \
"filter_fo.obj" \
"flash.obj" \
"fw.obj" \
"gpio.obj" \
"ipark.obj" \
"offset.obj" \
"osc.obj" \
"park.obj" \
"pid.obj" \
"pie.obj" \
"pll.obj" \
"proj_lab09a.obj" \
"pwm.obj" \
"pwr.obj" \
"spi.obj" \
"svgen.obj" \
"svgen_current.obj" \
"timer.obj" \
"traj.obj" \
"usDelay.obj" \
"user.obj" \
"wdog.obj" 

ASM_DEPS__QUOTED += \
"CodeStartBranch.pp" \
"usDelay.pp" 

ASM_SRCS__QUOTED += \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/CodeStartBranch.asm" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm" 

C_SRCS__QUOTED += \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2806x/adc.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/clarke/src/32b/clarke.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2806x/clk.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/cpu.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/ctrl/src/32b/ctrl.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8305/src/32b/f28x/f2806x/drv8305.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/filter/src/32b/filter_fo.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2806x/flash.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/fw/src/32b/fw.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2806x/gpio.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/ipark/src/32b/ipark.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/offset/src/32b/offset.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2806x/osc.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/park/src/32b/park.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/pid/src/32b/pid.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2806x/pie.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2806x/pll.c" \
"../proj_lab09a.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2806x/pwm.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2806x/pwr.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2806x/spi.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/svgen/src/32b/svgen_current.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2806x/timer.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/traj/src/32b/traj.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2806x/wdog.c" 


