/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: launchpad_tx.h
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

#ifndef RTW_HEADER_launchpad_tx_h_
#define RTW_HEADER_launchpad_tx_h_
#ifndef launchpad_tx_COMMON_INCLUDES_
#define launchpad_tx_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#endif                                 /* launchpad_tx_COMMON_INCLUDES_ */

#include "launchpad_tx_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);

/* Block signals (default storage) */
typedef struct {
  uint16_T SCITransmit;                /* '<Root>/SCI Transmit' */
  uint16_T FixPtSum1;                  /* '<S2>/FixPt Sum1' */
} B_launchpad_tx_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T Output_DSTATE;              /* '<S1>/Output' */
} DW_launchpad_tx_T;

/* Parameters (default storage) */
struct P_launchpad_tx_T_ {
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S3>/FixPt Switch'
                                        */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S1>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S2>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_launchpad_tx_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_launchpad_tx_T launchpad_tx_P;

/* Block signals (default storage) */
extern B_launchpad_tx_T launchpad_tx_B;

/* Block states (default storage) */
extern DW_launchpad_tx_T launchpad_tx_DW;

/* Model entry point functions */
extern void launchpad_tx_initialize(void);
extern void launchpad_tx_step(void);
extern void launchpad_tx_terminate(void);

/* Real-time Model object */
extern RT_MODEL_launchpad_tx_T *const launchpad_tx_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'launchpad_tx'
 * '<S1>'   : 'launchpad_tx/Counter Limited'
 * '<S2>'   : 'launchpad_tx/Counter Limited/Increment Real World'
 * '<S3>'   : 'launchpad_tx/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_launchpad_tx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
