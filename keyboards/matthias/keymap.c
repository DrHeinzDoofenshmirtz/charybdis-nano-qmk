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
};

enum charybdis_keymap_layers {
    LAYER_BASE    = 0,
    LAYER_NAVPLUS = 1,
    LAYER_NUMPAD  = 2,
    LAYER_SYMBOLS = 3,
    LAYER_ACTIONS = 4,
    LAYER_FUNC    = 5,
    LAYER_MOUSE   = 6,
};

#define L_NAV LT(LAYER_NAVPLUS, KC_BSPC)
#define L_SYM LT(LAYER_SYMBOLS, KC_DEL)
#define L_NUM LT(LAYER_NUMPAD, KC_SPC)
#define L_FUNC MO(LAYER_FUNC)
#define L_ACT MO(LAYER_ACTIONS)
#define L_MOUSE MO(LAYER_MOUSE)

#define L_SYM2 LT(LAYER_SYMBOLS, KC_ENT)
#define L_NAV2 LT(LAYER_NAVPLUS, KC_BSPC)
#define LT_FUNC MO(LAYER_FUNC)

#define HOME_J _RC(KC_J)
#define HOME_K _RS(KC_K)
#define HOME_L _A(KC_L)
#define HOME_AE _RW(DK_AE)
#define HOME_F _LC(KC_F)
#define HOME_D _LS(KC_D)
#define HOME_S _A(KC_S)
#define HOME_A _LW(KC_A)

#define _LC(kc) MT(MOD_LCTL, kc)
#define _RC(kc) MT(MOD_RCTL, kc)
#define _LS(kc) MT(MOD_LSFT, kc)
#define _RS(kc) MT(MOD_RSFT, kc)
#define _A(kc) MT(MOD_LALT, kc)
#define _LW(kc) MT(MOD_LGUI, kc)
#define _RW(kc) MT(MOD_RGUI, kc)

#define ST_LCTL OSM(MOD_LCTL)
#define ST_LSFT OSM(MOD_LSFT)
#define ST_LALT OSM(MOD_LALT)
#define ST_LGUI OSM(MOD_LGUI)

// #define CTL_BSP CTL_T(KC_BSPC)
// #define LT_NAV LT(LAYER_NAVPLUS, KC_BSPC)
// #define SFT_SPC SFT_T(KC_SPC)
// #define GUI_ENT GUI_T(KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LAYER_BASE] = MATTHIAS_SPLIT_35(
            KC_Q,     KC_W,      KC_E,      KC_R,      KC_T,          KC_Y,      KC_U,      KC_I,      KC_O,       KC_P,
          HOME_A,   HOME_S,    HOME_D,    HOME_F,      KC_G,          KC_H,    HOME_J,    HOME_K,    HOME_L,    HOME_AE,
            KC_Z,     KC_X,      KC_C,      KC_V,      KC_B,          KC_N,      KC_M,   DK_COMM,    DK_DOT,    DK_MINS,
                                L_NAV,     L_NUM,   L_MOUSE,         L_SYM,   KC_LSFT
  ),

  [LAYER_NAVPLUS] = MATTHIAS_SPLIT_35(
       _______, _______,   KC_F5,  KC_F12,_LC(KC_F12),    _______, KC_HOME,  KC_END, DK_OSTR, DK_ARNG,
       KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,  L_FUNC,       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, DK_ARNG,
       _______, _______, _______, _______, _______,       DK_BSLS, DK_SLSH, DK_SCLN, DK_COLN, DK_UNDS,
                         _______, _______, _______,        L_SYM2,  KC_DEL
  ),

  [LAYER_NUMPAD] = MATTHIAS_SPLIT_35(
       _______, _______, _______, _______, _______,    _______,    KC_7,    KC_8,    KC_9, _______,
       KC_LWIN, KC_LALT, KC_LSFT, KC_LCTL, LT_FUNC,    _______,    KC_4,    KC_5,    KC_6, _______,
       _______, _______, _______, _______, _______,    QK_BOOT,    KC_1,    KC_2,    KC_3, _______,
                         _______, _______, _______,    _______,    KC_0
  ),

  [LAYER_SYMBOLS] = MATTHIAS_SPLIT_35(
       DK_CURR, _______,  DK_EQL, DK_PLUS, DK_LABK,    DK_RABK, DK_EXLM, DK_ACUT,  DK_GRV, DK_CIRC,
        DK_DLR,   DK_AT, DK_QUOT, DK_DQUO, DK_LPRN,    DK_RPRN, DK_ASTR, DK_HASH, DK_QUES, DK_TILD,
       DK_EURO, DK_PIPE, DK_AMPR, DK_LCBR, DK_LBRC,    DK_RBRC, DK_RCBR, DK_PERC, DK_HALF, DK_DIAE,
                           L_NAV2,  KC_SPC, _______,    _______, _______
  ),

  [LAYER_ACTIONS] = MATTHIAS_SPLIT_35(
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, QK_BOOT,
                         _______, _______, _______,    _______, _______
  ),

  [LAYER_FUNC] = MATTHIAS_SPLIT_35(
       _______, _______, _______, _______, _______,    _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
       _______, _______, _______, _______, _______,    _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
       _______, _______, _______, _______, _______,    _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
                         _______, _______, _______,    _______, _______
  ),

  [LAYER_MOUSE] = MATTHIAS_SPLIT_35(
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
       _______, MS_BTN3, MS_BTN2, MS_BTN1, _______,    _______, MS_BTN1, MS_BTN2, MS_BTN3, _______,
       _______, _______, _______, _______, _______,    MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,
                         _______, _______, _______,    _______, _______
  ),

};
// clang-format on

