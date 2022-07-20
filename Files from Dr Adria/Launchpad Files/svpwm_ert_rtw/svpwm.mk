###########################################################################
## Makefile generated for component 'svpwm'. 
## 
## Makefile     : svpwm.mk
## Generated on : Thu May 19 15:38:29 2022
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/svpwm.out
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = svpwm
MAKEFILE                  = svpwm.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/adria/Desktop/motor_driver
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = TI C28x
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Texas Instruments Code Composer Studio (C2000)
# Supported Version(s):    
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# CCSINSTALLDIR
# CCSSCRIPTINGDIR
# TARGET_LOAD_CMD_ARGS
# TIF28XXXSYSSWDIR

#-----------
# MACROS
#-----------

TARGET_SCRIPTINGTOOLS_INSTALLDIR = $(CCSSCRIPTINGDIR)
TI_TOOLS                         = $(CCSINSTALLDIR)/bin
TI_INCLUDE                       = $(CCSINSTALLDIR)/include
TI_LIB                           = $(CCSINSTALLDIR)/lib
F28_HEADERS                      = $(TIF28XXXSYSSWDIR)/~SupportFiles/DSP280x_headers
CCOUTPUTFLAG                     = --output_file=
LDOUTPUTFLAG                     = --output_file=
EXE_FILE_EXT                     = $(PROGRAM_FILE_EXT)
PRODUCT_HEX                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
DOWN_EXE_JS                      = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/runProgram_generic.js
CCS_CONFIG                       = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/f28x_generic.ccxml
SHELL                            = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: C2000 Assembler
AS_PATH = $(TI_TOOLS)
AS = "$(AS_PATH)/cl2000"

# C Compiler: C2000 C Compiler
CC_PATH = $(TI_TOOLS)
CC = "$(CC_PATH)/cl2000"

# Linker: C2000 Linker
LD_PATH = $(TI_TOOLS)
LD = "$(LD_PATH)/cl2000"

# C++ Compiler: C2000 C++ Compiler
CPP_PATH = $(TI_TOOLS)
CPP = "$(CPP_PATH)/cl2000"

# C++ Linker: C2000 C++ Linker
CPP_LD_PATH = $(TI_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/cl2000"

# Archiver: C2000 Archiver
AR_PATH = $(TI_TOOLS)
AR = "$(AR_PATH)/ar2000"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Hex Converter: Hex Converter

# Download: Download
DOWNLOAD_PATH = $(TARGET_SCRIPTINGTOOLS_INSTALLDIR)/bin
DOWNLOAD = "$(DOWNLOAD_PATH)/dss.bat"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = --output_file=
CDEBUG              = -g
C_OUTPUT_FLAG       = --output_file=
LDDEBUG             =
OUTPUT_FLAG         = --output_file=
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = --output_file=
CPPLDDEBUG          =
OUTPUT_FLAG         = --output_file=
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
ASFLAGS              = -s \
                       -v28 \
                       -ml \
                       $(ASFLAGS_ADDITIONAL)
CFLAGS               = --compile_only \
                       --preproc_dependency="$(@:%.obj=%.dep)" --preproc_with_compile  \
                       --large_memory_model \
                       --silicon_version=28 \
                       --define="LARGE_MODEL" \
                       -I"$(F28_HEADERS)" \
                       -I"$(F28_HEADERS)/include" \
                       -I"$(TI_INCLUDE)"
CPPFLAGS             =
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     =  -i "$<" -o "$@" -order MS -romwidth 16 -q
LDFLAGS              = -z -I$(TI_LIB) \
                       --stack_size=$(STACK_SIZE) --warn_sections \
                       --heap_size=$(HEAP_SIZE) \
                       --reread_libs --rom_model \
                       --priority \
                       -m"$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/svpwm.out
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/svpwm_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/tic2000/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/tic2000/inc -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/shared/SUPPOR~1/tic2000/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/shared/SUPPOR~1/tic2000/inc -IC:/ti/CONTRO~1/DEVICE~1/f2802x/v230/F2802X~1/include -IC:/ti/CONTRO~1/DEVICE~1/f2802x/v230/F2802X~4/include -IC:/ti/CONTRO~1/DEVICE~1/f2802x/v230 -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/shared/EXTERN~1/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=0
DEFINES_SKIPFORSIL = -DDAEMON_MODE=1 -DXCP_CUSTOM_PLATFORM -DMW_PIL_SCIFIFOLEN=4 -DSTACK_SIZE=768 -DRT -DF28027 -DBOOT_FROM_FLASH=1
DEFINES_STANDARD = -DMODEL=svpwm -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/svpwm_ert_rtw/MW_c28xx_board.c $(START_DIR)/svpwm_ert_rtw/MW_c28xx_adc.c $(START_DIR)/svpwm_ert_rtw/MW_c28xx_csl.c $(START_DIR)/svpwm_ert_rtw/MW_c28xx_pwm.c $(START_DIR)/svpwm_ert_rtw/rtGetInf.c $(START_DIR)/svpwm_ert_rtw/rtGetNaN.c $(START_DIR)/svpwm_ert_rtw/rt_nonfinite.c $(START_DIR)/svpwm_ert_rtw/svpwm.c $(START_DIR)/svpwm_ert_rtw/svpwm_data.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/c2802xBoard_Realtime_Support.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGlobalInterrupts.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_cputimers.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_defaultisr.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/source/F2802x_GlobalVariableDefs.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_piectrl.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_pievect.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_sysctrl.c C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_usdelay.asm C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_codestartbranch.asm C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_adc.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/profiler_Support.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGPIO.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/c2802xSchedulerTimer0.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/ext_svr_c2000.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/updown_c2000.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/ext_work_c2000.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/rtiostream_utils_c2000.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/rtiostream_interface_c2000.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/rtiostream_serial_c28x_ext.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/datamodify.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/shared/externalmode_daemon/src/daemon_checksum.c

MAIN_SRC = $(START_DIR)/svpwm_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_c28xx_board.obj MW_c28xx_adc.obj MW_c28xx_csl.obj MW_c28xx_pwm.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj svpwm.obj svpwm_data.obj c2802xBoard_Realtime_Support.obj MW_c28xGlobalInterrupts.obj f2802x_cputimers.obj f2802x_defaultisr.obj F2802x_GlobalVariableDefs.obj f2802x_piectrl.obj f2802x_pievect.obj f2802x_sysctrl.obj f2802x_usdelay.obj f2802x_codestartbranch.obj f2802x_adc.obj profiler_Support.obj MW_c28xGPIO.obj c2802xSchedulerTimer0.obj ext_svr_c2000.obj updown_c2000.obj ext_work_c2000.obj rtiostream_utils_c2000.obj rtiostream_interface_c2000.obj rtiostream_serial_c28x_ext.obj datamodify.obj daemon_checksum.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/shared/supportpackages/tic2000/rtlib/IQmath.lib C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/c2802xPeripherals.cmd C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/c28027.cmd

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ =  --define="EXTMODE_DISABLEPRINTF" 
CFLAGS_SKIPFORSIL = -v28 -ml -DF28027 -DBOOT_FROM_FLASH=1
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ =  --define="EXTMODE_DISABLEPRINTF" 
CPPFLAGS_SKIPFORSIL = -v28 -ml -DF28027 -DBOOT_FROM_FLASH=1
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -l"rts2800_ml.lib" --define F28027 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_ml.lib" --define F28027 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -l"rts2800_ml.lib" --define F28027 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_ml.lib" --define F28027 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


all :

ifeq ($(PRODUCT_TYPE),"executable")
postbuild : $(PRODUCT_HEX)

$(PRODUCT_HEX): $(PRODUCT)
	@echo "### Invoking postbuild tool "Hex Converter" on "$<"..."
	$(CCSINSTALLDIR)/bin/hex2000 $(OBJCOPYFLAGS_HEX)
	@echo "### Done Invoking postbuild tool "Hex Converter" ..."

endif

ifeq ($(DEPRULES),1) 
ALL_DEPS:=$(patsubst %.obj,%.dep,$(ALL_OBJS))
all:
else
ALL_DEPS:=
endif




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)


