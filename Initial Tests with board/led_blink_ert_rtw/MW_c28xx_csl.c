#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "led_blink.h"
#include "led_blink_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}
