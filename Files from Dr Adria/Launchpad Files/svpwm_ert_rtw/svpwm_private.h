/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: svpwm_private.h
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

#ifndef RTW_HEADER_svpwm_private_h_
#define RTW_HEADER_svpwm_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "svpwm.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdc (void);
void config_ADC_SOC0 (void);
extern uint16_T MW_adcInitFlag;
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
void isr_int10pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int10pie1_task_fcn(void);

#endif                                 /* RTW_HEADER_svpwm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
