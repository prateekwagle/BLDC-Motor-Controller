#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "hall_effect_pos_vel_track_enhanced.h"
#include "hall_effect_pos_vel_track_enhanced_private.h"

void init_CAP1()
{
  EALLOW;
  CpuSysRegs.PCLKCR3.bit.ECAP1 = 1;
  ECap1Regs.ECEINT.all = 0x0000;       /* Disable all capture interrupts*/
  ECap1Regs.ECCLR.all = 0xFFFF;        /* Clear all CAP interrupt flags*/
  ECap1Regs.ECCTL1.bit.CAPLDEN = 0;    /* Disable CAP1-CAP4 register loads*/
  ECap1Regs.ECCTL2.bit.TSCTRSTOP = 0;  /* Make sure the counter is stopped*/
  ECap1Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap1Regs.ECCTL2.bit.SYNCO_SEL = 1;  /* Select CTR=PRD event */
  ECap1Regs.ECCTL2.bit.CAP_APWM = 0;   /* Capture mode*/
  ECap1Regs.ECCTL2.bit.CONT_ONESHT = 0;/* One-shot*/
  ECap1Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap1Regs.ECCTL2.bit.STOP_WRAP = 1;  /* Stop at 4 events*/
  ECap1Regs.ECCTL1.bit.CAP1POL = 0;    /* Select rising or falling edge*/
  ECap1Regs.ECCTL1.bit.CTRRST1 = 1;    /* Difference operation        */
  ECap1Regs.ECCTL1.bit.CAP2POL = 1;    /* Select rising or falling edge*/
  ECap1Regs.ECCTL1.bit.CTRRST2 = 1;    /* Difference operation        */
  ECap1Regs.ECEINT.bit.CEVT1 = 1;
  ECap1Regs.ECEINT.bit.CEVT2 = 1;
  ECap1Regs.ECCLR.all = 0x0FF;         /* Clear pending interrupts*/
  ECap1Regs.ECCTL2.bit.REARM = 1;      /* arm one-shot*/
  ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1;  /* Start Counter*/
  ECap1Regs.ECCTL1.bit.CAPLDEN = 1;    /* Enable CAP1-CAP4 register loads*/
  EDIS;
}

void init_CAP2()
{
  EALLOW;
  CpuSysRegs.PCLKCR3.bit.ECAP2 = 1;
  ECap2Regs.ECEINT.all = 0x0000;       /* Disable all capture interrupts*/
  ECap2Regs.ECCLR.all = 0xFFFF;        /* Clear all CAP interrupt flags*/
  ECap2Regs.ECCTL1.bit.CAPLDEN = 0;    /* Disable CAP1-CAP4 register loads*/
  ECap2Regs.ECCTL2.bit.TSCTRSTOP = 0;  /* Make sure the counter is stopped*/
  ECap2Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap2Regs.ECCTL2.bit.SYNCO_SEL = 1;  /* Select CTR=PRD event */
  ECap2Regs.ECCTL2.bit.CAP_APWM = 0;   /* Capture mode*/
  ECap2Regs.ECCTL2.bit.CONT_ONESHT = 0;/* One-shot*/
  ECap2Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap2Regs.ECCTL2.bit.STOP_WRAP = 1;  /* Stop at 4 events*/
  ECap2Regs.ECCTL1.bit.CAP1POL = 0;    /* Select rising or falling edge*/
  ECap2Regs.ECCTL1.bit.CTRRST1 = 1;    /* Difference operation        */
  ECap2Regs.ECCTL1.bit.CAP2POL = 1;    /* Select rising or falling edge*/
  ECap2Regs.ECCTL1.bit.CTRRST2 = 1;    /* Difference operation        */
  ECap2Regs.ECEINT.bit.CEVT1 = 1;
  ECap2Regs.ECEINT.bit.CEVT2 = 1;
  ECap2Regs.ECCLR.all = 0x0FF;         /* Clear pending interrupts*/
  ECap2Regs.ECCTL2.bit.REARM = 1;      /* arm one-shot*/
  ECap2Regs.ECCTL2.bit.TSCTRSTOP = 1;  /* Start Counter*/
  ECap2Regs.ECCTL1.bit.CAPLDEN = 1;    /* Enable CAP1-CAP4 register loads*/
  EDIS;
}

void init_CAP3()
{
  EALLOW;
  CpuSysRegs.PCLKCR3.bit.ECAP3 = 1;
  ECap3Regs.ECEINT.all = 0x0000;       /* Disable all capture interrupts*/
  ECap3Regs.ECCLR.all = 0xFFFF;        /* Clear all CAP interrupt flags*/
  ECap3Regs.ECCTL1.bit.CAPLDEN = 0;    /* Disable CAP1-CAP4 register loads*/
  ECap3Regs.ECCTL2.bit.TSCTRSTOP = 0;  /* Make sure the counter is stopped*/
  ECap3Regs.CTRPHS = 0U;               /* Counter Phase Control*/
  ECap3Regs.ECCTL2.bit.SYNCO_SEL = 1;  /* Select CTR=PRD event */
  ECap3Regs.ECCTL2.bit.CAP_APWM = 0;   /* Capture mode*/
  ECap3Regs.ECCTL2.bit.CONT_ONESHT = 0;/* One-shot*/
  ECap3Regs.ECCTL1.bit.PRESCALE = 0U;  /*Event prescaler*/
  ECap3Regs.ECCTL2.bit.STOP_WRAP = 1;  /* Stop at 4 events*/
  ECap3Regs.ECCTL1.bit.CAP1POL = 0;    /* Select rising or falling edge*/
  ECap3Regs.ECCTL1.bit.CTRRST1 = 1;    /* Difference operation        */
  ECap3Regs.ECCTL1.bit.CAP2POL = 1;    /* Select rising or falling edge*/
  ECap3Regs.ECCTL1.bit.CTRRST2 = 1;    /* Difference operation        */
  ECap3Regs.ECEINT.bit.CEVT1 = 1;
  ECap3Regs.ECEINT.bit.CEVT2 = 1;
  ECap3Regs.ECCLR.all = 0x0FF;         /* Clear pending interrupts*/
  ECap3Regs.ECCTL2.bit.REARM = 1;      /* arm one-shot*/
  ECap3Regs.ECCTL2.bit.TSCTRSTOP = 1;  /* Start Counter*/
  ECap3Regs.ECCTL1.bit.CAPLDEN = 1;    /* Enable CAP1-CAP4 register loads*/
  EDIS;
}
