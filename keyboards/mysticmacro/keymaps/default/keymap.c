/* Copyright 2018 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *               Visual Reference of MysticMacro
 *	----------------------------------------------------------
 *	|      |   MPRV   |   MNXT   |    UP    | PSCREEN  |  S  |
 *	| PLAY |-------------------------------------------|  C  |
 *	|      |   NOPE   |   LEFT   |   DOWN   |  RIGHT   |  R  |
 *	----------------------------------------------------------
 */

	[_BASE] = LAYOUT(
		KC_MPLY,  KC_MPRV, KC_MNXT,  KC_UP,   KC_PSCREEN,\
		          KC_NO,   KC_LEFT,  KC_DOWN, KC_RIGHT \
	)
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
		case _BASE:
			oled_write_ln_P(PSTR("Default"), false);
			oled_write_ln_P(PSTR("| MysticMacro |"), false);
			oled_write_ln_P(PSTR("MysticMechs.com"), false);
			oled_write_ln_P(PSTR("    BETA V1    "), false);
    }

    // Host Keyboard LED Status
    //led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
