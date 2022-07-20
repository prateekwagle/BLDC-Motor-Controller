/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: svpwm3_private.h
 *
 * Code generated for Simulink model 'svpwm3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jun 24 15:25:55 2022
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

void InitAdcA (void);
void config_ADCA_SOC0 (void);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
extern uint16_T MW_adcAInitFlag;
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcCInitFlag;
void isr_int1pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie1_task_fcn(void);

#endif                                 /* RTW_HEADER_svpwm3_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
