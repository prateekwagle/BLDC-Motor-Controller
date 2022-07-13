#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "launchpad_tx.h"
#include "launchpad_tx_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

int checkSCITransmitInprogress;
void init_SCI(void)
{
  // to prevent re-entrancy in SCI transmit function
  checkSCITransmitInprogress = 0;

  /* initialize SCI & FIFO registers */
  EALLOW;

  /*
   * Initialize SCI_C with following parameters:
   *    BaudRate              : 115207
   *    CharacterLengthBits   : 8
   *    EnableLoopBack        : 0
   *    NumberOfStopBits      : 1
   *    ParityMode            : None
   *    SuspensionMode        : Free_run
   *    CommMode              : Raw_data
   */
  CpuSysRegs.PCLKCR7.bit.SCI_C = 1;
  asm(" NOP");
  ScicRegs.SCICCR.bit.STOPBITS = 0;
                    /*Number of stop bits. (0: One stop bit, 1: Two stop bits)*/
  ScicRegs.SCICCR.bit.PARITY = 0;/*Parity mode (0: Odd parity, 1: Even parity)*/
  ScicRegs.SCICCR.bit.PARITYENA = 0;   /*Enable Pary Mode */
  ScicRegs.SCICCR.bit.LOOPBKENA = 0;   /*Loop Back enable*/
  ScicRegs.SCICCR.bit.ADDRIDLE_MODE = 0;/*ADDR/IDLE Mode control*/
  ScicRegs.SCICCR.bit.SCICHAR = 7;     /*Character length*/
  ScicRegs.SCICTL1.bit.RXERRINTENA = 0;/*Disable receive error interrupt*/
  ScicRegs.SCICTL1.bit.SWRESET = 1;    /*Software reset*/
  ScicRegs.SCICTL1.bit.TXENA = 1;      /* SCI transmitter enable*/
  ScicRegs.SCICTL1.bit.RXENA = 0;      /* SCI receiver enable*/
  ScicRegs.SCIHBAUD.bit.BAUD = 0U;
  ScicRegs.SCILBAUD.bit.BAUD = 216U;

  /*Free run, continue SCI operation regardless of suspend*/
  ScicRegs.SCIPRI.bit.FREESOFT = 3;
  ScicRegs.SCIFFCT.bit.ABDCLR = 0;
  ScicRegs.SCIFFCT.bit.CDC = 0;
  ScicRegs.SCIFFTX.bit.SCIRST = 1;     /* SCI reset rx/tx channels*/
  ScicRegs.SCIFFTX.bit.SCIFFENA = 1;   /* SCI FIFO enhancements are enabled.*/
  ScicRegs.SCIFFTX.bit.TXFIFORESET = 1;/* Re-enable transmit FIFO operation.*/
  ScicRegs.SCIFFRX.bit.RXFIFORESET = 1;/* Re-enable receive FIFO operation.*/
  EDIS;
}

void init_SCI_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;  /*Enable pull-up for GPIO56*/
  GpioCtrlRegs.GPBGMUX2.bit.GPIO56 = 1;
  GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 2; /*Configure GPIO56 as SCITXDC*/
  EDIS;
}
