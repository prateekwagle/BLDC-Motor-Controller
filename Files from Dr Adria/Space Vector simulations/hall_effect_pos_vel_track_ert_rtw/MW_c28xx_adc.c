#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "hall_effect_pos_vel_track.h"
#include "hall_effect_pos_vel_track_private.h"

void config_ADCA_SOC1()
{
  EALLOW;
  AdcaRegs.ADCSOC1CTL.bit.CHSEL = 15;  /* Set SOC1 channel select to ADCIN15*/
  AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = 11;
  AdcaRegs.ADCSOC1CTL.bit.ACQPS = 62.0;
                               /* Set SOC1 S/H Window to 63.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC1 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCC_SOC1()
{
  EALLOW;
  AdccRegs.ADCSOC1CTL.bit.CHSEL = 5;   /* Set SOC1 channel select to ADCIN5*/
  AdccRegs.ADCSOC1CTL.bit.TRIGSEL = 11;
  AdccRegs.ADCSOC1CTL.bit.ACQPS = 62.0;
                               /* Set SOC1 S/H Window to 63.0 ADC Clock Cycles*/
  AdccRegs.ADCINTSOCSEL1.bit.SOC1 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdccRegs.ADCOFFTRIM.bit.OFFTRIM = AdccRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCB_SOC1()
{
  EALLOW;
  AdcbRegs.ADCSOC1CTL.bit.CHSEL = 5;   /* Set SOC1 channel select to ADCIN5*/
  AdcbRegs.ADCSOC1CTL.bit.TRIGSEL = 11;
  AdcbRegs.ADCSOC1CTL.bit.ACQPS = 62.0;
                               /* Set SOC1 S/H Window to 63.0 ADC Clock Cycles*/
  AdcbRegs.ADCINTSOCSEL1.bit.SOC1 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcbRegs.ADCOFFTRIM.bit.OFFTRIM = AdcbRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcbRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC2()
{
  EALLOW;
  AdcaRegs.ADCSOC2CTL.bit.CHSEL = 5;   /* Set SOC2 channel select to ADCIN5*/
  AdcaRegs.ADCSOC2CTL.bit.TRIGSEL = 11;
  AdcaRegs.ADCSOC2CTL.bit.ACQPS = 62.0;
                               /* Set SOC2 S/H Window to 63.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1; /* Enabled/Disable ADCINT1 interrupt*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 2;/* Setup EOC2 to trigger ADCINT1*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1CONT = 0;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC2 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCC_SOC0()
{
  EALLOW;
  AdccRegs.ADCSOC0CTL.bit.CHSEL = 4;   /* Set SOC0 channel select to ADCIN4*/
  AdccRegs.ADCSOC0CTL.bit.TRIGSEL = 11;
  AdccRegs.ADCSOC0CTL.bit.ACQPS = 62.0;
                               /* Set SOC0 S/H Window to 63.0 ADC Clock Cycles*/
  AdccRegs.ADCINTSOCSEL1.bit.SOC0 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdccRegs.ADCOFFTRIM.bit.OFFTRIM = AdccRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCB_SOC0()
{
  EALLOW;
  AdcbRegs.ADCSOC0CTL.bit.CHSEL = 4;   /* Set SOC0 channel select to ADCIN4*/
  AdcbRegs.ADCSOC0CTL.bit.TRIGSEL = 11;
  AdcbRegs.ADCSOC0CTL.bit.ACQPS = 62.0;
                               /* Set SOC0 S/H Window to 63.0 ADC Clock Cycles*/
  AdcbRegs.ADCINTSOCSEL1.bit.SOC0 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcbRegs.ADCOFFTRIM.bit.OFFTRIM = AdcbRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcbRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC0()
{
  EALLOW;
  AdcaRegs.ADCSOC0CTL.bit.CHSEL = 4;   /* Set SOC0 channel select to ADCIN4*/
  AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = 11;
  AdcaRegs.ADCSOC0CTL.bit.ACQPS = 62.0;
                               /* Set SOC0 S/H Window to 63.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC0 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void InitAdcA()
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
  AdcaRegs.ADCCTL2.bit.PRESCALE = 8;
  AdcSetMode(ADC_ADCA, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);

  //power up the ADC
  AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}

void InitAdcB()
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
  AdcbRegs.ADCCTL2.bit.PRESCALE = 8;
  AdcSetMode(ADC_ADCB, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);

  //power up the ADC
  AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}

void InitAdcC()
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
  AdccRegs.ADCCTL2.bit.PRESCALE = 8;
  AdcSetMode(ADC_ADCC, ADC_RESOLUTION_12BIT, ADC_SIGNALMODE_SINGLE);

  //power up the ADC
  AdccRegs.ADCCTL1.bit.ADCPWDNZ = 1;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}
