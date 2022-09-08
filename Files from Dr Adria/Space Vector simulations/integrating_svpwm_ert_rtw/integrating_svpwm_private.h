/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integrating_svpwm_private.h
 *
 * Code generated for Simulink model 'integrating_svpwm'.
 *
 * Model version                  : 4.73
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul 26 16:25:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_integrating_svpwm_private_h_
#define RTW_HEADER_integrating_svpwm_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "integrating_svpwm.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcA (void);
void config_ADCA_SOC2 (void);
void config_ADCA_SOC1 (void);
void InitAdcC (void);
void config_ADCC_SOC1 (void);
void InitAdcB (void);
void config_ADCB_SOC1 (void);
void config_ADCA_SOC0 (void);
void config_ADCC_SOC0 (void);
void config_ADCB_SOC0 (void);
extern uint16_T MW_adcAInitFlag;
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcBInitFlag;
extern real32_T rt_remf_snf(real32_T u0, real32_T u1);
void isr_int1pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
extern void SwitchCaseActionSubsystem1_Init(real32_T *rty_Out1,
  P_SwitchCaseActionSubsystem15_T *localP);
extern void SwitchCaseActionSubsyst_Disable(real32_T *rty_Out1,
  P_SwitchCaseActionSubsystem15_T *localP);
extern void int_SwitchCaseActionSubsystem15(real32_T *rty_Out1,
  P_SwitchCaseActionSubsystem15_T *localP);
void isr_int1pie1_task_fcn(void);

#endif                             /* RTW_HEADER_integrating_svpwm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
