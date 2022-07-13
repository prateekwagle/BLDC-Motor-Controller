/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_meas.c
 *
 * Code generated for Simulink model 'adc_meas'.
 *
 * Model version                  : 5.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jul  8 14:22:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "adc_meas.h"
#include "adc_meas_private.h"

/* Block signals (default storage) */
B_adc_meas_T adc_meas_B;

/* Block states (default storage) */
DW_adc_meas_T adc_meas_DW;

/* Real-time model */
static RT_MODEL_adc_meas_T adc_meas_M_;
RT_MODEL_adc_meas_T *const adc_meas_M = &adc_meas_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

/* Model step function */
void adc_meas_step(void)
{
  /* S-Function (c2802xadc): '<Root>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    float wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    adc_meas_B.ADC = (AdccResultRegs.ADCRESULT0);
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  adc_meas_M->Timing.taskTime0 =
    ((time_T)(++adc_meas_M->Timing.clockTick0)) * adc_meas_M->Timing.stepSize0;
}

/* Model initialize function */
void adc_meas_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)adc_meas_M, 0,
                sizeof(RT_MODEL_adc_meas_T));
  rtmSetTFinal(adc_meas_M, -1);
  adc_meas_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  adc_meas_M->Sizes.checksums[0] = (2030349381U);
  adc_meas_M->Sizes.checksums[1] = (2530851124U);
  adc_meas_M->Sizes.checksums[2] = (4269053503U);
  adc_meas_M->Sizes.checksums[3] = (452221273U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    adc_meas_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(adc_meas_M->extModeInfo,
      &adc_meas_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(adc_meas_M->extModeInfo, adc_meas_M->Sizes.checksums);
    rteiSetTPtr(adc_meas_M->extModeInfo, rtmGetTPtr(adc_meas_M));
  }

  /* block I/O */
  (void) memset(((void *) &adc_meas_B), 0,
                sizeof(B_adc_meas_T));

  /* states (dwork) */
  (void) memset((void *)&adc_meas_DW, 0,
                sizeof(DW_adc_meas_T));

  /* Start for S-Function (c2802xadc): '<Root>/ADC' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC0 ();
}

/* Model terminate function */
void adc_meas_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
