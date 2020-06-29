/* the only one who needs to understand this is me
 * but I'll try not to make it too weird for you
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _THE1,
  _GAMER,
  _TOUHOU,
  _NUMBERS,
  _GLOWER,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define V_V_V_V KC_TRNS
#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_LOTG TG(_LOWER)
#define KC_RATG TG(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_GLWR MO(_GLOWER)
#define MT_CTAB MT(MOD_LCTL, KC_TAB)
#define KC_NMBS LT(_NUMBERS, KC_BSPC)
#define MT_ETAB MT(MOD_LCTL, KC_ESC)

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

[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT_CTAB, KC_LG_A, KC_LA_S, KC_LC_D, KC_LS_F, KC_G,    KC_H,    KC_RS_J, KC_RC_K, KC_RA_L, KC_RGSC, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_NMBS, KC_LCTL, KC_LGUI, KC_LALT, KC_LOWR, KC_NMBS, KC_SPC,  KC_RASE, KC_LGUI, KC_DOWN, KC_UP,   KC_RGHT
),

[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    MT_CTAB, KC_LG_A, KC_LA_R, KC_LC_S, KC_LS_T, KC_G,    KC_M,    KC_RS_N, KC_RC_E, KC_RA_I, KC_RG_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_NMBS, KC_LCTL, KC_LGUI, KC_LALT, KC_LOWR, KC_NMBS, KC_SPC,  KC_RASE, KC_LGUI, KC_DOWN, KC_UP,   KC_RGHT
),

[_THE1] = LAYOUT_planck_grid(
    KC_ESC,  KC_K,    KC_M,    KC_L,    KC_U,    KC_SLSH, KC_V,    KC_D,    KC_R,    KC_QUOT, KC_Q,    KC_BSPC,
    MT_CTAB, KC_LG_A, KC_LA_T, KC_LC_H, KC_LS_E, KC_DOT,  KC_C,    KC_RS_S, KC_RC_N, KC_RA_O, KC_RG_I, KC_QUOT,
    KC_LSFT, KC_Z,    KC_P,    KC_F,    KC_J,    KC_COMM, KC_B,    KC_G,    KC_W,    KC_X,    KC_Y,    KC_ENT,
    KC_NMBS, KC_LCTL, KC_LGUI, KC_LALT, KC_LOWR, KC_NMBS, KC_SPC,  KC_RASE, KC_LGUI, KC_DOWN, KC_UP,   KC_RGHT
),

[_GAMER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_GLWR, KC_BSPC, _______, _______, _______, _______, _______, _______
),

[_TOUHOU] = LAYOUT_planck_grid( // greetz to @ZUN_CODE
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUMBERS] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PSCR,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, V_V_V_V, _______, _______, _______, _______, _______, _______
),

[_GLOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, _______, KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_BSLS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, V_V_V_V, _______, _______, KC_ADJS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, _______, KC_DEL,
    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_BSLS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, KC_LOTG, _______, KC_BSPC, KC_ADJS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_INS,  KC_7,    KC_8,    KC_9,    KC_PSLS, KC_PAST,
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, _______, KC_4,    KC_5,    KC_6,    KC_PMNS, KC_PPLS,
    _______, _______, KC_WH_L, _______, KC_WH_R, KC_BTN5, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT, KC_PENT,
    _______, _______, _______, _______, KC_ADJS, KC_DEL,  _______, KC_RATG, KC_0,    KC_PDOT, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    RESET,   _______, _______, KC_FBVU, KC_FBPL, KC_VOLU, _______, TG_THE1, _______, RGB_HUI, RGB_HUD, KC_PSCR,
    DEBUG,   KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_VOLD, AU_ON,   TG_CLMK, TG_GAME, TG_TOHO, NK_TOGG, A(KC_PSCR),
    AG_NORM, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, AU_OFF,  MU_ON,   MU_OFF,  MUV_DE,  MUV_IN,  MU_MOD,
    _______, _______, _______, _______, V_V_V_V, _______, _______, V_V_V_V, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
