#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "svpwm.h"
#include "svpwm_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;  /* Configure GPIOGPIO0 as EPWM1A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;  /* Configure GPIOGPIO1 as EPWM1B*/

  /*-- Configure pin assignments for ePWM2 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;  /* Configure GPIOGPIO2 as EPWM2A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;  /* Configure GPIOGPIO3 as EPWM2B*/

  /*-- Configure pin assignments for ePWM3 --*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;  /* Configure GPIOGPIO4 as EPWM3A*/
  GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;  /* Configure GPIOGPIO5 as EPWM3B*/

  /*--- Configure pin assignments for TZn ---*/
  EDIS;
}
