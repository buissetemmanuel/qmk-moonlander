/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"
#include "keymap_extras/keymap_fr_ch.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL


enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
  VRSN = ML_SAFE_RANGE,
  RGB_SLD = ML_SAFE_RANGE,
  HSV_COLOR_1,
  HSV_COLOR_2,
  HSV_COLOR_3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,  CH_1,    CH_2,    CH_3,    CH_4,    CH_5,     CH_QUOT,        CH_CIRC, CH_6,      CH_7,    CH_8,    CH_9,      CH_0,    KC_BSPACE,
        KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,     CH_EGRV,        CH_DIAE, CH_Z,      CH_U,    CH_I,    CH_O,      CH_P,    KC_PSCREEN,
        KC_CAPS, CH_A,    CH_S,    CH_D,    CH_F,    CH_G,     CH_AGRV,        CH_DLR,  KC_H,      CH_J,    CH_K,    CH_L,      CH_EACU, KC_PGUP,
        KC_LSFT, CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,                              CH_N,      CH_M,    CH_COMM, CH_DOT,    CH_MINS, KC_PGDOWN,
        KC_LCTRL,KC_LGUI, CH_LABK, KC_LEFT, KC_RGHT, LALT_T(KC_APPLICATION), LCTL_T(KC_ESCAPE), KC_UP,   KC_DOWN, KC_DELETE, KC_PAUSE,LT(1,KC_ENTER),
                                            KC_SPC, KC_LALT, KC_HOME,          KC_END, KC_ALGR, KC_ENTER
    ),

    [SYMB] = LAYOUT_moonlander(
        KC_ESCAPE, KC_F1,    KC_F2,       KC_F3,       KC_F4,       KC_F5,    _______,          _______, KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10,     KC_F11,         
        _______,   KC_EXLM,  KC_AT,       KC_LCBR,     KC_RCBR,     KC_PIPE,  _______,          _______, KC_UP,   KC_7,    KC_8,  KC_9,  KC_ASTR,    KC_F12,         
        _______,   KC_HASH,  KC_DLR,      KC_LPRN,     KC_RPRN,     KC_GRAVE, _______,          _______, KC_DOWN, KC_4,    KC_5,  KC_6,  KC_KP_PLUS, _______, 
        _______,   KC_PERC,  KC_CIRC,     KC_LBRACKET, KC_RBRACKET, KC_TILD,                             KC_AMPR, KC_1,    KC_2,  KC_3,  KC_BSLASH,  _______, 
        _______,   KC_COMMA, HSV_COLOR_1, HSV_COLOR_2, HSV_COLOR_3, RGB_MOD,                             RGB_TOG, _______, KC_DOT,KC_0,  KC_EQUAL,   _______, 
                                                RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR,             RGB_SLD, RGB_HUD, RGB_HUI

    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_COLOR_1:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(201,255,255);
      }
      return false;
    case HSV_COLOR_2:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_COLOR_3:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(21,255,255);
      }
      return false;
  }
  return true;
}

