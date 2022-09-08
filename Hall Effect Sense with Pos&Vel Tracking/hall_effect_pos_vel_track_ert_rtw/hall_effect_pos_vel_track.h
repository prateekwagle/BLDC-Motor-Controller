/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hall_effect_pos_vel_track.h
 *
 * Code generated for Simulink model 'hall_effect_pos_vel_track'.
 *
 * Model version                  : 4.73
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 23 14:52:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hall_effect_pos_vel_track_h_
#define RTW_HEADER_hall_effect_pos_vel_track_h_
#ifndef hall_effect_pos_vel_track_COMMON_INCLUDES_
#define hall_effect_pos_vel_track_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                          /* hall_effect_pos_vel_track_COMMON_INCLUDES_ */

#include "hall_effect_pos_vel_track_types.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);

/* Block states (default storage) for system '<S1>/Switch Case Action Subsystem15' */
typedef struct {
  int16_T SwitchCaseActionSubsystem15_Sub;
                                     /* '<S1>/Switch Case Action Subsystem15' */
} DW_SwitchCaseActionSubsystem1_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Product;                    /* '<S15>/Product' */
  real32_T Product_d;                  /* '<S11>/Product' */
  real32_T Product_p;                  /* '<S12>/Product' */
  real32_T Product_o;                  /* '<S13>/Product' */
  real32_T Divide;                     /* '<S9>/Divide' */
  real32_T Divide_b;                   /* '<S7>/Divide' */
  real32_T Divide_d;                   /* '<S8>/Divide' */
  real32_T DataStoreRead3;             /* '<S1>/Data Store Read3' */
  real32_T DataStoreRead4;             /* '<S1>/Data Store Read4' */
  real32_T Add;                        /* '<S21>/Add' */
  real32_T Product_od;                 /* '<S20>/Product' */
  real32_T Product_f;                  /* '<S19>/Product' */
  real32_T Product_ph;                 /* '<S18>/Product' */
  uint16_T ADC3;                       /* '<S1>/ADC3' */
  uint16_T ADC;                        /* '<S1>/ADC' */
  uint16_T ADC1;                       /* '<S1>/ADC1' */
  uint16_T ADC2;                       /* '<S1>/ADC2' */
  uint16_T ADC6;                       /* '<S1>/ADC6' */
  uint16_T ADC4;                       /* '<S1>/ADC4' */
  uint16_T ADC5;                       /* '<S1>/ADC5' */
  boolean_T Hall_V_Digital1;           /* '<S1>/Hall_V_Digital1' */
  boolean_T Hall_W_Digital1;           /* '<S1>/Hall_W_Digital1' */
  boolean_T Hall_U_Digital1;           /* '<S1>/Hall_U_Digital1' */
} B_hall_effect_pos_vel_track_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DelayOneStep3_DSTATE;       /* '<S1>/Delay One Step3' */
  real32_T DelayOneStep4_DSTATE;       /* '<S1>/Delay One Step4' */
  real32_T MOT_VEL;                    /* '<Root>/Data Store Memory10' */
  real32_T MOT_POS;                    /* '<Root>/Data Store Memory13' */
  real32_T I_A;                        /* '<Root>/Data Store Memory3' */
  real32_T I_B;                        /* '<Root>/Data Store Memory4' */
  real32_T I_C;                        /* '<Root>/Data Store Memory5' */
  real32_T V_A;                        /* '<Root>/Data Store Memory6' */
  real32_T V_B;                        /* '<Root>/Data Store Memory7' */
  real32_T V_C;                        /* '<Root>/Data Store Memory8' */
  real32_T V_PVDD;                     /* '<Root>/Data Store Memory9' */
  real32_T TmpLatchAtTriggeredSubsystem3In;/* synthesized block */
  uint32_T A;                          /* '<Root>/Data Store Memory' */
  uint32_T B;                          /* '<Root>/Data Store Memory1' */
  uint32_T C;                          /* '<Root>/Data Store Memory2' */
  int16_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int16_T SwitchCase3_ActiveSubsystem; /* '<S1>/Switch Case3' */
  int16_T TriggeredSubsystem3_SubsysRanBC;/* '<S1>/Triggered Subsystem3' */
  int16_T TriggeredSubsystem2_SubsysRanBC;/* '<S1>/Triggered Subsystem2' */
  int16_T SwitchCaseActionSubsystem17_Sub;
                                     /* '<S1>/Switch Case Action Subsystem17' */
  int16_T IfActionSubsystem1_SubsysRanBC;/* '<S1>/If Action Subsystem1' */
  DW_SwitchCaseActionSubsystem1_T SwitchCaseActionSubsystem16;
                                     /* '<S1>/Switch Case Action Subsystem16' */
  DW_SwitchCaseActionSubsystem1_T SwitchCaseActionSubsystem15;
                                     /* '<S1>/Switch Case Action Subsystem15' */
} DW_hall_effect_pos_vel_track_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem3_Trig_ZCE;/* '<S1>/Triggered Subsystem3' */
  ZCSigState TriggeredSubsystem2_Trig_ZCE;/* '<S1>/Triggered Subsystem2' */
} PrevZCX_hall_effect_pos_vel_t_T;

/* Parameters for system: '<S1>/Switch Case Action Subsystem15' */
struct P_SwitchCaseActionSubsystem15_T_ {
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S18>/Out1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real32_T Pi_Value;                   /* Computed Parameter: Pi_Value
                                        * Referenced by: '<S18>/Pi'
                                        */
};

