#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=clock/rtcc.c clock/setttingsRtcc.c clock/ds1307.c clock/drvI2C.c Draw/DrawGraphics.c Draw/DrawText.c Draw/DrawMenuRoot.c Draw/DrawIcon.c Draw/DrawLogo.c Draw/DrawClock.c Draw/DrawConfigWifi.c drivers/tsc2046.c drivers/spiTsc2046.c drivers/esp8266.c drivers/SST25VF016.c fonts/century_size12.c Graphics/Ssd1963.c main.c Uart.c inits.c run.c TimeDelay.c interrupts.c GlobalVar.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/clock/rtcc.o ${OBJECTDIR}/clock/setttingsRtcc.o ${OBJECTDIR}/clock/ds1307.o ${OBJECTDIR}/clock/drvI2C.o ${OBJECTDIR}/Draw/DrawGraphics.o ${OBJECTDIR}/Draw/DrawText.o ${OBJECTDIR}/Draw/DrawMenuRoot.o ${OBJECTDIR}/Draw/DrawIcon.o ${OBJECTDIR}/Draw/DrawLogo.o ${OBJECTDIR}/Draw/DrawClock.o ${OBJECTDIR}/Draw/DrawConfigWifi.o ${OBJECTDIR}/drivers/tsc2046.o ${OBJECTDIR}/drivers/spiTsc2046.o ${OBJECTDIR}/drivers/esp8266.o ${OBJECTDIR}/drivers/SST25VF016.o ${OBJECTDIR}/fonts/century_size12.o ${OBJECTDIR}/Graphics/Ssd1963.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Uart.o ${OBJECTDIR}/inits.o ${OBJECTDIR}/run.o ${OBJECTDIR}/TimeDelay.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/GlobalVar.o
POSSIBLE_DEPFILES=${OBJECTDIR}/clock/rtcc.o.d ${OBJECTDIR}/clock/setttingsRtcc.o.d ${OBJECTDIR}/clock/ds1307.o.d ${OBJECTDIR}/clock/drvI2C.o.d ${OBJECTDIR}/Draw/DrawGraphics.o.d ${OBJECTDIR}/Draw/DrawText.o.d ${OBJECTDIR}/Draw/DrawMenuRoot.o.d ${OBJECTDIR}/Draw/DrawIcon.o.d ${OBJECTDIR}/Draw/DrawLogo.o.d ${OBJECTDIR}/Draw/DrawClock.o.d ${OBJECTDIR}/Draw/DrawConfigWifi.o.d ${OBJECTDIR}/drivers/tsc2046.o.d ${OBJECTDIR}/drivers/spiTsc2046.o.d ${OBJECTDIR}/drivers/esp8266.o.d ${OBJECTDIR}/drivers/SST25VF016.o.d ${OBJECTDIR}/fonts/century_size12.o.d ${OBJECTDIR}/Graphics/Ssd1963.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/Uart.o.d ${OBJECTDIR}/inits.o.d ${OBJECTDIR}/run.o.d ${OBJECTDIR}/TimeDelay.o.d ${OBJECTDIR}/interrupts.o.d ${OBJECTDIR}/GlobalVar.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/clock/rtcc.o ${OBJECTDIR}/clock/setttingsRtcc.o ${OBJECTDIR}/clock/ds1307.o ${OBJECTDIR}/clock/drvI2C.o ${OBJECTDIR}/Draw/DrawGraphics.o ${OBJECTDIR}/Draw/DrawText.o ${OBJECTDIR}/Draw/DrawMenuRoot.o ${OBJECTDIR}/Draw/DrawIcon.o ${OBJECTDIR}/Draw/DrawLogo.o ${OBJECTDIR}/Draw/DrawClock.o ${OBJECTDIR}/Draw/DrawConfigWifi.o ${OBJECTDIR}/drivers/tsc2046.o ${OBJECTDIR}/drivers/spiTsc2046.o ${OBJECTDIR}/drivers/esp8266.o ${OBJECTDIR}/drivers/SST25VF016.o ${OBJECTDIR}/fonts/century_size12.o ${OBJECTDIR}/Graphics/Ssd1963.o ${OBJECTDIR}/main.o ${OBJECTDIR}/Uart.o ${OBJECTDIR}/inits.o ${OBJECTDIR}/run.o ${OBJECTDIR}/TimeDelay.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/GlobalVar.o

