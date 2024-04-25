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
#include "features/achordion.h"
// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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
};

#include "features/macro.c"
#include "features/combos.c"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
   ┌─────────────────────────────────────────────────┐
   │ q w e r t y                                     │
   └─────────────────────────────────────────────────┘
*/
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,   KC_R,      KC_T,         KC_MUTE,       KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,   SHT_F,     KC_G,                        KC_H,    SHT_J,   KC_K,     KC_L,    KC_SCLN,
    CTL_Z,   GUI_X,   ALT_C,  KC_V,      KC_B,                        KC_N,    KC_M,    ALT_COMM, GUI_DOT, CTL_SLSH,
                              KC_BSPC,   LT(_LOWER, KC_ENT),           LT(_RAISE, KC_SPACE),   ALT_DEL
  ),

/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


   ┌─────────────────────────────────────────────────┐
   │ l o w e r                                       │
   └─────────────────────────────────────────────────┘
*/
  [_LOWER] = LAYOUT(
    KC_CAPS, KC_HOME, KC_UP,   KC_PGUP,  KC_LCBR,     KC_MUTE,      KC_RCBR,   KC_7,   KC_8,   KC_9,   KC_PPLS,
    KC_QUOT, KC_LEFT, KC_DOWN, KC_RGHT,  KC_LBRC,                   KC_RBRC,   KC_4,   KC_5,   KC_6,   KC_EQL,
    XXXXXXX, KC_END,  C(KC_S), KC_PGDN,  KC_LPRN,                   KC_RPRN,   KC_1,   KC_2,   KC_3,   KC_PAST,
                                _______, _______,                   ADJUST,    KC_0
  ),

/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ r a i s e                                       │
   └─────────────────────────────────────────────────┘
*/
  [_RAISE] = LAYOUT(
    KC_EXLM,      KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,     KC_MUTE,       KC_CIRC, RALT(KC_Y),       KC_AMPR,    RALT(KC_P), Celsius,
    RALT(KC_Q),   RALT(KC_S), RALT(KC_F), RALT(KC_E), LSFT(RALT(KC_COMM)),        KC_BSLS, LSFT(RALT(KC_4)), RALT(KC_5), RALT(KC_4), RALT(KC_M),
    LSFT(KC_GRV), KC_GRV,     RALT(KC_C), XXXXXXX,    XXXXXXX,                    KC_PIPE, XXXXXXX,          RALT(KC_2), RALT(KC_3), XXXXXXX,
                                          KC_ESC,     ADJUST,                     _______, KC_TAB
  ),


/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ a d j u s t                                     │
   └─────────────────────────────────────────────────┘
   */
// Adjust
  [_ADJUST] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MUTE,      KC_MUTE, KC_F7,   KC_F8,   KC_F9,   KC_F12,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                   KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                   KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F10,
                               KC_ESC,  _______,                   _______, KC_TAB
  )
};
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H O M E  R O W  M O D S                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


// source: https://getreuer.info/posts/keyboards/achordion/index.html
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Magic Sturdy.
  switch (tap_hold_keycode) {
    case CTL_Z:
      if (other_keycode == GUI_X || other_keycode == ALT_C || other_keycode == KC_V) {
        return true;
      }
	  break;
	case GUI_X:
	  if (other_keycode == KC_E) {
        return true;
      }
	  break;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 500;  // Use a timeout of 500 ms.
}

uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }zs

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 0;  // Disable for Shift mod-tap keys.
  } else {
    return 100;
  }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =  {ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_NUM_SYM] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_NAV] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }
};
#endif