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
ifeq "$(wildcard nbproject/Makefile-local-ATmega16A.mk)" "nbproject/Makefile-local-ATmega16A.mk"
include nbproject/Makefile-local-ATmega16A.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=ATmega16A
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/app.c src/userSystem.c src/configuration.c src/network.c src/DisplayQueue.c src/Requests.c src/PowerOn.c src/userSystem2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/app.o ${OBJECTDIR}/src/userSystem.o ${OBJECTDIR}/src/configuration.o ${OBJECTDIR}/src/network.o ${OBJECTDIR}/src/DisplayQueue.o ${OBJECTDIR}/src/Requests.o ${OBJECTDIR}/src/PowerOn.o ${OBJECTDIR}/src/userSystem2.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/app.o.d ${OBJECTDIR}/src/userSystem.o.d ${OBJECTDIR}/src/configuration.o.d ${OBJECTDIR}/src/network.o.d ${OBJECTDIR}/src/DisplayQueue.o.d ${OBJECTDIR}/src/Requests.o.d ${OBJECTDIR}/src/PowerOn.o.d ${OBJECTDIR}/src/userSystem2.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/app.o ${OBJECTDIR}/src/userSystem.o ${OBJECTDIR}/src/configuration.o ${OBJECTDIR}/src/network.o ${OBJECTDIR}/src/DisplayQueue.o ${OBJECTDIR}/src/Requests.o ${OBJECTDIR}/src/PowerOn.o ${OBJECTDIR}/src/userSystem2.o

