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
    MATT2,
};

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_NAVPLUS,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

#define _S(kc) MT(MOD_LSFT, kc)
#define _A(kc) MT(MOD_LALT, kc)
#define _C(kc) MT(MOD_LCTL, kc)
#define _W(kc) MT(MOD_LGUI, kc)

#define CTL_BSP CTL_T(KC_BSPC)
#define LT_NAV LT(LAYER_NAVPLUS, KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         LT_NAV, _S(KC_SPC),  LOWER,      KC_ENT,  _S(KC_SPC)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAVPLUS] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_HOME, KC_END,  MATT1, DK_AA,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         CTL_BSP, SFT_SPC,   LOWER,      KC_ENT, GUI_ENT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       RGB_TOG, KC_MNXT, KC_MPLY, KC_MPRV, XXXXXXX,    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PMNS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,    KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
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
    case KC_W:
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
