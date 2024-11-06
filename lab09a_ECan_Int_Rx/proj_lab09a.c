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
//! \file   solutions/instaspin_foc/src/proj_lab09a.c
//! \brief Automatic field weakening FPU32
//!
//! (C) Copyright 2011, Texas Instruments, Inc.

//! \defgroup PROJ_LAB09A PROJ_LAB09A
//@{

//! \defgroup PROJ_LAB09A_OVERVIEW Project Overview
//!
//! Experimentation with Field Weakening FPU32
//!
//! Added ECanBack2Back  Andrew Buckin.
//!

// **************************************************************************
// the includes

// system includes
#include <math.h>
#include "main.h"

#ifdef FLASH
#pragma CODE_SECTION(mainISR, "ramfuncs");
#endif

#include "can.h"
#include "fifo.h"

// Include header files used in the main function

// **************************************************************************
// the defines

#define LED_BLINK_FREQ_Hz 5

// **************************************************************************
// the globals

uint_least16_t gCounter_updateGlobals = 0;

bool Flag_Latch_softwareUpdate = true;

CTRL_Handle ctrlHandle;

#ifdef CSM_ENABLE
#pragma DATA_SECTION(halHandle, "rom_accessed_data");
#endif

HAL_Handle halHandle;

#ifdef CSM_ENABLE
#pragma DATA_SECTION(gUserParams, "rom_accessed_data");
#endif

USER_Params gUserParams;

HAL_PwmData_t gPwmData = {_IQ(0.0), _IQ(0.0), _IQ(0.0)};

HAL_AdcData_t gAdcData;

_iq gMaxCurrentSlope = _IQ(0.0);

#ifdef FAST_ROM_V1p6
CTRL_Obj *controller_obj;
#else

#ifdef CSM_ENABLE
#pragma DATA_SECTION(ctrl, "rom_accessed_data");
#endif

CTRL_Obj ctrl;  // v1p7 format
#endif

uint16_t gLEDcnt = 0;

#ifdef ECAN_API
#endif

uint_least32_t ErrorCount = 0;
uint_least32_t PassCount = 0;
uint_least32_t MessageReceivedCount = 0;

uint16_t gTXtemp = 0;

int ECANIDS = 511;
uint32_t ECAN_rxBuf[8] = {0, 0, 0, 0, 0, 0, 0, 0};

ECAN_Mailbox gECAN_Mailbox;
FIFO_ID_Obj gECAN_rxFIFO_ID;
FIFO_ID_Obj gECAN_txFIFO_ID;
MSG_t msg_temp;

uint32_t timer0_count = 0;
uint32_t ecan_int0count = 0;  // Counter to track the # of level 0 interrupts
uint32_t ecan_int1count = 0;  // Counter to track the # of level 1 interrupts
uint16_t ecan_isrFlags0 = 0;
uint16_t ecan_isrFlags1 = 0;

volatile MOTOR_Vars_t gMotorVars = MOTOR_Vars_INIT;

#ifdef FLASH
// Used for running BackGround in flash, and ISR in RAM
extern uint16_t *RamfuncsLoadStart, *RamfuncsLoadEnd, *RamfuncsRunStart;

#ifdef CSM_ENABLE
extern uint16_t *econst_start, *econst_end, *econst_ram_load;
extern uint16_t *switch_start, *switch_end, *switch_ram_load;
#endif
#endif

FW_Obj fw;
FW_Handle fwHandle;

_iq Iq_Max_pu;

#ifdef DRV8301_SPI
// Watch window interface to the 8301 SPI
DRV_SPI_8301_Vars_t gDrvSpi8301Vars;
#endif
#ifdef DRV8305_SPI
// Watch window interface to the 8305 SPI
DRV_SPI_8305_Vars_t gDrvSpi8305Vars;
#endif

_iq gFlux_pu_to_Wb_sf;

_iq gFlux_pu_to_VpHz_sf;

_iq gTorque_Ls_Id_Iq_pu_to_Nm_sf;

_iq gTorque_Flux_Iq_pu_to_Nm_sf;

// **************************************************************************
// the functions

