/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: svpwm3.h
 *
 * Code generated for Simulink model 'svpwm3'.
 *
 * Model version                  : 4.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul  7 16:24:49 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_svpwm3_h_
#define RTW_HEADER_svpwm3_h_
#ifndef svpwm3_COMMON_INCLUDES_
#define svpwm3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* svpwm3_COMMON_INCLUDES_ */

#include "svpwm3_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  uint16_T ADC;                        /* '<S1>/ADC' */
  uint16_T ADC1;                       /* '<S1>/ADC1' */
  uint16_T ADC2;                       /* '<S1>/ADC2' */
} B_svpwm3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T A;                          /* '<Root>/Data Store Memory' */
  uint32_T B;                          /* '<Root>/Data Store Memory1' */
  uint32_T C;                          /* '<Root>/Data Store Memory2' */
} DW_svpwm3_T;

/* Parameters (default storage) */
struct P_svpwm3_T_ {
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
struct tag_RTM_svpwm3_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_svpwm3_T svpwm3_P;

/* Block signals (default storage) */
extern B_svpwm3_T svpwm3_B;

/* Block states (default storage) */
extern DW_svpwm3_T svpwm3_DW;

/* Model entry point functions */
extern void svpwm3_initialize(void);
extern void svpwm3_step(void);
extern void svpwm3_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_svpwm3_T *const svpwm3_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
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
 * '<Root>' : 'svpwm3'
 * '<S1>'   : 'svpwm3/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_svpwm3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
