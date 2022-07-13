# BLDC-Motor-Controller
12-week UROP supervised by Dr Adria Junyent Ferre which looks at developing a motor controller for a BLDC motor using a TI Delfino F28379D Launchpad and a Boostxl-drv8305.

IMPORTANT:

Check all relevant packages are downloaded. Embedded Coder, Embedded for C2000, Simulink Coder toolboxes are required for Simulink.
CCStudio, controlSUITE are required 3rd party software.

Initial Tests with Boards:
- LED Blink Test works (Digital Out). GPIO for 3 In-Built LED is from Datasheet.
- ADC (Analog In) tested individually using AnalogIn Pin:ADCINA5. Data output from Simulink block is in range 0 to 4095.
