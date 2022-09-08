#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "hall_effect_pos_vel_track_enhanced.h"
#include "hall_effect_pos_vel_track_enhanced_private.h"
#include "MW_c28xGPIO.h"

void configureIXbar(void)
{
  /*--- Configuring GPIO set in Input Xbar---*/
  EALLOW;
  InputXbarRegs.INPUT7SELECT = 124;
  InputXbarRegs.INPUT8SELECT = 125;
  InputXbarRegs.INPUT9SELECT = 29;
  EDIS;
}
