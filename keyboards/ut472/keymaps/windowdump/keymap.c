#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _THE1 2
#define _GAMER 3
#define _TOUHOU 4
#define _NUMBERS 5
#define _GLOWER 6
#define _LOWER 7
#define _RAISE 8
#define _ADJUST 9

#define V_V_V_V KC_TRNS
#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_LOTG TG(_LOWER)
#define KC_RATG TG(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_GLWR MO(_GLOWER)
#define MT_CTAB MT(MOD_LCTL, KC_TAB)
#define KC_NMBS LT(_NUMBERS, KC_BSPC)

#define TG_CLMK TG(_COLEMAK)
#define TG_THE1 TG(_THE1)
#define TG_GAME TG(_GAMER)
#define TG_TOHO TG(_TOUHOU)

#define KC_FBVU A(S(KC_EQL))
#define KC_FBVD A(S(KC_MINS))
#define KC_FBNX A(S(KC_RGHT))
#define KC_FBPR A(S(KC_LEFT))
#define KC_FBRN A(S(KC_DOWN))
#define KC_FBPL A(S(KC_ENT))

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

// THE1 Homerow Mods
#define KC_LA_T MT(MOD_LALT, KC_T)
#define KC_LC_H MT(MOD_LCTL, KC_H)
#define KC_LS_E MT(MOD_LSFT, KC_E)
#define KC_RS_S MT(MOD_RSFT, KC_S)
#define KC_RC_N MT(MOD_RCTL, KC_N)
#define KC_RA_O MT(MOD_RALT, KC_O)
#define KC_RG_I MT(MOD_RGUI, KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// _QWERTY
LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  MT_CTAB, KC_LG_A, KC_LA_S, KC_LC_D, KC_LS_F, KC_G,    KC_H,    KC_RS_J, KC_RC_K, KC_RA_L, KC_RGSC, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_NMBS, KC_LCTL, KC_LGUI, KC_LALT, KC_LOWR,     KC_SPC,       KC_RASE, KC_LGUI, KC_DOWN, KC_UP,   KC_RGHT
),

// _COLEMAK
LAYOUT(
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, KC_LG_A, KC_LA_R, KC_LC_S, KC_LS_T, KC_G,    KC_M,    KC_RS_N, KC_RC_E, KC_RA_I, KC_RG_O, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

// _THE1
LAYOUT(
  _______, KC_K,    KC_M,    KC_L,    KC_U,    KC_SLSH, KC_V,    KC_D,    KC_R,    KC_QUOT, KC_Q,    _______,
  _______, KC_LG_A, KC_LA_T, KC_LC_H, KC_LS_E, KC_DOT,  KC_C,    KC_RS_S, KC_RC_N, KC_RA_O, KC_RG_I, KC_SCLN,
  _______, KC_Z,    KC_P,    KC_F,    KC_J,    KC_COMM, KC_B,    KC_G,    KC_W,    KC_X,    KC_Y,    _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

// _GAMER
LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_GLWR,     _______,      _______, _______, _______, _______, _______
),

// _TOUHOU - greetz to @ZUN_CODE
LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
),

// _NUMBERS
LAYOUT(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PSCR,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  V_V_V_V, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

// _GLOWER
LAYOUT(
  KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, _______, KC_DEL,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_BSLS,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, V_V_V_V,     KC_BSPC,      KC_ADJS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

// _LOWER
LAYOUT(
  KC_GRV,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, _______, KC_DEL,
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_BSLS,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, KC_LOTG,     KC_BSPC,      KC_ADJS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

// _RAISE
LAYOUT(
  KC_TILD, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_INS,  KC_7,    KC_8,    KC_9,    KC_PSLS, KC_PAST,
  _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, _______, KC_4,    KC_5,    KC_6,    KC_PMNS, KC_PPLS,
  _______, _______, KC_WH_L, _______, KC_WH_R, KC_BTN5, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT, KC_PENT,
  _______, _______, _______, _______, KC_ADJS,     KC_BSPC,      KC_RATG, KC_0,    KC_PDOT, _______, _______
),

// _ADJUST
LAYOUT(
  RESET,   _______, _______, KC_FBVU, KC_FBPL, KC_VOLU, _______, TG_THE1, _______, RGB_HUI, RGB_HUD, KC_PSCR,
  _______, KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_VOLD, _______, TG_CLMK, TG_GAME, TG_TOHO, NK_TOGG, A(KC_PSCR),
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______,
  _______, _______, _______, _______, V_V_V_V,     _______,      V_V_V_V, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),
};
