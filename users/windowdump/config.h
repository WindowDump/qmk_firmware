// copyright 2021 window dump
// licensed under the WTFPL
// use at your own risk

#pragma once

// Use custom magic number so that when switching branches, EEPROM always gets reset
// thanks drashna
#define EECONFIG_MAGIC_NUMBER (uint16_t)0x0479

// Homerow Mods
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#undef  PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// Mousekeys
#define MOUSEKEY_DELAY 25
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_MAX_SPEED 4

// Combos
#ifdef COMBO_ENABLE
#define COMBO_TERM 30
#endif // COMBO_ENABLE

// Ricing
#define USB_POLLING_INTERVAL_MS 2
#define QMK_KEYS_PER_SCAN 4
#define FORCE_NKRO

// RGBLight
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 5
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 10
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 10

// RGB Matrix
// RGB_Matrix settings
#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  // #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
  #define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
  #define RGB_MATRIX_HUE_STEP 8
  #define RGB_MATRIX_SAT_STEP 8
  #define RGB_MATRIX_VAL_STEP 8
  #define RGB_MATRIX_SPD_STEP 10
  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
  /* Disable the animations you don't want/need.  You will need to disable a good number of these
    because they take up a lot of space.  Disable until you can successfully compile your firmware. */
  // #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  // #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define DISABLE_RGB_MATRIX_BREATHING
  // #define DISABLE_RGB_MATRIX_CYCLE_ALL
  // #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  // #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
  // #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
  // #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define DISABLE_RGB_MATRIX_DUAL_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  // #define DISABLE_RGB_MATRIX_RAINDROPS
  #define DISABLE_RGB_MATRIX_JELLYBEN_RAINDROPS
  #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
  #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  // #define DISABLE_RGB_MATRIX_SPLASH
  // #define DISABLE_RGB_MATRIX_MULTISPLASH
  // #define DISABLE_RGB_MATRIX_SOLID_SPLASH
  // #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif //RGB_MATRIX_ENABLE

// thanks drashna
#define TAP_CODE_DELAY 5

#ifdef SPLIT_KEYBOARD
#    define OLED_UPDATE_INTERVAL 60
#else
#    define OLED_UPDATE_INTERVAL 15
#endif

#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

// Hex size reduction options
#ifndef NO_DEBUG
  #define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
  #define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_ONESHOT