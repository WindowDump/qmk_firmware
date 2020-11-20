#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define AUTO_SHIFT_SETUP
#define AUTO_SHIFT_TIMEOUT 150

#define USE_SERIAL_PD2

#define TAPPING_TERM 200
#define TAPPING_TOGGLE 3

// Mousekeys

#define MOUSEKEY_DELAY 25
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_MAX_SPEED 4

// Underglow

#undef RGBLED_NUM
#define RGBLED_NUM 12    // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP

#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
