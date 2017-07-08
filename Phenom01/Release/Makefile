################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Battery_Message.cpp \
../Debug_Pin.cpp \
../Firing_Mode_Demux.cpp \
../Light_Message.cpp \
../Number_Flasher_Command_Message.cpp \
../Number_Flasher_Status_Message.cpp \
../Pushbutton_Message.cpp \
../Runtime_State_Message.cpp \
../Main.cpp \
../CPP_Dynamic_Memory.cpp \
../CPP_Virtual_Inheritance.cpp \
../Solenoid_Message.cpp \
../Time_Frame_Manager.cpp \
../Trigger_Message.cpp \
../User_Configuration.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Battery_Message.o \
Debug_Pin.o \
Firing_Mode_Demux.o \
Light_Message.o \
Number_Flasher_Command_Message.o \
Number_Flasher_Status_Message.o \
Pushbutton_Message.o \
Runtime_State_Message.o \
Main.o \
CPP_Dynamic_Memory.o \
CPP_Virtual_Inheritance.o \
Solenoid_Message.o \
Time_Frame_Manager.o \
Trigger_Message.o \
User_Configuration.o

OBJS_AS_ARGS +=  \
Battery_Message.o \
Debug_Pin.o \
Firing_Mode_Demux.o \
Light_Message.o \
Number_Flasher_Command_Message.o \
Number_Flasher_Status_Message.o \
Pushbutton_Message.o \
Runtime_State_Message.o \
Main.o \
CPP_Dynamic_Memory.o \
CPP_Virtual_Inheritance.o \
Solenoid_Message.o \
Time_Frame_Manager.o \
Trigger_Message.o \
User_Configuration.o

C_DEPS +=  \
Battery_Message.d \
Debug_Pin.d \
Firing_Mode_Demux.d \
Light_Message.d \
Number_Flasher_Command_Message.d \
Number_Flasher_Status_Message.d \
Pushbutton_Message.d \
Runtime_State_Message.d \
Main.d \
CPP_Dynamic_Memory.d \
CPP_Virtual_Inheritance.d \
Solenoid_Message.d \
Time_Frame_Manager.d \
Trigger_Message.d \
User_Configuration.d

C_DEPS_AS_ARGS +=  \
Battery_Message.d \
Debug_Pin.d \
Firing_Mode_Demux.d \
Light_Message.d \
Number_Flasher_Command_Message.d \
Number_Flasher_Status_Message.d \
Pushbutton_Message.d \
Runtime_State_Message.d \
Main.d \
CPP_Dynamic_Memory.d \
CPP_Virtual_Inheritance.d \
Solenoid_Message.d \
Time_Frame_Manager.d \
Trigger_Message.d \
User_Configuration.d

OUTPUT_FILE_PATH +=Phenom01.elf

OUTPUT_FILE_PATH_AS_ARGS +=Phenom01.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler































./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=attiny44a -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Phenom01.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=attiny44a 
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "Phenom01.elf" "Phenom01.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Phenom01.elf" "Phenom01.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Phenom01.elf" > "Phenom01.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "Phenom01.elf" "Phenom01.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-size.exe" "Phenom01.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Phenom01.elf" "Phenom01.a" "Phenom01.hex" "Phenom01.lss" "Phenom01.eep" "Phenom01.map" "Phenom01.srec"
	