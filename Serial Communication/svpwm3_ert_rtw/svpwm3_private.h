/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: svpwm3_private.h
 *
 * Code generated for Simulink model 'svpwm3'.
 *
 * Model version                  : 4.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul 12 13:38:27 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_svpwm3_private_h_
#define RTW_HEADER_svpwm3_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "svpwm3.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcC (void);
void config_ADCC_SOC2 (void);
void InitAdcB (void);
void config_ADCB_SOC1 (void);
void InitAdcA (void);
void config_ADCA_SOC0 (void);
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcAInitFlag;
void isr_int1pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie1_task_fcn(void);

#endif                                 /* RTW_HEADER_svpwm3_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