void main(void) {
    uint_least8_t estNumber = 0;

#ifdef FAST_ROM_V1p6
    uint_least8_t ctrlNumber = 0;
#endif

// Only used if running from FLASH
// Note that the variable FLASH is defined by the project
#ifdef FLASH
    // Copy time critical code and Flash setup code to RAM
    // The RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
    // symbols are created by the linker. Refer to the linker files.
    memCopy((uint16_t *)&RamfuncsLoadStart, (uint16_t *)&RamfuncsLoadEnd, (uint16_t *)&RamfuncsRunStart);

#ifdef CSM_ENABLE
    // copy .econst to unsecure RAM
    if (*econst_end - *econst_start) {
        memCopy((uint16_t *)&econst_start, (uint16_t *)&econst_end, (uint16_t *)&econst_ram_load);
    }

    // copy .switch ot unsecure RAM
    if (*switch_end - *switch_start) {
        memCopy((uint16_t *)&switch_start, (uint16_t *)&switch_end, (uint16_t *)&switch_ram_load);
    }
#endif
#endif

    // initialize the hardware abstraction layer
    halHandle = HAL_init(&hal, sizeof(hal));

    // check for errors in user parameters
    USER_checkForErrors(&gUserParams);

    // store user parameter error in global variable
    gMotorVars.UserErrorCode = USER_getErrorCode(&gUserParams);

    // do not allow code execution if there is a user parameter error
    if (gMotorVars.UserErrorCode != USER_ErrorCode_NoError) {
        for (;;) {
            gMotorVars.Flag_enableSys = false;
        }
    }

    // initialize the user parameters
    USER_setParams(&gUserParams);

    // set the hardware abstraction layer parameters
    HAL_setParams(halHandle, &gUserParams);

    // initialize the controller
#ifdef FAST_ROM_V1p6
    ctrlHandle = CTRL_initCtrl(ctrlNumber, estNumber);  // v1p6 format (06xF and 06xM devices)
    controller_obj = (CTRL_Obj *)ctrlHandle;
#else
    ctrlHandle = CTRL_initCtrl(estNumber, &ctrl, sizeof(ctrl));  // v1p7 format default
#endif

    {
        CTRL_Version version;

        // get the version number
        CTRL_getVersion(ctrlHandle, &version);

        gMotorVars.CtrlVersion = version;
    }

    // set the default controller parameters
    CTRL_setParams(ctrlHandle, &gUserParams);

    // Initialize field weakening
    fwHandle = FW_init(&fw, sizeof(fw));

    // Disable field weakening
    FW_setFlag_enableFw(fwHandle, false);

    // Clear field weakening counter
    FW_clearCounter(fwHandle);

    // Set the number of ISR per field weakening ticks
    FW_setNumIsrTicksPerFwTick(fwHandle, FW_NUM_ISR_TICKS_PER_CTRL_TICK);

    // Set the deltas of field weakening
    FW_setDeltas(fwHandle, FW_INC_DELTA, FW_DEC_DELTA);

    // Set initial output of field weakening to zero
    FW_setOutput(fwHandle, _IQ(0.0));

    // Set the field weakening controller limits
    FW_setMinMax(fwHandle, _IQ(USER_MAX_NEGATIVE_ID_REF_CURRENT_A / USER_IQ_FULL_SCALE_CURRENT_A), _IQ(0.0));

    // setup faults
    HAL_setupFaults(halHandle);

    // initialize the interrupt vector table
    HAL_initIntVectorTable(halHandle);

    // enable the ADC interrupts
    HAL_enableAdcInts(halHandle);

    // enable ECAN interrupts
    HAL_enableEcanInt(halHandle);

    // enable global interrupts
    HAL_enableGlobalInts(halHandle);

    // enable debug interrupts
    HAL_enableDebugInt(halHandle);

    // disable the PWM
    HAL_disablePwm(halHandle);

    // enable the Timer 0 interrupts
    HAL_enableTimer0Int(halHandle);

#ifdef DRV8301_SPI
    // turn on the DRV8301 if present
    HAL_enableDrv(halHandle);
    // initialize the DRV8301 interface
    HAL_setupDrvSpi(halHandle, &gDrvSpi8301Vars);
#endif

#ifdef DRV8305_SPI
    // turn on the DRV8305 if present
    HAL_enableDrv(halHandle);
    // initialize the DRV8305 interface
    HAL_setupDrvSpi(halHandle, &gDrvSpi8305Vars);
#endif

    // enable DC bus compensation
    CTRL_setFlag_enableDcBusComp(ctrlHandle, true);

    // compute scaling factors for flux and torque calculations
    gFlux_pu_to_Wb_sf = USER_computeFlux_pu_to_Wb_sf();
    gFlux_pu_to_VpHz_sf = USER_computeFlux_pu_to_VpHz_sf();
    gTorque_Ls_Id_Iq_pu_to_Nm_sf = USER_computeTorque_Ls_Id_Iq_pu_to_Nm_sf();
    gTorque_Flux_Iq_pu_to_Nm_sf = USER_computeTorque_Flux_Iq_pu_to_Nm_sf();

    //  ECAN_configAuto_Answer(halHandle->ecanaHandle, MailBox0, 8,Standard_ID, DLC_8, 0x5A5A5A5A, 0x5A5A5A5A);
    //                                               	    MailBoxID                                                              Mask
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox0, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox1, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox2, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox3, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox4, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox5, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox6, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox7, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox8, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox9, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox10, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox11, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox12, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox13, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox14, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    ECAN_configMailbox(halHandle->ecanaHandle, MailBox15, ECANIDS, Enable_Mbox, Tx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);

    ECAN_setTx_Priority(halHandle->ecanaHandle, MailBox15, Tx_leve31);

    ECAN_configMailbox(halHandle->ecanaHandle, MailBox16, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_on, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox17, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox18, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox19, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox20, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox21, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox22, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox23, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox24, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox25, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox26, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox27, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox28, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox29, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox30, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);
    // ECAN_configMailbox(halHandle->ecanaHandle, MailBox31, ECANIDS, Enable_Mbox, Rx_Dir, Extended_ID, DLC_8, Overwrite_off, LAMI_0, Mask_is_used, 0x1FFFFFFF);  // 1F80
    //                                    TX_max    TX_min    RX_max     RX_min
    ECAN_initMailboxUse(&gECAN_Mailbox, MailBox15, MailBox0, MailBox31, MailBox16);

    //  ECAN_setTx_Priority(halHandle->ecanaHandle, MailBox0, Tx_leve31);
    //  ECAN_SelfTest(halHandle->ecanaHandle, Self_test_mode);
    ECAN_SelfTest(halHandle->ecanaHandle, Normal_mode);

    //  ECAN_Int_Mask(halHandle->ecanaHandle, MBOX16_BIT);
    //  ECAN_Mailbox_Int_Line0(halHandle->ecanaHandle, MBOX16_BIT);

    ECAN_configMailbox_Int(halHandle->ecanaHandle, MailBox16, Int_enable, Line1);
    // uint32_t mailbox;
    // for (mailbox = 16; mailbox < 32; mailbox++) {
    //     ECAN_configMailbox_Int(
    //         halHandle->ecanaHandle,
    //         mailbox,
    //         Int_enable,
    //         Line1);
    // }

    ECAN_GlobalInt_Mask(halHandle->ecanaHandle, INT0_ENABLE | INT1_ENABLE);

    FIFO_FLUSH(gECAN_rxFIFO_ID);
    FIFO_FLUSH(gECAN_txFIFO_ID);

#ifdef ECAN_API
    int i = 0;
    for (i = 0; i < 16; i++) {
        FIFO_PUSH_ID(&gECAN_txFIFO_ID, 0x006 + (0x100 * i), DLC_0 + i, 0x01020304, 0x05060708);
        // MessageReceivedCount++;
    }

    while (!(ECAN_sendMsg_FIFO_ID_One(halHandle->ecanaHandle, &gECAN_Mailbox, &gECAN_txFIFO_ID))) MessageReceivedCount++;
#endif

    for (;;) {
        // Waiting for enable system flag to be set
        while (!(gMotorVars.Flag_enableSys)) {
#ifdef test_cmd
            if (ECAN_checkMail(halHandle->ecanaHandle)) {
                ECAN_getMsgFIFO_ID_N(halHandle->ecanaHandle, &gECAN_Mailbox, &gECAN_rxFIFO_ID);
            }

            while (!(FIFO_IS_EMPTY(gECAN_rxFIFO_ID))) {
                msg_temp = FIFO_FRONT(gECAN_rxFIFO_ID);
                FIFO_POP(gECAN_rxFIFO_ID);

                int i = 0;
                i = msg_temp.msgID;
                switch (i) {
                    case 0x006:
                        gMotorVars.Flag_enableUserParams = false;
                        break;
                    case 0x106:
                        gMotorVars.Flag_enableUserParams = true;
                        break;
                    default:
                        gMotorVars.Flag_enableSys = true;
                        break;
                }
            }
            FIFO_FLUSH(gECAN_rxFIFO_ID);
#endif
        }

        Flag_Latch_softwareUpdate = true;

        // Enable the Library internal PI.  Iq is referenced by the speed PI now
        CTRL_setFlag_enableSpeedCtrl(ctrlHandle, true);

        // loop while the enable system flag is true
        while (gMotorVars.Flag_enableSys) {
#ifdef ECAN_API

            ECAN_rxBuf[0] = ECAN_isRx(halHandle->ecanaHandle);
            //     if(ECAN_rxBuf[0] == 16) {
            if (ecan_isrFlags1) {
                ECAN_getMsgFIFO_ID_N(halHandle->ecanaHandle, &gECAN_Mailbox, &gECAN_rxFIFO_ID);
                FIFO_FLUSH(gECAN_rxFIFO_ID);
                ecan_isrFlags1 = 0;
            }

#endif
            CTRL_Obj *obj = (CTRL_Obj *)ctrlHandle;

            // increment counters
            gCounter_updateGlobals++;

            // enable/disable the use of motor parameters being loaded from user.h
            CTRL_setFlag_enableUserMotorParams(ctrlHandle, gMotorVars.Flag_enableUserParams);

            // enable/disable Rs recalibration during motor startup
            EST_setFlag_enableRsRecalc(obj->estHandle, gMotorVars.Flag_enableRsRecalc);

            // enable/disable automatic calculation of bias values
            CTRL_setFlag_enableOffset(ctrlHandle, gMotorVars.Flag_enableOffsetcalc);

            if (CTRL_isError(ctrlHandle)) {
                // set the enable controller flag to false
                CTRL_setFlag_enableCtrl(ctrlHandle, false);

                // set the enable system flag to false
                gMotorVars.Flag_enableSys = false;

                // disable the PWM
                HAL_disablePwm(halHandle);
            } else {
                // update the controller state
                bool flag_ctrlStateChanged = CTRL_updateState(ctrlHandle);

                // enable or disable the control
                CTRL_setFlag_enableCtrl(ctrlHandle, gMotorVars.Flag_Run_Identify);

                if (flag_ctrlStateChanged) {
                    CTRL_State_e ctrlState = CTRL_getState(ctrlHandle);

                    if (ctrlState == CTRL_State_OffLine) {
                        // enable the PWM
                        HAL_enablePwm(halHandle);
                    } else if (ctrlState == CTRL_State_OnLine) {
                        if (gMotorVars.Flag_enableOffsetcalc == true) {
                            // update the ADC bias values
                            HAL_updateAdcBias(halHandle);
                        } else {
                            // set the current bias
                            HAL_setBias(halHandle, HAL_SensorType_Current, 0, _IQ(I_A_offset));
                            HAL_setBias(halHandle, HAL_SensorType_Current, 1, _IQ(I_B_offset));
                            HAL_setBias(halHandle, HAL_SensorType_Current, 2, _IQ(I_C_offset));

                            // set the voltage bias
                            HAL_setBias(halHandle, HAL_SensorType_Voltage, 0, _IQ(V_A_offset));
                            HAL_setBias(halHandle, HAL_SensorType_Voltage, 1, _IQ(V_B_offset));
                            HAL_setBias(halHandle, HAL_SensorType_Voltage, 2, _IQ(V_C_offset));
                        }

                        // Return the bias value for currents
                        gMotorVars.I_bias.value[0] = HAL_getBias(halHandle, HAL_SensorType_Current, 0);
                        gMotorVars.I_bias.value[1] = HAL_getBias(halHandle, HAL_SensorType_Current, 1);
                        gMotorVars.I_bias.value[2] = HAL_getBias(halHandle, HAL_SensorType_Current, 2);

                        // Return the bias value for voltages
                        gMotorVars.V_bias.value[0] = HAL_getBias(halHandle, HAL_SensorType_Voltage, 0);
                        gMotorVars.V_bias.value[1] = HAL_getBias(halHandle, HAL_SensorType_Voltage, 1);
                        gMotorVars.V_bias.value[2] = HAL_getBias(halHandle, HAL_SensorType_Voltage, 2);

                        // enable the PWM
                        HAL_enablePwm(halHandle);
                    } else if (ctrlState == CTRL_State_Idle) {
                        // disable the PWM
                        HAL_disablePwm(halHandle);
                        gMotorVars.Flag_Run_Identify = false;
                    }

                    if ((CTRL_getFlag_enableUserMotorParams(ctrlHandle) == true) &&
                        (ctrlState > CTRL_State_Idle) &&
                        (gMotorVars.CtrlVersion.minor == 6)) {
                        // call this function to fix 1p6
                        USER_softwareUpdate1p6(ctrlHandle);
                    }
                }
            }

            if (EST_isMotorIdentified(obj->estHandle)) {
                _iq Is_Max_squared_pu = _IQ((USER_MOTOR_MAX_CURRENT * USER_MOTOR_MAX_CURRENT) /
                                            (USER_IQ_FULL_SCALE_CURRENT_A * USER_IQ_FULL_SCALE_CURRENT_A));
                _iq Id_squared_pu = _IQmpy(CTRL_getId_ref_pu(ctrlHandle), CTRL_getId_ref_pu(ctrlHandle));

                // Take into consideration that Iq^2+Id^2 = Is^2
                Iq_Max_pu = _IQsqrt(Is_Max_squared_pu - Id_squared_pu);

                // Set new max trajectory
                CTRL_setSpdMax(ctrlHandle, Iq_Max_pu);

                // set the current ramp
                EST_setMaxCurrentSlope_pu(obj->estHandle, gMaxCurrentSlope);
                gMotorVars.Flag_MotorIdentified = true;

                // set the speed reference
                CTRL_setSpd_ref_krpm(ctrlHandle, gMotorVars.SpeedRef_krpm);

                // set the speed acceleration
                CTRL_setMaxAccel_pu(ctrlHandle, _IQmpy(MAX_ACCEL_KRPMPS_SF, gMotorVars.MaxAccel_krpmps));

                if (Flag_Latch_softwareUpdate) {
                    Flag_Latch_softwareUpdate = false;

                    USER_calcPIgains(ctrlHandle);

                    // initialize the watch window kp and ki current values with pre-calculated values
                    gMotorVars.Kp_Idq = CTRL_getKp(ctrlHandle, CTRL_Type_PID_Id);
                    gMotorVars.Ki_Idq = CTRL_getKi(ctrlHandle, CTRL_Type_PID_Id);
                }

            } else {
                Flag_Latch_softwareUpdate = true;

                // initialize the watch window kp and ki values with pre-calculated values
                gMotorVars.Kp_spd = CTRL_getKp(ctrlHandle, CTRL_Type_PID_spd);
                gMotorVars.Ki_spd = CTRL_getKi(ctrlHandle, CTRL_Type_PID_spd);

                // the estimator sets the maximum current slope during identification
                gMaxCurrentSlope = EST_getMaxCurrentSlope_pu(obj->estHandle);
            }

            // when appropriate, update the global variables
            if (gCounter_updateGlobals >= NUM_MAIN_TICKS_FOR_GLOBAL_VARIABLE_UPDATE) {
                // reset the counter
                gCounter_updateGlobals = 0;

                updateGlobalVariables_motor(ctrlHandle);
            }

            // update Kp and Ki gains
            updateKpKiGains(ctrlHandle);

            // set field weakening enable flag depending on user's input
            FW_setFlag_enableFw(fwHandle, gMotorVars.Flag_enableFieldWeakening);

            // enable/disable the forced angle
            EST_setFlag_enableForceAngle(obj->estHandle, gMotorVars.Flag_enableForceAngle);

            // enable or disable power warp
            CTRL_setFlag_enablePowerWarp(ctrlHandle, gMotorVars.Flag_enablePowerWarp);

#ifdef DRV8301_SPI
            HAL_writeDrvData(halHandle, &gDrvSpi8301Vars);

            HAL_readDrvData(halHandle, &gDrvSpi8301Vars);
#endif
#ifdef DRV8305_SPI
            HAL_writeDrvData(halHandle, &gDrvSpi8305Vars);

            HAL_readDrvData(halHandle, &gDrvSpi8305Vars);
#endif

        }  // end of while(gFlag_enableSys) loop

        // disable the PWM
        HAL_disablePwm(halHandle);

        // set the default controller parameters (Reset the control to re-identify the motor)
        CTRL_setParams(ctrlHandle, &gUserParams);
        gMotorVars.Flag_Run_Identify = false;

    }  // end of for(;;) loop

}  // end of main() function

