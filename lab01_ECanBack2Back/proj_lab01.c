/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//! \file   solutions/instaspin_foc/src/proj_lab01.c
//! \brief CPU and Inverter Set-up and introduction to interfacing to the ROM library
//!
//! (C) Copyright 2011, Texas Instruments, Inc.

//! \defgroup PROJ_LAB01 PROJ_LAB01
//@{

//! \defgroup PROJ_LAB01_OVERVIEW Project Overview
//!
//! CPU and Inverter Set-up and introduction to interfacing to the ROM library
//!

//
// **************************************************************************
// the includes

// system includes
#include <math.h>


// modules
#include "sw/modules/math/src/32b/math.h"
#include "sw/modules/memCopy/src/memCopy.h"


// drivers

#ifdef eCAN
#include "sw/drivers/can/src/32b/f28x/f2806x/can.h"

#pragma DATA_SECTION(ECanaRegs,"ECanaRegsFile");

volatile struct ECAN_REGS ECanaRegs;

#pragma DATA_SECTION(ECanaMboxes,"ECanaMboxesFile");

volatile struct ECAN_MBOXES ECanaMboxes;
#endif


// platforms
#include "sw/solutions/instaspin_foc/src/main.h"


// **************************************************************************
// the defines

#define LED_BLINK_FREQ_Hz   5

// **************************************************************************
// the globals

uint_least32_t gLEDcnt = 0;                   // Counter used to divide down the ISR rate for visually blinking an LED

#ifdef CSM_ENABLE
#pragma DATA_SECTION(halHandle,"rom_accessed_data");
#endif
HAL_Handle halHandle;                         // Handle to the Inverter hardware abstraction layer

#ifdef CSM_ENABLE
#pragma DATA_SECTION(gUserParams,"rom_accessed_data");
#endif
USER_Params gUserParams;                      // Contains the user.h settings

HAL_PwmData_t gPwmData = {0,0,0};             // Contains PWM duty cycles in global Q format

HAL_AdcData_t gAdcData = {0,0,0,0,0,0,0};     // Contains Current and Voltage ADC readings in global Q format

volatile MOTOR_Vars_t gMotorVars = MOTOR_Vars_INIT;

#ifdef FLASH
// Used for running BackGround in flash, and ISR in RAM
extern uint16_t *RamfuncsLoadStart, *RamfuncsLoadEnd, *RamfuncsRunStart;

#ifdef CSM_ENABLE
extern uint16_t *econst_start, *econst_end, *econst_ram_load;
extern uint16_t *switch_start, *switch_end, *switch_ram_load;
#endif
#endif


#ifdef DRV8301_SPI
// Watch window interface to the 8301 SPI
DRV_SPI_8301_Vars_t gDrvSpi8301Vars;
#endif

#ifdef DRV8305_SPI
// Watch window interface to the 8305 SPI
DRV_SPI_8305_Vars_t gDrvSpi8305Vars;
#endif

// **************************************************************************
// the functions

#ifdef eCAN
uint_least32_t  ErrorCount;
uint_least32_t  PassCount;
uint_least32_t  MessageReceivedCount;

uint_least32_t  TestMbox1 = 0;
uint_least32_t  TestMbox2 = 0;
uint_least32_t  TestMbox3 = 0;

// Prototype statements for functions found within this file.
void mailbox_check(int_least32_t T1, int_least32_t T2, int_least32_t T3);
void mailbox_read(int_least16_t i);

void InitECana(void);
#endif

