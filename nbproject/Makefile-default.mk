#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuration_bits.p1 ${OBJECTDIR}/interrupts.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/system.p1 ${OBJECTDIR}/user.p1 ${OBJECTDIR}/uart.p1 ${OBJECTDIR}/cirBuff.p1 ${OBJECTDIR}/cliParser.p1 ${OBJECTDIR}/SRAM.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/configuration_bits.p1.d ${OBJECTDIR}/interrupts.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/system.p1.d ${OBJECTDIR}/user.p1.d ${OBJECTDIR}/uart.p1.d ${OBJECTDIR}/cirBuff.p1.d ${OBJECTDIR}/cliParser.p1.d ${OBJECTDIR}/SRAM.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuration_bits.p1 ${OBJECTDIR}/interrupts.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/system.p1 ${OBJECTDIR}/user.p1 ${OBJECTDIR}/uart.p1 ${OBJECTDIR}/cirBuff.p1 ${OBJECTDIR}/cliParser.p1 ${OBJECTDIR}/SRAM.p1


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuration_bits.p1: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/configuration_bits.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/configuration_bits.p1  configuration_bits.c 
	@-${MV} ${OBJECTDIR}/configuration_bits.d ${OBJECTDIR}/configuration_bits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/configuration_bits.p1.d $(SILENT) 
	
${OBJECTDIR}/interrupts.p1: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/interrupts.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/interrupts.p1  interrupts.c 
	@-${MV} ${OBJECTDIR}/interrupts.d ${OBJECTDIR}/interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/interrupts.p1.d $(SILENT) 
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) 
	
${OBJECTDIR}/system.p1: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/system.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/system.p1  system.c 
	@-${MV} ${OBJECTDIR}/system.d ${OBJECTDIR}/system.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/system.p1.d $(SILENT) 
	
${OBJECTDIR}/user.p1: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/user.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/user.p1  user.c 
	@-${MV} ${OBJECTDIR}/user.d ${OBJECTDIR}/user.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/user.p1.d $(SILENT) 
	
${OBJECTDIR}/uart.p1: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/uart.p1  uart.c 
	@-${MV} ${OBJECTDIR}/uart.d ${OBJECTDIR}/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/uart.p1.d $(SILENT) 
	
${OBJECTDIR}/cirBuff.p1: cirBuff.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/cirBuff.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/cirBuff.p1  cirBuff.c 
	@-${MV} ${OBJECTDIR}/cirBuff.d ${OBJECTDIR}/cirBuff.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/cirBuff.p1.d $(SILENT) 
	
${OBJECTDIR}/cliParser.p1: cliParser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/cliParser.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/cliParser.p1  cliParser.c 
	@-${MV} ${OBJECTDIR}/cliParser.d ${OBJECTDIR}/cliParser.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/cliParser.p1.d $(SILENT) 
	
${OBJECTDIR}/SRAM.p1: SRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SRAM.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/SRAM.p1  SRAM.c 
	@-${MV} ${OBJECTDIR}/SRAM.d ${OBJECTDIR}/SRAM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SRAM.p1.d $(SILENT) 
	
else
${OBJECTDIR}/configuration_bits.p1: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/configuration_bits.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/configuration_bits.p1  configuration_bits.c 
	@-${MV} ${OBJECTDIR}/configuration_bits.d ${OBJECTDIR}/configuration_bits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/configuration_bits.p1.d $(SILENT) 
	
${OBJECTDIR}/interrupts.p1: interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/interrupts.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/interrupts.p1  interrupts.c 
	@-${MV} ${OBJECTDIR}/interrupts.d ${OBJECTDIR}/interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/interrupts.p1.d $(SILENT) 
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) 
	
${OBJECTDIR}/system.p1: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/system.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/system.p1  system.c 
	@-${MV} ${OBJECTDIR}/system.d ${OBJECTDIR}/system.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/system.p1.d $(SILENT) 
	
${OBJECTDIR}/user.p1: user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/user.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/user.p1  user.c 
	@-${MV} ${OBJECTDIR}/user.d ${OBJECTDIR}/user.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/user.p1.d $(SILENT) 
	
${OBJECTDIR}/uart.p1: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/uart.p1  uart.c 
	@-${MV} ${OBJECTDIR}/uart.d ${OBJECTDIR}/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/uart.p1.d $(SILENT) 
	
${OBJECTDIR}/cirBuff.p1: cirBuff.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/cirBuff.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/cirBuff.p1  cirBuff.c 
	@-${MV} ${OBJECTDIR}/cirBuff.d ${OBJECTDIR}/cirBuff.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/cirBuff.p1.d $(SILENT) 
	
${OBJECTDIR}/cliParser.p1: cliParser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/cliParser.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/cliParser.p1  cliParser.c 
	@-${MV} ${OBJECTDIR}/cliParser.d ${OBJECTDIR}/cliParser.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/cliParser.p1.d $(SILENT) 
	
${OBJECTDIR}/SRAM.p1: SRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/SRAM.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/SRAM.p1  SRAM.c 
	@-${MV} ${OBJECTDIR}/SRAM.d ${OBJECTDIR}/SRAM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SRAM.p1.d $(SILENT) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G --asmlist -mdist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"   -odist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G --asmlist -mdist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,-speed,+space,-debug,9 --addrqual=ignore --mode=free -N31 -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include" -I"C:\Program Files (x86)\Microchip\xc8\v1.10\include\plib" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,-config,+clib,+plib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"   -odist/${CND_CONF}/${IMAGE_TYPE}/pic18f4550_SRAM_test.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
