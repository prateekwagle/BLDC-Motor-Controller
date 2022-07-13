/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: launchpad_tx.c
 *
 * Code generated for Simulink model 'launchpad_tx'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jul  8 13:53:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "launchpad_tx.h"
#include "launchpad_tx_private.h"
#include "launchpad_tx_dt.h"

/* Block signals (default storage) */
B_launchpad_tx_T launchpad_tx_B;

/* Block states (default storage) */
DW_launchpad_tx_T launchpad_tx_DW;

/* Real-time model */
static RT_MODEL_launchpad_tx_T launchpad_tx_M_;
RT_MODEL_launchpad_tx_T *const launchpad_tx_M = &launchpad_tx_M_;

/* Model step function */
void launchpad_tx_step(void)
{
  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  launchpad_tx_B.FixPtSum1 = launchpad_tx_DW.Output_DSTATE;

  /* S-Function (c28xsci_tx): '<Root>/SCI Transmit' */
  {
    if (checkSCITransmitInprogress != 1) {
      checkSCITransmitInprogress = 1;
      int errFlgHeader = NOERROR;
      int errFlgData = NOERROR;
      int errFlgTail = NOERROR;
      errFlgData = scic_xmit((char*)&launchpad_tx_B.FixPtSum1, 1, 1);
      launchpad_tx_B.SCITransmit = (errFlgHeader | errFlgData | errFlgTail);
      checkSCITransmitInprogress = 0;
    }
  }

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   */
  launchpad_tx_B.FixPtSum1 = (launchpad_tx_B.FixPtSum1 +
    launchpad_tx_P.FixPtConstant_Value) & 255U;

  /* Switch: '<S3>/FixPt Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sum: '<S2>/FixPt Sum1'
   *  UnitDelay: '<S1>/Output'
   */
  if (launchpad_tx_B.FixPtSum1 > launchpad_tx_P.CounterLimited_uplimit) {
    launchpad_tx_DW.Output_DSTATE = launchpad_tx_P.Constant_Value;
  } else {
    launchpad_tx_DW.Output_DSTATE = launchpad_tx_B.FixPtSum1;
  }

  /* End of Switch: '<S3>/FixPt Switch' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [1.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)launchpad_tx_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(launchpad_tx_M)!=-1) &&
        !((rtmGetTFinal(launchpad_tx_M)-launchpad_tx_M->Timing.taskTime0) >
          launchpad_tx_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(launchpad_tx_M, "Simulation finished");
    }

    if (rtmGetStopRequested(launchpad_tx_M)) {
      rtmSetErrorStatus(launchpad_tx_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  launchpad_tx_M->Timing.taskTime0 =
    ((time_T)(++launchpad_tx_M->Timing.clockTick0)) *
    launchpad_tx_M->Timing.stepSize0;
}

/* Model initialize function */
void launchpad_tx_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)launchpad_tx_M, 0,
                sizeof(RT_MODEL_launchpad_tx_T));
  rtmSetTFinal(launchpad_tx_M, -1);
  launchpad_tx_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  launchpad_tx_M->Sizes.checksums[0] = (2853882016U);
  launchpad_tx_M->Sizes.checksums[1] = (1884756393U);
  launchpad_tx_M->Sizes.checksums[2] = (2754753971U);
  launchpad_tx_M->Sizes.checksums[3] = (3313928912U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    launchpad_tx_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(launchpad_tx_M->extModeInfo,
      &launchpad_tx_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(launchpad_tx_M->extModeInfo,
                        launchpad_tx_M->Sizes.checksums);
    rteiSetTPtr(launchpad_tx_M->extModeInfo, rtmGetTPtr(launchpad_tx_M));
  }

  /* block I/O */
  (void) memset(((void *) &launchpad_tx_B), 0,
                sizeof(B_launchpad_tx_T));

  /* states (dwork) */
  (void) memset((void *)&launchpad_tx_DW, 0,
                sizeof(DW_launchpad_tx_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    launchpad_tx_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  launchpad_tx_DW.Output_DSTATE = launchpad_tx_P.Output_InitialCondition;
}

/* Model terminate function */
void launchpad_tx_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
