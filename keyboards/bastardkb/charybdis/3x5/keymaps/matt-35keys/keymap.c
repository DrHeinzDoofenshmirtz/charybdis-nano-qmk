/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#include "keymap_danish.h"

enum custom_keycodes {
    MATT1 = SAFE_RANGE,
    ST_LCTL,
    ST_LSFT,
    ST_LALT,
    ST_LWIN,
};

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAVPLUS = 1,
    LAYER_SYMBOLS = 2,
    LAYER_NUMPAD = 3,
    LAYER_ACTIONS = 4,
    LAYER_FUNC = 5,
};

#define L_NAV LT(LAYER_NAVPLUS, KC_BSPC)
#define L_SYM LT(LAYER_SYMBOLS, KC_SPACE)
#define L_NUM LT(LAYER_NUMPAD, KC_DELETE)
#define MO_FUNC MO(LAYER_FUNC)
#define MO_ACT MO(LAYER_ACTIONS)

#define _C(kc) MT(MOD_LCTL, kc)
#define _S(kc) MT(MOD_LSFT, kc)
#define _A(kc) MT(MOD_LALT, kc)
#define _W(kc) MT(MOD_LGUI, kc)

#define CTL_BSP CTL_T(KC_BSPC)
#define LT_NAV LT(LAYER_NAVPLUS, KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,   DK_AE,
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, DK_COMM,  DK_DOT, DK_MINS,
                           L_NAV,   L_NUM, _______,    KC_LSFT,   L_SYM
  ),

  [LAYER_NAVPLUS] = LAYOUT(
       _______, _______,   KC_F5,  KC_F12,LCTL(KC_F12),   _______, KC_HOME,  KC_END, DK_OSTR, DK_ARNG,
       ST_LWIN, ST_LALT, ST_LSFT, ST_LCTL, MO_FUNC,       KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______,
       _______, _______, _______, _______, _______,       DK_BSLS, DK_SLSH, DK_SCLN, DK_COLN, DK_UNDS,
                         _______, _______, _______,        KC_ENT,  MO_ACT
  ),
  [LAYER_SYMBOLS] = LAYOUT(
       DK_CURR, _______,  DK_EQL, DK_PLUS, DK_LABK,    DK_RABK, DK_QUOT, DK_ACUT,  DK_GRV, DK_CIRC,
        DK_DLR,   DK_AT, DK_EXLM, DK_QUES, DK_LPRN,    DK_RPRN, DK_DQUO, DK_ASTR, DK_HASH, DK_TILD,
       DK_PERC, DK_PIPE, DK_AMPR, DK_LCBR, DK_LBRC,    DK_RBRC, DK_RCBR, DK_EURO, DK_HALF, DK_DIAE,
                          MO_ACT, _______, _______,    _______, _______
  ),

  [LAYER_NUMPAD] = LAYOUT(
       _______, _______, _______, _______, _______,    _______,    KC_7,    KC_8,    KC_9, _______,
       KC_LWIN, KC_LALT, KC_LSFT, KC_LCTL, _______,    _______,    KC_4,    KC_5,    KC_6, _______,
       _______, _______, _______,LALT(KC_V), _______,  QK_BOOT,    KC_1,    KC_2,    KC_3, _______,
                         _______, _______, _______,       KC_Q,    KC_0
  ),
};
// clang-format on

static uint16_t key_timer;
static bool key_held = false;
static int repeat_interval = 0;
static uint16_t keycode_held = 0;


// handle_keys is called every time a key is pressed/released/event
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed == true;
  //bool released = record->event.pressed == false;
  switch (keycode) {

    case MATT1:
      if(pressed){
        tap_code(KC_H);
        tap_code(KC_E);
        tap_code(KC_J);
      }
      return false;
    case KC_UP:
    case KC_DOWN:
    case KC_LEFT:
    case KC_RIGHT:
        if (pressed)  {
            key_held = true;
            repeat_interval = 100;
            keycode_held = keycode;
            key_timer = timer_read(); // Start the timer when the key is pressed
            tap_code(keycode);        // Tap the key once immediately
        } else {
            key_held = false;          // Key released, stop repeating
        }
        return false;
  }

  return true;
}

// This method is looped through constantly
void matrix_scan_user(void) {
    // fast repeat when holding down arrows
    if (key_held && timer_elapsed(key_timer) > repeat_interval) { // check if the key is still held after 200ms
        tap_code(keycode_held);                             // send the key again
        key_timer = timer_read();                    // reset the timer
        repeat_interval = 50;
    }
}
