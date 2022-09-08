/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hall_effect_pos_vel_track_enhanced.h
 *
 * Code generated for Simulink model 'hall_effect_pos_vel_track_enhanced'.
 *
 * Model version                  : 4.72
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul 26 11:56:31 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hall_effect_pos_vel_track_enhanced_h_
#define RTW_HEADER_hall_effect_pos_vel_track_enhanced_h_
#ifndef hall_effect_pos_vel_track_enhanced_COMMON_INCLUDES_
#define hall_effect_pos_vel_track_enhanced_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                 /* hall_effect_pos_vel_track_enhanced_COMMON_INCLUDES_ */

#include "hall_effect_pos_vel_track_enhanced_types.h"
#include <string.h>
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

#define hall_effect_pos_vel_track_enhanced_M (hall_effect_pos_vel_track_en_M)

extern void init_CAP_GPIO();
extern void init_CAP1();
extern void init_CAP2();
extern void init_CAP3();
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  real32_T DelayOneStep;               /* '<Root>/Delay One Step' */
  real32_T DataStoreRead;              /* '<Root>/Data Store Read' */
  real32_T DataStoreRead1;             /* '<Root>/Data Store Read1' */
  real32_T DataStoreRead2;             /* '<Root>/Data Store Read2' */
  real32_T DataStoreRead3;             /* '<Root>/Data Store Read3' */
  real32_T eCAP2_P125_HALL_W[2];       /* '<Root>/eCAP2_P125_HALL_W' */
  real32_T eCAP3_P29_HALL_V[2];        /* '<Root>/eCAP3_P29_HALL_V' */
  real32_T eCAP1_P124_HALL_U[2];       /* '<Root>/eCAP1_P124_HALL_U' */
  real32_T DigitalInput;               /* '<S3>/Digital Input' */
  real32_T Switch1;                    /* '<S3>/Switch1' */
  real32_T DigitalInput_m;             /* '<S4>/Digital Input' */
  real32_T Switch1_o;                  /* '<S4>/Switch1' */
  real32_T DigitalInput_e;             /* '<S2>/Digital Input' */
  real32_T Add1;                       /* '<S2>/Add1' */
  real32_T Product;                    /* '<S17>/Product' */
  real32_T Product_d;                  /* '<S13>/Product' */
  real32_T Product_p;                  /* '<S14>/Product' */
  real32_T Product_o;                  /* '<S15>/Product' */
  real32_T Divide;                     /* '<S11>/Divide' */
  real32_T Divide_b;                   /* '<S9>/Divide' */
  real32_T Divide_d;                   /* '<S10>/Divide' */
  uint16_T ADC3;                       /* '<S1>/ADC3' */
  uint16_T ADC;                        /* '<S1>/ADC' */
  uint16_T ADC1;                       /* '<S1>/ADC1' */
  uint16_T ADC2;                       /* '<S1>/ADC2' */
  uint16_T ADC6;                       /* '<S1>/ADC6' */
  uint16_T ADC4;                       /* '<S1>/ADC4' */
  uint16_T ADC5;                       /* '<S1>/ADC5' */
} B_hall_effect_pos_vel_track_e_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DelayOneStep_DSTATE;        /* '<Root>/Delay One Step' */
  volatile real32_T TmpRTBAtHALL_U_SUBSYSTEMOutport[2];/* synthesized block */
  volatile real32_T TmpRTBAtHALL_V_SUBSYSTEMOutport[2];/* synthesized block */
  volatile real32_T TmpRTBAtHALL_W_SUBSYSTEMOutport[2];/* synthesized block */
  real32_T HALL_U;                     /* '<Root>/Data Store Memory11' */
  real32_T HALL_W;                     /* '<Root>/Data Store Memory12' */
  real32_T MOT_POS;                    /* '<Root>/Data Store Memory13' */
  real32_T HALL_V;                     /* '<Root>/Data Store Memory14' */
  real32_T I_A;                        /* '<Root>/Data Store Memory3' */
  real32_T I_B;                        /* '<Root>/Data Store Memory4' */
  real32_T I_C;                        /* '<Root>/Data Store Memory5' */
  real32_T V_A;                        /* '<Root>/Data Store Memory6' */
  real32_T V_B;                        /* '<Root>/Data Store Memory7' */
  real32_T V_C;                        /* '<Root>/Data Store Memory8' */
  real32_T V_PVDD;                     /* '<Root>/Data Store Memory9' */
  uint32_T A;                          /* '<Root>/Data Store Memory' */
  uint32_T B;                          /* '<Root>/Data Store Memory1' */
  uint32_T C;                          /* '<Root>/Data Store Memory2' */
  volatile int16_T TmpRTBAtHALL_U_SUBSYSTEMOutpo_i;/* synthesized block */
  volatile int16_T TmpRTBAtHALL_U_SUBSYSTEMOutpo_m;/* synthesized block */
  volatile int16_T TmpRTBAtHALL_V_SUBSYSTEMOutpo_a;/* synthesized block */
  volatile int16_T TmpRTBAtHALL_V_SUBSYSTEMOutpo_e;/* synthesized block */
  volatile int16_T TmpRTBAtHALL_W_SUBSYSTEMOutpo_d;/* synthesized block */
  volatile int16_T TmpRTBAtHALL_W_SUBSYSTEMOutpo_g;/* synthesized block */
  int16_T HALL_V_SUBSYSTEM_SubsysRanBC;/* '<Root>/HALL_V_SUBSYSTEM' */
  int16_T HALL_W_SUBSYSTEM_SubsysRanBC;/* '<Root>/HALL_W_SUBSYSTEM' */
  int16_T HALL_U_SUBSYSTEM_SubsysRanBC;/* '<Root>/HALL_U_SUBSYSTEM' */
  int16_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_hall_effect_pos_vel_track__T;

