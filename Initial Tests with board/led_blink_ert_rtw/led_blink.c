/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_blink.c
 *
 * Code generated for Simulink model 'led_blink'.
 *
 * Model version                  : 5.3
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul  5 11:31:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led_blink.h"

/* Real-time model */
static RT_MODEL_led_blink_T led_blink_M_;
RT_MODEL_led_blink_T *const led_blink_M = &led_blink_M_;

/* Model step function */
void led_blink_step(void)
{
  /* S-Function (c280xgpio_do): '<Root>/RED LED' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (led_blink_P.Constant_Value != 0);
  }
}

/* Model initialize function */
void led_blink_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(led_blink_M, (NULL));

  /* Start for S-Function (c280xgpio_do): '<Root>/RED LED' incorporates:
   *  Constant: '<Root>/Constant'
   */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCF;
  GpioCtrlRegs.GPBDIR.all |= 0x4;
  EDIS;
}

/* Model terminate function */
void led_blink_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
