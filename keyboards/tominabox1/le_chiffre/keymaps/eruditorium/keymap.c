/* Copyright 2020 tominabox1
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
#include "features/select_word.h"

// ┌─────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                           │
// └─────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘
// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘
enum custom_keycodes {
  MC_QUOT = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  SNAP,
  SELWORD,
  SELECTLINE,
};
#include "features/macro.c"
#include "features/combos.c"



#define AE RALT(KC_Q)
#define SS RALT(KC_S)
#define EACC RALT(KC_F)
#define EACC2 RALT(KC_E)
#define SDF LSFT(RALT(KC_COMM))
#define JKL LSFT(RALT(KC_4))
#define UE RALT(KC_Y)
#define OE RALT(KC_P)

// ┌─────────────────────────────────────────────────────┐
// │ K E Y M A P S                                       │
// └─────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
      ┌─────────────────────────────────────────────────┐
      │ q w e r t y                                     │
      └─────────────────────────────────────────────────┘
    */
    [_QWERTY] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷╷         ╷ ╷ ╷ ╷
        // ╷
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MUTE, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, SHT_F, KC_G, KC_H, SHT_J, KC_K, KC_L, KC_SCLN, CTL_Z,
        GUI_X, ALT_C, KC_V, KC_B, KC_N, KC_M, ALT_COMM, GUI_DOT, CTL_SLSH,
        LT(_LOWER, KC_BSPC), KC_ENT, KC_SPACE, LT(_RAISE, KC_DEL)),

    /*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


      ┌─────────────────────────────────────────────────┐
      │ l o w e r                                       │
      └─────────────────────────────────────────────────┘
    */
    [_LOWER] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷╷         ╷ ╷ ╷ ╷
        // ╷
        KC_ESC, KC_HOME, KC_UP, KC_PGUP, KC_LCBR, KC_MUTE, KC_RCBR, KC_7, KC_8,
        KC_9, KC_PPLS, KC_TAB, KC_LEFT, KC_DOWN, KC_RGHT, KC_LBRC, KC_RBRC,
        KC_4, KC_5, KC_6, KC_EQL, XXXXXXX, KC_END, C(KC_S), KC_PGDN, KC_LPRN,
        KC_RPRN, KC_1, KC_2, KC_3, KC_PAST, _______, KC_ENT, ADJUST, KC_0),

    /*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ r a i s e                                       │
      └─────────────────────────────────────────────────┘
    */
    [_RAISE] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷╷         ╷ ╷ ╷ ╷
        // ╷
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_MUTE, KC_CIRC, UE, KC_AMPR,
        OE, Celsius, AE, SS, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
        RALT(KC_5), RALT(KC_4), RALT(KC_M), LSFT(KC_GRV), KC_GRV, RALT(KC_C),
        XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX, RALT(KC_2), RALT(KC_3), XXXXXXX,
        ADJUST, KC_ESC, KC_TAB, _______),

    /* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ a d j u s t                                     │
      └─────────────────────────────────────────────────┘
       */
    // Adjust
    [_ADJUST] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷╷         ╷ ╷ ╷ ╷
        // ╷
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MUTE, KC_F7,
        KC_F8, KC_F9, KC_F12, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
        KC_VOLU, KC_F4, KC_F5, KC_F6, KC_F11, RGB_MOD, RGB_HUD, RGB_SAD,
        RGB_VAD, XXXXXXX, KC_VOLD, KC_F1, KC_F2, KC_F3, KC_F10, _______,
        _______, _______, _______)};
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_select_word(keycode, record, SELWORD)) {
    return false;
  }

  switch (keycode) {

    // ┌─────────────────────────────────────────────────┐
    // │ d e a d   k e y s                               │
    // └─────────────────────────────────────────────────┘

  case MC_QUOT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
    }
    return false;

    // ┌─────────────────────────────────────────────────┐
    // │ l a y e r                                       │
    // └─────────────────────────────────────────────────┘

  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;

    // ┌─────────────────────────────────────────────────┐
    // │ p r o d u c t i v i t y                         │
    // └─────────────────────────────────────────────────┘

  case SNAP:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_LWIN("S"))); // WIN
    }
    return false;

  case SELECTLINE: // Selects the current line.
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
    }
    return false;
  }

  return true;
}

#include "features/tapping_term.c"
