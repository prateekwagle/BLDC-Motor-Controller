# BLDC-Motor-Controller
Year 2 UROP conducted by Prateek Wagle and supervised by Dr Adrià Junyent-Ferré which looks at developing a motor controller for a BLDC motor using a TI Delfino F28379D Launchpad and a Boostxl-drv8305. The entire design was implemented using MATLAB Simulink exclusively, with relevant coders needed to programme the evaluation board.

IMPORTANT:

Check all relevant packages are downloaded. Embedded Coder, Embedded for C2000, Simulink Coder toolboxes are required for Simulink.
CCStudio, controlSUITE are required 3rd party software.

Description of Files:

Initial Tests with Boards:
- LED Blink Test works (Digital Out). GPIO for 3 In-Built LED is from Datasheet.
- ADC (Analog In) tested individually using AnalogIn Pin:ADCINA5. Data output from Simulink block is in range 0 to 4095.

Serial Communication:
- Using the Instrumentation Toolbox, Serial Output from the Launchpad was read from the PC. SCI_A has to be used (connected to FTDI), with a fixed baud rate (tested with 5e6).

Serial with Encoder:
- A Protocol Encoder and Decoder module was used to streamline sending multiple data at once via Serial. Works as intended.

Manual PWM with ADC:
- V and I sense working with PWM controlled manually using sliders.
