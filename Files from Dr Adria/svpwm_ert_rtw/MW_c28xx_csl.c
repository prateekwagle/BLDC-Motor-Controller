#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "svpwm.h"
#include "svpwm_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void SWINT10_1_isr(void)
{
  isr_int10pie1_task_fcn();
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
                                     /* Acknowledge to receive more interrupts*/
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.rsvd10_1 = &SWINT10_1_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER10.bit.INTx1 = 1;  /* Enable interrupt SWINT10_1*/
  IER |= M_INT10;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                               /* Enable Global realtime interrupt DBGM*/
}

void configureGPIOExtInterrupt (void)
{
}

void enableExtInterrupt (void)
{
}
