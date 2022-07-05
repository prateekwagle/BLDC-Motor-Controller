/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'svpwm3'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul  5 13:16:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "svpwm3.h"
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
  svpwm3_step();

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

#if defined(MW_EXEC_PROFILER_ON) || defined(MW_EXTMODE_RUNNING)

  hardwareTimer1Init();

#endif

  ;
  rtmSetErrorStatus(svpwm3_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  svpwm3_initialize();
  globalInterruptDisable();
  globalInterruptEnable();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(svpwm3_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(svpwm3_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(svpwm3_M, true);
    }
  }

  rtERTExtModeStartMsg();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel = (rtmGetErrorStatus(svpwm3_M) == (NULL)) && !rtmGetStopRequested
    (svpwm3_M);
  enableTimer0Interrupt();
  enable_interrupts();
  globalInterruptEnable();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(svpwm3_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(svpwm3_M, true);
      }
    }

    stopRequested = !((rtmGetErrorStatus(svpwm3_M) == (NULL)) &&
                      !rtmGetStopRequested(svpwm3_M));
    runModel = !(stopRequested);
  }

  /* Terminate model */
  svpwm3_terminate();

  /* External mode shutdown */
  rtExtModeShutdown(1);
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
