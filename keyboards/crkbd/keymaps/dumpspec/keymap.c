#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _GAMER 2
#define _TOUHOU 3
#define _NUMBERS 4
#define _GLOWER 5
#define _LOWER 6
#define _RAISE 7
#define _ADJUST 8

#define L_QWERTY 0
#define L_COLEMAK 2
#define L_GAMER 4
#define L_TOUHOU 8
#define L_NUMBERS 16
#define L_GLOWER 32
#define L_LOWER 64
#define L_RAISE 128
#define L_ADJUST 256

#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_GLWR MO(_GLOWER)
#define KC_NMBS LT(_NUMBERS, KC_BSPC)
#define KC_V_V_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_NVBS LT(_NAV, KC_BSPC)

#define TG_CLMK TG(_COLEMAK)
#define TG_GAME TG(_GAMER)
#define TG_TOHO TG(_TOUHOU)

#define KC_FBVU A(S(KC_EQL))
#define KC_FBVD A(S(KC_MINS))
#define KC_FBNX A(S(KC_RGHT))
#define KC_FBPR A(S(KC_LEFT))
#define KC_FBRN A(S(KC_DOWN))
#define KC_FBPL A(S(KC_ENT))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
    KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                                        KC_LALT, KC_LOWR, KC_NMBS,  KC_SPC,  KC_RASE, KC_LGUI \
  ),

  [_COLEMAK] = LAYOUT( \
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______, \
    _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                       KC_K,    KC_H,    _______, _______, _______, _______, \
                                        _______, _______, _______,  _______, _______, _______\
  ),

  [_GAMER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, KC_BSPC, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
                                        _______, KC_GLWR, KC_BSPC,   _______, _______, _______\
  ),

  [_TOUHOU] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, KC_UP,   _______, _______, _______, \
    _______, KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
                                        _______, _______, KC_X,     _______, _______, _______\
  ),

  [_NUMBERS] = LAYOUT( \
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,  \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
                                        _______, _______, V_V_V_V,  _______, KC_ADJS, _______\
  ),

  [_GLOWER] = LAYOUT( \
    KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, _______, KC_PIPE, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  _______, KC_BSLS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_PSCR, _______, _______, _______, _______, _______, \
                                        _______, V_V_V_V, _______,  _______, KC_ADJS, _______\
  ),

  [_LOWER] = LAYOUT( \
    KC_ESC,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_LBRC,                    KC_RBRC, KC_UNDS, KC_PLUS, KC_TILD, _______, KC_PIPE, \
    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,                    KC_RPRN, KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_BSLS, \
    _______, _______, _______, _______, _______, KC_F5,                      KC_PSCR, _______, _______, _______, _______, _______, \
                                        _______, TG(_LOWER), _______,  _______, KC_ADJS, _______\
    ),

  [_RAISE] = LAYOUT( \
    KC_ESC,  _______, _______, _______, _______, _______,                    KC_INS,  KC_7,    KC_8,    KC_9,    KC_PSLS, KC_PAST, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F11,  KC_4,    KC_5,    KC_6,    KC_PMNS, KC_PPLS, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                     KC_F12,  KC_1,    KC_2,    KC_3,    KC_PDOT, KC_PENT, \
                                        _______, KC_ADJS, KC_DEL,   _______, TG(_RAISE), KC_0\
  ),

  [_ADJUST] = LAYOUT( \
    RESET,   _______, _______, KC_FBVU, KC_FBPL, KC_VOLU,                    KC_ASUP, KC_ASRP, _______, _______, _______, _______, \
    _______, KC_FBRN, KC_FBPR, KC_FBVD, KC_FBNX, KC_VOLD,                    KC_ASTG, TG_CLMK, TG_GAME, TG_TOHO, _______, _______, \
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                    KC_ASDN, _______, _______, _______, _______, _______, \
                                        _______, V_V_V_V, _______,  _______, V_V_V_V, _______\
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
