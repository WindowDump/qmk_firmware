// Copyright (C) 2019, 2020  Keyboard.io, Inc
// DESIGNED IN THE UNITED STATES, PERFECTED IN MY BEDROOM

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY = 0,
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
  _ADJUST
};

enum custom_keycodes {
  TG_CLMK = SAFE_RANGE,
  TG_HNDS,
  TG_QWER,
  GAMEOVR,
  HR_MODS,
  ALT_TAB,
  SALTTAB,
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
};

#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_GLWR MO(_GLOWER)
#define KC_NMBS LT(_NUMBERS, KC_BSPC)
#define KC_NVSP LT(_NAV, KC_SPC)
#define KC_NVBS LT(_NAV, KC_BSPC)
#define MT_CTAB MT(MOD_LCTL, KC_TAB)
#define LT_LWRE LT(_LOWER, KC_E)
#define LT_LWTB LT(_LOWER, KC_TAB)
#define LT_RSQT LT(_RAISE, KC_QUOTE)

#define TG_GAME TG(_GAMER)
#define TG_GAM2 TG(_GAMER2)
#define TG_TOHO TG(_TOUHOU)

#define KC_V_V_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP

#define NXT_TAB C(KC_PGDN)
#define PRV_TAB C(KC_PGUP)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)

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

// Hands Down Alt Homerow Mods
#define KC_LG_R MT(MOD_LGUI, KC_R)
#define KC_LC_N MT(MOD_LCTL, KC_N)
#define KC_RS_U MT(MOD_RSFT, KC_U)
#define KC_RA_A MT(MOD_RALT, KC_A)
#define KC_RG_I MT(MOD_RGUI, KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY with homerow mods
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_LG_A, KC_LA_S, KC_LC_D, KC_LS_F, KC_G,                      KC_H,    KC_RS_J, KC_RC_K, KC_RA_L, KC_RGSC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  HR_MODS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_LSFT, MT_CTAB, KC_LALT, KC_LOWR, KC_NMBS, KC_DEL,  KC_QUOT, KC_NVSP, KC_RASE, KC_LGUI, KC_QUOT, KC_ENT
  ),

  // Disabled homerow mods for QWERTY
  [_QWERTY_MODS] = LAYOUT(
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_A,    KC_S,    KC_D,    KC_F,    _______,                   _______, KC_J,    KC_K,    KC_L,    KC_SCLN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_COLEMAK] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_LG_A, KC_LA_R, KC_LC_S, KC_LS_T, KC_G,                      KC_M,    KC_RS_N, KC_RC_E, KC_RA_I, KC_RG_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_COLEMAK_MODS] = LAYOUT(
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_A,    KC_R,    KC_S,    KC_T,    _______,                   _______, KC_N,    KC_E,    KC_I,    KC_O,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_HANDSDOWN] = LAYOUT(
    KC_QUOT, KC_G,    KC_H,    KC_K,    KC_Z,                      KC_V,    KC_C,    KC_O,    KC_X,    KC_SLSH,
    KC_LG_R, KC_LA_S, KC_LC_N, KC_LS_T, KC_P,                      KC_Y,    KC_RS_U, KC_RC_E, KC_RA_A, KC_RG_I,
    KC_J,    KC_B,    KC_L,    KC_D,    KC_M,    _______, _______, KC_W,    KC_F,    KC_Q,    KC_COMM, KC_DOT,
    _______, _______, _______, LT_LWRE, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_HANDSDOWN_MODS] = LAYOUT(
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_R,    KC_S,    KC_N,    KC_T,    _______,                   _______, KC_U,    KC_E,    KC_A,    KC_I,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAMER] = LAYOUT(
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_A,    KC_S,    KC_D,    KC_F,    _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_ESC,  _______, _______, _______, _______, _______, _______,
    KC_LSFT, KC_LCTL, KC_LALT, KC_GLWR, KC_BSPC, KC_TAB,  _______, _______, _______, _______, _______, _______
  ),

  [_GAMER2] = LAYOUT(
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_SPC,  _______, _______, KC_NVBS, _______, _______, _______, _______
  ),

  [_TOUHOU] = LAYOUT(
    KC_ESC,  _______, _______, KC_R,    _______,                   _______, _______, KC_UP,   _______, _______,
    KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LSFT,
    _______, _______, _______, _______, _______, TG_TOHO, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUMBERS] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, V_V_V_V, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT(
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,                   SALTTAB, WNDW_7,  WNDW_8,  WNDW_9,  WNDW_0,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,                   ALT_TAB, WNDW_4,  WNDW_5,  WNDW_6,  KC_DEL,
    _______, PRV_TAB, _______, NXT_TAB, _______, _______, _______, _______, WNDW_1,  WNDW_2,  WNDW_3,  _______,
    _______, _______, _______, _______, _______, _______, _______, V_V_V_V, _______, _______, _______, _______
  ),

  [_GLOWER] = LAYOUT(
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_ESC,  _______, _______, V_V_V_V, _______, _______, _______, KC_DEL,  KC_ADJS, _______, _______, _______
  ),

  [_LOWER] = LAYOUT(
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC,                   KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,                   KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS,
    UNDO,    CUT,     COPY,    PASTE,   KC_LCBR, _______, _______, KC_RCBR, _______, _______, _______, _______,
    KC_GRV,  _______, _______, V_V_V_V, _______, _______, _______, KC_DEL, KC_ADJS, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,                   KC_INS,  KC_7,    KC_8,    KC_9,    KC_PSLS,
    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,                   _______, KC_4,    KC_5,    KC_6,    KC_PAST,
    _______, KC_WH_L, _______, KC_WH_R, KC_BTN4, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PMNS,
    KC_TILD, _______, _______, KC_ADJS, KC_DEL,  _______, _______, _______, V_V_V_V, KC_0,    KC_PDOT, KC_PPLS
  ),

  [_ADJUST] = LAYOUT(
    RESET,   _______, KC_FBVU, KC_FBPL, KC_VOLU,                   CMB_TOG, TG_HNDS, TG_GAM2, _______, KC_PSCR,
    KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_VOLD,                   HR_MODS, TG_CLMK, TG_GAME, TG_TOHO, A(KC_PSCR),
    _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______, _______, _______, TG_QWER, GAMEOVR, _______, _______,
    _______, _______, _______, V_V_V_V, _______, _______, _______, _______, V_V_V_V, _______, _______, _______
  ),
};

