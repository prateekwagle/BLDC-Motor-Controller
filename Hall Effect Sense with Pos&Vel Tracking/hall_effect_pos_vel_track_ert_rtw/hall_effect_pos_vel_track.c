/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hall_effect_pos_vel_track.c
 *
 * Code generated for Simulink model 'hall_effect_pos_vel_track'.
 *
 * Model version                  : 4.73
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 23 14:52:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hall_effect_pos_vel_track.h"
#include "rtwtypes.h"
#include "hall_effect_pos_vel_track_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_hall_effect_pos_vel_track_T hall_effect_pos_vel_track_B;

/* Block states (default storage) */
DW_hall_effect_pos_vel_track_T hall_effect_pos_vel_track_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_hall_effect_pos_vel_t_T hall_effect_pos_vel_tra_PrevZCX;

/* Real-time model */
static RT_MODEL_hall_effect_pos_vel__T hall_effect_pos_vel_track_M_;
RT_MODEL_hall_effect_pos_vel__T *const hall_effect_pos_vel_track_M =
  &hall_effect_pos_vel_track_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt' */
void isr_int1pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/Function-Call Subsystem */
    {
      /* Reset subsysRan breadcrumbs */
      srClearBC(hall_effect_pos_vel_track_DW.IfActionSubsystem1_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC
        (hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem15.SwitchCaseActionSubsystem15_Sub);

      /* Reset subsysRan breadcrumbs */
      srClearBC(hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem17_Sub);

      /* Reset subsysRan breadcrumbs */
      srClearBC(hall_effect_pos_vel_track_DW.TriggeredSubsystem2_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(hall_effect_pos_vel_track_DW.TriggeredSubsystem3_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(hall_effect_pos_vel_track_DW.FunctionCallSubsystem_SubsysRan);

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
      {
        real_T rtb_CombinatorialLogic;
        real32_T rtb_Add4;
        real32_T rtb_Subtract1;
        int16_T rtPrevAction;
        boolean_T rtb_Compare;

        /* Asynchronous task reads absolute time. Data (absolute time)
           transfers from low priority task (base rate) to high priority
           task (asynchronous rate). Double buffers are used to ensure
           data integrity.
           -- rtmL2HLastBufWr is the buffer index that is written last.
         */
        hall_effect_pos_vel_track_M->Timing.clockTick1 =
          hall_effect_pos_vel_track_M->
          Timing.rtmL2HDbBufClockTick
          [hall_effect_pos_vel_track_M->Timing.rtmL2HLastBufWr];

        /* S-Function (c2802xadc): '<S1>/ADC3' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC3 = (AdcaResultRegs.ADCRESULT2);
        }

        /* Product: '<S15>/Product' incorporates:
         *  Constant: '<S14>/Constant3'
         *  Constant: '<S15>/Constant1'
         *  Constant: '<S15>/Constant2'
         *  Constant: '<S1>/Constant'
         *  Product: '<S14>/Divide'
         *  Product: '<S14>/Product'
         *  Product: '<S15>/Divide'
         */
        hall_effect_pos_vel_track_B.Product = (real32_T)
          hall_effect_pos_vel_track_B.ADC3 /
          hall_effect_pos_vel_track_P.Constant3_Value *
          hall_effect_pos_vel_track_P.Constant_Value_b /
          hall_effect_pos_vel_track_P.Constant1_Value_c *
          hall_effect_pos_vel_track_P.Constant2_Value_b;

        /* DataStoreWrite: '<S1>/Data Store Write1' */
        hall_effect_pos_vel_track_DW.V_PVDD =
          hall_effect_pos_vel_track_B.Product;

        /* S-Function (c2802xadc): '<S1>/ADC' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC = (AdcaResultRegs.ADCRESULT1);
        }

        /* Product: '<S11>/Product' incorporates:
         *  Constant: '<S11>/Constant1'
         *  Constant: '<S11>/Constant2'
         *  Constant: '<S1>/Constant'
         *  Constant: '<S4>/Constant3'
         *  Product: '<S11>/Divide'
         *  Product: '<S4>/Divide'
         *  Product: '<S4>/Product'
         */
        hall_effect_pos_vel_track_B.Product_d = (real32_T)
          hall_effect_pos_vel_track_B.ADC /
          hall_effect_pos_vel_track_P.Constant3_Value_f *
          hall_effect_pos_vel_track_P.Constant_Value_b /
          hall_effect_pos_vel_track_P.Constant1_Value_d *
          hall_effect_pos_vel_track_P.Constant2_Value_g;

        /* DataStoreWrite: '<S1>/Data Store Write4' */
        hall_effect_pos_vel_track_DW.V_A = hall_effect_pos_vel_track_B.Product_d;

        /* S-Function (c2802xadc): '<S1>/ADC1' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC1 = (AdccResultRegs.ADCRESULT1);
        }

        /* Product: '<S12>/Product' incorporates:
         *  Constant: '<S12>/Constant1'
         *  Constant: '<S12>/Constant2'
         *  Constant: '<S1>/Constant'
         *  Constant: '<S5>/Constant3'
         *  Product: '<S12>/Divide'
         *  Product: '<S5>/Divide'
         *  Product: '<S5>/Product'
         */
        hall_effect_pos_vel_track_B.Product_p = (real32_T)
          hall_effect_pos_vel_track_B.ADC1 /
          hall_effect_pos_vel_track_P.Constant3_Value_j *
          hall_effect_pos_vel_track_P.Constant_Value_b /
          hall_effect_pos_vel_track_P.Constant1_Value_i *
          hall_effect_pos_vel_track_P.Constant2_Value_i;

        /* DataStoreWrite: '<S1>/Data Store Write5' */
        hall_effect_pos_vel_track_DW.V_B = hall_effect_pos_vel_track_B.Product_p;

        /* S-Function (c2802xadc): '<S1>/ADC2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC2 = (AdcbResultRegs.ADCRESULT1);
        }

        /* Product: '<S13>/Product' incorporates:
         *  Constant: '<S10>/Constant3'
         *  Constant: '<S13>/Constant1'
         *  Constant: '<S13>/Constant2'
         *  Constant: '<S1>/Constant'
         *  Product: '<S10>/Divide'
         *  Product: '<S10>/Product'
         *  Product: '<S13>/Divide'
         */
        hall_effect_pos_vel_track_B.Product_o = (real32_T)
          hall_effect_pos_vel_track_B.ADC2 /
          hall_effect_pos_vel_track_P.Constant3_Value_a *
          hall_effect_pos_vel_track_P.Constant_Value_b /
          hall_effect_pos_vel_track_P.Constant1_Value_ig *
          hall_effect_pos_vel_track_P.Constant2_Value_m;

        /* DataStoreWrite: '<S1>/Data Store Write6' */
        hall_effect_pos_vel_track_DW.V_C = hall_effect_pos_vel_track_B.Product_o;

        /* S-Function (c2802xadc): '<S1>/ADC6' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC6 = (AdcaResultRegs.ADCRESULT0);
        }

        /* Product: '<S9>/Divide' incorporates:
         *  Constant: '<S1>/Constant1'
         *  Constant: '<S6>/Constant3'
         *  Constant: '<S9>/Constant'
         *  Constant: '<S9>/Constant1'
         *  Constant: '<S9>/Constant2'
         *  Product: '<S6>/Divide'
         *  Product: '<S6>/Product'
         *  Product: '<S9>/Product'
         *  Sum: '<S9>/Subtract'
         */
        hall_effect_pos_vel_track_B.Divide = ((real32_T)
          hall_effect_pos_vel_track_B.ADC6 /
          hall_effect_pos_vel_track_P.Constant3_Value_jt *
          hall_effect_pos_vel_track_P.Constant1_Value_h -
          hall_effect_pos_vel_track_P.Constant1_Value_n) *
          hall_effect_pos_vel_track_P.Constant2_Value_ix /
          hall_effect_pos_vel_track_P.Constant_Value_k;

        /* DataStoreWrite: '<S1>/Data Store Write2' */
        hall_effect_pos_vel_track_DW.I_C = hall_effect_pos_vel_track_B.Divide;

        /* S-Function (c2802xadc): '<S1>/ADC4' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC4 = (AdccResultRegs.ADCRESULT0);
        }

        /* Product: '<S7>/Divide' incorporates:
         *  Constant: '<S16>/Constant3'
         *  Constant: '<S1>/Constant1'
         *  Constant: '<S7>/Constant'
         *  Constant: '<S7>/Constant1'
         *  Constant: '<S7>/Constant2'
         *  Product: '<S16>/Divide'
         *  Product: '<S16>/Product'
         *  Product: '<S7>/Product'
         *  Sum: '<S7>/Subtract'
         */
        hall_effect_pos_vel_track_B.Divide_b = ((real32_T)
          hall_effect_pos_vel_track_B.ADC4 /
          hall_effect_pos_vel_track_P.Constant3_Value_o *
          hall_effect_pos_vel_track_P.Constant1_Value_h -
          hall_effect_pos_vel_track_P.Constant1_Value_hp) *
          hall_effect_pos_vel_track_P.Constant2_Value_p /
          hall_effect_pos_vel_track_P.Constant_Value_e;

        /* DataStoreWrite: '<S1>/Data Store Write3' */
        hall_effect_pos_vel_track_DW.I_A = hall_effect_pos_vel_track_B.Divide_b;

        /* S-Function (c2802xadc): '<S1>/ADC5' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          hall_effect_pos_vel_track_B.ADC5 = (AdcbResultRegs.ADCRESULT0);
        }

        /* Product: '<S8>/Divide' incorporates:
         *  Constant: '<S17>/Constant3'
         *  Constant: '<S1>/Constant1'
         *  Constant: '<S8>/Constant'
         *  Constant: '<S8>/Constant1'
         *  Constant: '<S8>/Constant2'
         *  Product: '<S17>/Divide'
         *  Product: '<S17>/Product'
         *  Product: '<S8>/Product'
         *  Sum: '<S8>/Subtract'
         */
        hall_effect_pos_vel_track_B.Divide_d = ((real32_T)
          hall_effect_pos_vel_track_B.ADC5 /
          hall_effect_pos_vel_track_P.Constant3_Value_jd *
          hall_effect_pos_vel_track_P.Constant1_Value_h -
          hall_effect_pos_vel_track_P.Constant1_Value_e) *
          hall_effect_pos_vel_track_P.Constant2_Value_l /
          hall_effect_pos_vel_track_P.Constant_Value_l;

        /* DataStoreWrite: '<S1>/Data Store Write7' */
        hall_effect_pos_vel_track_DW.I_B = hall_effect_pos_vel_track_B.Divide_d;

        /* S-Function (c280xgpio_di): '<S1>/Hall_V_Digital1' */
        {
          hall_effect_pos_vel_track_B.Hall_V_Digital1 =
            GpioDataRegs.GPADAT.bit.GPIO29;
        }

        /* S-Function (c280xgpio_di): '<S1>/Hall_W_Digital1' */
        {
          hall_effect_pos_vel_track_B.Hall_W_Digital1 =
            GpioDataRegs.GPDDAT.bit.GPIO125;
        }

        /* S-Function (c280xgpio_di): '<S1>/Hall_U_Digital1' */
        {
          hall_effect_pos_vel_track_B.Hall_U_Digital1 =
            GpioDataRegs.GPDDAT.bit.GPIO124;
        }

        /* CombinatorialLogic: '<S1>/Combinatorial  Logic' */
        rtb_CombinatorialLogic =
          hall_effect_pos_vel_track_P.CombinatorialLogic_table[((((uint16_T)
          hall_effect_pos_vel_track_B.Hall_V_Digital1 << 1) +
          hall_effect_pos_vel_track_B.Hall_W_Digital1) << 1) +
          hall_effect_pos_vel_track_B.Hall_U_Digital1];

        /* Sum: '<S1>/Subtract1' incorporates:
         *  DataTypeConversion: '<S1>/Cast To Single'
         *  Delay: '<S1>/Delay One Step3'
         */
        rtb_Subtract1 = (real32_T)rtb_CombinatorialLogic -
          hall_effect_pos_vel_track_DW.DelayOneStep3_DSTATE;

        /* SwitchCase: '<S1>/Switch Case3' */
        rtPrevAction = hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem;
        if (rtb_Subtract1 < 0.0F) {
          rtb_Add4 = (real32_T)ceil(rtb_Subtract1);
        } else {
          rtb_Add4 = (real32_T)floor(rtb_Subtract1);
        }

        if (rtIsNaNF(rtb_Add4) || rtIsInfF(rtb_Add4)) {
          rtb_Add4 = 0.0F;
        } else {
          rtb_Add4 = (real32_T)fmod(rtb_Add4, 4.294967296E+9);
        }

        switch (rtb_Add4 < 0.0F ? -(int32_T)(uint32_T)-rtb_Add4 : (int32_T)
                (uint32_T)rtb_Add4) {
         case -5L:
          hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem = 0;
          break;

         case 5L:
          hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem = 1;
          break;

         default:
          hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem = 2;
          break;
        }

        if (rtPrevAction !=
            hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem) {
          switch (rtPrevAction) {
           case 0:
            SwitchCaseActionSubsyst_Disable
              (&hall_effect_pos_vel_track_B.Product_ph,
               &hall_effect_pos_vel_track_P.SwitchCaseActionSubsystem15);
            break;

           case 1:
            SwitchCaseActionSubsyst_Disable
              (&hall_effect_pos_vel_track_B.Product_f,
               &hall_effect_pos_vel_track_P.SwitchCaseActionSubsystem16);
            break;

           case 2:
            /* Disable for Product: '<S20>/Product' incorporates:
             *  Outport: '<S20>/Out1'
             * */
            hall_effect_pos_vel_track_B.Product_od =
              hall_effect_pos_vel_track_P.Out1_Y0;
            break;
          }
        }

        switch (hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem15' incorporates:
           *  ActionPort: '<S18>/Action Port'
           */
          hal_SwitchCaseActionSubsystem15
            (&hall_effect_pos_vel_track_B.Product_ph,
             &hall_effect_pos_vel_track_P.SwitchCaseActionSubsystem15);
          hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem15.SwitchCaseActionSubsystem15_Sub
            = 4;

          /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem15' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem16' incorporates:
           *  ActionPort: '<S19>/Action Port'
           */
          hal_SwitchCaseActionSubsystem15(&hall_effect_pos_vel_track_B.Product_f,
            &hall_effect_pos_vel_track_P.SwitchCaseActionSubsystem16);
          hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem16.SwitchCaseActionSubsystem15_Sub
            = 4;

          /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem16' */
          break;

         default:
          /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem17' incorporates:
           *  ActionPort: '<S20>/Action Port'
           */
          /* Product: '<S20>/Product' incorporates:
           *  Constant: '<S20>/Constant2'
           *  Constant: '<S20>/Pi'
           *  Product: '<S20>/Divide'
           */
          hall_effect_pos_vel_track_B.Product_od = rtb_Subtract1 /
            hall_effect_pos_vel_track_P.Constant2_Value *
            hall_effect_pos_vel_track_P.Pi_Value;
          hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem17_Sub = 4;

          /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem17' */
          break;
        }

        /* End of SwitchCase: '<S1>/Switch Case3' */

        /* Sum: '<S1>/Add4' */
        rtb_Add4 = (hall_effect_pos_vel_track_B.Product_ph +
                    hall_effect_pos_vel_track_B.Product_f) +
          hall_effect_pos_vel_track_B.Product_od;

        /* RelationalOperator: '<S2>/Compare' incorporates:
         *  Constant: '<S2>/Constant'
         */
        rtb_Compare = (rtb_Subtract1 !=
                       hall_effect_pos_vel_track_P.Constant_Value_h);

        /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem2' incorporates:
         *  TriggerPort: '<S21>/Trigger'
         */
        if (rtb_Compare &&
            (hall_effect_pos_vel_tra_PrevZCX.TriggeredSubsystem2_Trig_ZCE !=
             POS_ZCSIG)) {
          /* Switch: '<S21>/Switch' incorporates:
           *  Constant: '<S21>/Constant1'
           *  Constant: '<S23>/Lower Limit'
           *  Constant: '<S23>/Upper Limit'
           *  Logic: '<S23>/AND'
           *  Memory: '<S21>/Memory'
           *  RelationalOperator: '<S23>/Lower Test'
           *  RelationalOperator: '<S23>/Upper Test'
           *  Sum: '<S21>/Add'
           */
          if ((!(hall_effect_pos_vel_track_P.IntervalTest_lowlimit <
                 hall_effect_pos_vel_track_B.Add)) ||
              (!(hall_effect_pos_vel_track_B.Add <
                 hall_effect_pos_vel_track_P.IntervalTest_uplimit))) {
            hall_effect_pos_vel_track_B.Add =
              hall_effect_pos_vel_track_P.Constant1_Value;
          }

          hall_effect_pos_vel_track_B.Add += rtb_Add4;

          /* End of Switch: '<S21>/Switch' */
          hall_effect_pos_vel_track_DW.TriggeredSubsystem2_SubsysRanBC = 4;
        }

        hall_effect_pos_vel_tra_PrevZCX.TriggeredSubsystem2_Trig_ZCE =
          rtb_Compare;

        /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem2' */

        /* DataStoreWrite: '<S1>/Data Store Write8' */
        hall_effect_pos_vel_track_DW.MOT_POS = hall_effect_pos_vel_track_B.Add;

        /* If: '<S1>/If1' incorporates:
         *  Delay: '<S1>/Delay One Step4'
         */
        if (hall_effect_pos_vel_track_DW.DelayOneStep4_DSTATE > 1000.0F) {
          /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S3>/Action Port'
           */
          /* DataStoreWrite: '<S3>/Data Store Write8' incorporates:
           *  Constant: '<S3>/Constant'
           */
          hall_effect_pos_vel_track_DW.MOT_VEL =
            hall_effect_pos_vel_track_P.Constant_Value;

          /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S3>/Action Port'
           */
          /* Update for If: '<S1>/If1' */
          hall_effect_pos_vel_track_DW.IfActionSubsystem1_SubsysRanBC = 4;

          /* End of Update for SubSystem: '<S1>/If Action Subsystem1' */
        }

        /* End of If: '<S1>/If1' */

        /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem3' incorporates:
         *  TriggerPort: '<S22>/Trigger'
         */
        if (rtb_Compare &&
            (hall_effect_pos_vel_tra_PrevZCX.TriggeredSubsystem3_Trig_ZCE !=
             POS_ZCSIG)) {
          /* Product: '<S22>/Divide1' incorporates:
           *  Constant: '<S22>/Constant'
           *  DataStoreWrite: '<S22>/Data Store Write8'
           *  Memory generated from: '<S1>/Triggered Subsystem3'
           *  Product: '<S22>/Divide'
           */
          hall_effect_pos_vel_track_DW.MOT_VEL = rtb_Add4 /
            (hall_effect_pos_vel_track_DW.TmpLatchAtTriggeredSubsystem3In /
             hall_effect_pos_vel_track_P.Constant_Value_i);
          hall_effect_pos_vel_track_DW.TriggeredSubsystem3_SubsysRanBC = 4;
        }

        hall_effect_pos_vel_tra_PrevZCX.TriggeredSubsystem3_Trig_ZCE =
          rtb_Compare;

        /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem3' */

        /* Switch: '<S1>/Switch1' */
        if (rtb_Compare) {
          /* Switch: '<S1>/Switch1' incorporates:
           *  Constant: '<S1>/Constant5'
           */
          hall_effect_pos_vel_track_DW.DelayOneStep4_DSTATE =
            hall_effect_pos_vel_track_P.Constant5_Value;
        } else {
          /* Switch: '<S1>/Switch1' incorporates:
           *  Constant: '<S1>/Constant4'
           *  Delay: '<S1>/Delay One Step4'
           *  Sum: '<S1>/Add5'
           */
          hall_effect_pos_vel_track_DW.DelayOneStep4_DSTATE +=
            hall_effect_pos_vel_track_P.Constant4_Value;
        }

        /* End of Switch: '<S1>/Switch1' */

        /* S-Function (c2802xpwm): '<S1>/ePWM' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read'
         */

        /*-- Update CMPA value for ePWM4 --*/
        {
          EPwm4Regs.CMPA.bit.CMPA = (uint16_T)(hall_effect_pos_vel_track_DW.A);
        }

        /* S-Function (c2802xpwm): '<S1>/ePWM1' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read1'
         */

        /*-- Update CMPA value for ePWM5 --*/
        {
          EPwm5Regs.CMPA.bit.CMPA = (uint16_T)(hall_effect_pos_vel_track_DW.B);
        }

        /* S-Function (c2802xpwm): '<S1>/ePWM2' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read2'
         */

        /*-- Update CMPA value for ePWM6 --*/
        {
          EPwm6Regs.CMPA.bit.CMPA = (uint16_T)(hall_effect_pos_vel_track_DW.C);
        }

        /* DataStoreRead: '<S1>/Data Store Read3' */
        hall_effect_pos_vel_track_B.DataStoreRead3 =
          hall_effect_pos_vel_track_DW.MOT_POS;

        /* DataStoreRead: '<S1>/Data Store Read4' */
        hall_effect_pos_vel_track_B.DataStoreRead4 =
          hall_effect_pos_vel_track_DW.MOT_VEL;

        /* S-Function (c280xgpio_do): '<S1>/Digital Output' incorporates:
         *  Constant: '<S1>/Enable Gate'
         */
        {
          GpioDataRegs.GPBTOGGLE.bit.GPIO52 =
            (hall_effect_pos_vel_track_P.EnableGate_Value != 0);
        }

        /* Update for Delay: '<S1>/Delay One Step3' incorporates:
         *  DataTypeConversion: '<S1>/Cast To Single'
         */
        hall_effect_pos_vel_track_DW.DelayOneStep3_DSTATE = (real32_T)
          rtb_CombinatorialLogic;

        /* Update for Memory generated from: '<S1>/Triggered Subsystem3' */
        hall_effect_pos_vel_track_DW.TmpLatchAtTriggeredSubsystem3In =
          hall_effect_pos_vel_track_DW.DelayOneStep4_DSTATE;
        hall_effect_pos_vel_track_DW.FunctionCallSubsystem_SubsysRan = 4;
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }

    currentTime = (extmodeSimulationTime_T)
      hall_effect_pos_vel_track_M->Timing.clockTick0;
    extmodeEvent(1,currentTime);
  }
}

/*
 * System initialize for action system:
 *    '<S1>/Switch Case Action Subsystem15'
 *    '<S1>/Switch Case Action Subsystem16'
 */
void SwitchCaseActionSubsystem1_Init(real32_T *rty_Out1,
  P_SwitchCaseActionSubsystem15_T *localP)
{
  /* SystemInitialize for Outport: '<S18>/Out1' */
  *rty_Out1 = localP->Out1_Y0;
}

/*
 * Disable for action system:
 *    '<S1>/Switch Case Action Subsystem15'
 *    '<S1>/Switch Case Action Subsystem16'
 */
void SwitchCaseActionSubsyst_Disable(real32_T *rty_Out1,
  P_SwitchCaseActionSubsystem15_T *localP)
{
  /* Disable for Outport: '<S18>/Out1' */
  *rty_Out1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S1>/Switch Case Action Subsystem15'
 *    '<S1>/Switch Case Action Subsystem16'
 */
void hal_SwitchCaseActionSubsystem15(real32_T *rty_Out1,
  P_SwitchCaseActionSubsystem15_T *localP)
{
  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant2'
   *  Constant: '<S18>/Pi'
   *  Product: '<S18>/Divide'
   */
  *rty_Out1 = localP->Constant_Value / localP->Constant2_Value *
    localP->Pi_Value;
}

/* Model step function */
void hall_effect_pos_vel_track_step(void)
{
  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  hall_effect_pos_vel_track_DW.A = hall_effect_pos_vel_track_P.Constant_Value_c;

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  hall_effect_pos_vel_track_DW.B = hall_effect_pos_vel_track_P.Constant1_Value_a;

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  hall_effect_pos_vel_track_DW.C = hall_effect_pos_vel_track_P.Constant2_Value_e;

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Enable Gate'
   */
  {
    if (hall_effect_pos_vel_track_P.EnableGate_Value_f)
      GpioDataRegs.GPASET.bit.GPIO26 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Wake'
   */
  {
    if (hall_effect_pos_vel_track_P.Wake_Value)
      GpioDataRegs.GPASET.bit.GPIO27 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
  }

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  hall_effect_pos_vel_track_M->Timing.taskTime0 =
    ((time_T)(++hall_effect_pos_vel_track_M->Timing.clockTick0)) *
    hall_effect_pos_vel_track_M->Timing.stepSize0;

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !(hall_effect_pos_vel_track_M->Timing.rtmL2HLastBufWr !=
                         0U);
    hall_effect_pos_vel_track_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      hall_effect_pos_vel_track_M->Timing.clockTick0;
    hall_effect_pos_vel_track_M->Timing.rtmL2HLastBufWr = bufIdx ? 1U : 0U;
  }
}

/* Model initialize function */
void hall_effect_pos_vel_track_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)hall_effect_pos_vel_track_M, 0,
                sizeof(RT_MODEL_hall_effect_pos_vel__T));
  rtmSetTFinal(hall_effect_pos_vel_track_M, -1);
  hall_effect_pos_vel_track_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  hall_effect_pos_vel_track_M->Sizes.checksums[0] = (731664905U);
  hall_effect_pos_vel_track_M->Sizes.checksums[1] = (1533303453U);
  hall_effect_pos_vel_track_M->Sizes.checksums[2] = (1491280125U);
  hall_effect_pos_vel_track_M->Sizes.checksums[3] = (1477902816U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    hall_effect_pos_vel_track_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem15.SwitchCaseActionSubsystem15_Sub;
    systemRan[3] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem16.SwitchCaseActionSubsystem15_Sub;
    systemRan[4] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.SwitchCaseActionSubsystem17_Sub;
    systemRan[5] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[6] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[7] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.TriggeredSubsystem2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.TriggeredSubsystem2_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.TriggeredSubsystem3_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &hall_effect_pos_vel_track_DW.FunctionCallSubsystem_SubsysRan;
    rteiSetModelMappingInfoPtr(hall_effect_pos_vel_track_M->extModeInfo,
      &hall_effect_pos_vel_track_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(hall_effect_pos_vel_track_M->extModeInfo,
                        hall_effect_pos_vel_track_M->Sizes.checksums);
    rteiSetTPtr(hall_effect_pos_vel_track_M->extModeInfo, rtmGetTPtr
                (hall_effect_pos_vel_track_M));
  }

  /* block I/O */
  (void) memset(((void *) &hall_effect_pos_vel_track_B), 0,
                sizeof(B_hall_effect_pos_vel_track_T));

  /* states (dwork) */
  (void) memset((void *)&hall_effect_pos_vel_track_DW, 0,
                sizeof(DW_hall_effect_pos_vel_track_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Enable Gate'
   */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFCFFFFF;
  GpioCtrlRegs.GPADIR.all |= 0x4000000;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Wake'
   */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFF3FFFFF;
  GpioCtrlRegs.GPADIR.all |= 0x8000000;
  EDIS;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  hall_effect_pos_vel_track_DW.A =
    hall_effect_pos_vel_track_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  hall_effect_pos_vel_track_DW.B =
    hall_effect_pos_vel_track_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  hall_effect_pos_vel_track_DW.C =
    hall_effect_pos_vel_track_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  hall_effect_pos_vel_track_DW.MOT_VEL =
    hall_effect_pos_vel_track_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  hall_effect_pos_vel_track_DW.MOT_POS =
    hall_effect_pos_vel_track_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  hall_effect_pos_vel_track_DW.I_A =
    hall_effect_pos_vel_track_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  hall_effect_pos_vel_track_DW.I_B =
    hall_effect_pos_vel_track_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  hall_effect_pos_vel_track_DW.I_C =
    hall_effect_pos_vel_track_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  hall_effect_pos_vel_track_DW.V_A =
    hall_effect_pos_vel_track_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  hall_effect_pos_vel_track_DW.V_B =
    hall_effect_pos_vel_track_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  hall_effect_pos_vel_track_DW.V_C =
    hall_effect_pos_vel_track_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  hall_effect_pos_vel_track_DW.V_PVDD =
    hall_effect_pos_vel_track_P.DataStoreMemory9_InitialValue;
  hall_effect_pos_vel_tra_PrevZCX.TriggeredSubsystem2_Trig_ZCE = POS_ZCSIG;
  hall_effect_pos_vel_tra_PrevZCX.TriggeredSubsystem3_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  hall_effect_pos_vel_track_M->Timing.clockTick1 =
    hall_effect_pos_vel_track_M->
    Timing.rtmL2HDbBufClockTick
    [hall_effect_pos_vel_track_M->Timing.rtmL2HLastBufWr];

  /* Start for S-Function (c2802xadc): '<S1>/ADC3' */
  if (MW_adcAInitFlag == 0) {
    InitAdcA();
    MW_adcAInitFlag = 1;
  }

  config_ADCA_SOC2 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC' */
  if (MW_adcAInitFlag == 0) {
    InitAdcA();
    MW_adcAInitFlag = 1;
  }

  config_ADCA_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC1' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC2' */
  if (MW_adcBInitFlag == 0) {
    InitAdcB();
    MW_adcBInitFlag = 1;
  }

  config_ADCB_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC6' */
  if (MW_adcAInitFlag == 0) {
    InitAdcA();
    MW_adcAInitFlag = 1;
  }

  config_ADCA_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC4' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC5' */
  if (MW_adcBInitFlag == 0) {
    InitAdcB();
    MW_adcBInitFlag = 1;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c280xgpio_di): '<S1>/Hall_V_Digital1' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xF3FFFFFF;
  GpioCtrlRegs.GPADIR.all &= 0xDFFFFFFF;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<S1>/Hall_W_Digital1' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xF3FFFFFF;
  GpioCtrlRegs.GPDDIR.all &= 0xDFFFFFFF;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<S1>/Hall_U_Digital1' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFF;
  GpioCtrlRegs.GPDDIR.all &= 0xEFFFFFFF;
  EDIS;

  /* Start for SwitchCase: '<S1>/Switch Case3' */
  hall_effect_pos_vel_track_DW.SwitchCase3_ActiveSubsystem = -1;

  /* Start for S-Function (c2802xpwm): '<S1>/ePWM' */

  /*** Initialize ePWM4 modules ***/
  {
    /*  // Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 1;          // Sync Output Select

       EPwm4Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm4Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFF) | 0x12;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xC000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 10000;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm4Regs.CMPA.bit.CMPA = 32000;   // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm4Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm4Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 105;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 3;          // Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 2;          // Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFF) | 0xB;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(10.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(10.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 1;          // Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm4Regs.ETSEL.bit.INTEN                = 0;          // EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7F) | 0x1901;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30) | 0x30;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 0;          // TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 0;          // TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFF) | 0xFF0;

    /*	// Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select

     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm4Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0) | 0x0;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S1>/ePWM1' */

  /*** Initialize ePWM5 modules ***/
  {
    /*  // Time Base Control Register
       EPwm5Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm5Regs.TBCTL.bit.SYNCOSEL             = 0;          // Sync Output Select

       EPwm5Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm5Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm5Regs.TBCTL.bit.PHSEN                = 1;          // Phase Load Enable
       EPwm5Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm5Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm5Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm5Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FFF) | 0x6;
    EPwm5Regs.TBCTL2.all = (EPwm5Regs.TBCTL2.all & ~0xC000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm5Regs.TBPRD = 10000;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm5Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm5Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm5Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm5Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm5Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm5Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm5Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm5Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm5Regs.CMPCTL2.all = (EPwm5Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm5Regs.CMPA.bit.CMPA = 32000;   // Counter Compare A Register
    EPwm5Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm5Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm5Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm5Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm5Regs.AQCTLB.all = 105;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm5Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm5Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm5Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm5Regs.DBCTL.bit.OUT_MODE             = 3;          // Dead Band Output Mode Control
       EPwm5Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm5Regs.DBCTL.bit.POLSEL               = 2;          // Polarity Select Control
       EPwm5Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm5Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm5Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm5Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm5Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x8FFF) | 0xB;
    EPwm5Regs.DBRED.bit.DBRED = (uint16_T)(10.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm5Regs.DBFED.bit.DBFED = (uint16_T)(10.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm5Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm5Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm5Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM5SOC Period Select
       EPwm5Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm5Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm5Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm5Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM5SOCB Period Select
       EPwm5Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm5Regs.ETSEL.bit.INTEN                = 0;          // EPWM5INTn Enable
       EPwm5Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm5Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm5Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM5INTn Period Select
       EPwm5Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF7F) | 0x1001;
    EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x30) | 0x30;
    EPwm5Regs.ETSOCPS.all = (EPwm5Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm5Regs.ETINTPS.all = (EPwm5Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm5Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm5Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm5Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm5Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm5Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm5Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM5A
       EPwm5Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM5B
       EPwm5Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM5A action on DCAEVT1
       EPwm5Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM5A action on DCAEVT2
       EPwm5Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM5B action on DCBEVT1
       EPwm5Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM5B action on DCBEVT2
     */
    EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm5Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm5Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm5Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm5Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm5Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm5Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm5Regs.DCACTL.all = (EPwm5Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm5Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm5Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm5Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm5Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm5Regs.DCBCTL.all = (EPwm5Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm5Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm5Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select

     */
    EPwm5Regs.DCTRIPSEL.all = (EPwm5Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm5Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm5Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm5Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm5Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm5Regs.TZDCSEL.all = (EPwm5Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm5Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm5Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm5Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm5Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm5Regs.DCFCTL.all = (EPwm5Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm5Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm5Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm5Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm5Regs.DCCAPCTL.all = (EPwm5Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm5Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm5Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm5Regs.HRCNFG.all = (EPwm5Regs.HRCNFG.all & ~0xA0) | 0x0;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm5Regs.EPWMXLINK.bit.TBPRDLINK = 4;
    EPwm5Regs.EPWMXLINK.bit.CMPALINK = 4;
    EPwm5Regs.EPWMXLINK.bit.CMPBLINK = 4;
    EPwm5Regs.EPWMXLINK.bit.CMPCLINK = 4;
    EPwm5Regs.EPWMXLINK.bit.CMPDLINK = 4;

    /* SYNCPER - Peripheral synchronization output event
       EPwm5Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm5Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm5Regs.HRPCTL.all = (EPwm5Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S1>/ePWM2' */

  /*** Initialize ePWM6 modules ***/
  {
    /*  // Time Base Control Register
       EPwm6Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm6Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm6Regs.TBCTL2.bit.SYNCOSELX           = 0;          // Sync Output Select - additional options

       EPwm6Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm6Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm6Regs.TBCTL.bit.PHSEN                = 1;          // Phase Load Enable
       EPwm6Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm6Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm6Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm6Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm6Regs.TBCTL.all = (EPwm6Regs.TBCTL.all & ~0x3FFF) | 0x36;
    EPwm6Regs.TBCTL2.all = (EPwm6Regs.TBCTL2.all & ~0xF000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm6Regs.TBPRD = 10000;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm6Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm6Regs.TBPHS.all = (EPwm6Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm6Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm6Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm6Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm6Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm6Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm6Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm6Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm6Regs.CMPCTL.all = (EPwm6Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm6Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm6Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm6Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm6Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm6Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm6Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm6Regs.CMPCTL2.all = (EPwm6Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm6Regs.CMPA.bit.CMPA = 32000;   // Counter Compare A Register
    EPwm6Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm6Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm6Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm6Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm6Regs.AQCTLB.all = 105;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm6Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm6Regs.AQSFRC.all = (EPwm6Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm6Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm6Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm6Regs.AQCSFRC.all = (EPwm6Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm6Regs.DBCTL.bit.OUT_MODE             = 3;          // Dead Band Output Mode Control
       EPwm6Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm6Regs.DBCTL.bit.POLSEL               = 2;          // Polarity Select Control
       EPwm6Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm6Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm6Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm6Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm6Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm6Regs.DBCTL.all = (EPwm6Regs.DBCTL.all & ~0x8FFF) | 0xB;
    EPwm6Regs.DBRED.bit.DBRED = (uint16_T)(10.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm6Regs.DBFED.bit.DBFED = (uint16_T)(10.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm6Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm6Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm6Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm6Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM6SOC Period Select
       EPwm6Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm6Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm6Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm6Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm6Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM6SOCB Period Select
       EPwm6Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm6Regs.ETSEL.bit.INTEN                = 0;          // EPWM6INTn Enable
       EPwm6Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm6Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm6Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM6INTn Period Select
       EPwm6Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm6Regs.ETSEL.all = (EPwm6Regs.ETSEL.all & ~0xFF7F) | 0x1001;
    EPwm6Regs.ETPS.all = (EPwm6Regs.ETPS.all & ~0x30) | 0x30;
    EPwm6Regs.ETSOCPS.all = (EPwm6Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm6Regs.ETINTPS.all = (EPwm6Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm6Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm6Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm6Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm6Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm6Regs.PCCTL.all = (EPwm6Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm6Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm6Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM6A
       EPwm6Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM6B
       EPwm6Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM6A action on DCAEVT1
       EPwm6Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM6A action on DCAEVT2
       EPwm6Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM6B action on DCBEVT1
       EPwm6Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM6B action on DCBEVT2
     */
    EPwm6Regs.TZCTL.all = (EPwm6Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm6Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm6Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm6Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm6Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm6Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm6Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm6Regs.TZEINT.all = (EPwm6Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm6Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm6Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm6Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm6Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm6Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm6Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm6Regs.DCACTL.all = (EPwm6Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm6Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm6Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm6Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm6Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm6Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm6Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm6Regs.DCBCTL.all = (EPwm6Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm6Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm6Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm6Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm6Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select

     */
    EPwm6Regs.DCTRIPSEL.all = (EPwm6Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm6Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm6Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm6Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm6Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm6Regs.TZDCSEL.all = (EPwm6Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm6Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm6Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm6Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm6Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm6Regs.DCFCTL.all = (EPwm6Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm6Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm6Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm6Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm6Regs.DCCAPCTL.all = (EPwm6Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm6Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm6Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm6Regs.HRCNFG.all = (EPwm6Regs.HRCNFG.all & ~0xA0) | 0x0;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm6Regs.EPWMXLINK.bit.TBPRDLINK = 5;
    EPwm6Regs.EPWMXLINK.bit.CMPALINK = 5;
    EPwm6Regs.EPWMXLINK.bit.CMPBLINK = 5;
    EPwm6Regs.EPWMXLINK.bit.CMPCLINK = 5;
    EPwm6Regs.EPWMXLINK.bit.CMPDLINK = 5;

    /* SYNCPER - Peripheral synchronization output event
       EPwm6Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm6Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm6Regs.HRPCTL.all = (EPwm6Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
    EALLOW;

    /* Enable TBCLK within the EPWM*/
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S1>/Digital Output' incorporates:
   *  Constant: '<S1>/Enable Gate'
   */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFCFF;
  GpioCtrlRegs.GPBDIR.all |= 0x100000;
  EDIS;

  /* InitializeConditions for Delay: '<S1>/Delay One Step3' */
  hall_effect_pos_vel_track_DW.DelayOneStep3_DSTATE =
    hall_effect_pos_vel_track_P.DelayOneStep3_InitialCondition;

  /* InitializeConditions for Switch: '<S1>/Switch1' incorporates:
   *  Delay: '<S1>/Delay One Step4'
   */
  hall_effect_pos_vel_track_DW.DelayOneStep4_DSTATE =
    hall_effect_pos_vel_track_P.DelayOneStep4_InitialCondition;

  /* InitializeConditions for Memory generated from: '<S1>/Triggered Subsystem3' */
  hall_effect_pos_vel_track_DW.TmpLatchAtTriggeredSubsystem3In =
    hall_effect_pos_vel_track_P.TmpLatchAtTriggeredSubsystem3In;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Switch Case Action Subsystem15' */
  SwitchCaseActionSubsystem1_Init(&hall_effect_pos_vel_track_B.Product_ph,
    &hall_effect_pos_vel_track_P.SwitchCaseActionSubsystem15);

  /* End of SystemInitialize for SubSystem: '<S1>/Switch Case Action Subsystem15' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Switch Case Action Subsystem16' */
  SwitchCaseActionSubsystem1_Init(&hall_effect_pos_vel_track_B.Product_f,
    &hall_effect_pos_vel_track_P.SwitchCaseActionSubsystem16);

  /* End of SystemInitialize for SubSystem: '<S1>/Switch Case Action Subsystem16' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Switch Case Action Subsystem17' */
  /* SystemInitialize for Product: '<S20>/Product' incorporates:
   *  Outport: '<S20>/Out1'
   */
  hall_effect_pos_vel_track_B.Product_od = hall_effect_pos_vel_track_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Switch Case Action Subsystem17' */

  /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem2' */
  /* SystemInitialize for Switch: '<S21>/Switch' incorporates:
   *  Outport: '<S21>/Outport'
   *  Sum: '<S21>/Add'
   */
  hall_effect_pos_vel_track_B.Add = hall_effect_pos_vel_track_P.Outport_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem2' */
  ;

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
}

/* Model terminate function */
void hall_effect_pos_vel_track_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
