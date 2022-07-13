/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_meas_plus_serial.c
 *
 * Code generated for Simulink model 'adc_meas_plus_serial'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jul  8 14:38:22 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "adc_meas_plus_serial.h"
#include "adc_meas_plus_serial_private.h"

/* Block signals (default storage) */
B_adc_meas_plus_serial_T adc_meas_plus_serial_B;

/* Real-time model */
static RT_MODEL_adc_meas_plus_serial_T adc_meas_plus_serial_M_;
RT_MODEL_adc_meas_plus_serial_T *const adc_meas_plus_serial_M =
  &adc_meas_plus_serial_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

/* Model step function */
void adc_meas_plus_serial_step(void)
{
  /* S-Function (c2802xadc): '<Root>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    float wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    adc_meas_plus_serial_B.ADC = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c28xsci_tx): '<Root>/SCI Transmit' */
  {
    if (checkSCITransmitInprogress != 1) {
      checkSCITransmitInprogress = 1;
      int errFlgHeader = NOERROR;
      int errFlgData = NOERROR;
      int errFlgTail = NOERROR;
      errFlgData = scia_xmit((char*)&adc_meas_plus_serial_B.ADC, 2, 2);
      checkSCITransmitInprogress = 0;
    }
  }
}

/* Model initialize function */
void adc_meas_plus_serial_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(adc_meas_plus_serial_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &adc_meas_plus_serial_B), 0,
                sizeof(B_adc_meas_plus_serial_T));

  /* Start for S-Function (c2802xadc): '<Root>/ADC' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC0 ();
}

/* Model terminate function */
void adc_meas_plus_serial_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
