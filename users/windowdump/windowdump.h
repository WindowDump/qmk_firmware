#pragma once
#include QMK_KEYBOARD_H

void oled_render_layer_state(void);

enum userspace_layers {
  _QWERTY,
  _QWERTY_MODS,
  _COLEMAK,
  _COLEMAK_MODS,
  _HANDSDOWN,
  _HANDSDOWN_MODS,
  _GAMER,
  _GAMER2,
  _TOUHOU,
  _NUMBERS,
  _NAV,
  _GLOWER,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#ifdef OLED_DRIVER_ENABLE
#define L_QWERTY 0
#define L_QWERTY_MODS 2
#define L_COLEMAK 4
#define L_COLEMAK_MODS 8
#define L_HANDSDOWN 16
#define L_HANDSDOWN_MODS 32
#define L_GAMER 64
#define L_GAMER2 128
#define L_TOUHOU 256
#define L_NUMBERS 512
#define L_NAV 1024
#define L_GLOWER 2048
#define L_LOWER 4096
#define L_RAISE 8192
#define L_ADJUST 16384
#endif // OLED_DRIVER_ENABLE

enum userspace_custom_keycodes {
  TG_CLMK = SAFE_RANGE,
  TG_HNDS,
  TG_QWER,
  GAMEOVR,
  HR_MODS,
  ALT_TAB,
  SALTTAB,
  NXT_TAB,
  PRV_TAB,
  WNDW_1,
  WNDW_2,
  WNDW_3,
  WNDW_4,
  WNDW_5,
  WNDW_6,
  WNDW_7,
  WNDW_8,
  WNDW_9,
  WNDW_0,
# ifdef QUICK_SWITCH
  QCK_TAB,
  QCKSTAB,
  QCK_SEL,
# endif
  NEW_SAFE_RANGE
};

// QMK stuff

#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_GLWR MO(_GLOWER)

#define KC_NMBS LT(_NUMBERS, KC_BSPC)
#define KC_NMSP LT(_NUMBERS, KC_SPC)
#define KC_NVSP LT(_NAV, KC_SPC)
#define MT_CTAB MT(MOD_LCTL, KC_TAB)
#define KC_NAV MO(_NAV)
#define KC_NUMS MO(_NUMBERS)
#define KC_NVBS LT(_NAV, KC_BSPC)

#define TG_GAME TG(_GAMER)
#define TG_GAM2 TG(_GAMER2)
#define TG_TOHO TG(_TOUHOU)

#define KC_V_V_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP

// Hotkeys

#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)
#define CUR_WIN A(KC_PSCR)

// FB2K hotkeys
#define KC_FBVU A(S(KC_EQL))
#define KC_FBVD A(S(KC_MINS))
#define KC_FBNX A(S(KC_RGHT))
#define KC_FBPR A(S(KC_LEFT))
#define KC_FBRN A(S(KC_DOWN))
#define KC_FBPL A(S(KC_ENT))

// Homerow Mods

// QWERTY Homerow Mods
#define KC_LG_A MT(MOD_LGUI, KC_A)
#define KC_LA_S MT(MOD_LALT, KC_S)
#define KC_LC_D MT(MOD_LCTL, KC_D)
#define KC_LS_F MT(MOD_LSFT, KC_F)
#define KC_RS_J MT(MOD_RSFT, KC_J)
#define KC_RC_K MT(MOD_RCTL, KC_K)
#define KC_RA_L MT(MOD_RALT, KC_L)
#define KC_RGSC MT(MOD_RGUI, KC_SCLN)

// Colemak Homerow Mods
#define KC_LA_R MT(MOD_LALT, KC_R)
#define KC_LC_S MT(MOD_LCTL, KC_S)
#define KC_LS_T MT(MOD_LSFT, KC_T)
#define KC_RS_N MT(MOD_RSFT, KC_N)
#define KC_RC_E MT(MOD_RCTL, KC_E)
#define KC_RA_I MT(MOD_RALT, KC_I)
#define KC_RG_O MT(MOD_RGUI, KC_O)

// Hands Down Alt Homerow Mods
#define KC_LG_R MT(MOD_LGUI, KC_R)
#define KC_LC_N MT(MOD_LCTL, KC_N)
#define KC_RS_I MT(MOD_RSFT, KC_I)
#define KC_RA_A MT(MOD_RALT, KC_A)
#define KC_RG_O MT(MOD_RGUI, KC_O)

// Wrappers

// normie boring layout for losers
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_LG_A, KC_LA_S, KC_LC_D, KC_LS_F, KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define ____________QWERTY_L2_NO_HR_MODS___________       KC_A,    KC_S,    KC_D,    KC_F,    _______

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_RS_J, KC_RC_K, KC_RA_L, KC_RGSC
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
#define ____________QWERTY_R2_NO_HR_MODS___________       _______, KC_J,    KC_K,    KC_L,    KC_SCLN

// Colemak DHm
#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_LG_A, KC_LA_R, KC_LC_S, KC_LS_T, KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define ________COLEMAK_MOD_DH_L2_NO_HR_MODS_______       KC_A,    KC_R,    KC_S,    KC_T,    _______

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_RS_N, KC_RC_E, KC_RA_I, KC_RG_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH
#define ________COLEMAK_MOD_DH_R2_NO_HR_MODS_______       _______, KC_N,    KC_E,    KC_I,    KC_O

// Hands Down Alt May '21
#define ______________HANDS_DOWN_ALT_L1____________       KC_W,    KC_C,    KC_H,    KC_F,    KC_V
#define ______________HANDS_DOWN_ALT_L2____________       KC_LG_R, KC_LA_S, KC_LC_N, KC_LS_T, KC_G
#define ______________HANDS_DOWN_ALT_L3____________       KC_X,    KC_M,    KC_L,    KC_D,    KC_B
#define ________HANDS_DOWN_ALT_L2_NO_HR_MODS_______       KC_R,    KC_S,    KC_N,    KC_T,    _______

#define ______________HANDS_DOWN_ALT_R1____________       KC_SLSH, KC_Y,    KC_U,    KC_Q,    KC_J
#define ______________HANDS_DOWN_ALT_R2____________       KC_K,    KC_RS_I, KC_RC_E, KC_RA_A, KC_RG_O
#define ______________HANDS_DOWN_ALT_R3____________       KC_Z,    KC_P,    KC_QUOT, KC_COMM, KC_DOT
#define ________HANDS_DOWN_ALT_R2_NO_HR_MODS_______       _______, KC_I,    KC_E,    KC_A,    KC_O

// Numbers and stuff
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _______________SYMBOLS_LEFT________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _______________SYMBOLS_RIGHT_______________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

// Nav stuff
#define __________________NAV_L1___________________       KC_PGUP, KC_HOME, KC_UP,   KC_END,  SALTTAB
#define __________________NAV_L2___________________       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ALT_TAB
#define __________________NAV_L3___________________       _______, PRV_TAB, _______, NXT_TAB, _______

#define __________________NAV_R1___________________       SALTTAB, WNDW_7,  WNDW_8,  WNDW_9,  WNDW_0
#define __________________NAV_R2___________________       ALT_TAB, WNDW_4,  WNDW_5,  WNDW_6,  _______
#define __________________NAV_R3___________________       _______, WNDW_1,  WNDW_2,  WNDW_3,  _______

// GAMER
#define ________________TOUHOU_LEFT________________       KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C
#define ________________TOUHOU_RIGHT_______________       _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LSFT

// Lower
#define _________________LOWER_L1__________________        KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC
#define _________________LOWER_L2__________________        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN
#define _________________LOWER_L3__________________        UNDO,    CUT,     COPY,    PASTE,   KC_LCBR

#define _________________LOWER_R1__________________        KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE
#define _________________LOWER_R2__________________        KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS
#define _________________LOWER_R3__________________        KC_RCBR, _______, _______, _______, _______

// Raise
#define _________________RAISE_L1__________________        KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3
#define _________________RAISE_L2__________________        KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5
#define _________________RAISE_L3__________________        _______, KC_WH_L, _______, KC_WH_R, KC_BTN4

#define _________________RAISE_R1__________________        KC_INS,  KC_7,    KC_8,    KC_9,    KC_PSLS
#define _________________RAISE_R2__________________        _______, KC_4,    KC_5,    KC_6,    KC_PMNS
#define _________________RAISE_R3__________________        KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT

// Adjust
#define _________________ADJUST_L1_________________        RESET,   _______, KC_FBVU, KC_FBPL, KC_VOLU
#define _________________ADJUST_L2_________________        KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_VOLD
#define _________________ADJUST_L3_________________        NK_TOGG, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE

#define _________________ADJUST_R1_________________        RGB_TOG, TG_HNDS, TG_GAM2, CMB_TOG, RGB_HUI
#define _________________ADJUST_R2_________________        HR_MODS, TG_CLMK, TG_GAME, TG_TOHO, RGB_SAI
#define _________________ADJUST_R3_________________        RGB_MOD, TG_QWER, GAMEOVR, _______, RGB_VAI

#define ___________________BLANK___________________        _______, _______, _______, _______, _______
