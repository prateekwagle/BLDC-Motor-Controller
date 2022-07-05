/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: svpwm.h
 *
 * Code generated for Simulink model 'svpwm'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu May 19 15:38:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_svpwm_h_
#define RTW_HEADER_svpwm_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef svpwm_COMMON_INCLUDES_
#define svpwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "IQmathLib.h"
#endif                                 /* svpwm_COMMON_INCLUDES_ */

#include "svpwm_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

extern void config_ePWM_GPIO (void);

/* Block signals (default storage) */
typedef struct {
  uint16_T ADC;                        /* '<S1>/ADC' */
} B_svpwm_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  int16_T Subsystem_SubsysRanBC;       /* '<Root>/Subsystem' */
} DW_svpwm_T;

/* Parameters (default storage) */
struct P_svpwm_T_ {
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S1>/Unit Delay'
                                */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S1>/Constant10'
                                        */
  uint32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S1>/Constant9'
                                        */
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S1>/Constant8'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_svpwm_T {
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
    uint8_T rtmL2HLastBufWr;
    uint32_T rtmL2HDbBufClockTick[2];
    uint32_T clockTick1;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_svpwm_T svpwm_P;

/* Block signals (default storage) */
extern B_svpwm_T svpwm_B;

/* Block states (default storage) */
extern DW_svpwm_T svpwm_DW;

/* Model entry point functions */
extern void svpwm_initialize(void);
extern void svpwm_step(void);
extern void svpwm_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_svpwm_T *const svpwm_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'svpwm'
 * '<S1>'   : 'svpwm/Subsystem'
 * '<S2>'   : 'svpwm/Subsystem/Bit Shift'
 * '<S3>'   : 'svpwm/Subsystem/Bit Shift/bit_shift'
 */
#endif                                 /* RTW_HEADER_svpwm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
