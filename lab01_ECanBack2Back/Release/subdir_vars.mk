################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../f28069M_ram_lnk.cmd 

LIB_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/fast/lib/32b/f28x/f2806x/2806xRevB_FastSpinROMSymbols.lib \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/iqmath/lib/f28x/32b/IQmath.lib 

ASM_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm 

C_SRCS += \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2806x/adc.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2806x/clk.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/cpu.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8301/src/32b/f28x/f2806x/drv8301.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2806x/flash.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2806x/gpio.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2806x/osc.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2806x/pie.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2806x/pll.c \
../proj_lab01.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2806x/pwm.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2806x/pwr.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2806x/spi.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2806x/timer.c \
C:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c \
C:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2806x/wdog.c 

OBJS += \
./adc.obj \
./clk.obj \
./cpu.obj \
./drv8301.obj \
./flash.obj \
./gpio.obj \
./osc.obj \
./pie.obj \
./pll.obj \
./proj_lab01.obj \
./pwm.obj \
./pwr.obj \
./spi.obj \
./timer.obj \
./usDelay.obj \
./user.obj \
./wdog.obj 

ASM_DEPS += \
./usDelay.pp 

C_DEPS += \
./adc.pp \
./clk.pp \
./cpu.pp \
./drv8301.pp \
./flash.pp \
./gpio.pp \
./osc.pp \
./pie.pp \
./pll.pp \
./proj_lab01.pp \
./pwm.pp \
./pwr.pp \
./spi.pp \
./timer.pp \
./user.pp \
./wdog.pp 

C_DEPS__QUOTED += \
"adc.pp" \
"clk.pp" \
"cpu.pp" \
"drv8301.pp" \
"flash.pp" \
"gpio.pp" \
"osc.pp" \
"pie.pp" \
"pll.pp" \
"proj_lab01.pp" \
"pwm.pp" \
"pwr.pp" \
"spi.pp" \
"timer.pp" \
"user.pp" \
"wdog.pp" 

OBJS__QUOTED += \
"adc.obj" \
"clk.obj" \
"cpu.obj" \
"drv8301.obj" \
"flash.obj" \
"gpio.obj" \
"osc.obj" \
"pie.obj" \
"pll.obj" \
"proj_lab01.obj" \
"pwm.obj" \
"pwr.obj" \
"spi.obj" \
"timer.obj" \
"usDelay.obj" \
"user.obj" \
"wdog.obj" 

ASM_DEPS__QUOTED += \
"usDelay.pp" 

C_SRCS__QUOTED += \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/adc/src/32b/f28x/f2806x/adc.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/clk/src/32b/f28x/f2806x/clk.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/cpu/src/32b/f28x/f2806x/cpu.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/drvic/drv8301/src/32b/f28x/f2806x/drv8301.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/flash/src/32b/f28x/f2806x/flash.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/gpio/src/32b/f28x/f2806x/gpio.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/osc/src/32b/f28x/f2806x/osc.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pie/src/32b/f28x/f2806x/pie.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pll/src/32b/f28x/f2806x/pll.c" \
"../proj_lab01.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwm/src/32b/f28x/f2806x/pwm.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/pwr/src/32b/f28x/f2806x/pwr.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/spi/src/32b/f28x/f2806x/spi.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/timer/src/32b/f28x/f2806x/timer.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/user/src/32b/user.c" \
"C:/ti/motorware/motorware_1_01_00_18/sw/drivers/wdog/src/32b/f28x/f2806x/wdog.c" 

ASM_SRCS__QUOTED += \
"C:/ti/motorware/motorware_1_01_00_18/sw/modules/usDelay/src/32b/f28x/usDelay.asm" 


