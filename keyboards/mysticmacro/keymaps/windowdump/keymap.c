#include QMK_KEYBOARD_H

#define _BASE 0

enum mystic_keycodes {
  PSCR_AT = SAFE_RANGE,
  REIMU,
  MARISA,
  SANAE,
  REISEN,
  YOUMU,
  SAKUYA,
  AYA,
  CIRNO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		PSCR_AT,  KC_5,    KC_6,     KC_7,    KC_8,\
		          KC_1,    KC_2,     KC_3,    KC_4 \
	)
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
    oled_write_ln_P(PSTR("Window Dump's"), false);
    oled_write_ln_P(PSTR("| MysticMacro |"), false);
    oled_write_ln_P(PSTR("MysticMechs.com"), false);
    oled_write_ln_P(PSTR("    BETA V1    "), false);

    // switch (get_highest_layer(layer_state)) {
		// case _BASE:
			// oled_write_ln_P(PSTR("Default"), false);
			// oled_write_ln_P(PSTR("| MysticMacro |"), false);
			// oled_write_ln_P(PSTR("MysticMechs.com"), false);
			// oled_write_ln_P(PSTR("    BETA V1    "), false);
    // }

    // Host Keyboard LED Status
    //led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        clockwise ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        alt_tab_timer = timer_read();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PSCR_AT:
                if (is_alt_tab_active) {
                    unregister_code(KC_LALT);
                    is_alt_tab_active = false;
                }
                else {
                    tap_code16(KC_PSCR);
                }
                return false;
                break;
        }
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}
