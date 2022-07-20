/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'svpwm2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jun 16 10:04:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "svpwm2.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  enableTimer0Interrupt();
  svpwm2_step();

  /* Get model outputs here */
  disableTimer0Interrupt();
  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.2;
  float systemClock = 200;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  c2000_flash_init();
  init_board();

#ifdef MW_EXEC_PROFILER_ON

  config_profilerTimer();

#endif

  ;
  rtmSetErrorStatus(svpwm2_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  svpwm2_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(svpwm2_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(svpwm2_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(svpwm2_M, true);
    }
  }

  rtERTExtModeStartMsg();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    (rtmGetErrorStatus(svpwm2_M) == (NULL)) && !rtmGetStopRequested(svpwm2_M);
  enableTimer0Interrupt();
  globalInterruptEnable();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(svpwm2_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(svpwm2_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(svpwm2_M) == (NULL)) &&
                      !rtmGetStopRequested(svpwm2_M));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  svpwm2_terminate();
  rtExtModeShutdown(1);
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