void main(void)
{
#ifdef eCAN
	uint_least16_t  j;
    MessageReceivedCount = 0;
    ErrorCount = 0;
    PassCount = 0;

// eCAN control registers require read/write access using 32-bits.  Thus we
// will create a set of shadow registers for this example.  These shadow
// registers will be used to make sure the access is 32-bits and not 16.
   struct ECAN_REGS ECanaShadow;

#endif

  // Only used if running from FLASH
  // Note that the variable FLASH is defined by the project
  #ifdef FLASH
  // Copy time critical code and Flash setup code to RAM
  // The RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
  // symbols are created by the linker. Refer to the linker files.
  memCopy((uint16_t *)&RamfuncsLoadStart,(uint16_t *)&RamfuncsLoadEnd,(uint16_t *)&RamfuncsRunStart);

  #ifdef CSM_ENABLE
    //copy .econst to unsecure RAM
    if(*econst_end - *econst_start)
      {
        memCopy((uint16_t *)&econst_start,(uint16_t *)&econst_end,(uint16_t *)&econst_ram_load);
      }

    //copy .switch ot unsecure RAM
    if(*switch_end - *switch_start)
      {
        memCopy((uint16_t *)&switch_start,(uint16_t *)&switch_end,(uint16_t *)&switch_ram_load);
      }
  #endif
  #endif

  // initialize the hardware abstraction layer
  halHandle = HAL_init(&hal,sizeof(hal));

  // check for errors in user parameters
  USER_checkForErrors(&gUserParams);

  // store user parameter error in global variable
  gMotorVars.UserErrorCode = USER_getErrorCode(&gUserParams);

  // do not allow code execution if there is a user parameter error
  if(gMotorVars.UserErrorCode != USER_ErrorCode_NoError)
    {
      for(;;)
        {
          gMotorVars.Flag_enableSys = false;
        }
    }

  // initialize the user parameters
  USER_setParams(&gUserParams);

  // set the hardware abstraction layer parameters
  HAL_setParams(halHandle,&gUserParams);

#ifdef LAUNCHPAD
  // Setup GPIOs 0 and 1 as outputs for use in project lab1 only.
  // This is specific to the launchpad because its LEDs are also used by the PWM channels.
  HAL_setupLaunchPadGpio0and1(halHandle);
#endif

  // setup faults
  HAL_setupFaults(halHandle);


  // initialize the interrupt vector table
  HAL_initIntVectorTable(halHandle);


  // enable the ADC interrupts
  HAL_enableAdcInts(halHandle);


  // enable global interrupts
  HAL_enableGlobalInts(halHandle);


  // enable debug interrupts
  HAL_enableDebugInt(halHandle);


  // disable the PWM
  HAL_disablePwm(halHandle);


#ifdef DRV8301_SPI
  // turn on the DRV8301 if present
  HAL_enableDrv(halHandle);
  // initialize the DRV8301 interface
  HAL_setupDrvSpi(halHandle,&gDrvSpi8301Vars);
#endif

#ifdef DRV8305_SPI
  // turn on the DRV8305 if present
  HAL_enableDrv(halHandle);
  // initialize the DRV8305 interface
  HAL_setupDrvSpi(halHandle,&gDrvSpi8305Vars);
#endif

#ifdef eCAN
  InitECana();
  EALLOW;
  // Mailboxs can be written to 16-bits or 32-bits at a time
  // Write to the MSGID field of TRANSMIT mailboxes MBOX0 - 15
  ECanaMboxes.MBOX0.MSGID.all = 0x9555AAA0;
  ECanaMboxes.MBOX1.MSGID.all = 0x9555AAA1;
  ECanaMboxes.MBOX2.MSGID.all = 0x9555AAA2;
  ECanaMboxes.MBOX3.MSGID.all = 0x9555AAA3;
  ECanaMboxes.MBOX4.MSGID.all = 0x9555AAA4;
  ECanaMboxes.MBOX5.MSGID.all = 0x9555AAA5;
  ECanaMboxes.MBOX6.MSGID.all = 0x9555AAA6;
  ECanaMboxes.MBOX7.MSGID.all = 0x9555AAA7;
  ECanaMboxes.MBOX8.MSGID.all = 0x9555AAA8;
  ECanaMboxes.MBOX9.MSGID.all = 0x9555AAA9;
  ECanaMboxes.MBOX10.MSGID.all = 0x9555AAAA;
  ECanaMboxes.MBOX11.MSGID.all = 0x9555AAAB;
  ECanaMboxes.MBOX12.MSGID.all = 0x9555AAAC;
  ECanaMboxes.MBOX13.MSGID.all = 0x9555AAAD;
  ECanaMboxes.MBOX14.MSGID.all = 0x9555AAAE;
  ECanaMboxes.MBOX15.MSGID.all = 0x9555AAAF;

  // Write to the MSGID field of RECEIVE mailboxes MBOX16 - 31
  ECanaMboxes.MBOX16.MSGID.all = 0x9555AAA0;
  ECanaMboxes.MBOX17.MSGID.all = 0x9555AAA1;
  ECanaMboxes.MBOX18.MSGID.all = 0x9555AAA2;
  ECanaMboxes.MBOX19.MSGID.all = 0x9555AAA3;
  ECanaMboxes.MBOX20.MSGID.all = 0x9555AAA4;
  ECanaMboxes.MBOX21.MSGID.all = 0x9555AAA5;
  ECanaMboxes.MBOX22.MSGID.all = 0x9555AAA6;
  ECanaMboxes.MBOX23.MSGID.all = 0x9555AAA7;
  ECanaMboxes.MBOX24.MSGID.all = 0x9555AAA8;
  ECanaMboxes.MBOX25.MSGID.all = 0x9555AAA9;
  ECanaMboxes.MBOX26.MSGID.all = 0x9555AAAA;
  ECanaMboxes.MBOX27.MSGID.all = 0x9555AAAB;
  ECanaMboxes.MBOX28.MSGID.all = 0x9555AAAC;
  ECanaMboxes.MBOX29.MSGID.all = 0x9555AAAD;
  ECanaMboxes.MBOX30.MSGID.all = 0x9555AAAE;
  ECanaMboxes.MBOX31.MSGID.all = 0x9555AAAF;

  EDIS;
  // Configure Mailboxes 0-15 as Tx, 16-31 as Rx
  // Since this write is to the entire register (instead of a bit
  // field) a shadow register is not required.
  ECanaRegs.CANMD.all = 0xFFFF0000;

  // Enable all Mailboxes */
  // Since this write is to the entire register (instead of a bit
  // field) a shadow register is not required.
  ECanaRegs.CANME.all = 0xFFFFFFFF;

  // Specify that 8 bits will be sent/received
  ECanaMboxes.MBOX0.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX1.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX3.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX4.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX5.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX6.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX7.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX8.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX9.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX10.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX11.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX12.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX13.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX14.MSGCTRL.bit.DLC = 8;
  ECanaMboxes.MBOX15.MSGCTRL.bit.DLC = 8;

  // Write to the mailbox RAM field of MBOX0 - 15
  ECanaMboxes.MBOX0.MDL.all = 0x9555AAA0;
  ECanaMboxes.MBOX0.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX1.MDL.all = 0x9555AAA1;
  ECanaMboxes.MBOX1.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX2.MDL.all = 0x9555AAA2;
  ECanaMboxes.MBOX2.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX3.MDL.all = 0x9555AAA3;
  ECanaMboxes.MBOX3.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX4.MDL.all = 0x9555AAA4;
  ECanaMboxes.MBOX4.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX5.MDL.all = 0x9555AAA5;
  ECanaMboxes.MBOX5.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX6.MDL.all = 0x9555AAA6;
  ECanaMboxes.MBOX6.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX7.MDL.all = 0x9555AAA7;
  ECanaMboxes.MBOX7.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX8.MDL.all = 0x9555AAA8;
  ECanaMboxes.MBOX8.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX9.MDL.all = 0x9555AAA9;
  ECanaMboxes.MBOX9.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX10.MDL.all = 0x9555AAAA;
  ECanaMboxes.MBOX10.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX11.MDL.all = 0x9555AAAB;
  ECanaMboxes.MBOX11.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX12.MDL.all = 0x9555AAAC;
  ECanaMboxes.MBOX12.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX13.MDL.all = 0x9555AAAD;
  ECanaMboxes.MBOX13.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX14.MDL.all = 0x9555AAAE;
  ECanaMboxes.MBOX14.MDH.all = 0x89ABCDEF;

  ECanaMboxes.MBOX15.MDL.all = 0x9555AAAF;
  ECanaMboxes.MBOX15.MDH.all = 0x89ABCDEF;

  // Since this write is to the entire register (instead of a bit
  // field) a shadow register is not required.
  EALLOW;
  ECanaRegs.CANMIM.all = 0xFFFFFFFF;
  EDIS;
  // Configure the eCAN for self test mode
  // Enable the enhanced features of the eCAN.
  EALLOW;
  ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
  ECanaShadow.CANMC.bit.STM = 1;    // Configure CAN for self-test mode  1
  ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;
  EDIS;

  for(;;)
  {

     ECanaRegs.CANTRS.all = 0x0000FFFF;  // Set TRS for all transmit mailboxes
     while(ECanaRegs.CANTA.all != 0x0000FFFF ) {}  // Wait for all TAn bits to be set..
     ECanaRegs.CANTA.all = 0x0000FFFF;   // Clear all TAn
     MessageReceivedCount++;

     //Read from Receive mailboxes and begin checking for data */
     for(j=16; j<32; j++)         // Read & check 16 mailboxes
     {
        mailbox_read(j);         // This func reads the indicated mailbox data
        mailbox_check(TestMbox1,TestMbox2,TestMbox3); // Checks the received data
        //mailbox_read(16);
     }
  }

#else
  // For ever loop
  while(true);
#endif
} // end of main() function


