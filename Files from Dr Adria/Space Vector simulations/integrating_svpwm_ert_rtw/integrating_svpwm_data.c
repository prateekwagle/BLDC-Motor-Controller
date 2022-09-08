/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integrating_svpwm_data.c
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

#include "integrating_svpwm.h"

/* Block parameters (default storage) */
P_integrating_svpwm_T integrating_svpwm_P = {
  /* Mask Parameter: IntervalTest_lowlimit
   * Referenced by: '<S26>/Lower Limit'
   */
  -6.28318548F,

  /* Mask Parameter: IntervalTest_uplimit
   * Referenced by: '<S26>/Upper Limit'
   */
  6.28318548F,

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: [0;1;3;2;5;6;4;7]
   * Referenced by: '<S1>/Combinatorial  Logic'
   */
  { 0.0, 1.0, 3.0, 2.0, 5.0, 6.0, 4.0, 7.0 },

  /* Expression: [2,-1,-1;0,-sqrt(3),sqrt(3);1,1,1]
   * Referenced by: '<S25>/Clarke Transform'
   */
  { 2.0, 0.0, 1.0, -1.0, -1.7320508075688772, 1.0, -1.0, 1.7320508075688772, 1.0
  },

  /* Expression: 1/3
   * Referenced by: '<S25>/Gain1'
   */
  0.33333333333333331,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 2*pi/3
   * Referenced by: '<S25>/we1'
   */
  2.0943951023931953,

  /* Expression: sqrt(2)*1
   * Referenced by: '<S25>/Gain'
   */
  1.4142135623730951,

  /* Expression: [sqrt(3) 1;0,-1;-sqrt(3), 1]
   * Referenced by: '<S24>/Constant3'
   */
  { 1.7320508075688772, 0.0, -1.7320508075688772, 1.0, -1.0, 1.0 },

  /* Expression: [3;3;1;2;5;4;0;0]
   * Referenced by: '<S24>/Combinatorial  Logic'
   */
  { 3.0, 3.0, 1.0, 2.0, 5.0, 4.0, 0.0, 0.0 },

  /* Expression: [2,1,0,0,1,2]
   * Referenced by: '<S1>/cmpa'
   */
  { 2.0, 1.0, 0.0, 0.0, 1.0, 2.0 },

  /* Expression: [-0.5, -0.5; 0.5, -0.5; 0.5, 0.5]
   * Referenced by: '<S1>/Constant7'
   */
  { -0.5, 0.5, 0.5, -0.5, -0.5, 0.5 },

  /* Expression: [0,-sqrt(3)/3,-sqrt(3)/3,sqrt(3)/3,sqrt(3)/3,0]
   * Referenced by: '<S1>/v2beta'
   */
  { 0.0, -0.57735026918962573, -0.57735026918962573, 0.57735026918962573,
    0.57735026918962573, 0.0 },

  /* Expression: [-sqrt(3)/3,-sqrt(3)/3,0,0,sqrt(3)/3,sqrt(3)/3]
   * Referenced by: '<S1>/v1beta'
   */
  { -0.57735026918962573, -0.57735026918962573, 0.0, 0.0, 0.57735026918962573,
    0.57735026918962573 },

  /* Expression: -1
   * Referenced by: '<S1>/Gain4'
   */
  -1.0,

  /* Expression: [2/3,-1/3,-1/3,-1/3,-1/3,2/3]
   * Referenced by: '<S1>/v2alpha'
   */
  { 0.66666666666666663, -0.33333333333333331, -0.33333333333333331,
    -0.33333333333333331, -0.33333333333333331, 0.66666666666666663 },

  /* Expression: -1
   * Referenced by: '<S1>/Gain5'
   */
  -1.0,

  /* Expression: [1/3,1/3,-2/3,-2/3,1/3,1/3]
   * Referenced by: '<S1>/v1alpha'
   */
  { 0.33333333333333331, 0.33333333333333331, -0.66666666666666663,
    -0.66666666666666663, 0.33333333333333331, 0.33333333333333331 },

  /* Expression: 1
   * Referenced by: '<S23>/Constant4'
   */
  1.0,

  /* Expression: [0.5;0.5;0.5]
   * Referenced by: '<S1>/Constant8'
   */
  { 0.5, 0.5, 0.5 },

  /* Expression: [1,2,2,1,0,0]
   * Referenced by: '<S1>/cmpb'
   */
  { 1.0, 2.0, 2.0, 1.0, 0.0, 0.0 },

  /* Expression: [0,0,1,2,2,1]
   * Referenced by: '<S1>/cmpc'
   */
  { 0.0, 0.0, 1.0, 2.0, 2.0, 1.0 },

  /* Expression: 2*pi*50
   * Referenced by: '<S25>/we'
   */
  314.15926535897933,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S3>/Constant'
   */
  0.0F,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S20>/Out1'
   */
  0.0F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S20>/Constant2'
   */
  45.0F,

  /* Computed Parameter: Pi_Value
   * Referenced by: '<S20>/Pi'
   */
  3.14159274F,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S1>/Constant5'
   */
  0.0F,

  /* Computed Parameter: Constant4_Value_f
   * Referenced by: '<S1>/Constant4'
   */
  1.0F,

  /* Computed Parameter: Constant2_Value_k
   * Referenced by: '<S21>/Constant2'
   */
  45.0F,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S21>/Constant'
   */
  2.0F,

  /* Computed Parameter: Pi_Value_p
   * Referenced by: '<S21>/Pi'
   */
  3.14159274F,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S21>/Outport'
   */
  0.0F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S21>/Memory'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_i2
   * Referenced by: '<S22>/Constant'
   */
  5000.0F,

  /* Computed Parameter: Constant_Value_hl
   * Referenced by: '<S2>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant3_Value_o
   * Referenced by: '<S14>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S1>/Constant'
   */
  3.03F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S15>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_b
   * Referenced by: '<S15>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_f
   * Referenced by: '<S4>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_d
   * Referenced by: '<S11>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_g
   * Referenced by: '<S11>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_j
   * Referenced by: '<S5>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_i
   * Referenced by: '<S12>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_i
   * Referenced by: '<S12>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_a
   * Referenced by: '<S10>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_ig
   * Referenced by: '<S13>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_m
   * Referenced by: '<S13>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_jt
   * Referenced by: '<S6>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_h
   * Referenced by: '<S1>/Constant1'
   */
  3.03F,

  /* Computed Parameter: Constant1_Value_n
   * Referenced by: '<S9>/Constant1'
   */
  1.65F,

  /* Computed Parameter: Constant2_Value_ix
   * Referenced by: '<S9>/Constant2'
   */
  10.0F,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S9>/Constant'
   */
  0.007F,

  /* Computed Parameter: Constant3_Value_o0
   * Referenced by: '<S16>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_hp
   * Referenced by: '<S7>/Constant1'
   */
  1.65F,

  /* Computed Parameter: Constant2_Value_p
   * Referenced by: '<S7>/Constant2'
   */
  10.0F,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S7>/Constant'
   */
  0.007F,

  /* Computed Parameter: Constant3_Value_jd
   * Referenced by: '<S17>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_e
   * Referenced by: '<S8>/Constant1'
   */
  1.65F,

  /* Computed Parameter: Constant2_Value_l
   * Referenced by: '<S8>/Constant2'
   */
  10.0F,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S8>/Constant'
   */
  0.007F,

  /* Computed Parameter: DelayOneStep3_InitialCondition
   * Referenced by: '<S1>/Delay One Step3'
   */
  0.0F,

  /* Computed Parameter: DelayOneStep4_InitialCondition
   * Referenced by: '<S1>/Delay One Step4'
   */
  0.0F,

  /* Computed Parameter: TmpLatchAtTriggeredSubsystem3In
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory10_InitialValue
   * Referenced by: '<Root>/Data Store Memory10'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory13_InitialValue
   * Referenced by: '<Root>/Data Store Memory13'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory4_InitialValue
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory6_InitialValue
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory7_InitialValue
   * Referenced by: '<Root>/Data Store Memory7'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory9_InitialValue
   * Referenced by: '<Root>/Data Store Memory9'
   */
  0.0F,

  /* Computed Parameter: EnableGate_Value
   * Referenced by: '<S1>/Enable Gate'
   */
  1U,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<Root>/Constant'
   */
  3000U,

  /* Computed Parameter: Constant1_Value_a
   * Referenced by: '<Root>/Constant1'
   */
  3000U,

  /* Computed Parameter: Constant2_Value_e
   * Referenced by: '<Root>/Constant2'
   */
  3000U,

  /* Computed Parameter: EnableGate_Value_f
   * Referenced by: '<Root>/Enable Gate'
   */
  0U,

  /* Computed Parameter: Wake_Value
   * Referenced by: '<Root>/Wake'
   */
  1U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  0U,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0U,

  /* Computed Parameter: DataStoreMemory2_InitialValue
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0U,

  /* Start of '<S1>/Switch Case Action Subsystem16' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S19>/Out1'
     */
    0.0F,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S19>/Constant'
     */
    -1.0F,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S19>/Constant2'
     */
    45.0F,

    /* Computed Parameter: Pi_Value
     * Referenced by: '<S19>/Pi'
     */
    3.14159274F
  }
  ,

  /* End of '<S1>/Switch Case Action Subsystem16' */

  /* Start of '<S1>/Switch Case Action Subsystem15' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S18>/Out1'
     */
    0.0F,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S18>/Constant'
     */
    1.0F,

    /* Computed Parameter: Constant2_Value
     * Referenced by: '<S18>/Constant2'
     */
    45.0F,

    /* Computed Parameter: Pi_Value
     * Referenced by: '<S18>/Pi'
     */
    3.14159274F
  }
  /* End of '<S1>/Switch Case Action Subsystem15' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
