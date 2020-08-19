/* Copyright 2019
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

enum layers {
  _BASE = 0,
  _NUM,
  _FN1,
  _FN2,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MO(_FN1), KC_Q,     KC_W,     KC_E,   \
    MO(_FN2), KC_A,     KC_S,     KC_D,   \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,   \
    KC_LCTL,  KC_LCMD,  KC_LALT,  KC_SPC  \
  ),
  [_NUM] = LAYOUT_ortho_4x4(
    MO(_FN1), KC_KP_7,  KC_KP_8,  KC_KP_9, \
    MO(_FN2), KC_KP_4,  KC_KP_5,  KC_KP_6, \
    KC_LSFT,  KC_KP_1,  KC_KP_2,  KC_KP_3, \
    KC_LCTL,  KC_PCMM,  KC_KP_0,  KC_PDOT  \
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    _______,  DF(_BASE),KC_PGUP,  DF(_NUM),\
    _______,  KC_HOME,  KC_PGDN,  KC_END,  \
    _______,  _______,  _______,  KC_ENT,  \
    _______,  _______,  _______,  KC_ESC   \
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    BL_STEP,  KC_MPRV,  KC_BRIU,  KC_MNXT, \
    _______,  KC_VOLD,  KC_BRID,  KC_VOLU, \
    RGB_M_T,  _______,  _______,  RESET,   \
    RGB_TOG,  _______,  QMKBEST,  QMKURL   \
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("20chan macropad (temp)");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        eeconfig_init();
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _BASE:
      rgblight_setrgb (0x00,  0x00, 0xFF);
      break;
    case _NUM:
      rgblight_setrgb (0xFF,  0x00, 0x00);
      break;
    default:
      rgblight_setrgb (0x00,  0xFF, 0xFF);
      break;
  }
  return state;
}