/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_blink.h
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

#ifndef RTW_HEADER_led_blink_h_
#define RTW_HEADER_led_blink_h_
#ifndef led_blink_COMMON_INCLUDES_
#define led_blink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#endif                                 /* led_blink_COMMON_INCLUDES_ */

#include "led_blink_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Parameters (default storage) */
struct P_led_blink_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_blink_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_led_blink_T led_blink_P;

/* Model entry point functions */
extern void led_blink_initialize(void);
extern void led_blink_step(void);
extern void led_blink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_led_blink_T *const led_blink_M;
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
 * '<Root>' : 'led_blink'
 */
#endif                                 /* RTW_HEADER_led_blink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
