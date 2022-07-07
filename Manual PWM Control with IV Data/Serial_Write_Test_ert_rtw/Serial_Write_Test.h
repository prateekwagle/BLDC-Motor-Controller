/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_Write_Test.h
 *
 * Code generated for Simulink model 'Serial_Write_Test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul  7 13:50:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Serial_Write_Test_h_
#define RTW_HEADER_Serial_Write_Test_h_
#ifndef Serial_Write_Test_COMMON_INCLUDES_
#define Serial_Write_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#endif                                 /* Serial_Write_Test_COMMON_INCLUDES_ */

#include "Serial_Write_Test_types.h"
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
  uint16_T SCITransmit;                /* '<Root>/SCI Transmit' */
} B_Serial_Write_Test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T Output_DSTATE;              /* '<S1>/Output' */
} DW_Serial_Write_Test_T;

/* Parameters (default storage) */
struct P_Serial_Write_Test_T_ {
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S3>/FixPt Switch'
                                        */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S2>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S1>/Output'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_Serial_Write_Test_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Serial_Write_Test_T Serial_Write_Test_P;

/* Block signals (default storage) */
extern B_Serial_Write_Test_T Serial_Write_Test_B;

/* Block states (default storage) */
extern DW_Serial_Write_Test_T Serial_Write_Test_DW;

/* Model entry point functions */
extern void Serial_Write_Test_initialize(void);
extern void Serial_Write_Test_step(void);
extern void Serial_Write_Test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Serial_Write_Test_T *const Serial_Write_Test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
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
 * '<Root>' : 'Serial_Write_Test'
 * '<S1>'   : 'Serial_Write_Test/Counter Limited'
 * '<S2>'   : 'Serial_Write_Test/Counter Limited/Increment Real World'
 * '<S3>'   : 'Serial_Write_Test/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Serial_Write_Test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