# Source Files
SOURCEFILES=src/app.c src/userSystem.c src/configuration.c src/network.c src/DisplayQueue.c src/Requests.c src/PowerOn.c src/userSystem2.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega16a"



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
	${MAKE}  -f nbproject/Makefile-ATmega16A.mk ${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega16A
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
${OBJECTDIR}/src/app.o: src/app.c  .generated_files/flags/ATmega16A/41fb4d8186c4d8fc17d76084c3950181287cb263 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/app.o.d 
	@${RM} ${OBJECTDIR}/src/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/app.o.d" -MT "${OBJECTDIR}/src/app.o.d" -MT ${OBJECTDIR}/src/app.o  -o ${OBJECTDIR}/src/app.o src/app.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem.o: src/userSystem.c  .generated_files/flags/ATmega16A/97ceea608fce2358aa11b0d75ea70a97fd99816b .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/userSystem.o.d" -MT "${OBJECTDIR}/src/userSystem.o.d" -MT ${OBJECTDIR}/src/userSystem.o  -o ${OBJECTDIR}/src/userSystem.o src/userSystem.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration.o: src/configuration.c  .generated_files/flags/ATmega16A/dc84aa8b5e01351ed2747eef4c9a2271ccef3c91 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration.o.d 
	@${RM} ${OBJECTDIR}/src/configuration.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/configuration.o.d" -MT "${OBJECTDIR}/src/configuration.o.d" -MT ${OBJECTDIR}/src/configuration.o  -o ${OBJECTDIR}/src/configuration.o src/configuration.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/network.o: src/network.c  .generated_files/flags/ATmega16A/efe84b06fa7cb77d553a38ad18b3f06091c86848 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/network.o.d 
	@${RM} ${OBJECTDIR}/src/network.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/network.o.d" -MT "${OBJECTDIR}/src/network.o.d" -MT ${OBJECTDIR}/src/network.o  -o ${OBJECTDIR}/src/network.o src/network.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/DisplayQueue.o: src/DisplayQueue.c  .generated_files/flags/ATmega16A/7090f8c0f852d0f1736b1064f82f604b07c610c2 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/DisplayQueue.o.d 
	@${RM} ${OBJECTDIR}/src/DisplayQueue.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/DisplayQueue.o.d" -MT "${OBJECTDIR}/src/DisplayQueue.o.d" -MT ${OBJECTDIR}/src/DisplayQueue.o  -o ${OBJECTDIR}/src/DisplayQueue.o src/DisplayQueue.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Requests.o: src/Requests.c  .generated_files/flags/ATmega16A/ff5372518859c2f737709f359414df52717f5c50 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Requests.o.d 
	@${RM} ${OBJECTDIR}/src/Requests.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/Requests.o.d" -MT "${OBJECTDIR}/src/Requests.o.d" -MT ${OBJECTDIR}/src/Requests.o  -o ${OBJECTDIR}/src/Requests.o src/Requests.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PowerOn.o: src/PowerOn.c  .generated_files/flags/ATmega16A/37aaab2adfee3eb88559292aa1f2ccdfe99abdd3 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PowerOn.o.d 
	@${RM} ${OBJECTDIR}/src/PowerOn.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/PowerOn.o.d" -MT "${OBJECTDIR}/src/PowerOn.o.d" -MT ${OBJECTDIR}/src/PowerOn.o  -o ${OBJECTDIR}/src/PowerOn.o src/PowerOn.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem2.o: src/userSystem2.c  .generated_files/flags/ATmega16A/9e9cf2f332994efd2e945d05477b69fdee6b7237 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem2.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem2.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/userSystem2.o.d" -MT "${OBJECTDIR}/src/userSystem2.o.d" -MT ${OBJECTDIR}/src/userSystem2.o  -o ${OBJECTDIR}/src/userSystem2.o src/userSystem2.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/src/app.o: src/app.c  .generated_files/flags/ATmega16A/b147b167434533ffdc959f6edc8d5ed8d9ce86b3 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/app.o.d 
	@${RM} ${OBJECTDIR}/src/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/app.o.d" -MT "${OBJECTDIR}/src/app.o.d" -MT ${OBJECTDIR}/src/app.o  -o ${OBJECTDIR}/src/app.o src/app.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem.o: src/userSystem.c  .generated_files/flags/ATmega16A/ed2777bb1d28509fb1d92dc5f3749bfb817a8a7 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/userSystem.o.d" -MT "${OBJECTDIR}/src/userSystem.o.d" -MT ${OBJECTDIR}/src/userSystem.o  -o ${OBJECTDIR}/src/userSystem.o src/userSystem.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/configuration.o: src/configuration.c  .generated_files/flags/ATmega16A/550cc64ae7e1aff9029dedd6d611e369118a5b6a .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration.o.d 
	@${RM} ${OBJECTDIR}/src/configuration.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/configuration.o.d" -MT "${OBJECTDIR}/src/configuration.o.d" -MT ${OBJECTDIR}/src/configuration.o  -o ${OBJECTDIR}/src/configuration.o src/configuration.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/network.o: src/network.c  .generated_files/flags/ATmega16A/b7045113214fe1a2a90e59cd21b7005132fc453d .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/network.o.d 
	@${RM} ${OBJECTDIR}/src/network.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/network.o.d" -MT "${OBJECTDIR}/src/network.o.d" -MT ${OBJECTDIR}/src/network.o  -o ${OBJECTDIR}/src/network.o src/network.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/DisplayQueue.o: src/DisplayQueue.c  .generated_files/flags/ATmega16A/6197ec20e5ad43eef51fef9f6c920f17e4928efc .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/DisplayQueue.o.d 
	@${RM} ${OBJECTDIR}/src/DisplayQueue.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/DisplayQueue.o.d" -MT "${OBJECTDIR}/src/DisplayQueue.o.d" -MT ${OBJECTDIR}/src/DisplayQueue.o  -o ${OBJECTDIR}/src/DisplayQueue.o src/DisplayQueue.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/Requests.o: src/Requests.c  .generated_files/flags/ATmega16A/b8d72c3526a6cc833a8c3767a2155480aa08538e .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Requests.o.d 
	@${RM} ${OBJECTDIR}/src/Requests.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/Requests.o.d" -MT "${OBJECTDIR}/src/Requests.o.d" -MT ${OBJECTDIR}/src/Requests.o  -o ${OBJECTDIR}/src/Requests.o src/Requests.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/PowerOn.o: src/PowerOn.c  .generated_files/flags/ATmega16A/87aeb35af87043b57575a4a0abad7d406d5fbe1b .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/PowerOn.o.d 
	@${RM} ${OBJECTDIR}/src/PowerOn.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/PowerOn.o.d" -MT "${OBJECTDIR}/src/PowerOn.o.d" -MT ${OBJECTDIR}/src/PowerOn.o  -o ${OBJECTDIR}/src/PowerOn.o src/PowerOn.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/src/userSystem2.o: src/userSystem2.c  .generated_files/flags/ATmega16A/915653caa8f4a7e4c58ee8bfb0f4aad33894c2f5 .generated_files/flags/ATmega16A/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/userSystem2.o.d 
	@${RM} ${OBJECTDIR}/src/userSystem2.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega16a ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mshort-calls -Wall -Wundef -MD -MP -MF "${OBJECTDIR}/src/userSystem2.o.d" -MT "${OBJECTDIR}/src/userSystem2.o.d" -MT ${OBJECTDIR}/src/userSystem2.o  -o ${OBJECTDIR}/src/userSystem2.o src/userSystem2.c  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/mega2.X.a  
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega16a ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\NurseRoom.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    lib\mega2.X.a  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  lib/mega2.X.a 
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega16a ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\NurseRoom.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    lib\mega2.X.a  -DXPRJ_ATmega16A=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/NurseRoom.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
