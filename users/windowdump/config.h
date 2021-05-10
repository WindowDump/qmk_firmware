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

#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 5
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 10
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 10

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