# Source Files
SOURCEFILES=clock/rtcc.c clock/setttingsRtcc.c clock/ds1307.c clock/drvI2C.c Draw/DrawGraphics.c Draw/DrawText.c Draw/DrawMenuRoot.c Draw/DrawIcon.c Draw/DrawLogo.c Draw/DrawClock.c Draw/DrawConfigWifi.c drivers/tsc2046.c drivers/spiTsc2046.c drivers/esp8266.c drivers/SST25VF016.c fonts/century_size12.c Graphics/Ssd1963.c main.c Uart.c inits.c run.c TimeDelay.c interrupts.c GlobalVar.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX360F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/clock/rtcc.o: clock/rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/rtcc.o.d 
	@${RM} ${OBJECTDIR}/clock/rtcc.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/rtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/rtcc.o.d" -o ${OBJECTDIR}/clock/rtcc.o clock/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/clock/setttingsRtcc.o: clock/setttingsRtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/setttingsRtcc.o.d 
	@${RM} ${OBJECTDIR}/clock/setttingsRtcc.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/setttingsRtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/setttingsRtcc.o.d" -o ${OBJECTDIR}/clock/setttingsRtcc.o clock/setttingsRtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/clock/ds1307.o: clock/ds1307.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/ds1307.o.d 
	@${RM} ${OBJECTDIR}/clock/ds1307.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/ds1307.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/ds1307.o.d" -o ${OBJECTDIR}/clock/ds1307.o clock/ds1307.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/clock/drvI2C.o: clock/drvI2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/drvI2C.o.d 
	@${RM} ${OBJECTDIR}/clock/drvI2C.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/drvI2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/drvI2C.o.d" -o ${OBJECTDIR}/clock/drvI2C.o clock/drvI2C.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawGraphics.o: Draw/DrawGraphics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawGraphics.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawGraphics.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawGraphics.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawGraphics.o.d" -o ${OBJECTDIR}/Draw/DrawGraphics.o Draw/DrawGraphics.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawText.o: Draw/DrawText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawText.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawText.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawText.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawText.o.d" -o ${OBJECTDIR}/Draw/DrawText.o Draw/DrawText.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawMenuRoot.o: Draw/DrawMenuRoot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawMenuRoot.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawMenuRoot.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawMenuRoot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawMenuRoot.o.d" -o ${OBJECTDIR}/Draw/DrawMenuRoot.o Draw/DrawMenuRoot.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawIcon.o: Draw/DrawIcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawIcon.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawIcon.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawIcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawIcon.o.d" -o ${OBJECTDIR}/Draw/DrawIcon.o Draw/DrawIcon.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawLogo.o: Draw/DrawLogo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawLogo.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawLogo.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawLogo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawLogo.o.d" -o ${OBJECTDIR}/Draw/DrawLogo.o Draw/DrawLogo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawClock.o: Draw/DrawClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawClock.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawClock.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawClock.o.d" -o ${OBJECTDIR}/Draw/DrawClock.o Draw/DrawClock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawConfigWifi.o: Draw/DrawConfigWifi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawConfigWifi.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawConfigWifi.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawConfigWifi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawConfigWifi.o.d" -o ${OBJECTDIR}/Draw/DrawConfigWifi.o Draw/DrawConfigWifi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/tsc2046.o: drivers/tsc2046.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/tsc2046.o.d 
	@${RM} ${OBJECTDIR}/drivers/tsc2046.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/tsc2046.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/tsc2046.o.d" -o ${OBJECTDIR}/drivers/tsc2046.o drivers/tsc2046.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/spiTsc2046.o: drivers/spiTsc2046.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/spiTsc2046.o.d 
	@${RM} ${OBJECTDIR}/drivers/spiTsc2046.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/spiTsc2046.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/spiTsc2046.o.d" -o ${OBJECTDIR}/drivers/spiTsc2046.o drivers/spiTsc2046.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/esp8266.o: drivers/esp8266.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/esp8266.o.d 
	@${RM} ${OBJECTDIR}/drivers/esp8266.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/esp8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/esp8266.o.d" -o ${OBJECTDIR}/drivers/esp8266.o drivers/esp8266.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/SST25VF016.o: drivers/SST25VF016.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/SST25VF016.o.d 
	@${RM} ${OBJECTDIR}/drivers/SST25VF016.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/SST25VF016.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/SST25VF016.o.d" -o ${OBJECTDIR}/drivers/SST25VF016.o drivers/SST25VF016.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/fonts/century_size12.o: fonts/century_size12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/fonts" 
	@${RM} ${OBJECTDIR}/fonts/century_size12.o.d 
	@${RM} ${OBJECTDIR}/fonts/century_size12.o 
	@${FIXDEPS} "${OBJECTDIR}/fonts/century_size12.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fonts/century_size12.o.d" -o ${OBJECTDIR}/fonts/century_size12.o fonts/century_size12.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Graphics/Ssd1963.o: Graphics/Ssd1963.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Graphics" 
	@${RM} ${OBJECTDIR}/Graphics/Ssd1963.o.d 
	@${RM} ${OBJECTDIR}/Graphics/Ssd1963.o 
	@${FIXDEPS} "${OBJECTDIR}/Graphics/Ssd1963.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Graphics/Ssd1963.o.d" -o ${OBJECTDIR}/Graphics/Ssd1963.o Graphics/Ssd1963.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Uart.o: Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Uart.o.d 
	@${RM} ${OBJECTDIR}/Uart.o 
	@${FIXDEPS} "${OBJECTDIR}/Uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Uart.o.d" -o ${OBJECTDIR}/Uart.o Uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/inits.o: inits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/inits.o.d 
	@${RM} ${OBJECTDIR}/inits.o 
	@${FIXDEPS} "${OBJECTDIR}/inits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/inits.o.d" -o ${OBJECTDIR}/inits.o inits.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/run.o: run.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run.o.d 
	@${RM} ${OBJECTDIR}/run.o 
	@${FIXDEPS} "${OBJECTDIR}/run.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run.o.d" -o ${OBJECTDIR}/run.o run.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/TimeDelay.o: TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimeDelay.o.d" -o ${OBJECTDIR}/TimeDelay.o TimeDelay.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/GlobalVar.o: GlobalVar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GlobalVar.o.d 
	@${RM} ${OBJECTDIR}/GlobalVar.o 
	@${FIXDEPS} "${OBJECTDIR}/GlobalVar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/GlobalVar.o.d" -o ${OBJECTDIR}/GlobalVar.o GlobalVar.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/clock/rtcc.o: clock/rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/rtcc.o.d 
	@${RM} ${OBJECTDIR}/clock/rtcc.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/rtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/rtcc.o.d" -o ${OBJECTDIR}/clock/rtcc.o clock/rtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/clock/setttingsRtcc.o: clock/setttingsRtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/setttingsRtcc.o.d 
	@${RM} ${OBJECTDIR}/clock/setttingsRtcc.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/setttingsRtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/setttingsRtcc.o.d" -o ${OBJECTDIR}/clock/setttingsRtcc.o clock/setttingsRtcc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/clock/ds1307.o: clock/ds1307.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/ds1307.o.d 
	@${RM} ${OBJECTDIR}/clock/ds1307.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/ds1307.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/ds1307.o.d" -o ${OBJECTDIR}/clock/ds1307.o clock/ds1307.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/clock/drvI2C.o: clock/drvI2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/clock" 
	@${RM} ${OBJECTDIR}/clock/drvI2C.o.d 
	@${RM} ${OBJECTDIR}/clock/drvI2C.o 
	@${FIXDEPS} "${OBJECTDIR}/clock/drvI2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/clock/drvI2C.o.d" -o ${OBJECTDIR}/clock/drvI2C.o clock/drvI2C.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawGraphics.o: Draw/DrawGraphics.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawGraphics.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawGraphics.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawGraphics.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawGraphics.o.d" -o ${OBJECTDIR}/Draw/DrawGraphics.o Draw/DrawGraphics.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawText.o: Draw/DrawText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawText.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawText.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawText.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawText.o.d" -o ${OBJECTDIR}/Draw/DrawText.o Draw/DrawText.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawMenuRoot.o: Draw/DrawMenuRoot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawMenuRoot.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawMenuRoot.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawMenuRoot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawMenuRoot.o.d" -o ${OBJECTDIR}/Draw/DrawMenuRoot.o Draw/DrawMenuRoot.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawIcon.o: Draw/DrawIcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawIcon.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawIcon.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawIcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawIcon.o.d" -o ${OBJECTDIR}/Draw/DrawIcon.o Draw/DrawIcon.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawLogo.o: Draw/DrawLogo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawLogo.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawLogo.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawLogo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawLogo.o.d" -o ${OBJECTDIR}/Draw/DrawLogo.o Draw/DrawLogo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawClock.o: Draw/DrawClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawClock.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawClock.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawClock.o.d" -o ${OBJECTDIR}/Draw/DrawClock.o Draw/DrawClock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Draw/DrawConfigWifi.o: Draw/DrawConfigWifi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Draw" 
	@${RM} ${OBJECTDIR}/Draw/DrawConfigWifi.o.d 
	@${RM} ${OBJECTDIR}/Draw/DrawConfigWifi.o 
	@${FIXDEPS} "${OBJECTDIR}/Draw/DrawConfigWifi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Draw/DrawConfigWifi.o.d" -o ${OBJECTDIR}/Draw/DrawConfigWifi.o Draw/DrawConfigWifi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/tsc2046.o: drivers/tsc2046.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/tsc2046.o.d 
	@${RM} ${OBJECTDIR}/drivers/tsc2046.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/tsc2046.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/tsc2046.o.d" -o ${OBJECTDIR}/drivers/tsc2046.o drivers/tsc2046.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/spiTsc2046.o: drivers/spiTsc2046.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/spiTsc2046.o.d 
	@${RM} ${OBJECTDIR}/drivers/spiTsc2046.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/spiTsc2046.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/spiTsc2046.o.d" -o ${OBJECTDIR}/drivers/spiTsc2046.o drivers/spiTsc2046.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/esp8266.o: drivers/esp8266.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/esp8266.o.d 
	@${RM} ${OBJECTDIR}/drivers/esp8266.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/esp8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/esp8266.o.d" -o ${OBJECTDIR}/drivers/esp8266.o drivers/esp8266.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/SST25VF016.o: drivers/SST25VF016.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers" 
	@${RM} ${OBJECTDIR}/drivers/SST25VF016.o.d 
	@${RM} ${OBJECTDIR}/drivers/SST25VF016.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/SST25VF016.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/drivers/SST25VF016.o.d" -o ${OBJECTDIR}/drivers/SST25VF016.o drivers/SST25VF016.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/fonts/century_size12.o: fonts/century_size12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/fonts" 
	@${RM} ${OBJECTDIR}/fonts/century_size12.o.d 
	@${RM} ${OBJECTDIR}/fonts/century_size12.o 
	@${FIXDEPS} "${OBJECTDIR}/fonts/century_size12.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fonts/century_size12.o.d" -o ${OBJECTDIR}/fonts/century_size12.o fonts/century_size12.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Graphics/Ssd1963.o: Graphics/Ssd1963.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Graphics" 
	@${RM} ${OBJECTDIR}/Graphics/Ssd1963.o.d 
	@${RM} ${OBJECTDIR}/Graphics/Ssd1963.o 
	@${FIXDEPS} "${OBJECTDIR}/Graphics/Ssd1963.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Graphics/Ssd1963.o.d" -o ${OBJECTDIR}/Graphics/Ssd1963.o Graphics/Ssd1963.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Uart.o: Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Uart.o.d 
	@${RM} ${OBJECTDIR}/Uart.o 
	@${FIXDEPS} "${OBJECTDIR}/Uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Uart.o.d" -o ${OBJECTDIR}/Uart.o Uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/inits.o: inits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/inits.o.d 
	@${RM} ${OBJECTDIR}/inits.o 
	@${FIXDEPS} "${OBJECTDIR}/inits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/inits.o.d" -o ${OBJECTDIR}/inits.o inits.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/run.o: run.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/run.o.d 
	@${RM} ${OBJECTDIR}/run.o 
	@${FIXDEPS} "${OBJECTDIR}/run.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/run.o.d" -o ${OBJECTDIR}/run.o run.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/TimeDelay.o: TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimeDelay.o.d" -o ${OBJECTDIR}/TimeDelay.o TimeDelay.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/interrupts.o: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/interrupts.o.d" -o ${OBJECTDIR}/interrupts.o interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/GlobalVar.o: GlobalVar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GlobalVar.o.d 
	@${RM} ${OBJECTDIR}/GlobalVar.o 
	@${FIXDEPS} "${OBJECTDIR}/GlobalVar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/GlobalVar.o.d" -o ${OBJECTDIR}/GlobalVar.o GlobalVar.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MMPIC32.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
