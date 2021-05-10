// born to corne
#include QMK_KEYBOARD_H
#include "windowdump.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// all of the sauce is in users/windowdump

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Basic QWERTY
  [_QWERTY] = LAYOUT_wrapper( \
    KC_ESC,  _________________QWERTY_L1_________________,                    _________________QWERTY_R1_________________, KC_DEL,  \
    MT_CTAB, _________________QWERTY_L2_________________,                    _________________QWERTY_R2_________________, KC_QUOT, \
    KC_LSFT, _________________QWERTY_L3_________________,                    _________________QWERTY_R3_________________, KC_ENT,  \
                                        KC_LALT, KC_LOWR, KC_NMBS,  KC_NVSP, KC_RASE, KC_LGUI \
  ),

  // Homerow Mods for QWERTY
  [_QWERTY_MODS] = LAYOUT_wrapper( \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
    _______, ____________QWERTY_L2_NO_HR_MODS___________,                    ____________QWERTY_R2_NO_HR_MODS___________, _______, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
                                        _______, _______, _______,  _______, _______, _______\
  ),

  // Colemak DHm
  [_COLEMAK] = LAYOUT_wrapper( \
    _______, ______________COLEMAK_MOD_DH_L1____________,                    ______________COLEMAK_MOD_DH_R1____________, _______, \
    _______, ______________COLEMAK_MOD_DH_L2____________,                    ______________COLEMAK_MOD_DH_R2____________, KC_QUOT, \
    _______, ______________COLEMAK_MOD_DH_L3____________,                    ______________COLEMAK_MOD_DH_R3____________, _______, \
                                        _______, _______, _______,  _______, _______, _______\
  ),

  // Homerow mods for Colemak
  [_COLEMAK_MODS] = LAYOUT_wrapper( \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
    _______, ________COLEMAK_MOD_DH_L2_NO_HR_MODS_______,                    ________COLEMAK_MOD_DH_R2_NO_HR_MODS_______, _______, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
                                        _______, _______, _______,  _______, _______, _______\
  ),

  // Hands Down Alt to flex on the Dvorak peasants
  [_HANDSDOWN] = LAYOUT_wrapper( \
    _______, ______________HANDS_DOWN_ALT_L1____________,                    ______________HANDS_DOWN_ALT_R1____________, _______, \
    _______, ______________HANDS_DOWN_ALT_L2____________,                    ______________HANDS_DOWN_ALT_R2____________, KC_SCLN, \
    _______, ______________HANDS_DOWN_ALT_L3____________,                    ______________HANDS_DOWN_ALT_R3____________, _______, \
                                        _______, _______, _______,  _______, _______, _______\
  ),

  // Homerow mods for Hands Down Alt
  [_HANDSDOWN_MODS] = LAYOUT_wrapper( \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
    _______, ________HANDS_DOWN_ALT_L2_NO_HR_MODS_______,                    ________HANDS_DOWN_ALT_R2_NO_HR_MODS_______, _______, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
                                        _______, _______, _______,  _______, _______, _______\
  ),

  // Disable tapping functions and homerow stuff on left side.
  [_GAMER] = LAYOUT_wrapper( \
    KC_TAB,  ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
    KC_LCTL, ____________QWERTY_L2_NO_HR_MODS___________,                    ___________________BLANK___________________, _______, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
                                        _______, KC_GLWR, KC_BSPC,  _______, _______, _______\
  ),

  // I installed a rootkit and all I got was this lousy layer.
  [_GAMER2] = LAYOUT_wrapper( \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, KC_BSPC, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
                                        _______, KC_GLWR, KC_SPC,   _______, _______, _______\
  ),

  // greetz to @ZUN_CODE
  [_TOUHOU] = LAYOUT_wrapper( \
    _______, ___________________BLANK___________________,                    _______, _______, KC_UP,   _______, _______, TG_TOHO, \
    _______, ________________TOUHOU_LEFT________________,                    ________________TOUHOU_RIGHT_______________, KC_LCTL, \
    _______, ___________________BLANK___________________,                    ___________________BLANK___________________, _______, \
                                        _______, _______, KC_X,     KC_X,    KC_Z,    KC_C   \
  ),

  // Extra access to numbers, shifted number symbols, and function keys.
  [_NUMBERS] = LAYOUT_wrapper( \
    _______, _______________SYMBOLS_LEFT________________,                    _______________SYMBOLS_RIGHT_______________, _______, \
    _______, ________________NUMBER_LEFT________________,                    ________________NUMBER_RIGHT_______________, KC_F12,  \
    _______, _________________FUNC_LEFT_________________,                    _________________FUNC_RIGHT________________, KC_F11,  \
                                        _______, _______, V_V_V_V,  _______, _______, _______\
  ),

  // Arrow keys, window switching, tab switching.
  [_NAV] = LAYOUT_wrapper( \
    _______, __________________NAV_L1___________________,                    __________________NAV_R1___________________, _______, \
    _______, __________________NAV_L2___________________,                    __________________NAV_R2___________________, _______, \
    _______, __________________NAV_L3___________________,                    __________________NAV_R3___________________, _______, \
                                        _______, _______, _______,  V_V_V_V, _______, _______\
  ),

  // Gaming lower layer, access to all the number keys and F1-F5 on left half.
  [_GLOWER] = LAYOUT_wrapper( \
    KC_ESC,  ________________NUMBER_RIGHT_______________,                    _________________LOWER_R1__________________, KC_LBRC, \
    _______, ________________NUMBER_LEFT________________,                    _________________LOWER_R2__________________, KC_RBRC, \
    KC_F12,  _________________FUNC_LEFT_________________,                    _________________FUNC_RIGHT________________, KC_F11,  \
                                        _______, V_V_V_V, _______,  _______, KC_ADJS, _______\
  ),

  // One-handed arrow keys and symbols
  [_LOWER] = LAYOUT_wrapper( \
    KC_GRV,  _________________LOWER_L1__________________,                    _________________LOWER_R1__________________, KC_LBRC, \
    _______, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________, KC_RBRC, \
    _______, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, _______, \
                                        _______, V_V_V_V, _______,  _______, KC_ADJS, _______\
  ),

  // Mouse keys and numpad
  [_RAISE] = LAYOUT_wrapper( \
    KC_TILD, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, KC_PAST, \
    _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, KC_PPLS, \
    _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, KC_PENT, \
                                        _______, KC_ADJS, KC_DEL,   _______, TG(_RAISE), KC_0\
  ),

  // Media controls and layer toggles
  [_ADJUST] = LAYOUT_wrapper( \
    RESET,   _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________, KC_PSCR, \
    _______, _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________, A(KC_PSCR), \
    NK_TOGG, _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________, _______, \
                                        _______, V_V_V_V, _______,  _______, V_V_V_V, _______\
  )
};