//-- COMBOS BEGIN --//
const uint16_t PROGMEM esc_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_M, DK_COMM, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {HOME_F, KC_G, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(gui_combo, KC_LGUI),
    COMBO(tab_combo, KC_TAB),
};
//-- COMBOS END --//

//-- REPEAT BEGIN --//
struct repeat_key {
    uint16_t key_time;
    bool     key_held;
    int      repeat_interval;
    uint16_t keycode_held;
};

static struct repeat_key arrow_repeat;
const int                ARROW_REPEAT_INTERVAL_INITIAL   = 150;
const int                ARROW_REPEAT_INTERVAL_REPEATING = 40;
//-- REPEAT END --//

bool nullify_check(bool pressed, int tapCount, uint8_t mod_keycode_to_check, uint16_t keycode_instead_1, uint16_t keycode_instead_2) {
    /*
        This piece of code nullifies the effect of Left Shift when
        tapping the LCTL_T(KC_T) key.
        This helps rolling over LSFT_T(KC_S) and LCTL_T(KC_T)
        to obtain the intended "st" instead of "T".
        Consequently, capital T can only be obtained by tapping LCTL_T(KC_T)
        and holding RSFT_T(KC_E) (which is the right Shift mod tap).
    */
    tap_code(KC_9);

    if (pressed && tapCount > 0) {
        tap_code(KC_8);
        if (get_mods() & MOD_BIT(MOD_MASK_GUI)) {
            tap_code(KC_7);
            unregister_mods(MOD_BIT(mod_keycode_to_check));
            tap_code(keycode_instead_1);
            tap_code(keycode_instead_2);
            return false;
        }
    }
    return true;
}

// process_record_user is called every time a key is pressed/released/event
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed == true;
    // bool released = record->event.pressed == false;

    switch (keycode) {
        case MATT1:
            if (pressed) {
                tap_code(KC_H);
                tap_code(KC_E);
                tap_code(KC_J);
            }
            return false;

        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
            if (pressed) {
                arrow_repeat.key_held        = true;                          // Key pressed, start repeating
                arrow_repeat.repeat_interval = ARROW_REPEAT_INTERVAL_INITIAL; // In milliseconds
                arrow_repeat.keycode_held    = keycode;                       // Cache the key that was pressed
                arrow_repeat.key_time        = timer_read();                  // Read the current time
                tap_code(keycode);                                            // Tap the key
            } else {
                arrow_repeat.key_held = false; // Key released, stop repeating
            }
            return false;
        /*
        case KC_E:
            return false;
        case KC_R:
            return nullify_check(record->event.pressed, record->tap.count, KC_LGUI, KC_A, KC_R);
        */
    }

    return true;
}

// This method is looped through constantly
void matrix_scan_user(void) {
    // fast repeat when holding down arrow keys
    if (arrow_repeat.key_held && timer_elapsed(arrow_repeat.key_time) > arrow_repeat.repeat_interval) { // check if the key is still held
        tap_code(arrow_repeat.keycode_held);                                                            // send the key again
        arrow_repeat.key_time        = timer_read();                                                    // reset the timer
        arrow_repeat.repeat_interval = ARROW_REPEAT_INTERVAL_REPEATING;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, LAYER_NAVPLUS, LAYER_SYMBOLS, LAYER_ACTIONS);
    // state = update_tri_layer_state(state, LAYER_NUMPAD, LAYER_FUNC, );
    return state;
}
