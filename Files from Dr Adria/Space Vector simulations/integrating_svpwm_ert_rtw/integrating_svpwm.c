/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integrating_svpwm.c
 *
 * Code generated for Simulink model 'integrating_svpwm'.
 *
 * Model version                  : 4.73
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul 26 16:25:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "integrating_svpwm.h"
#include "rtwtypes.h"
#include "integrating_svpwm_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "zero_crossing_types.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_integrating_svpwm_T integrating_svpwm_B;

/* Block states (default storage) */
DW_integrating_svpwm_T integrating_svpwm_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_integrating_svpwm_T integrating_svpwm_PrevZCX;

/* Real-time model */
static RT_MODEL_integrating_svpwm_T integrating_svpwm_M_;
RT_MODEL_integrating_svpwm_T *const integrating_svpwm_M = &integrating_svpwm_M_;

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
      srClearBC(integrating_svpwm_DW.IfActionSubsystem1_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC
        (integrating_svpwm_DW.SwitchCaseActionSubsystem15.SwitchCaseActionSubsystem15_Sub);

      /* Reset subsysRan breadcrumbs */
      srClearBC(integrating_svpwm_DW.SwitchCaseActionSubsystem17_Sub);

      /* Reset subsysRan breadcrumbs */
      srClearBC(integrating_svpwm_DW.TriggeredSubsystem2_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(integrating_svpwm_DW.TriggeredSubsystem3_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(integrating_svpwm_DW.FunctionCallSubsystem_SubsysRan);

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
      {
        real_T rtb_Sum1_d[3];
        real_T rtb_Product5;
        real_T rtb_Sum1_e;
        real_T rtb_v1beta;
        real_T rtb_v2alpha;
        real_T rtb_v2beta;
        real32_T rtb_Add4;
        real32_T rtb_CastToSingle;
        real32_T rtb_Subtract1;
        uint32_T FunctionCallSubsystem_ELAPS_T;
        int16_T rtPrevAction;
        boolean_T rtb_Compare_e[3];
        boolean_T rtb_Compare;

        /* Asynchronous task reads absolute time. Data (absolute time)
           transfers from low priority task (base rate) to high priority
           task (asynchronous rate). Double buffers are used to ensure
           data integrity.
           -- rtmL2HLastBufWr is the buffer index that is written last.
         */
        integrating_svpwm_M->Timing.clockTick1 =
          integrating_svpwm_M->Timing.rtmL2HDbBufClockTick
          [integrating_svpwm_M->Timing.rtmL2HLastBufWr];
        if (integrating_svpwm_DW.FunctionCallSubsystem_RESET_ELA) {
          FunctionCallSubsystem_ELAPS_T = 0UL;
        } else {
          FunctionCallSubsystem_ELAPS_T = integrating_svpwm_M->Timing.clockTick1
            - integrating_svpwm_DW.FunctionCallSubsystem_PREV_T;
        }

        integrating_svpwm_DW.FunctionCallSubsystem_PREV_T =
          integrating_svpwm_M->Timing.clockTick1;
        integrating_svpwm_DW.FunctionCallSubsystem_RESET_ELA = false;

        /* S-Function (c2802xadc): '<S1>/ADC3' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC3 = (AdcaResultRegs.ADCRESULT2);
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
        integrating_svpwm_B.Product = (real32_T)integrating_svpwm_B.ADC3 /
          integrating_svpwm_P.Constant3_Value_o *
          integrating_svpwm_P.Constant_Value_b /
          integrating_svpwm_P.Constant1_Value *
          integrating_svpwm_P.Constant2_Value_b;

        /* DataStoreWrite: '<S1>/Data Store Write1' */
        integrating_svpwm_DW.V_PVDD = integrating_svpwm_B.Product;

        /* S-Function (c2802xadc): '<S1>/ADC' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC = (AdcaResultRegs.ADCRESULT1);
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
        integrating_svpwm_B.Product_d = (real32_T)integrating_svpwm_B.ADC /
          integrating_svpwm_P.Constant3_Value_f *
          integrating_svpwm_P.Constant_Value_b /
          integrating_svpwm_P.Constant1_Value_d *
          integrating_svpwm_P.Constant2_Value_g;

        /* DataStoreWrite: '<S1>/Data Store Write4' */
        integrating_svpwm_DW.V_A = integrating_svpwm_B.Product_d;

        /* S-Function (c2802xadc): '<S1>/ADC1' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC1 = (AdccResultRegs.ADCRESULT1);
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
        integrating_svpwm_B.Product_p = (real32_T)integrating_svpwm_B.ADC1 /
          integrating_svpwm_P.Constant3_Value_j *
          integrating_svpwm_P.Constant_Value_b /
          integrating_svpwm_P.Constant1_Value_i *
          integrating_svpwm_P.Constant2_Value_i;

        /* DataStoreWrite: '<S1>/Data Store Write5' */
        integrating_svpwm_DW.V_B = integrating_svpwm_B.Product_p;

        /* S-Function (c2802xadc): '<S1>/ADC2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC2 = (AdcbResultRegs.ADCRESULT1);
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
        integrating_svpwm_B.Product_o = (real32_T)integrating_svpwm_B.ADC2 /
          integrating_svpwm_P.Constant3_Value_a *
          integrating_svpwm_P.Constant_Value_b /
          integrating_svpwm_P.Constant1_Value_ig *
          integrating_svpwm_P.Constant2_Value_m;

        /* DataStoreWrite: '<S1>/Data Store Write6' */
        integrating_svpwm_DW.V_C = integrating_svpwm_B.Product_o;

        /* S-Function (c2802xadc): '<S1>/ADC6' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC6 = (AdcaResultRegs.ADCRESULT0);
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
        integrating_svpwm_B.Divide = ((real32_T)integrating_svpwm_B.ADC6 /
          integrating_svpwm_P.Constant3_Value_jt *
          integrating_svpwm_P.Constant1_Value_h -
          integrating_svpwm_P.Constant1_Value_n) *
          integrating_svpwm_P.Constant2_Value_ix /
          integrating_svpwm_P.Constant_Value_k;

        /* DataStoreWrite: '<S1>/Data Store Write2' */
        integrating_svpwm_DW.I_C = integrating_svpwm_B.Divide;

        /* S-Function (c2802xadc): '<S1>/ADC4' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC4 = (AdccResultRegs.ADCRESULT0);
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
        integrating_svpwm_B.Divide_b = ((real32_T)integrating_svpwm_B.ADC4 /
          integrating_svpwm_P.Constant3_Value_o0 *
          integrating_svpwm_P.Constant1_Value_h -
          integrating_svpwm_P.Constant1_Value_hp) *
          integrating_svpwm_P.Constant2_Value_p /
          integrating_svpwm_P.Constant_Value_e;

        /* DataStoreWrite: '<S1>/Data Store Write3' */
        integrating_svpwm_DW.I_A = integrating_svpwm_B.Divide_b;

        /* S-Function (c2802xadc): '<S1>/ADC5' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          integrating_svpwm_B.ADC5 = (AdcbResultRegs.ADCRESULT0);
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
        integrating_svpwm_B.Divide_d = ((real32_T)integrating_svpwm_B.ADC5 /
          integrating_svpwm_P.Constant3_Value_jd *
          integrating_svpwm_P.Constant1_Value_h -
          integrating_svpwm_P.Constant1_Value_e) *
          integrating_svpwm_P.Constant2_Value_l /
          integrating_svpwm_P.Constant_Value_l;

        /* DataStoreWrite: '<S1>/Data Store Write7' */
        integrating_svpwm_DW.I_B = integrating_svpwm_B.Divide_d;

        /* S-Function (c280xgpio_di): '<S1>/Hall_V_Digital1' */
        {
          integrating_svpwm_B.Hall_V_Digital1 = GpioDataRegs.GPADAT.bit.GPIO29;
        }

        /* S-Function (c280xgpio_di): '<S1>/Hall_W_Digital1' */
        {
          integrating_svpwm_B.Hall_W_Digital1 = GpioDataRegs.GPDDAT.bit.GPIO125;
        }

        /* S-Function (c280xgpio_di): '<S1>/Hall_U_Digital1' */
        {
          integrating_svpwm_B.Hall_U_Digital1 = GpioDataRegs.GPDDAT.bit.GPIO124;
        }

        /* CombinatorialLogic: '<S1>/Combinatorial  Logic' */
        rtb_v2alpha = integrating_svpwm_P.CombinatorialLogic_table[((((uint16_T)
          integrating_svpwm_B.Hall_V_Digital1 << 1) +
          integrating_svpwm_B.Hall_W_Digital1) << 1) +
          integrating_svpwm_B.Hall_U_Digital1];

        /* DataTypeConversion: '<S1>/Cast To Single' */
        rtb_CastToSingle = (real32_T)rtb_v2alpha;

        /* Sum: '<S1>/Subtract1' incorporates:
         *  DataTypeConversion: '<S1>/Cast To Single'
         *  Delay: '<S1>/Delay One Step3'
         */
        rtb_Subtract1 = (real32_T)rtb_v2alpha -
          integrating_svpwm_DW.DelayOneStep3_DSTATE;

        /* SwitchCase: '<S1>/Switch Case3' */
        rtPrevAction = integrating_svpwm_DW.SwitchCase3_ActiveSubsystem;
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
          integrating_svpwm_DW.SwitchCase3_ActiveSubsystem = 0;
          break;

         case 5L:
          integrating_svpwm_DW.SwitchCase3_ActiveSubsystem = 1;
          break;

         default:
          integrating_svpwm_DW.SwitchCase3_ActiveSubsystem = 2;
          break;
        }

        if (rtPrevAction != integrating_svpwm_DW.SwitchCase3_ActiveSubsystem) {
          switch (rtPrevAction) {
           case 0:
            SwitchCaseActionSubsyst_Disable(&integrating_svpwm_B.Product_ph,
              &integrating_svpwm_P.SwitchCaseActionSubsystem15);
            break;

           case 1:
            SwitchCaseActionSubsyst_Disable(&integrating_svpwm_B.Product_f,
              &integrating_svpwm_P.SwitchCaseActionSubsystem16);
            break;

           case 2:
            /* Disable for Product: '<S20>/Product' incorporates:
             *  Outport: '<S20>/Out1'
             * */
            integrating_svpwm_B.Product_od = integrating_svpwm_P.Out1_Y0;
            break;
          }
        }

        switch (integrating_svpwm_DW.SwitchCase3_ActiveSubsystem) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem15' incorporates:
           *  ActionPort: '<S18>/Action Port'
           */
          int_SwitchCaseActionSubsystem15(&integrating_svpwm_B.Product_ph,
            &integrating_svpwm_P.SwitchCaseActionSubsystem15);
          integrating_svpwm_DW.SwitchCaseActionSubsystem15.SwitchCaseActionSubsystem15_Sub
            = 4;

          /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem15' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem16' incorporates:
           *  ActionPort: '<S19>/Action Port'
           */
          int_SwitchCaseActionSubsystem15(&integrating_svpwm_B.Product_f,
            &integrating_svpwm_P.SwitchCaseActionSubsystem16);
          integrating_svpwm_DW.SwitchCaseActionSubsystem16.SwitchCaseActionSubsystem15_Sub
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
          integrating_svpwm_B.Product_od = rtb_Subtract1 /
            integrating_svpwm_P.Constant2_Value * integrating_svpwm_P.Pi_Value;
          integrating_svpwm_DW.SwitchCaseActionSubsystem17_Sub = 4;

          /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem17' */
          break;
        }

        /* End of SwitchCase: '<S1>/Switch Case3' */

        /* Sum: '<S1>/Add4' */
        rtb_Add4 = (integrating_svpwm_B.Product_ph +
                    integrating_svpwm_B.Product_f) +
          integrating_svpwm_B.Product_od;

        /* RelationalOperator: '<S2>/Compare' incorporates:
         *  Constant: '<S2>/Constant'
         */
        rtb_Compare = (rtb_Subtract1 != integrating_svpwm_P.Constant_Value_hl);

        /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem2' incorporates:
         *  TriggerPort: '<S21>/Trigger'
         */
        if (rtb_Compare &&
            (integrating_svpwm_PrevZCX.TriggeredSubsystem2_Trig_ZCE != POS_ZCSIG))
        {
          /* Switch: '<S21>/Switch' incorporates:
           *  Constant: '<S26>/Lower Limit'
           *  Constant: '<S26>/Upper Limit'
           *  Logic: '<S26>/AND'
           *  Memory: '<S21>/Memory'
           *  RelationalOperator: '<S26>/Lower Test'
           *  RelationalOperator: '<S26>/Upper Test'
           */
          if ((!(integrating_svpwm_P.IntervalTest_lowlimit <
                 integrating_svpwm_B.Add)) || (!(integrating_svpwm_B.Add <
                integrating_svpwm_P.IntervalTest_uplimit))) {
            /* Switch: '<S21>/Switch' incorporates:
             *  Constant: '<S21>/Constant'
             *  Constant: '<S21>/Constant2'
             *  Constant: '<S21>/Pi'
             *  Math: '<S21>/Math Function'
             *  Product: '<S21>/Divide'
             *  Product: '<S21>/Product'
             *  Sum: '<S21>/Subtract'
             */
            integrating_svpwm_B.Add = rt_remf_snf(0.0F - integrating_svpwm_B.Add,
              integrating_svpwm_P.Constant_Value_h /
              integrating_svpwm_P.Constant2_Value_k *
              integrating_svpwm_P.Pi_Value_p);
          }

          /* End of Switch: '<S21>/Switch' */

          /* Switch: '<S21>/Switch' incorporates:
           *  Sum: '<S21>/Add'
           */
          integrating_svpwm_B.Add += rtb_Add4;
          integrating_svpwm_DW.TriggeredSubsystem2_SubsysRanBC = 4;
        }

        integrating_svpwm_PrevZCX.TriggeredSubsystem2_Trig_ZCE = rtb_Compare;

        /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem2' */

        /* DataStoreWrite: '<S1>/Data Store Write8' */
        integrating_svpwm_DW.MOT_POS = integrating_svpwm_B.Add;

        /* If: '<S1>/If1' incorporates:
         *  Delay: '<S1>/Delay One Step4'
         */
        if (integrating_svpwm_DW.DelayOneStep4_DSTATE > 1000.0F) {
          /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S3>/Action Port'
           */
          /* DataStoreWrite: '<S3>/Data Store Write8' incorporates:
           *  Constant: '<S3>/Constant'
           */
          integrating_svpwm_DW.MOT_VEL = integrating_svpwm_P.Constant_Value_i;

          /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */

          /* Update for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S3>/Action Port'
           */
          /* Update for If: '<S1>/If1' */
          integrating_svpwm_DW.IfActionSubsystem1_SubsysRanBC = 4;

          /* End of Update for SubSystem: '<S1>/If Action Subsystem1' */
        }

        /* End of If: '<S1>/If1' */

        /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem3' incorporates:
         *  TriggerPort: '<S22>/Trigger'
         */
        if (rtb_Compare &&
            (integrating_svpwm_PrevZCX.TriggeredSubsystem3_Trig_ZCE != POS_ZCSIG))
        {
          /* Product: '<S22>/Divide1' incorporates:
           *  Constant: '<S22>/Constant'
           *  DataStoreWrite: '<S22>/Data Store Write8'
           *  Memory generated from: '<S1>/Triggered Subsystem3'
           *  Product: '<S22>/Divide'
           */
          integrating_svpwm_DW.MOT_VEL = rtb_Add4 /
            (integrating_svpwm_DW.TmpLatchAtTriggeredSubsystem3In /
             integrating_svpwm_P.Constant_Value_i2);
          integrating_svpwm_DW.TriggeredSubsystem3_SubsysRanBC = 4;
        }

        integrating_svpwm_PrevZCX.TriggeredSubsystem3_Trig_ZCE = rtb_Compare;

        /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem3' */

        /* Switch: '<S1>/Switch1' */
        if (rtb_Compare) {
          /* Switch: '<S1>/Switch1' incorporates:
           *  Constant: '<S1>/Constant5'
           */
          integrating_svpwm_DW.DelayOneStep4_DSTATE =
            integrating_svpwm_P.Constant5_Value;
        } else {
          /* Switch: '<S1>/Switch1' incorporates:
           *  Constant: '<S1>/Constant4'
           *  Delay: '<S1>/Delay One Step4'
           *  Sum: '<S1>/Add5'
           */
          integrating_svpwm_DW.DelayOneStep4_DSTATE +=
            integrating_svpwm_P.Constant4_Value_f;
        }

        /* End of Switch: '<S1>/Switch1' */

        /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
        if (integrating_svpwm_DW.DiscreteTimeIntegrator_SYSTEM_E == 0U) {
          /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
          integrating_svpwm_DW.DiscreteTimeIntegrator_DSTATE +=
            integrating_svpwm_P.DiscreteTimeIntegrator_gainval * (real_T)
            FunctionCallSubsystem_ELAPS_T
            * integrating_svpwm_DW.DiscreteTimeIntegrator_PREV_U;
        }

        /* End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

        /* Gain: '<S25>/Gain' incorporates:
         *  Constant: '<S25>/we1'
         *  Sum: '<S25>/Sum'
         *  Sum: '<S25>/Sum1'
         *  Trigonometry: '<S25>/Trigonometric Function'
         *  Trigonometry: '<S25>/Trigonometric Function1'
         *  Trigonometry: '<S25>/Trigonometric Function2'
         */
        rtb_v2alpha = integrating_svpwm_P.Gain_Gain * cos
          (integrating_svpwm_DW.DiscreteTimeIntegrator_DSTATE);
        rtb_v1beta = cos(integrating_svpwm_DW.DiscreteTimeIntegrator_DSTATE -
                         integrating_svpwm_P.we1_Value) *
          integrating_svpwm_P.Gain_Gain;
        rtb_Sum1_e = cos(integrating_svpwm_DW.DiscreteTimeIntegrator_DSTATE +
                         integrating_svpwm_P.we1_Value) *
          integrating_svpwm_P.Gain_Gain;
        for (rtPrevAction = 0; rtPrevAction < 3; rtPrevAction++) {
          /* Product: '<S25>/Clarke Transformation' incorporates:
           *  Constant: '<S25>/Clarke Transform'
           *  Gain: '<S25>/Gain1'
           */
          integrating_svpwm_B.ClarkeTransformation[rtPrevAction] = 0.0;
          integrating_svpwm_B.ClarkeTransformation[rtPrevAction] +=
            integrating_svpwm_P.Gain1_Gain *
            integrating_svpwm_P.ClarkeTransform_Value[rtPrevAction] *
            rtb_v2alpha;
          integrating_svpwm_B.ClarkeTransformation[rtPrevAction] +=
            integrating_svpwm_P.ClarkeTransform_Value[rtPrevAction + 3] *
            integrating_svpwm_P.Gain1_Gain * rtb_v1beta;
          integrating_svpwm_B.ClarkeTransformation[rtPrevAction] +=
            integrating_svpwm_P.ClarkeTransform_Value[rtPrevAction + 6] *
            integrating_svpwm_P.Gain1_Gain * rtb_Sum1_e;
        }

        /* RelationalOperator: '<S27>/Compare' incorporates:
         *  Constant: '<S24>/Constant3'
         *  Constant: '<S27>/Constant'
         *  Product: '<S24>/Product1'
         */
        for (rtPrevAction = 0; rtPrevAction < 3; rtPrevAction++) {
          rtb_Compare_e[rtPrevAction] =
            (integrating_svpwm_P.Constant3_Value[rtPrevAction + 3] *
             integrating_svpwm_B.ClarkeTransformation[1] +
             integrating_svpwm_P.Constant3_Value[rtPrevAction] *
             integrating_svpwm_B.ClarkeTransformation[0] >
             integrating_svpwm_P.Constant_Value);
        }

        /* End of RelationalOperator: '<S27>/Compare' */

        /* CombinatorialLogic: '<S24>/Combinatorial  Logic' */
        integrating_svpwm_B.CombinatorialLogic =
          integrating_svpwm_P.CombinatorialLogic_table_i[((((uint16_T)
          rtb_Compare_e[0U] << 1) + rtb_Compare_e[1U]) << 1) + rtb_Compare_e[2U]];

        /* LookupNDDirect: '<S1>/v2beta' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/v2beta':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        rtb_v2beta = integrating_svpwm_P.v2beta_table[(int16_T)rtb_Sum1_e];

        /* End of LookupNDDirect: '<S1>/v2beta' */

        /* LookupNDDirect: '<S1>/v1beta' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/v1beta':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        rtb_v1beta = integrating_svpwm_P.v1beta_table[(int16_T)rtb_Sum1_e];

        /* End of LookupNDDirect: '<S1>/v1beta' */

        /* LookupNDDirect: '<S1>/v2alpha' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/v2alpha':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        rtb_v2alpha = integrating_svpwm_P.v2alpha_table[(int16_T)rtb_Sum1_e];

        /* End of LookupNDDirect: '<S1>/v2alpha' */

        /* LookupNDDirect: '<S1>/v1alpha' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/v1alpha':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        rtb_Sum1_e = integrating_svpwm_P.v1alpha_table[(int16_T)rtb_Sum1_e];

        /* End of LookupNDDirect: '<S1>/v1alpha' */

        /* Product: '<S1>/Product5' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read5'
         *  Product: '<S1>/Product3'
         *  Product: '<S1>/Product4'
         *  Sum: '<S1>/Sum'
         */
        rtb_Product5 = (rtb_Sum1_e * rtb_v2beta - rtb_v2alpha * rtb_v1beta) *
          integrating_svpwm_DW.V_PVDD;

        /* Product: '<S1>/Product6' incorporates:
         *  Gain: '<S1>/Gain4'
         *  Gain: '<S1>/Gain5'
         *  Product: '<S1>/Divide'
         *  SignalConversion generated from: '<S1>/Matrix Concatenate'
         * */
        rtb_v2alpha = integrating_svpwm_P.Gain5_Gain * rtb_v2alpha /
          rtb_Product5 * integrating_svpwm_B.ClarkeTransformation[1] +
          rtb_v2beta / rtb_Product5 * integrating_svpwm_B.ClarkeTransformation[0];
        rtb_v1beta = integrating_svpwm_P.Gain4_Gain * rtb_v1beta / rtb_Product5 *
          integrating_svpwm_B.ClarkeTransformation[0] + rtb_Sum1_e /
          rtb_Product5 * integrating_svpwm_B.ClarkeTransformation[1];

        /* Sum: '<S23>/Sum1' */
        rtb_Sum1_e = rtb_v2alpha + rtb_v1beta;

        /* MinMax: '<S23>/MinMax' incorporates:
         *  Constant: '<S23>/Constant4'
         */
        if ((!(rtb_Sum1_e >= integrating_svpwm_P.Constant4_Value)) && (!rtIsNaN
             (integrating_svpwm_P.Constant4_Value))) {
          rtb_Sum1_e = integrating_svpwm_P.Constant4_Value;
        }

        /* End of MinMax: '<S23>/MinMax' */

        /* Product: '<S23>/Divide1' */
        rtb_v2alpha /= rtb_Sum1_e;
        rtb_v1beta /= rtb_Sum1_e;

        /* Sum: '<S1>/Sum1' incorporates:
         *  Constant: '<S1>/Constant7'
         *  Constant: '<S1>/Constant8'
         *  Product: '<S1>/Product7'
         */
        for (rtPrevAction = 0; rtPrevAction < 3; rtPrevAction++) {
          rtb_Sum1_d[rtPrevAction] =
            (integrating_svpwm_P.Constant7_Value[rtPrevAction + 3] * rtb_v1beta
             + integrating_svpwm_P.Constant7_Value[rtPrevAction] * rtb_v2alpha)
            + integrating_svpwm_P.Constant8_Value[rtPrevAction];
        }

        /* End of Sum: '<S1>/Sum1' */

        /* LookupNDDirect: '<S1>/cmpa' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/cmpa':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        /* MultiPortSwitch: '<S1>/Index Vector3' incorporates:
         *  LookupNDDirect: '<S1>/cmpa'
         *
         * About '<S1>/cmpa':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        integrating_svpwm_B.IndexVector3 = rtb_Sum1_d[(int16_T)
          integrating_svpwm_P.cmpa_table[(int16_T)rtb_Sum1_e]];

        /* LookupNDDirect: '<S1>/cmpb' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/cmpb':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        /* MultiPortSwitch: '<S1>/Index Vector4' incorporates:
         *  LookupNDDirect: '<S1>/cmpb'
         *
         * About '<S1>/cmpb':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        integrating_svpwm_B.IndexVector4 = rtb_Sum1_d[(int16_T)
          integrating_svpwm_P.cmpb_table[(int16_T)rtb_Sum1_e]];

        /* LookupNDDirect: '<S1>/cmpc' incorporates:
         *  CombinatorialLogic: '<S24>/Combinatorial  Logic'
         *
         * About '<S1>/cmpc':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        if (integrating_svpwm_B.CombinatorialLogic > 5.0) {
          rtb_Sum1_e = 5.0;
        } else if (integrating_svpwm_B.CombinatorialLogic < 0.0) {
          rtb_Sum1_e = 0.0;
        } else {
          rtb_Sum1_e = integrating_svpwm_B.CombinatorialLogic;
        }

        /* MultiPortSwitch: '<S1>/Index Vector5' incorporates:
         *  LookupNDDirect: '<S1>/cmpc'
         *
         * About '<S1>/cmpc':
         *  1-dimensional Direct Look-Up returning a Scalar,
         *
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        integrating_svpwm_B.IndexVector5 = rtb_Sum1_d[(int16_T)
          integrating_svpwm_P.cmpc_table[(int16_T)rtb_Sum1_e]];

        /* S-Function (c2802xpwm): '<S1>/ePWM' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read'
         */

        /*-- Update CMPA value for ePWM4 --*/
        {
          EPwm4Regs.CMPA.bit.CMPA = (uint16_T)(integrating_svpwm_DW.A);
        }

        /* S-Function (c2802xpwm): '<S1>/ePWM1' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read1'
         */

        /*-- Update CMPA value for ePWM5 --*/
        {
          EPwm5Regs.CMPA.bit.CMPA = (uint16_T)(integrating_svpwm_DW.B);
        }

        /* S-Function (c2802xpwm): '<S1>/ePWM2' incorporates:
         *  DataStoreRead: '<S1>/Data Store Read2'
         */

        /*-- Update CMPA value for ePWM6 --*/
        {
          EPwm6Regs.CMPA.bit.CMPA = (uint16_T)(integrating_svpwm_DW.C);
        }

        /* DataStoreRead: '<S1>/Data Store Read3' */
        integrating_svpwm_B.DataStoreRead3 = integrating_svpwm_DW.MOT_POS;

        /* DataStoreRead: '<S1>/Data Store Read4' */
        integrating_svpwm_B.DataStoreRead4 = integrating_svpwm_DW.MOT_VEL;

        /* S-Function (c280xgpio_do): '<S1>/Digital Output' incorporates:
         *  Constant: '<S1>/Enable Gate'
         */
        {
          GpioDataRegs.GPBTOGGLE.bit.GPIO52 =
            (integrating_svpwm_P.EnableGate_Value != 0);
        }

        /* Update for Delay: '<S1>/Delay One Step3' */
        integrating_svpwm_DW.DelayOneStep3_DSTATE = rtb_CastToSingle;

        /* Update for Memory generated from: '<S1>/Triggered Subsystem3' */
        integrating_svpwm_DW.TmpLatchAtTriggeredSubsystem3In =
          integrating_svpwm_DW.DelayOneStep4_DSTATE;

        /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S25>/we'
         */
        integrating_svpwm_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
        integrating_svpwm_DW.DiscreteTimeIntegrator_PREV_U =
          integrating_svpwm_P.we_Value;
        integrating_svpwm_DW.FunctionCallSubsystem_SubsysRan = 4;
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }

    currentTime = (extmodeSimulationTime_T)
      integrating_svpwm_M->Timing.clockTick0;
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
void int_SwitchCaseActionSubsystem15(real32_T *rty_Out1,
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

real32_T rt_remf_snf(real32_T u0, real32_T u1)
{
  real32_T u1_p;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0F) {
      u1_p = (real32_T)ceil(u1);
    } else {
      u1_p = (real32_T)floor(u1);
    }

    if ((u1 != 0.0F) && (u1 != u1_p)) {
      u1_p = fabsf(u0 / u1);
      if (!(fabsf(u1_p - (real32_T)floor(u1_p + 0.5F)) > FLT_EPSILON * u1_p)) {
        y = 0.0F * u0;
      } else {
        y = (real32_T)fmod(u0, u1);
      }
    } else {
      y = (real32_T)fmod(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void integrating_svpwm_step(void)
{
  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  integrating_svpwm_DW.A = integrating_svpwm_P.Constant_Value_c;

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  integrating_svpwm_DW.B = integrating_svpwm_P.Constant1_Value_a;

  /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  integrating_svpwm_DW.C = integrating_svpwm_P.Constant2_Value_e;

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Enable Gate'
   */
  {
    if (integrating_svpwm_P.EnableGate_Value_f)
      GpioDataRegs.GPASET.bit.GPIO26 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' incorporates:
   *  Constant: '<Root>/Wake'
   */
  {
    if (integrating_svpwm_P.Wake_Value)
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
  integrating_svpwm_M->Timing.taskTime0 =
    ((time_T)(++integrating_svpwm_M->Timing.clockTick0)) *
    integrating_svpwm_M->Timing.stepSize0;

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !(integrating_svpwm_M->Timing.rtmL2HLastBufWr != 0U);
    integrating_svpwm_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      integrating_svpwm_M->Timing.clockTick0;
    integrating_svpwm_M->Timing.rtmL2HLastBufWr = bufIdx ? 1U : 0U;
  }
}

/* Model initialize function */
void integrating_svpwm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)integrating_svpwm_M, 0,
                sizeof(RT_MODEL_integrating_svpwm_T));
  rtmSetTFinal(integrating_svpwm_M, -1);
  integrating_svpwm_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  integrating_svpwm_M->Sizes.checksums[0] = (1961858683U);
  integrating_svpwm_M->Sizes.checksums[1] = (2840233274U);
  integrating_svpwm_M->Sizes.checksums[2] = (3925476156U);
  integrating_svpwm_M->Sizes.checksums[3] = (71865810U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    integrating_svpwm_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &integrating_svpwm_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &integrating_svpwm_DW.SwitchCaseActionSubsystem15.SwitchCaseActionSubsystem15_Sub;
    systemRan[3] = (sysRanDType *)
      &integrating_svpwm_DW.SwitchCaseActionSubsystem16.SwitchCaseActionSubsystem15_Sub;
    systemRan[4] = (sysRanDType *)
      &integrating_svpwm_DW.SwitchCaseActionSubsystem17_Sub;
    systemRan[5] = (sysRanDType *)
      &integrating_svpwm_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[6] = (sysRanDType *)
      &integrating_svpwm_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[7] = (sysRanDType *)
      &integrating_svpwm_DW.TriggeredSubsystem2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &integrating_svpwm_DW.TriggeredSubsystem2_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &integrating_svpwm_DW.TriggeredSubsystem3_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &integrating_svpwm_DW.FunctionCallSubsystem_SubsysRan;
    rteiSetModelMappingInfoPtr(integrating_svpwm_M->extModeInfo,
      &integrating_svpwm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(integrating_svpwm_M->extModeInfo,
                        integrating_svpwm_M->Sizes.checksums);
    rteiSetTPtr(integrating_svpwm_M->extModeInfo, rtmGetTPtr(integrating_svpwm_M));
  }

  /* block I/O */
  (void) memset(((void *) &integrating_svpwm_B), 0,
                sizeof(B_integrating_svpwm_T));

  /* states (dwork) */
  (void) memset((void *)&integrating_svpwm_DW, 0,
                sizeof(DW_integrating_svpwm_T));

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
  integrating_svpwm_DW.A = integrating_svpwm_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  integrating_svpwm_DW.B = integrating_svpwm_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  integrating_svpwm_DW.C = integrating_svpwm_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  integrating_svpwm_DW.MOT_VEL =
    integrating_svpwm_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  integrating_svpwm_DW.MOT_POS =
    integrating_svpwm_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  integrating_svpwm_DW.I_A = integrating_svpwm_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  integrating_svpwm_DW.I_B = integrating_svpwm_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  integrating_svpwm_DW.I_C = integrating_svpwm_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  integrating_svpwm_DW.V_A = integrating_svpwm_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  integrating_svpwm_DW.V_B = integrating_svpwm_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  integrating_svpwm_DW.V_C = integrating_svpwm_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  integrating_svpwm_DW.V_PVDD =
    integrating_svpwm_P.DataStoreMemory9_InitialValue;
  integrating_svpwm_PrevZCX.TriggeredSubsystem2_Trig_ZCE = POS_ZCSIG;
  integrating_svpwm_PrevZCX.TriggeredSubsystem3_Trig_ZCE = POS_ZCSIG;

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
  integrating_svpwm_M->Timing.clockTick1 =
    integrating_svpwm_M->Timing.rtmL2HDbBufClockTick
    [integrating_svpwm_M->Timing.rtmL2HLastBufWr];

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
  integrating_svpwm_DW.SwitchCase3_ActiveSubsystem = -1;

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
       EPwm4Regs.ETSEL.bit.SOCASEL              = 2;          // Start of Conversion A Select
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
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7F) | 0x1A01;
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
  integrating_svpwm_DW.DelayOneStep3_DSTATE =
    integrating_svpwm_P.DelayOneStep3_InitialCondition;

  /* InitializeConditions for Switch: '<S1>/Switch1' incorporates:
   *  Delay: '<S1>/Delay One Step4'
   */
  integrating_svpwm_DW.DelayOneStep4_DSTATE =
    integrating_svpwm_P.DelayOneStep4_InitialCondition;

  /* InitializeConditions for Memory generated from: '<S1>/Triggered Subsystem3' */
  integrating_svpwm_DW.TmpLatchAtTriggeredSubsystem3In =
    integrating_svpwm_P.TmpLatchAtTriggeredSubsystem3In;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  integrating_svpwm_DW.DiscreteTimeIntegrator_DSTATE =
    integrating_svpwm_P.DiscreteTimeIntegrator_IC;
  integrating_svpwm_DW.DiscreteTimeIntegrator_PREV_U = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Switch Case Action Subsystem15' */
  SwitchCaseActionSubsystem1_Init(&integrating_svpwm_B.Product_ph,
    &integrating_svpwm_P.SwitchCaseActionSubsystem15);

  /* End of SystemInitialize for SubSystem: '<S1>/Switch Case Action Subsystem15' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Switch Case Action Subsystem16' */
  SwitchCaseActionSubsystem1_Init(&integrating_svpwm_B.Product_f,
    &integrating_svpwm_P.SwitchCaseActionSubsystem16);

  /* End of SystemInitialize for SubSystem: '<S1>/Switch Case Action Subsystem16' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Switch Case Action Subsystem17' */
  /* SystemInitialize for Product: '<S20>/Product' incorporates:
   *  Outport: '<S20>/Out1'
   */
  integrating_svpwm_B.Product_od = integrating_svpwm_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Switch Case Action Subsystem17' */

  /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem2' */
  /* SystemInitialize for Switch: '<S21>/Switch' incorporates:
   *  Outport: '<S21>/Outport'
   *  Sum: '<S21>/Add'
   */
  integrating_svpwm_B.Add = integrating_svpwm_P.Outport_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem2' */
  ;

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

  /* Enable for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Enable for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  integrating_svpwm_M->Timing.clockTick1 =
    integrating_svpwm_M->Timing.rtmL2HDbBufClockTick
    [integrating_svpwm_M->Timing.rtmL2HLastBufWr];
  integrating_svpwm_DW.FunctionCallSubsystem_RESET_ELA = true;

  /* Enable for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  integrating_svpwm_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;
  ;

  /* End of Enable for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
}

/* Model terminate function */
void integrating_svpwm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
