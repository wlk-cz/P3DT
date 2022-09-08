#ifndef USERPINS_H
#define USERPINS_H

/****************************************************************************************
* AX
*
****************************************************************************************/

#ifndef __AVR_ATmega1281__
#error Oops! Make sure you have correct processor selected.
#endif

#define LARGE_FLASH true

#define ORIG_X_STEP_PIN 38
#define ORIG_X_DIR_PIN 17
#define ORIG_X_ENABLE_PIN 30
#define ORIG_X_MIN_PIN 25
//2 //Max endstops default to disabled "-1", set to commented value to enable.
#define ORIG_X_MAX_PIN -1
#define ORIG_X_HALF_PIN 22

#define ORIG_Y_STEP_PIN 39
#define ORIG_Y_DIR_PIN 18
#define ORIG_Y_ENABLE_PIN 31
#define ORIG_Y_MIN_PIN 26
#define ORIG_Y_MAX_PIN -1
#define ORIG_Y_HALF_PIN 23

#define ORIG_Z_STEP_PIN 40
#define ORIG_Z_DIR_PIN 13
#define ORIG_Z_ENABLE_PIN 32
#define ORIG_Z_MIN_PIN 27
#define ORIG_Z_MAX_PIN -1
#define ORIG_Z_HALF_PIN 24

#define ORIG_E0_STEP_PIN 41
#define ORIG_E0_DIR_PIN 9
#define ORIG_E0_ENABLE_PIN 33

#define ORIG_E1_STEP_PIN 42
#define ORIG_E1_DIR_PIN 21
#define ORIG_E1_ENABLE_PIN 34

#define ORIG_E2_STEP_PIN -1
#define ORIG_E2_DIR_PIN -1
#define ORIG_E2_ENABLE_PIN -1

#define ORIG_E__HALF_PIN 35

#define SDPOWER -1
#define SDSS 45
#define SDEN 44
#define SCK_PIN 10
#define MISO_PIN 12
#define MOSI_PIN 11
#define LED_PIN -1

#define ORIG_FAN_PIN 7
#define ORIG_FAN2_PIN 8
#define ORIG_PS_ON_PIN -1
#define KILL_PIN -1

// EXTRUDER 1
#define HEATER_0_PIN 2
// BED
#define HEATER_1_PIN 5
// EXTRUDER 2
#define HEATER_2_PIN 3
#define HEATER_3_PIN -1

#define AUX0_PIN 6
#define AUX1_PIN 14
#define AUX2_PIN 15
#define AUX3_PIN 16

// ANALOG NUMBERING
#define TEMP_0_PIN 0
// BED SENSOR ANALOG NUMBERING
#define TEMP_1_PIN 2
// ANALOG NUMBERING
#define TEMP_2_PIN 1
// ANALOG NUMBERING
#define TEMP_3_PIN 3

#define BEEPER_PIN -1

#define ORIG_SDCARDDETECT -1 // Megatronics does not use this port
#define E0_PINS ORIG_E0_STEP_PIN,ORIG_E0_DIR_PIN,ORIG_E0_ENABLE_PIN,
#define E1_PINS ORIG_E1_STEP_PIN,ORIG_E1_DIR_PIN,ORIG_E1_ENABLE_PIN,
#define E2_PINS

#endif
