#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
LINKER_FILE = -T msp432p401r.lds
CPU = cortext-m4
ARCH = cpu=cortex-m4 \
	   thumb \
       arch=armv7e-m \
       float-abi=hard \
       fpu=fpv4-sp-d16 \
       
SPECS = nosys.specs

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
else
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
	SIZE =size




# Architectures Specific Flags



# Compiler Flags and Defines

#linker flags 
LDFLAGS = 
#c programming flags for gcc
CFLAGS = 
#c preprocessor flags
CPPFLAGs = 