interrupt void mainISR(void)
{

  // toggle status LED
  if(++gLEDcnt >= (uint_least32_t)(USER_ISR_FREQ_Hz / LED_BLINK_FREQ_Hz))
  {
    HAL_toggleLed(halHandle,(GPIO_Number_e)HAL_Gpio_LED2);
    gLEDcnt = 0;
  }


  // acknowledge the ADC interrupt
  HAL_acqAdcInt(halHandle,ADC_IntNumber_1);


  // convert the ADC data
  HAL_readAdcData(halHandle,&gAdcData);


  // ADC processing and pwm result code goes here


  // write the PWM compare values
  HAL_writePwmData(halHandle,&gPwmData);


  return;
} // end of mainISR() function

#ifdef eCAN
// This function reads out the contents of the indicated
// by the Mailbox number (MBXnbr).
void mailbox_read(int_least16_t MBXnbr)
{
   volatile struct MBOX *Mailbox;
   Mailbox = &ECanaMboxes.MBOX0 + MBXnbr;
   TestMbox1 = Mailbox->MDL.all; // = 0x9555AAAn (n is the MBX number)
   TestMbox2 = Mailbox->MDH.all; // = 0x89ABCDEF (a constant)
   TestMbox3 = Mailbox->MSGID.all;// = 0x9555AAAn (n is the MBX number)

} // MSGID of a rcv MBX is transmitted as the MDL data.

