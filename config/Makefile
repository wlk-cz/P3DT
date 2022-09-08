# simple AVR Makefile
#
# written by michael cousins (http://github.com/mcous)
# released to the public domain

# Makefile
#
# targets:
#   all:    compiles the source code
#   clean:  removes all .hex, .elf, and .o files in the source code and library directories

# parameters (change this stuff accordingly)
# project name
PRJ = Repetier
# avr mcu
MCU = atmega1281
# mcu clock frequency
CLK = 16000000
# program source files (not including external libraries)
SRC = \
  Repetier.cpp \
  BedLeveling.cpp \
  Commands.cpp \
  Communication.cpp \
  Distortion.cpp \
  Drivers.cpp \
  Eeprom.cpp \
  Endstops.cpp \
  Extruder.cpp \
  gcode.cpp \
  HAL.cpp \
  motion.cpp \
  Printer.cpp \
  SDCard.cpp \
  ui.cpp \
  uilang.cpp \
  main.cpp \
  wiring.c \
  wiring_digital.c \
  wiring_analog.c \
  Print.cpp \
  abi.cpp \
  hooks.c \
  HardwareSerial.cpp \
  HardwareSerial0.cpp \
  HardwareSerial1.cpp


#################################################################################################
# \/ stuff nobody needs to worry about until such time that worrying about it is appropriate \/ #
#################################################################################################

# include path
INCLUDE = /usr/share/arduino/hardware/archlinux-arduino/avr/cores/arduino
# c flags
CCFLAGS = -Wall -Os -gdwarf-2 -DF_CPU=$(CLK) -mmcu=$(MCU) -I$(INCLUDE) -ffunction-sections -DSERIAL_RX_BUFFER_SIZE=128
CPFLAGS = -Wall -Os -gdwarf-2 -DF_CPU=$(CLK) -mmcu=$(MCU) -I$(INCLUDE) -ffunction-sections -DSERIAL_RX_BUFFER_SIZE=128
CSFLAGS = -Wa,-gdwarf-2 -x assembler-with-cpp -c -mmcu=$(MCU)
LDFLAGS = -Wl,-gc-sections -mmcu=$(MCU)

# executables
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE    = avr-size --format=avr --mcu=$(MCU)
CC      = avr-gcc
CP      = avr-g++
CS      = avr-gcc
RM      = rm

# generate list of objects
CCFILES   = $(filter %.c, $(SRC))
CPFILES   = $(filter %.cpp, $(SRC))
CSFILES   = $(filter %.s, $(SRC))
OBJ       = $(CCFILES:.c=.o) $(CPFILES:.cpp=.o) $(CSFILES:.s=.o)

# user targets
# compile all files
all: $(PRJ).hex $(PRJ).eep

# generate disassembly files for debugging
disasm: $(PRJ).elf
	$(OBJDUMP) -d $(PRJ).elf

# remove compiled files
clean:
	$(RM) -f *.hex *.eep *.elf *.o

# other targets
# objects from c files
.c.o:
	$(CC) $(CCFLAGS) -c $< -o $@

# objects from c++ files
.cpp.o:
	$(CP) $(CPFLAGS) -c $< -o $@

# objects from preprocessing files
.s.o:
	$(CS) $(CSFLAGS) -c $< -o $@

# elf file
$(PRJ).elf: $(OBJ)
	$(CP) $(LDFLAGS) -o $(PRJ).elf $(OBJ)
	$(SIZE) $(PRJ).elf

# hex file
$(PRJ).hex: $(PRJ).elf
	$(OBJCOPY) -R .eeprom -O ihex $(PRJ).elf $(PRJ).hex

# eeprom file
$(PRJ).eep: $(PRJ).elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $(PRJ).elf $(PRJ).eep
