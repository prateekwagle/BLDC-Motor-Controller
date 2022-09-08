/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hall_effect_pos_vel_track_enhanced_data.c
 *
 * Code generated for Simulink model 'hall_effect_pos_vel_track_enhanced'.
 *
 * Model version                  : 4.71
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul 21 15:32:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hall_effect_pos_vel_track_enhanced.h"

/* Block parameters (default storage) */
P_hall_effect_pos_vel_track_e_T hall_effect_pos_vel_track_enh_P = {
  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S15>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  3.03F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S16>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S16>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_f
   * Referenced by: '<S5>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_d
   * Referenced by: '<S12>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_g
   * Referenced by: '<S12>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_j
   * Referenced by: '<S6>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_i
   * Referenced by: '<S13>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_i
   * Referenced by: '<S13>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_a
   * Referenced by: '<S11>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_ig
   * Referenced by: '<S14>/Constant1'
   */
  4.99F,

  /* Computed Parameter: Constant2_Value_m
   * Referenced by: '<S14>/Constant2'
   */
  66.99F,

  /* Computed Parameter: Constant3_Value_jt
   * Referenced by: '<S7>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_h
   * Referenced by: '<S1>/Constant1'
   */
  3.03F,

  /* Computed Parameter: Constant1_Value_n
   * Referenced by: '<S10>/Constant1'
   */
  1.65F,

  /* Computed Parameter: Constant2_Value_ix
   * Referenced by: '<S10>/Constant2'
   */
  10.0F,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S10>/Constant'
   */
  0.007F,

  /* Computed Parameter: Constant3_Value_o
   * Referenced by: '<S17>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_hp
   * Referenced by: '<S8>/Constant1'
   */
  1.65F,

  /* Computed Parameter: Constant2_Value_p
   * Referenced by: '<S8>/Constant2'
   */
  10.0F,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S8>/Constant'
   */
  0.007F,

  /* Computed Parameter: Constant3_Value_jd
   * Referenced by: '<S18>/Constant3'
   */
  4095.0F,

  /* Computed Parameter: Constant1_Value_e
   * Referenced by: '<S9>/Constant1'
   */
  1.65F,

  /* Computed Parameter: Constant2_Value_l
   * Referenced by: '<S9>/Constant2'
   */
  10.0F,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S9>/Constant'
   */
  0.007F,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S2>/Outport'
   */
  0.0F,

  /* Computed Parameter: Outport_Y0_o
   * Referenced by: '<S4>/Outport'
   */
  0.0F,

  /* Computed Parameter: Outport_Y0_i
   * Referenced by: '<S3>/Outport'
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

  /* Computed Parameter: TmpRTBAtDisplayInport1_InitialC
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: TmpRTBAtDisplay1Inport1_Initial
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: TmpRTBAtDisplay2Inport1_Initial
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: RT_InitialCondition
   * Referenced by: '<Root>/RT'
   */
  0.0F,

  /* Computed Parameter: RT1_InitialCondition
   * Referenced by: '<Root>/RT1'
   */
  0.0F,

  /* Computed Parameter: RT2_InitialCondition
   * Referenced by: '<Root>/RT2'
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
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
