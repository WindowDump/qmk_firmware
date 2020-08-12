/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define AUTO_SHIFT_SETUP
#define AUTO_SHIFT_TIMEOUT 150

#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

#define MOUSEKEY_DELAY 25
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 40

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 4
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// #define ENCODER_RESOLUTION 4
// #define TAP_CODE_DELAY 20
