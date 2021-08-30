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
CPU = cortex-m4
#thumb is an instruction set 
ARCH = thumb 
       
ifeq ($(PLATFORM), MSP432)
#compile on target system
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
#Linker file has to be added here because in target system we link according to the given linker file
	LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
	SPECS = nosys.specs
	ARMFLAGS = -mcpu=cortex-m4 \
			   -mthumb \
               -march=armv7e-m \
               -mfloat-abi=hard \
               -mfpu=fpv4-sp-d16 
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -DMSP432 --specs=$(SPECS) $(ARMFLAGS)
	
else
	CC = gcc
	LD = ld
#we dont have to add linker file because in this block our code is arch-independent so linker file can be automatic
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
	SIZE =size
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -DHOST

endif

TARGET = c1m2

 
CPPFLAGS = -E
MAIN = main

OBJS = $(SOURCES:.c=.o)

PREPRO = $(SOURCES:.c=.i)

ASMS = $(SOURCES:.c=.asm)

DEPS = $(SOURCES:.c=.d)
 
FILES = *.asm *.i *.o *.d

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out  $(TARGET).asm
$(TARGET).out: $(OBJS) $(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PREPRO) $(ASMS) $(DEPS) $(OBJS)

