/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_Write_Test.c
 *
 * Code generated for Simulink model 'Serial_Write_Test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul  7 13:50:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Serial_Write_Test.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_Serial_Write_Test_T Serial_Write_Test_B;

/* Block states (default storage) */
DW_Serial_Write_Test_T Serial_Write_Test_DW;

/* Real-time model */
static RT_MODEL_Serial_Write_Test_T Serial_Write_Test_M_;
RT_MODEL_Serial_Write_Test_T *const Serial_Write_Test_M = &Serial_Write_Test_M_;

/* Model step function */
void Serial_Write_Test_step(void)
{
  uint16_T rtb_FixPtSum1;

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  rtb_FixPtSum1 = (Serial_Write_Test_DW.Output_DSTATE +
                   Serial_Write_Test_P.FixPtConstant_Value) & 255U;

  /* S-Function (c28xsci_tx): '<Root>/SCI Transmit' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  {
    if (checkSCITransmitInprogress != 1) {
      checkSCITransmitInprogress = 1;
      int errFlgHeader = NOERROR;
      int errFlgData = NOERROR;
      int errFlgTail = NOERROR;
      errFlgData = scia_xmit((char*)&Serial_Write_Test_DW.Output_DSTATE, 1, 1);
      Serial_Write_Test_B.SCITransmit = (errFlgHeader | errFlgData | errFlgTail);
      checkSCITransmitInprogress = 0;
    }
  }

  /* Switch: '<S3>/FixPt Switch' incorporates:
   *  Sum: '<S2>/FixPt Sum1'
   */
  if (rtb_FixPtSum1 > Serial_Write_Test_P.CounterLimited_uplimit) {
    /* Update for UnitDelay: '<S1>/Output' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Serial_Write_Test_DW.Output_DSTATE = Serial_Write_Test_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S1>/Output' */
    Serial_Write_Test_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S3>/FixPt Switch' */
}

/* Model initialize function */
void Serial_Write_Test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Serial_Write_Test_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Serial_Write_Test_B), 0,
                sizeof(B_Serial_Write_Test_T));

  /* states (dwork) */
  (void) memset((void *)&Serial_Write_Test_DW, 0,
                sizeof(DW_Serial_Write_Test_T));

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  Serial_Write_Test_DW.Output_DSTATE =
    Serial_Write_Test_P.Output_InitialCondition;
}

/* Model terminate function */
void Serial_Write_Test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
