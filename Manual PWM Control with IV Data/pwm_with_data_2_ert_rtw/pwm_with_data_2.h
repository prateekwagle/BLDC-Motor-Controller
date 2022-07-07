/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pwm_with_data_2.h
 *
 * Code generated for Simulink model 'pwm_with_data_2'.
 *
 * Model version                  : 4.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Jul  6 15:39:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pwm_with_data_2_h_
#define RTW_HEADER_pwm_with_data_2_h_
#ifndef pwm_with_data_2_COMMON_INCLUDES_
#define pwm_with_data_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* pwm_with_data_2_COMMON_INCLUDES_ */

#include "pwm_with_data_2_types.h"
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

extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  uint16_T DataStoreRead1;             /* '<Root>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<Root>/Data Store Read2' */
  uint16_T DataStoreRead3;             /* '<Root>/Data Store Read3' */
  uint16_T ADC2;                       /* '<S1>/ADC2' */
} B_pwm_with_data_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  uint32_T A;                          /* '<Root>/Data Store Memory' */
  uint32_T B;                          /* '<Root>/Data Store Memory1' */
  uint32_T C;                          /* '<Root>/Data Store Memory2' */
  uint16_T D;                          /* '<Root>/Data Store Memory3' */
  uint16_T E;                          /* '<Root>/Data Store Memory4' */
  uint16_T F;                          /* '<Root>/Data Store Memory5' */
  int16_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_pwm_with_data_2_T;

/* Parameters (default storage) */
struct P_pwm_with_data_2_T_ {
  uint32_T EnableGate_Value;           /* Computed Parameter: EnableGate_Value
                                        * Referenced by: '<S1>/Enable Gate'
                                        */
  uint32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint32_T EnableGate_Value_f;         /* Computed Parameter: EnableGate_Value_f
                                        * Referenced by: '<Root>/Enable Gate'
                                        */
  uint32_T Wake_Value;                 /* Computed Parameter: Wake_Value
                                        * Referenced by: '<Root>/Wake'
                                        */
  uint32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  uint32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint32_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  uint16_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint16_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  uint16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_pwm_with_data_2_T {
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
extern P_pwm_with_data_2_T pwm_with_data_2_P;

/* Block signals (default storage) */
extern B_pwm_with_data_2_T pwm_with_data_2_B;

/* Block states (default storage) */
extern DW_pwm_with_data_2_T pwm_with_data_2_DW;

/* Model entry point functions */
extern void pwm_with_data_2_initialize(void);
extern void pwm_with_data_2_step(void);
extern void pwm_with_data_2_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_pwm_with_data_2_T *const pwm_with_data_2_M;
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
 * '<Root>' : 'pwm_with_data_2'
 * '<S1>'   : 'pwm_with_data_2/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_pwm_with_data_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
