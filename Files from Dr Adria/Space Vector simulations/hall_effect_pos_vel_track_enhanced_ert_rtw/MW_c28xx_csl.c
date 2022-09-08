#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "hall_effect_pos_vel_track_enhanced.h"
#include "hall_effect_pos_vel_track_enhanced_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void ADCA1_INT_isr(void)
{
  isr_int1pie1_task_fcn();
  EALLOW;
  AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
  EDIS;
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
                                     /* Acknowledge to receive more interrupts*/
}

interrupt void ECAP1_INT_isr(void)
{
  isr_int4pie1_task_fcn();
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
                                     /* Acknowledge to receive more interrupts*/
  ECap1Regs.ECCLR.all = ECap1Regs.ECFLG.all;
}

interrupt void ECAP2_INT_isr(void)
{
  isr_int4pie2_task_fcn();
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
                                     /* Acknowledge to receive more interrupts*/
  ECap2Regs.ECCLR.all = ECap2Regs.ECFLG.all;
}

interrupt void ECAP3_INT_isr(void)
{
  isr_int4pie3_task_fcn();
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
                                     /* Acknowledge to receive more interrupts*/
  ECap3Regs.ECCLR.all = ECap3Regs.ECFLG.all;
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.ADCA1_INT = &ADCA1_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER1.bit.INTx1 = 1;   /* Enable interrupt ADCA1_INT*/
  IER |= M_INT1;
  EALLOW;
  PieVectTable.ECAP1_INT = &ECAP1_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER4.bit.INTx1 = 1;   /* Enable interrupt ECAP1_INT*/
  IER |= M_INT4;
  EALLOW;
  PieVectTable.ECAP2_INT = &ECAP2_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER4.bit.INTx2 = 1;   /* Enable interrupt ECAP2_INT*/
  IER |= M_INT4;
  EALLOW;
  PieVectTable.ECAP3_INT = &ECAP3_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER4.bit.INTx3 = 1;   /* Enable interrupt ECAP3_INT*/
  IER |= M_INT4;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                               /* Enable Global realtime interrupt DBGM*/
}
