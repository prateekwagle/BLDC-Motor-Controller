#include "c2000BoardSupport.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"
#include "F2837xD_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "svpwm3.h"
#include "svpwm3_private.h"

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

void enable_interrupts()
{
  EALLOW;
  PieVectTable.ADCA1_INT = &ADCA1_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER1.bit.INTx1 = 1;   /* Enable interrupt ADCA1_INT*/
  IER |= M_INT1;

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