/*
'  g  h  k  z    v  c  o  x  /
r  s  n  t  p    y  u  e  a  i
j  b  l  d  m    w  f  q  ,  .
#define KC_LG_R MT(MOD_LGUI, KC_R)
#define KC_LC_N MT(MOD_LCTL, KC_N)
#define KC_RS_U MT(MOD_RSFT, KC_U)
#define KC_RA_A MT(MOD_RALT, KC_A)
#define KC_RG_I MT(MOD_RGUI, KC_I)
*/

enum combos {
  QW_ESC,
  ZX_TAB,
  OP_DEL,
  LS_QOT,
  LS_HR_QOT,
  DS_ENT,
  YS_DEL,
  IO_QOT,
  IO_HR_QOT,
  QG_ESC,
  JB_TAB,
  XS_DEL,
  AI_HR_SCLN,
  AI_SCLN,
  CD_ENT,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ls_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ls_hr_combo[] = {KC_RA_L, KC_RGSC, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ys_combo[] = {KC_Y, KC_SLSH, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM io_hr_combo[] = {KC_RA_I, KC_RG_O, COMBO_END};
const uint16_t PROGMEM qg_combo[] = {KC_QUOT, KC_G, COMBO_END};
const uint16_t PROGMEM jb_combo[] = {KC_J, KC_B, COMBO_END};
const uint16_t PROGMEM xs_combo[] = {KC_X, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ai_hr_combo[] = {KC_RA_A, KC_RG_I, COMBO_END};
const uint16_t PROGMEM ai_combo[] = {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC),
  [ZX_TAB] = COMBO(zx_combo, KC_TAB),
  [OP_DEL] = COMBO(op_combo, KC_DEL),
  [LS_HR_QOT] = COMBO(ls_hr_combo, KC_QUOT),
  [DS_ENT] = COMBO(ds_combo, KC_ENT),
  [YS_DEL] = COMBO(ys_combo, KC_DEL),
  [IO_QOT] = COMBO(io_combo, KC_QUOT),
  [IO_HR_QOT] = COMBO(io_hr_combo, KC_QUOT),
  [QG_ESC] = COMBO(qg_combo, KC_ESC),
  [JB_TAB] = COMBO(jb_combo, KC_TAB),
  [XS_DEL] = COMBO(xs_combo, KC_DEL),
  [AI_HR_SCLN] = COMBO(ai_hr_combo, KC_SCLN),
  [AI_SCLN] = COMBO(ai_combo, KC_SCLN),
  [CD_ENT] = COMBO(cd_combo, KC_ENT)
};

int RGB_current_mode;
bool is_win_switch_active = false;
bool is_alt_tab_active = false;

void matrix_scan_user(void) {
  // End window switching if the NAV layer has been deactivated.
  if (is_win_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LGUI);
    is_win_switch_active = false;
  }
  if (is_alt_tab_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Homerow mods
    case MT(MOD_LGUI, KC_A):
    case MT(MOD_LALT, KC_S):
    case MT(MOD_LCTL, KC_D):
    case MT(MOD_RCTL, KC_K):
    case MT(MOD_RALT, KC_L):
    case MT(MOD_RGUI, KC_SCLN):
    case MT(MOD_LALT, KC_R):
    case MT(MOD_LCTL, KC_S):
    case MT(MOD_RCTL, KC_E):
    case MT(MOD_RALT, KC_I):
    case MT(MOD_RGUI, KC_O):
    case MT(MOD_LGUI, KC_R):
    case MT(MOD_LCTL, KC_T):
    case MT(MOD_RCTL, KC_A):
      return TAPPING_TERM;
    // Shift
    case MT(MOD_LSFT, KC_F):
    case MT(MOD_RSFT, KC_J):
    case MT(MOD_LSFT, KC_T):
    case MT(MOD_RSFT, KC_N):
    case MT(MOD_LSFT, KC_H):
      return TAPPING_TERM + 25;
    // LT
    case MT(MOD_LCTL, KC_TAB):
    case LT(_NUMBERS, KC_BSPC):
    case LT(_NAV, KC_SPC):
    case LT(_LOWER, KC_E):
      return TAPPING_TERM - 25;
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case KC_LS_F:
    case KC_RS_J:
    case KC_LS_T:
    case KC_RS_N:
    case KC_RS_U:
      return true;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // Window switching macro, only available when NAV layer is active.
    if (keycode >= WNDW_1 && keycode <= WNDW_0) {
      if (is_alt_tab_active) {
        is_alt_tab_active = false;
        unregister_code(KC_LALT);
      }
      if (!is_win_switch_active) {
        is_win_switch_active = true;
        register_code(KC_LGUI);
      }
      switch (keycode) {
        case WNDW_0:
          tap_code16(KC_0);
          break;
        case WNDW_1:
          tap_code16(KC_1);
          break;
        case WNDW_2:
          tap_code16(KC_2);
          break;
        case WNDW_3:
          tap_code16(KC_3);
          break;
        case WNDW_4:
          tap_code16(KC_4);
          break;
        case WNDW_5:
          tap_code16(KC_5);
          break;
        case WNDW_6:
          tap_code16(KC_6);
          break;
        case WNDW_7:
          tap_code16(KC_7);
          break;
        case WNDW_8:
          tap_code16(KC_8);
          break;
        case WNDW_9:
          tap_code16(KC_9);
          break;
      }
      return false;
    }
    switch (keycode) {
      // Super Alt-Tab
      case ALT_TAB:
      case SALTTAB:
        if (is_win_switch_active) {
          is_win_switch_active = false;
          unregister_code(KC_LGUI);
        }
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        keycode == ALT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
      // Activate alternative layouts while preserving homerow mod status
      case TG_CLMK:
        // turn off any other active typing layers first
        layer_off(_HANDSDOWN);
        if (IS_LAYER_ON(_COLEMAK)) { // toggle off
          layer_off(_COLEMAK);
          layer_off(_COLEMAK_MODS);
        }
        else { // toggle on
          if (IS_LAYER_ON(_QWERTY_MODS)) { // set homerow mods as needed
            layer_on(_COLEMAK_MODS);
            layer_off(_HANDSDOWN_MODS);
          }
          layer_on(_COLEMAK);
        }
        return false;
      case TG_HNDS:
        // turn off any other active typing layers first
        layer_off(_COLEMAK);
        if (IS_LAYER_ON(_HANDSDOWN)) { // toggle off
          layer_off(_HANDSDOWN);
          layer_off(_HANDSDOWN_MODS);
        }
        else { // toggle on
          if (IS_LAYER_ON(_QWERTY_MODS)) { // set homerow mods as needed
            layer_on(_HANDSDOWN_MODS);
            layer_off(_COLEMAK_MODS);
          }
          layer_on(_HANDSDOWN);
        }
        return false;
      case TG_QWER:
        // QWERTY escape hatch
        if (IS_LAYER_ON(_QWERTY_MODS)) { // unset homerow mods as needed
          layer_off(_COLEMAK_MODS);
          layer_off(_HANDSDOWN_MODS);
        }
        layer_off(_COLEMAK);
        layer_off(_HANDSDOWN);
        return false;
      case GAMEOVR:
        // G A M E O V E R G A M E O V E R GAME OVER GAME OVER
        layer_off(_GAMER);
        layer_off(_GAMER2);
        return false;
      // Toggle homerow mods, regardless of the current layout.
      case HR_MODS:
        if (IS_LAYER_ON(_QWERTY_MODS)) { // toggle off
          layer_off(_QWERTY_MODS);
          layer_off(_COLEMAK_MODS);
          layer_off(_HANDSDOWN_MODS);
        }
        else { // toggle on
          layer_on(_QWERTY_MODS);
          // determine current active typing layer, turn on mods for that layer
          if (IS_LAYER_ON(_COLEMAK)) {
            layer_on(_COLEMAK_MODS);
          } else if (IS_LAYER_ON(_HANDSDOWN)) {
            layer_on(_HANDSDOWN_MODS);
          }
        }
        return false;
    }
  }

  return true;
}