void mailbox_check(int_least32_t T1, int_least32_t T2, int_least32_t T3)
{
    if((T1 != T3) || ( T2 != 0x89ABCDEF))
    {
       ErrorCount++;
    }
    else
    {
       PassCount++;
    }
}

void InitECana(void)        // Initialize eCAN-A module
{

	/* Create a shadow register structure for the CAN control registers. This is
	 needed, since only 32-bit access is allowed to these registers. 16-bit access
	 to these registers could potentially corrupt the register contents or return
	 false data. */

	struct ECAN_REGS ECanaShadow;

    EALLOW;     // asm(" asm(" EALLOW")") enables access to protected bits

	/* Configure eCAN RX and TX pins for CAN operation using eCAN regs*/

    ECanaShadow.CANTIOC.all = ECanaRegs.CANTIOC.all;
    ECanaShadow.CANTIOC.bit.TXFUNC = 1;
    ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;

    ECanaShadow.CANRIOC.all = ECanaRegs.CANRIOC.all;
    ECanaShadow.CANRIOC.bit.RXFUNC = 1;
    ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;

	/* Configure eCAN for HECC mode - (reqd to access mailboxes 16 thru 31) */
	// HECC mode also enables time-stamping feature

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.SCB = 1;
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

	/* Initialize all bits of 'Message Control Register' to zero */
// Some bits of MSGCTRL register come up in an unknown state. For proper operation,
// all bits (including reserved bits) of MSGCTRL must be initialized to zero

    ECanaMboxes.MBOX0.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX2.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX3.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX6.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX7.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX8.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX9.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000;

// TAn, RMPn, GIFn bits are all zero upon reset and are cleared again
//  as a matter of precaution.

    ECanaRegs.CANTA.all = 0xFFFFFFFF;   /* Clear all TAn bits */

    ECanaRegs.CANRMP.all = 0xFFFFFFFF;  /* Clear all RMPn bits */

    ECanaRegs.CANGIF0.all = 0xFFFFFFFF; /* Clear all interrupt flag bits */
    ECanaRegs.CANGIF1.all = 0xFFFFFFFF;

	/* Configure bit timing parameters for eCANA*/

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 1 ;            // Set CCR = 1
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // Wait until the CPU has been granted permission to change the configuration registers
    do
    {
		ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    } while(ECanaShadow.CANES.bit.CCE != 1 );       // Wait for CCE bit to be set..

    ECanaShadow.CANBTC.all = 0;
    ECanaShadow.CANBTC.all = 0x000503BD;   // 500k
    ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 0 ;            // Set CCR = 0
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // Wait until the CPU no longer has permission to change the configuration registers
    do
    {
		ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    } while(ECanaShadow.CANES.bit.CCE != 0 );       // Wait for CCE bit to be  cleared..

	/* Disable all Mailboxes  */
    ECanaRegs.CANME.all = 0;        // Required before writing the MSGIDs

    EDIS;
}
#endif

//@} //defgroup
// end of file




