 #include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum iris_layers {
  _QWERTY,
  _QWERTY_MODS,
  _COLEMAK,
  _COLEMAK_MODS,
  _GAMER,
  _TOUHOU,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  KC_CLMK = SAFE_RANGE,
  KC_HMOD,
};

#define L_QWERTY 0
#define L_HMODS 2
#define L_COLEMAK 4
#define L_GAMER 16
#define L_TOUHOU 32
#define L_LOWER 64
#define L_RAISE 128
#define L_ADJUST 256

#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_V_V_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_NVBS LT(_NAV, KC_BSPC)
#define KC_PGAL LT

#define TG_CLMK TG(_COLEMAK)
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

// RSTHD Homerow Mods
#define KC_LG_R MT(MOD_LGUI, KC_R)
#define KC_LC_T MT(MOD_LCTL, KC_T)
#define KC_LS_H MT(MOD_LSFT, KC_H)
#define KC_RS_N MT(MOD_RSFT, KC_N)
#define KC_RC_A MT(MOD_RCTL, KC_A)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
    KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_HMOD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                            C(KC_PGUP), KC_LALT, KC_LOWR, KC_BSPC,  KC_SPC,  KC_RASE, KC_LGUI, C(KC_PGDN) \
),

[_QWERTY_MODS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, KC_LG_A, KC_LA_S, KC_LC_D, KC_LS_F, _______,                    _______, KC_RS_J, KC_RC_K, KC_RA_L, KC_RGSC, _______, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_COLEMAK] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______, \
    _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,  _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
                               _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_COLEMAK_MODS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, KC_LG_A, KC_LA_R, KC_LC_S, KC_LS_T, _______,                    _______, KC_RS_N, KC_RC_E, KC_RA_I, KC_RG_O, _______, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_GAMER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, KC_SPC,   _______, _______, _______, _______ \
),

[_TOUHOU] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, KC_UP,   _______, _______, _______, \
    _______, KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,  TG_TOHO, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, KC_X,     _______, _______, _______, _______ \
),

[_LOWER] = LAYOUT( \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC,                    KC_RBRC, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,                    KC_RPRN, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
                               _______, _______, TG(_LOWER), _______,  _______, KC_ADJS, _______, _______\
),

[_RAISE] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PSCR, \
    _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,                    _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, \
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,                    _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
    _______, _______, KC_WH_L, _______, KC_WH_R, KC_BTN4, _______,  _______, KC_INS,  KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, KC_PENT, \
                               _______, _______, KC_ADJS, KC_DEL,   _______, TG(_RAISE), _______, _______ \
),

[_ADJUST] = LAYOUT( \
    RESET,   DEBUG,   _______, _______, _______, _______,                    KC_ASRP, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_FBVU, KC_FBPL, KC_VOLU,                    KC_ASUP, _______, _______, _______, _______, _______, \
    _______, KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_VOLD,                    KC_ASTG, KC_CLMK, TG_GAME, TG_TOHO, _______, _______, \
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______,  _______, KC_ASDN, _______, _______, _______, _______, _______, \
                               _______, _______, V_V_V_V, _______,  _______, V_V_V_V, _______, _______ \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_CLMK:
                // turn off any other active typing layers first
                if (IS_LAYER_ON(_COLEMAK)) { // toggle off
                    layer_off(_COLEMAK);
                    layer_off(_COLEMAK_MODS);
                }
                else { // toggle on
                    if (IS_LAYER_ON(_QWERTY_MODS)) { // set homerow mods as needed
                        layer_on(_COLEMAK_MODS);
                    }
                    layer_on(_COLEMAK);
                }
                return false;
            // Toggle homerow mods, regardless of the current layout.
            case KC_HMOD:
                if (IS_LAYER_ON(_QWERTY_MODS)) { // toggle off
                    layer_off(_QWERTY_MODS);
                    layer_off(_COLEMAK_MODS);
                }
                else { // toggle on
                    layer_on(_QWERTY_MODS);
                    // determine current active typing layer, turn on mods for that layer
                    if (IS_LAYER_ON(_COLEMAK)) {
                        layer_on(_COLEMAK_MODS);
                    }
                }
                return false;
        }
    }
    return true;
}

// Custom tapping term per key!
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
      return 175;
    // Shift
    case MT(MOD_LSFT, KC_F):
    case MT(MOD_RSFT, KC_J):
    case MT(MOD_LSFT, KC_T):
    case MT(MOD_RSFT, KC_N):
      return 125;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

static unsigned char skipped_lines;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return OLED_ROTATION_270;
    // return rotation;
}

char autoshift_state_str[11];