interrupt void mainISR(void) {
    // toggle status LED
    if (++gLEDcnt >= (uint_least32_t)(USER_ISR_FREQ_Hz / LED_BLINK_FREQ_Hz)) {
        HAL_toggleLed(halHandle, (GPIO_Number_e)HAL_Gpio_LED2);
        gLEDcnt = 0;
    }

    // acknowledge the ADC interrupt
    HAL_acqAdcInt(halHandle, ADC_IntNumber_1);

    // convert the ADC data
    HAL_readAdcData(halHandle, &gAdcData);

    // run the controller
    CTRL_run(ctrlHandle, halHandle, &gAdcData, &gPwmData);

    // write the PWM compare values
    HAL_writePwmData(halHandle, &gPwmData);

    if (FW_getFlag_enableFw(fwHandle) == true) {
        FW_incCounter(fwHandle);

        if (FW_getCounter(fwHandle) > FW_getNumIsrTicksPerFwTick(fwHandle)) {
            _iq refValue;
            _iq fbackValue;
            _iq output;

            FW_clearCounter(fwHandle);

            refValue = gMotorVars.VsRef;

            fbackValue = gMotorVars.Vs;

            FW_run(fwHandle, refValue, fbackValue, &output);

            CTRL_setId_ref_pu(ctrlHandle, output);

            gMotorVars.IdRef_A = _IQmpy(CTRL_getId_ref_pu(ctrlHandle), _IQ(USER_IQ_FULL_SCALE_CURRENT_A));
        }
    } else {
        CTRL_setId_ref_pu(ctrlHandle, _IQmpy(gMotorVars.IdRef_A, _IQ(1.0 / USER_IQ_FULL_SCALE_CURRENT_A)));
    }

    // setup the controller
    CTRL_setup(ctrlHandle);

    return;
}  // end of mainISR() function

