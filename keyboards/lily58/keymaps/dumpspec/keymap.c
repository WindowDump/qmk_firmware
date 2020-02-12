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

#define _QWERTY 0
#define _COLEMAK 1
#define _GAMER 2
#define _TOUHOU 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 6

#define L_QWERTY 0
#define L_COLEMAK 2
#define L_GAMER 4
#define L_TOUHOU 8
#define L_LOWER 16
#define L_RAISE 32
#define L_ADJUST 64

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
// };

#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
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

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
                            C(KC_PGUP), KC_LALT, KC_LOWR, KC_BSPC,  KC_SPC,  KC_RASE, KC_LGUI, C(KC_PGDN) \
),

[_COLEMAK] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______, \
    _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,  _______, KC_K,    KC_H,    _______, _______, _______, _______, \
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
    _______, _______, _______, KC_FBVU, KC_FBPL, KC_LBRC,                    KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, \
    _______, KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_LPRN,                    KC_RPRN, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______,  _______, KC_INS,  KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, KC_PENT, \
                               _______, _______, KC_ADJS, KC_DEL,   _______, TG(_RAISE), _______, _______ \
),

[_ADJUST] = LAYOUT( \
    RESET,   DEBUG,   _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    VLK_TOG, _______, _______, _______, _______, _______,                    KC_ASUP, _______, _______, _______, _______, _______, \
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  BL_INC,                    KC_ASTG, TG_CLMK, TG_GAME, TG_TOHO, _______, _______, \
    BL_TOGG, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,  BL_DEC, _______,  KC_ASRP, KC_ASDN, _______, _______, _______, _______, _______, \
                               _______, _______, V_V_V_V, _______,  _______, V_V_V_V, _______, _______ \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
  return true;
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

char layer_state_str[6];

// When add source files to SRC in rules.mk, you can use functions.
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
void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// Layer mode icons are 32 x 32 pixels, 0 padding at start and end to avoid display errors
// static const char PROGMEM auto_shift_off[] = {
//     0, 248, 252, 14, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 195, 227, 227, 227, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 14, 252, 248, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 252, 31, 7, 7, 63, 255, 255, 252, 224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0, 0, 192, 240, 254, 31, 7, 6, 6, 6, 6, 6, 7, 7, 63, 255, 255, 252, 240, 128, 0, 0, 0, 0, 0, 255, 255, 31, 63, 112, 224, 192, 192, 195, 195, 195, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 193, 195, 195, 195, 195, 194, 192, 192, 224, 112, 63, 31, 0
// };

// static const char PROGMEM auto_shift_on[] = {
//     0, 248, 252, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 63, 31, 31, 31, 255, 255, 255, 255, 127, 191, 223, 191, 127, 255, 255, 254, 252, 248, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 31, 3, 224, 248, 248, 192, 0, 0, 3, 29, 124, 253, 1, 255, 1, 253, 252, 253, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 63, 15, 1, 224, 248, 249, 249, 249, 249, 249, 248, 248, 192, 0, 0, 3, 14, 127, 192, 255, 255, 255, 255, 255, 255, 31, 63, 127, 255, 255, 255, 252, 252, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 252, 252, 252, 252, 253, 255, 255, 255, 127, 63, 31, 0
// };

// static const char PROGMEM touhou[] = {
//     0, 248, 252, 14, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 14, 252, 248, 255, 255, 0, 0, 4, 244, 244, 84, 84, 254, 254, 84, 84, 244, 244, 4, 0, 8, 8, 8, 8, 248, 254, 78, 72, 72, 200, 200, 0, 0, 255, 255, 255, 255, 0, 0, 16, 25, 13, 7, 3, 31, 31, 3, 7, 13, 25, 16, 0, 16, 24, 12, 7, 3, 0, 16, 16, 30, 15, 1, 0, 0, 255, 255, 31, 63, 112, 224, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 224, 112, 63, 31, 0
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
            // default:
            //     clockwise ? tap_code(KC_1) : tap_code(KC_2);
            //     break;
        }
    }
}
#endif