download : postbuild
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) --output_file=$(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/svpwm_ert_rtw/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/svpwm_ert_rtw/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/svpwm_ert_rtw/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/svpwm_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


MW_c28xx_board.obj : $(START_DIR)/svpwm_ert_rtw/MW_c28xx_board.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_adc.obj : $(START_DIR)/svpwm_ert_rtw/MW_c28xx_adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_csl.obj : $(START_DIR)/svpwm_ert_rtw/MW_c28xx_csl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_pwm.obj : $(START_DIR)/svpwm_ert_rtw/MW_c28xx_pwm.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ert_main.obj : $(START_DIR)/svpwm_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtGetInf.obj : $(START_DIR)/svpwm_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtGetNaN.obj : $(START_DIR)/svpwm_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rt_nonfinite.obj : $(START_DIR)/svpwm_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


svpwm.obj : $(START_DIR)/svpwm_ert_rtw/svpwm.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


svpwm_data.obj : $(START_DIR)/svpwm_ert_rtw/svpwm_data.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2802xBoard_Realtime_Support.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/c2802xBoard_Realtime_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGlobalInterrupts.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGlobalInterrupts.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f2802x_cputimers.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_cputimers.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f2802x_defaultisr.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_defaultisr.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2802x_GlobalVariableDefs.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_headers/source/F2802x_GlobalVariableDefs.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f2802x_piectrl.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_piectrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f2802x_pievect.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_pievect.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f2802x_sysctrl.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_sysctrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f2802x_usdelay.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_usdelay.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


f2802x_codestartbranch.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_codestartbranch.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


f2802x_adc.obj : C:/ti/controlSUITE/device_support/f2802x/v230/f2802x_common/source/f2802x_adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


profiler_Support.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/profiler_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGPIO.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGPIO.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2802xSchedulerTimer0.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/c2802xSchedulerTimer0.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ext_svr_c2000.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/ext_svr_c2000.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


updown_c2000.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/updown_c2000.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ext_work_c2000.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/ext_work_c2000.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtiostream_utils_c2000.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/rtiostream_utils_c2000.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtiostream_interface_c2000.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/rtiostream_interface_c2000.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtiostream_serial_c28x_ext.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/rtiostream_serial_c28x_ext.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


datamodify.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/tic2000/src/datamodify.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


daemon_checksum.obj : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/shared/externalmode_daemon/src/daemon_checksum.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


