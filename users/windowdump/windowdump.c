#include "windowdump.h"

bool is_win_switch_active = false;
bool is_alt_tab_active = false;
bool is_tab_switch_active = false;
#ifdef QUICK_SWITCH
bool is_quick_tab_active = false;
uint16_t quick_tab_timer = 0;
#endif

void matrix_scan_user(void) {
  // End fancy nav switching if the NAV layer has been deactivated.
  if (is_win_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LGUI);
    is_win_switch_active = false;
  }
  if (is_alt_tab_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }
  if (is_tab_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LCTL);
    is_tab_switch_active = false;
  }
# ifdef QUICK_SWITCH
  if (is_quick_tab_active && timer_elapsed(quick_tab_timer) > 1000) {
    unregister_code(KC_LALT);
    is_quick_tab_active = false;
  }
# endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // Window switching macro, only available when NAV layer is active.
    if (keycode >= WNDW_1 && keycode <= WNDW_0) {
      if (is_alt_tab_active) {
        is_alt_tab_active = false;
        unregister_code(KC_LALT);
      }
      if (is_tab_switch_active) {
          is_tab_switch_active = false;
          unregister_code(KC_LCTL);
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
        if (is_tab_switch_active) {
          is_tab_switch_active = false;
          unregister_code(KC_LCTL);
        }
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        keycode == ALT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
      // Super tab switching
      case NXT_TAB:
      case PRV_TAB:
        if (is_win_switch_active) {
          is_win_switch_active = false;
          unregister_code(KC_LGUI);
        }
        if (is_alt_tab_active) {
          is_alt_tab_active = false;
          unregister_code(KC_LALT);
        }
        if (!is_tab_switch_active) {
          is_tab_switch_active = true;
          register_code(KC_LCTL);
        }
        keycode == NXT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
#     ifdef QUICK_SWITCH
      // Quickly toggle between windows with three fancy keys
      case QCK_TAB:
      case QCKSTAB:
        if (!is_quick_tab_active) {
          is_quick_tab_active = true;
          register_code(KC_LALT);
        }
        keycode == QCK_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        quick_tab_timer = timer_read();
        return false;
      case QCK_SEL:
        if (is_quick_tab_active) {
          is_quick_tab_active = false;
          unregister_code(KC_LALT);
        }
        return false; 
#     endif
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
        layer_off(_TOUHOU);
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
    case MT(MOD_LCTL, KC_N):
    case MT(MOD_RALT, KC_A):
    case MT(MOD_RGUI, KC_I):
      return TAPPING_TERM;
    // Shift
    case MT(MOD_LSFT, KC_F):
    case MT(MOD_RSFT, KC_J):
    case MT(MOD_LSFT, KC_T):
    case MT(MOD_RSFT, KC_N):
    case MT(MOD_RSFT, KC_U):
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
    case KC_RS_I:
      return true;
    default:
      return false;
  }
}

#ifdef OLED_DRIVER_ENABLE
// need to remember to define all of the layers involved
void oled_render_layer_state(void) {
    uint8_t skipped_lines = 0;
    if (layer_state & L_COLEMAK) {
        oled_write_P(PSTR("Colmk"), false);
    } else if (layer_state & L_HANDSDOWN) {
        oled_write_P(PSTR("Hands"), false);
    } else {
        oled_write_P(PSTR("QWERT"), false);
    }

    if (layer_state & L_QWERTY_MODS) {
        skipped_lines += 2;
    } else {
        oled_write_P(PSTR("H-RowMods "), false);
    }

    oled_advance_page(true);

    if (layer_state & L_GAMER) {
        oled_write_P(PSTR("GAMER"), false);
    } else {
        oled_write_P(PSTR(":D?  "), false);
    }

    (layer_state & L_GAMER2) ? oled_write_P(PSTR("L Spc"), false) : skipped_lines++;
    (layer_state & L_TOUHOU) ? oled_write_P(PSTR("2hu  "), false) : skipped_lines++;

    if (layer_state & L_ADJUST) {
        oled_write_P(PSTR("Adj. "), false);
    } else if (layer_state & L_RAISE) {
        oled_write_P(PSTR("Raise"), false);
    } else if (layer_state & L_LOWER) {
        oled_write_P(PSTR("Lower"), false);
    } else if (layer_state & L_GLOWER) {
        oled_write_P(PSTR("Lower"), false);
    } else if (layer_state & L_NAV) {
        oled_write_P(PSTR("Nav  "), false);
    } else if (layer_state & L_NUMBERS) {
        oled_write_P(PSTR("Nmbrs"), false);
    } else {
        skipped_lines++;
    }

    for (uint8_t i = 0; i < skipped_lines; i++) {
        oled_advance_page(true);
    }
}
#endif // OLED_DRIVER_ENABLE

#ifdef COMBO_ENABLE
enum combos {
  QW_ESC = 0, // QWERTY
  ZX_TAB,
  OP_DEL,
  LS_QOT, // l semicolon
  LS_HR_QOT, // l semicolon
  DS_ENT, // dot slash
  YS_DEL, // y semicolon - Colemak DHm
  IO_QOT,
  IO_HR_QOT,
  WC_ESC, // Hands Down Alt
  XM_TAB,
  QJ_DEL,
  AO_SCLN,
  AO_HR_SCLN,
  CD_ENT,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END}; // QWERTY
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ls_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ls_hr_combo[] = {KC_RA_L, KC_RGSC, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ys_combo[] = {KC_Y, KC_SCLN, COMBO_END}; // Colemak DHm
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM io_hr_combo[] = {KC_RA_I, KC_RG_O, COMBO_END};
const uint16_t PROGMEM wc_combo[] = {KC_W, KC_C, COMBO_END}; // Hands Down Alt
const uint16_t PROGMEM xm_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM qj_combo[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM ao_hr_combo[] = {KC_RA_A, KC_RG_O, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC), // QWERTY
  [ZX_TAB] = COMBO(zx_combo, KC_TAB),
  [OP_DEL] = COMBO(op_combo, KC_DEL),
  [LS_QOT] = COMBO(ls_combo, KC_QUOT),
  [LS_HR_QOT] = COMBO(ls_hr_combo, KC_QUOT),
  [DS_ENT] = COMBO(ds_combo, KC_ENT),
  [YS_DEL] = COMBO(ys_combo, KC_DEL), // Colemak DHm
  [IO_QOT] = COMBO(io_combo, KC_QUOT),
  [IO_HR_QOT] = COMBO(io_hr_combo, KC_QUOT),
  [WC_ESC] = COMBO(wc_combo, KC_ESC), // Hands Down Alt
  [XM_TAB] = COMBO(xm_combo, KC_TAB),
  [QJ_DEL] = COMBO(qj_combo, KC_DEL),
  [AO_SCLN] = COMBO(ao_combo, KC_SCLN),
  [AO_HR_SCLN] = COMBO(ao_hr_combo, KC_SCLN),
  [CD_ENT] = COMBO(cd_combo, KC_ENT)
};
#endif // COMBO_ENABLE