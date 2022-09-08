#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "integrating_svpwm.h"
#include "integrating_svpwm_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1;

  /*-- Configure pin assignments for ePWM4 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;  /* Configure GPIOGPIO6 as EPWM4A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;  /* Configure GPIOGPIO7 as EPWM4B*/

  /*-- Configure pin assignments for ePWM5 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;  /* Configure GPIOGPIO8 as EPWM5A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO9 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;  /* Configure GPIOGPIO9 as EPWM5B*/

  /*-- Configure pin assignments for ePWM6 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO10 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1; /* Configure GPIOGPIO10 as EPWM6A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO11 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1; /* Configure GPIOGPIO11 as EPWM6B*/
  EDIS;
}