/* Parameters (default storage) */
struct P_hall_effect_pos_vel_track_T_ {
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S23>/Lower Limit'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S23>/Upper Limit'
                                        */
  real_T CombinatorialLogic_table[8];  /* Expression: [0;1;3;2;5;6;4;7]
                                        * Referenced by: '<S1>/Combinatorial  Logic'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S20>/Out1'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real32_T Pi_Value;                   /* Computed Parameter: Pi_Value
                                        * Referenced by: '<S20>/Pi'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real32_T Outport_Y0;                 /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S21>/Outport'
                                        */
  real32_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S21>/Memory'
                                   */
  real32_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S22>/Constant'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real32_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real32_T Constant2_Value_b;          /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real32_T Constant3_Value_f;          /* Computed Parameter: Constant3_Value_f
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real32_T Constant1_Value_d;          /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real32_T Constant2_Value_g;          /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real32_T Constant3_Value_j;          /* Computed Parameter: Constant3_Value_j
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real32_T Constant2_Value_i;          /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real32_T Constant3_Value_a;          /* Computed Parameter: Constant3_Value_a
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real32_T Constant1_Value_ig;         /* Computed Parameter: Constant1_Value_ig
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real32_T Constant2_Value_m;          /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real32_T Constant3_Value_jt;         /* Computed Parameter: Constant3_Value_jt
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real32_T Constant2_Value_ix;         /* Computed Parameter: Constant2_Value_ix
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T Constant3_Value_o;          /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real32_T Constant1_Value_hp;         /* Computed Parameter: Constant1_Value_hp
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T Constant3_Value_jd;         /* Computed Parameter: Constant3_Value_jd
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real32_T Constant2_Value_l;          /* Computed Parameter: Constant2_Value_l
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S8>/Constant'
                                        */
  real32_T DelayOneStep3_InitialCondition;
                           /* Computed Parameter: DelayOneStep3_InitialCondition
                            * Referenced by: '<S1>/Delay One Step3'
                            */
  real32_T DelayOneStep4_InitialCondition;
                           /* Computed Parameter: DelayOneStep4_InitialCondition
                            * Referenced by: '<S1>/Delay One Step4'
                            */
  real32_T TmpLatchAtTriggeredSubsystem3In;
                          /* Computed Parameter: TmpLatchAtTriggeredSubsystem3In
                           * Referenced by:
                           */
  real32_T DataStoreMemory10_InitialValue;
                           /* Computed Parameter: DataStoreMemory10_InitialValue
                            * Referenced by: '<Root>/Data Store Memory10'
                            */
  real32_T DataStoreMemory13_InitialValue;
                           /* Computed Parameter: DataStoreMemory13_InitialValue
                            * Referenced by: '<Root>/Data Store Memory13'
                            */
  real32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  real32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  real32_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  real32_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  real32_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  real32_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  real32_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  uint32_T EnableGate_Value;           /* Computed Parameter: EnableGate_Value
                                        * Referenced by: '<S1>/Enable Gate'
                                        */
  uint32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint32_T Constant1_Value_a;          /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint32_T Constant2_Value_e;          /* Computed Parameter: Constant2_Value_e
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint32_T EnableGate_Value_f;         /* Computed Parameter: EnableGate_Value_f
                                        * Referenced by: '<Root>/Enable Gate'
                                        */
  uint32_T Wake_Value;                 /* Computed Parameter: Wake_Value
                                        * Referenced by: '<Root>/Wake'
                                        */
  uint32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  uint32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint32_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  P_SwitchCaseActionSubsystem15_T SwitchCaseActionSubsystem16;
                                     /* '<S1>/Switch Case Action Subsystem16' */
  P_SwitchCaseActionSubsystem15_T SwitchCaseActionSubsystem15;
                                     /* '<S1>/Switch Case Action Subsystem15' */
};

/* Real-time Model Data Structure */
struct tag_RTM_hall_effect_pos_vel_t_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint8_T rtmL2HLastBufWr;
    uint32_T rtmL2HDbBufClockTick[2];
    uint32_T clockTick1;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_hall_effect_pos_vel_track_T hall_effect_pos_vel_track_P;

/* Block signals (default storage) */
extern B_hall_effect_pos_vel_track_T hall_effect_pos_vel_track_B;

/* Block states (default storage) */
extern DW_hall_effect_pos_vel_track_T hall_effect_pos_vel_track_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_hall_effect_pos_vel_t_T hall_effect_pos_vel_tra_PrevZCX;

/* Model entry point functions */
extern void hall_effect_pos_vel_track_initialize(void);
extern void hall_effect_pos_vel_track_step(void);
extern void hall_effect_pos_vel_track_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_hall_effect_pos_vel__T *const hall_effect_pos_vel_track_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S23>/FixPt Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'hall_effect_pos_vel_track'
 * '<S1>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem'
 * '<S2>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Compare To Zero1'
 * '<S3>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/If Action Subsystem1'
 * '<S4>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem'
 * '<S5>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem1'
 * '<S6>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem10'
 * '<S7>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem11'
 * '<S8>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem12'
 * '<S9>'   : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem13'
 * '<S10>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem2'
 * '<S11>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem3'
 * '<S12>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem4'
 * '<S13>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem5'
 * '<S14>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem6'
 * '<S15>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem7'
 * '<S16>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem8'
 * '<S17>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Subsystem9'
 * '<S18>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Switch Case Action Subsystem15'
 * '<S19>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Switch Case Action Subsystem16'
 * '<S20>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Switch Case Action Subsystem17'
 * '<S21>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Triggered Subsystem2'
 * '<S22>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Triggered Subsystem3'
 * '<S23>'  : 'hall_effect_pos_vel_track/Function-Call Subsystem/Triggered Subsystem2/Interval Test'
 */
#endif                             /* RTW_HEADER_hall_effect_pos_vel_track_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