void updateGlobalVariables_motor(CTRL_Handle handle) {
    CTRL_Obj *obj = (CTRL_Obj *)handle;
    int32_t tmp;

    // get the speed estimate
    gMotorVars.Speed_krpm = EST_getSpeed_krpm(obj->estHandle);

    // get the real time speed reference coming out of the speed trajectory generator
    gMotorVars.SpeedTraj_krpm = _IQmpy(CTRL_getSpd_int_ref_pu(handle), EST_get_pu_to_krpm_sf(obj->estHandle));

    // get the torque estimate
    gMotorVars.Torque_Nm = USER_computeTorque_Nm(handle, gTorque_Flux_Iq_pu_to_Nm_sf, gTorque_Ls_Id_Iq_pu_to_Nm_sf);

    // when calling EST_ functions that return a float, and fpu32 is enabled, an integer is needed as a return
    // so that the compiler reads the returned value from the accumulator instead of fpu32 registers
    // get the magnetizing current
    tmp = EST_getIdRated(obj->estHandle);
    gMotorVars.MagnCurr_A = *((float_t *)&tmp);

    // get the rotor resistance
    tmp = EST_getRr_Ohm(obj->estHandle);
    gMotorVars.Rr_Ohm = *((float_t *)&tmp);

    // get the stator resistance
    tmp = EST_getRs_Ohm(obj->estHandle);
    gMotorVars.Rs_Ohm = *((float_t *)&tmp);

    // get the stator inductance in the direct coordinate direction
    tmp = EST_getLs_d_H(obj->estHandle);
    gMotorVars.Lsd_H = *((float_t *)&tmp);

    // get the stator inductance in the quadrature coordinate direction
    tmp = EST_getLs_q_H(obj->estHandle);
    gMotorVars.Lsq_H = *((float_t *)&tmp);

    // get the flux in V/Hz in floating point
    tmp = EST_getFlux_VpHz(obj->estHandle);
    gMotorVars.Flux_VpHz = *((float_t *)&tmp);

    // get the flux in Wb in fixed point
    gMotorVars.Flux_Wb = USER_computeFlux(handle, gFlux_pu_to_Wb_sf);

    // get the controller state
    gMotorVars.CtrlState = CTRL_getState(handle);

    // get the estimator state
    gMotorVars.EstState = EST_getState(obj->estHandle);

    // read Vd and Vq vectors per units
    gMotorVars.Vd = CTRL_getVd_out_pu(ctrlHandle);
    gMotorVars.Vq = CTRL_getVq_out_pu(ctrlHandle);

    // calculate vector Vs in per units
    gMotorVars.Vs = _IQsqrt(_IQmpy(gMotorVars.Vd, gMotorVars.Vd) + _IQmpy(gMotorVars.Vq, gMotorVars.Vq));

    // read Id and Iq vectors in amps
    gMotorVars.Id_A = _IQmpy(CTRL_getId_in_pu(ctrlHandle), _IQ(USER_IQ_FULL_SCALE_CURRENT_A));
    gMotorVars.Iq_A = _IQmpy(CTRL_getIq_in_pu(ctrlHandle), _IQ(USER_IQ_FULL_SCALE_CURRENT_A));

    // calculate vector Is in amps
    gMotorVars.Is_A = _IQsqrt(_IQmpy(gMotorVars.Id_A, gMotorVars.Id_A) + _IQmpy(gMotorVars.Iq_A, gMotorVars.Iq_A));

    // Get the DC buss voltage
    gMotorVars.VdcBus_kV = _IQmpy(gAdcData.dcBus, _IQ(USER_IQ_FULL_SCALE_VOLTAGE_V / 1000.0));

    return;
}  // end of updateGlobalVariables_motor() function

