/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DSP28xx_SciUtil.c
 *
 * Code generated for Simulink model 'launchpad_tx'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jul  8 13:53:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DSP28xx_SciUtil.h"

/* Transmit character(s) from the SCIc*/
int scic_xmit(char* pmsg, int msglen, int typeLen)
/*Blocking mode*/
{
  int i,j;
  if (typeLen==1) {
    for (i = 0; i < msglen; i++) {
      while (ScicRegs.SCIFFTX.bit.TXFFST == 16) {
      }                                /* The buffer is full;*/

      ScicRegs.SCITXBUF.bit.TXDT = pmsg[i];
    }
  } else {
    for (i = 0; i < (msglen/2); i++) {
      for (j = 0; j<=1; j++) {
        while (ScicRegs.SCIFFTX.bit.TXFFST == 16) {
        }                              /* The buffer is full;*/

        ScicRegs.SCITXBUF.bit.TXDT = pmsg[i]>>(8*j);
      }
    }
  }

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