void write_autoshift_state(void) {
    if (get_autoshift_state()) {
        snprintf(autoshift_state_str, sizeof(autoshift_state_str), "Auto Shift");
        oled_write_ln(autoshift_state_str, false);
    } else {
        skipped_lines += 3;
    }
}

char hmods_state_str[11];

void write_hmods_state(void) {
    if (layer_state & L_HMODS) {
        snprintf(hmods_state_str, sizeof(hmods_state_str), "H-RowMods ");
        oled_write_ln(hmods_state_str, false);
    } else {
        skipped_lines += 3;
    }
}

char layer_state_str[6];

void write_layer_state(void) {
    if (layer_state & L_ADJUST) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Adj. ");
        oled_write_ln(layer_state_str, false);
    } else if (layer_state & L_RAISE) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Raise");
        oled_write_ln(layer_state_str, false);
    } else if (layer_state & L_LOWER) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Lower");
        oled_write_ln(layer_state_str, false);
    } else {
        skipped_lines++;
    }
}

char layer_base_str[11];

void write_base_state(void) {
    skipped_lines++;
    if (layer_state & L_TOUHOU) {
        snprintf(layer_base_str, sizeof(layer_base_str), "2hu  ");
    } else if (layer_state & L_GAMER) {
        snprintf(layer_base_str, sizeof(layer_base_str), "GAMER");
    } else if (layer_state & L_COLEMAK) {
        snprintf(layer_base_str, sizeof(layer_base_str), "ClmakDHm  ");
        skipped_lines--;
    } else {
        snprintf(layer_base_str, sizeof(layer_base_str), "QWERT");
    }

    oled_write_ln(layer_base_str, false);
}

const char *read_logo(void);

// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// Layer mode icons are 32 x 32 pixels, 0 padding at start and end to avoid display errors
// static const char PROGMEM auto_shift_off[] = {
//     0x00, 0xf8, 0xfc, 0x0e, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xc3, 0xe3,
//     0xe3, 0xe3, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0e, 0xfc, 0xf8,
//     0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xfc, 0x1f, 0x07, 0x07,
//     0x3f, 0xff, 0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
//     0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfe, 0x1f, 0x07, 0x06, 0x06, 0x06, 0x06,
//     0x06, 0x07, 0x07, 0x3f, 0xff, 0xff, 0xfc, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
//     0x1f, 0x3f, 0x70, 0xe0, 0xc0, 0xc0, 0xc3, 0xc3, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
//     0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xc3, 0xc3, 0xc3, 0xc3, 0xc2, 0xc0, 0xc0, 0xe0, 0x70, 0x3f, 0x1f
// };

// static const char PROGMEM auto_shift_on[] = {
//     0x00, 0xf8, 0xfc, 0x0e, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xc3, 0xe3,
//     0xe3, 0xe3, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0e, 0xfc, 0xf8,
//     0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xfc, 0x1f, 0x07, 0x07,
//     0x3f, 0xff, 0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
//     0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfe, 0x1f, 0x07, 0x06, 0x06, 0x06, 0x06,
//     0x06, 0x07, 0x07, 0x3f, 0xff, 0xff, 0xfc, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
//     0x1f, 0x3f, 0x70, 0xe0, 0xc0, 0xc0, 0xc3, 0xc3, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
//     0xc0, 0xc0, 0xc0, 0xc0, 0xc1, 0xc3, 0xc3, 0xc3, 0xc3, 0xc2, 0xc0, 0xc0, 0xe0, 0x70, 0x3f, 0x1f,
// };

// OLED display fun stuff
void oled_task_user(void) {
    if (is_keyboard_master()) {
        // oled_write_raw_P doesn't care about the cursor position
        // oled_write_raw_P(auto_shift_off, sizeof(auto_shift_off));
        // oled_set_cursor(0, 32);
        // oled_write_raw_P_position(touhou, sizeof(touhou), 0);
        // oled_write_raw_P_position(auto_shift_off, sizeof(auto_shift_off), 128);
        // oled_write_raw_P_position(auto_shift_on, 130, 256);
        // for (uint8_t i = 0; i < OLED_DISPLAY_WIDTH; i++) {
        //     oled_write_byte(i, 0, touhou[i]);
        // }
        // oled_write_raw_P(touhou, sizeof(touhou));
        // oled_set_cursor(0, 4);
        skipped_lines = 0;
        write_hmods_state();
        write_autoshift_state();
        write_base_state();
        write_layer_state();
        for (uint8_t i = 0; i < skipped_lines; i++) {
            oled_advance_page(true);
        }
    } else {
        oled_write(read_logo(), false);
    }
}
#endif // OLED_DRIVER_ENABLE

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _LOWER:
                clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
                break;
            case _RAISE:
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                break;
            default:
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                clockwise ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
                alt_tab_timer = timer_read();
                break;
        }
    }
}
#endif