void updateKpKiGains(CTRL_Handle handle) {
    if ((gMotorVars.CtrlState == CTRL_State_OnLine) && (gMotorVars.Flag_MotorIdentified == true) && (Flag_Latch_softwareUpdate == false)) {
        // set the kp and ki speed values from the watch window
        CTRL_setKp(handle, CTRL_Type_PID_spd, gMotorVars.Kp_spd);
        CTRL_setKi(handle, CTRL_Type_PID_spd, gMotorVars.Ki_spd);

        // set the kp and ki current values for Id and Iq from the watch window
        CTRL_setKp(handle, CTRL_Type_PID_Id, gMotorVars.Kp_Idq);
        CTRL_setKi(handle, CTRL_Type_PID_Id, gMotorVars.Ki_Idq);
        CTRL_setKp(handle, CTRL_Type_PID_Iq, gMotorVars.Kp_Idq);
        CTRL_setKi(handle, CTRL_Type_PID_Iq, gMotorVars.Ki_Idq);
    }

    return;
}  // end of updateKpKiGains() function

interrupt void timer0ISR(void) {
    // acknowledge the Timer 0 interrupt
    HAL_acqTimer0Int(halHandle);
    // toggle status LED
    // HAL_toggleLed(halHandle,HAL_GPIO_LED3);
    timer0_count++;
    return;
}  // end of timer0ISR() function

interrupt void ecan0ISR(void) {
    ecan_isrFlags0 = 1;
    ecan_int0count++;
    HAL_pieAckInt(halHandle, PIE_GroupNumber_9);
    return;
}

interrupt void ecan1ISR(void) {
    ecan_isrFlags1 = 1;
    ecan_int1count++;
    HAL_pieAckInt(halHandle, PIE_GroupNumber_9);
    return;
}

//@} //defgroup
// end of file
