/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pwm_with_data_2_private.h
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

#ifndef RTW_HEADER_pwm_with_data_2_private_h_
#define RTW_HEADER_pwm_with_data_2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "pwm_with_data_2.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcA (void);
void config_ADCA_SOC0 (void);
extern uint16_T MW_adcAInitFlag;
void isr_int1pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie1_task_fcn(void);

#endif                               /* RTW_HEADER_pwm_with_data_2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
