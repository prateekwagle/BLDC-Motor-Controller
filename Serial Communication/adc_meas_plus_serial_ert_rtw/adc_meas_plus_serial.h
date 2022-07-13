/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_meas_plus_serial.h
 *
 * Code generated for Simulink model 'adc_meas_plus_serial'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jul  8 14:38:22 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_adc_meas_plus_serial_h_
#define RTW_HEADER_adc_meas_plus_serial_h_
#ifndef adc_meas_plus_serial_COMMON_INCLUDES_
#define adc_meas_plus_serial_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#endif                               /* adc_meas_plus_serial_COMMON_INCLUDES_ */

#include "adc_meas_plus_serial_types.h"
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

extern void init_SCI(void);
extern void init_SCI_GPIO(void);

/* Block signals (default storage) */
typedef struct {
  uint16_T ADC;                        /* '<Root>/ADC' */
} B_adc_meas_plus_serial_T;

/* Real-time Model Data Structure */
struct tag_RTM_adc_meas_plus_serial_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_adc_meas_plus_serial_T adc_meas_plus_serial_B;

/* Model entry point functions */
extern void adc_meas_plus_serial_initialize(void);
extern void adc_meas_plus_serial_step(void);
extern void adc_meas_plus_serial_terminate(void);

/* Real-time Model object */
extern RT_MODEL_adc_meas_plus_serial_T *const adc_meas_plus_serial_M;
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
 * '<Root>' : 'adc_meas_plus_serial'
 */
#endif                                 /* RTW_HEADER_adc_meas_plus_serial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
