#pragma once

#include "config_common.h"

// Tapping settings (homerow mods, etc)
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#undef  PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// Mousekey Settings
#define MOUSEKEY_DELAY 25
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_MAX_SPEED 4

// Ricing
#define USB_POLLING_INTERVAL_MS 2
#define QMK_KEYS_PER_SCAN 4
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 4
