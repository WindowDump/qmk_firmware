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

enum lily_layers {
  _QWERTY = 0,
  _COLEMAK,
  _GAMER,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  SALTTAB,
};

#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_V_V_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP

#define TG_CLMK TG(_COLEMAK)
#define TG_GAME TG(_GAMER)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR, \
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
    KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    SALTTAB,  ALT_TAB, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                           C(KC_PGUP), KC_LALT, KC_LOWR, KC_BSPC,  KC_SPC,  KC_RASE, KC_LGUI, C(KC_PGDN) \
),

[_COLEMAK] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,  \
    KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,  _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                               _______, _______, _______, _______,  _______, _______, _______, _______ \
),

[_GAMER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, KC_BSPC, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, KC_SPC,   _______, _______, _______, _______ \
),

[_LOWER] = LAYOUT( \
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC,                    KC_RBRC, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,                    KC_RPRN, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
                               _______, _______, TG(_LOWER), _______,  _______, KC_ADJS, _______, _______\
),

[_RAISE] = LAYOUT( \
    KC_GRV,  _______, _______, _______, _______, _______,                    KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PSCR, \
    _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,                    KC_SLCK, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_BSPC, \
    _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,                    KC_CAPS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
    _______, _______, KC_WH_L, _______, KC_WH_R, KC_BTN4, _______,  _______, KC_INS,  KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, KC_PENT, \
                               _______, _______, KC_ADJS, KC_DEL,   _______, TG(_RAISE), _______, _______ \
),

[_ADJUST] = LAYOUT( \
    RESET,   DEBUG,   _______, _______, _______, _______,                    KC_ASRP, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    KC_ASUP, KC_MSTP, KC_VOLU, KC_MPLY, _______, _______, \
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  BL_INC,                    KC_ASTG, KC_MPRV, KC_VOLD, KC_MNXT, KC_MUTE, _______, \
    BL_TOGG, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,  BL_DEC, _______,  NK_TOGG, KC_ASDN, TG_CLMK, TG_GAME, _______, _______, _______, \
                               _______, _______, V_V_V_V, _______,  _______, V_V_V_V, _______, _______ \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case ALT_TAB:
            case SALTTAB:
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                keycode == ALT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
                return false;
        }
    }
  return true;
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
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return OLED_ROTATION_270;
}

static unsigned char skipped_lines;

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
    if (layer_state & L_COLEMAK) {
        snprintf(layer_base_str, sizeof(layer_base_str), "ClmakDHm  ");
        skipped_lines--;
    } else {
        snprintf(layer_base_str, sizeof(layer_base_str), "QWERT");
    }

    oled_write_ln(layer_base_str, false);
}

const char *read_logo(void);

// OLED display fun stuff
void oled_task_user(void) {
    if (is_keyboard_master()) {
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