/* Parameters (default storage) */
struct P_hall_effect_pos_vel_track_e_T_ {
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S5>/Lower Limit'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S5>/Upper Limit'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real32_T Constant3_Value_f;          /* Computed Parameter: Constant3_Value_f
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real32_T Constant1_Value_d;          /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real32_T Constant2_Value_g;          /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real32_T Constant3_Value_j;          /* Computed Parameter: Constant3_Value_j
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real32_T Constant2_Value_i;          /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real32_T Constant3_Value_a;          /* Computed Parameter: Constant3_Value_a
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real32_T Constant1_Value_ig;         /* Computed Parameter: Constant1_Value_ig
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real32_T Constant2_Value_m;          /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real32_T Constant3_Value_jt;         /* Computed Parameter: Constant3_Value_jt
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real32_T Constant2_Value_ix;         /* Computed Parameter: Constant2_Value_ix
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S11>/Constant'
                                        */
  real32_T Constant3_Value_o;          /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real32_T Constant1_Value_hp;         /* Computed Parameter: Constant1_Value_hp
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T Constant3_Value_jd;         /* Computed Parameter: Constant3_Value_jd
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real32_T Constant2_Value_l;          /* Computed Parameter: Constant2_Value_l
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S10>/Constant'
                                        */
  real32_T Constant_Value_ej;          /* Computed Parameter: Constant_Value_ej
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T Constant1_Value_nw;         /* Computed Parameter: Constant1_Value_nw
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real32_T Outport_Y0;                 /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S2>/Outport'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S20>/Constant'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S4>/Constant'
                                        */
  real32_T Constant1_Value_p;          /* Computed Parameter: Constant1_Value_p
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real32_T Outport_Y0_c;               /* Computed Parameter: Outport_Y0_c
                                        * Referenced by: '<S4>/Outport'
                                        */
  real32_T Constant_Value_o1;          /* Computed Parameter: Constant_Value_o1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real32_T Constant_Value_es;          /* Computed Parameter: Constant_Value_es
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real32_T Outport_Y0_d;               /* Computed Parameter: Outport_Y0_d
                                        * Referenced by: '<S3>/Outport'
                                        */
  real32_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S21>/Constant'
                                        */
  real32_T Constant3_Value_m;          /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real32_T DataStoreMemory10_InitialValue;
                           /* Computed Parameter: DataStoreMemory10_InitialValue
                            * Referenced by: '<Root>/Data Store Memory10'
                            */
  real32_T TmpRTBAtHALL_U_SUBSYSTEMOutport;
                          /* Computed Parameter: TmpRTBAtHALL_U_SUBSYSTEMOutport
                           * Referenced by:
                           */
  real32_T TmpRTBAtHALL_V_SUBSYSTEMOutport;
                          /* Computed Parameter: TmpRTBAtHALL_V_SUBSYSTEMOutport
                           * Referenced by:
                           */
  real32_T TmpRTBAtHALL_W_SUBSYSTEMOutport;
                          /* Computed Parameter: TmpRTBAtHALL_W_SUBSYSTEMOutport
                           * Referenced by:
                           */
  real32_T DelayOneStep_InitialCondition;
                            /* Computed Parameter: DelayOneStep_InitialCondition
                             * Referenced by: '<Root>/Delay One Step'
                             */
  real32_T DataStoreMemory11_InitialValue;
                           /* Computed Parameter: DataStoreMemory11_InitialValue
                            * Referenced by: '<Root>/Data Store Memory11'
                            */
  real32_T DataStoreMemory12_InitialValue;
                           /* Computed Parameter: DataStoreMemory12_InitialValue
                            * Referenced by: '<Root>/Data Store Memory12'
                            */
  real32_T DataStoreMemory13_InitialValue;
                           /* Computed Parameter: DataStoreMemory13_InitialValue
                            * Referenced by: '<Root>/Data Store Memory13'
                            */
  real32_T DataStoreMemory14_InitialValue;
                           /* Computed Parameter: DataStoreMemory14_InitialValue
                            * Referenced by: '<Root>/Data Store Memory14'
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
  uint32_T Constant_Value_c1;          /* Computed Parameter: Constant_Value_c1
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
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint32_T clockTick4;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_hall_effect_pos_vel_track_e_T hall_effect_pos_vel_track_enh_P;

/* Block signals (default storage) */
extern B_hall_effect_pos_vel_track_e_T hall_effect_pos_vel_track_enh_B;

/* Block states (default storage) */
extern DW_hall_effect_pos_vel_track__T hall_effect_pos_vel_track_en_DW;

/* Model entry point functions */
extern void hall_effect_pos_vel_track_enhanced_initialize(void);
extern void hall_effect_pos_vel_track_enhanced_step(void);
extern void hall_effect_pos_vel_track_enhanced_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_hall_effect_pos_vel__T *const hall_effect_pos_vel_track_en_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Add' : Unused code path elimination
 * Block '<S3>/Add' : Unused code path elimination
 * Block '<S4>/Add' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/RT' : Unused code path elimination
 * Block '<Root>/RT1' : Unused code path elimination
 * Block '<Root>/RT2' : Unused code path elimination
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
 * '<Root>' : 'hall_effect_pos_vel_track_enhanced'
 * '<S1>'   : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem'
 * '<S2>'   : 'hall_effect_pos_vel_track_enhanced/HALL_U_SUBSYSTEM'
 * '<S3>'   : 'hall_effect_pos_vel_track_enhanced/HALL_V_SUBSYSTEM'
 * '<S4>'   : 'hall_effect_pos_vel_track_enhanced/HALL_W_SUBSYSTEM'
 * '<S5>'   : 'hall_effect_pos_vel_track_enhanced/Interval Test'
 * '<S6>'   : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem'
 * '<S7>'   : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem1'
 * '<S8>'   : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem10'
 * '<S9>'   : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem11'
 * '<S10>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem12'
 * '<S11>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem13'
 * '<S12>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem2'
 * '<S13>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem3'
 * '<S14>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem4'
 * '<S15>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem5'
 * '<S16>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem6'
 * '<S17>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem7'
 * '<S18>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem8'
 * '<S19>'  : 'hall_effect_pos_vel_track_enhanced/Function-Call Subsystem/Subsystem9'
 * '<S20>'  : 'hall_effect_pos_vel_track_enhanced/HALL_U_SUBSYSTEM/Compare To Zero'
 * '<S21>'  : 'hall_effect_pos_vel_track_enhanced/HALL_V_SUBSYSTEM/Compare To Zero'
 * '<S22>'  : 'hall_effect_pos_vel_track_enhanced/HALL_W_SUBSYSTEM/Compare To Zero'
 */
#endif                    /* RTW_HEADER_hall_effect_pos_vel_track_enhanced_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
