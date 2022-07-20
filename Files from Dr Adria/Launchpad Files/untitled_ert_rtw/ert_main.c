/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri May 27 15:30:02 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
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
  untitled_step();

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
  rtmSetErrorStatus(untitled_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  untitled_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(untitled_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(untitled_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(untitled_M, true);
    }
  }

  rtERTExtModeStartMsg();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel =
    (rtmGetErrorStatus(untitled_M) == (NULL)) && !rtmGetStopRequested(untitled_M);
  enableTimer0Interrupt();
  globalInterruptEnable();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(untitled_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(untitled_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(untitled_M) == (NULL)) &&
                      !rtmGetStopRequested(untitled_M));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  untitled_terminate();
  rtExtModeShutdown(1);
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
