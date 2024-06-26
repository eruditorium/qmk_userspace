/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// qmk compile -j 0 -kb crkbd -km nico
// qmk flash -j 0 -kb crkbd -km nico
// qmk c2json -o ~/crkbd-nico.json -km nico -kb crkbd keymap.c --no-cpp

#include QMK_KEYBOARD_H
#include "features/select_word.h"
// ┌──────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S │
// └──────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘
// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
enum crkbd_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘
enum custom_keycodes {
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  SNAP,
  SELWORD,
  SELECTLINE,
  MC_QUOT
};
#include "features/macro.c"
#include "features/combos.c"


// ┌──────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S │
// └──────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
          ┌─────────────────────────────────────────────────┐
          │ q w e r t y                                     │
          └─────────────────────────────────────────────────┘

          ,-----------------------------------------------------.
          ,-----------------------------------------------------. |   ESC  |   Q
       | W    |   E    |   R    |   T    |                    |   Y    |   U |
          I    |   O    |   P    |  BSPC  |
          |--------+--------+--------+--------+--------+--------|
          |--------+--------+--------+--------+--------+--------| |   Tab  |   A
       | S    |   D    | F/Shft |   G    |                    |   H    | J/Shft
       | K    |   L    |   ;/:  |  '/"   |
          |--------+--------+--------+--------+--------+--------|
          |--------+--------+--------+--------+--------+--------| | Ctrl/- |
       Z/Ctrl | X/Gui  |  C/Alt |   V    |   B    |                    |   N |
       M |
          ,/RAlt | ./Gui  | //Ctrl | Shift  |
          `--------+--------+--------+--------+--------+--------+--------.
          .--------+--------+--------+--------+--------+--------+--------' |
       BSPC |  LW/-  | ENTER  |  |  SPACE | RS/TAB |RAlt/Del|
                                              `--------------------------'
          `--------------------------'
        */
    [_QWERTY] = LAYOUT_split_3x6_3(
        QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, SHT_F, KC_G, KC_H, SHT_J, KC_K, KC_L,
        KC_SCLN, KC_QUOT, CTL_MNS, CTL_Z, GUI_X, ALT_C, KC_V, KC_B, KC_N, KC_M,
        ALT_COMM, GUI_DOT, CTL_SLSH, KC_RSFT, KC_BSPC, LOWER, KC_ENTER,
        KC_SPACE, RAISE, ALT_DEL),

    /*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


      ┌─────────────────────────────────────────────────┐
      │ l o w e r                                       │
      └─────────────────────────────────────────────────┘
    */
    // Lower
    //  ,-----------------------------------------------------.
    //  ,-----------------------------------------------------. |    ▼   |
    //  CAPSLCK|  Home  |   ↑    |   Pg↑  |   {    |                    |    }
    //  |   7    |   8    |   9    |   +    |  Del   |
    //  |--------+--------+--------+--------+--------+--------|
    //  |--------+--------+--------+--------+--------+--------| |    ▼   |
    //  NUMLCK |   ←    │   ↓    │    →   |   [    |                    |    ]
    //  |   4    |   5    |   6    |   -    |   =    |
    //  |--------+--------+--------+--------+--------+--------|
    //  |--------+--------+--------+--------+--------+--------| |    ▼   | | End
    //  |  SAVE  |   Pg↓  |   (    |                    |    )   |   1    |   2
    //  |   3    |   *    |   ▼    |
    //  `--------+--------+--------+--------+--------+--------+--------.
    //  .--------+--------+--------+--------+--------+--------+--------'
    //                                      |    ▼   |   ▼    |    ▼   |  |   -
    //                                      | Adjust |   0    |
    //                                      `--------------------------'
    //                                      `--------------------------'
    [_LOWER] = LAYOUT_split_3x6_3(
        _______, KC_CAPS, KC_HOME, KC_UP, KC_PGUP, KC_LCBR, KC_RCBR, KC_7, KC_8,
        KC_9, KC_PPLS, KC_DEL, _______, KC_QUOT, KC_LEFT, KC_DOWN, KC_RGHT,
        KC_LBRC, KC_RBRC, KC_4, KC_5, KC_6, KC_MINS, KC_EQL, _______, XXXXXXX,
        KC_END, C(KC_S), KC_PGDN, KC_LPRN, KC_RPRN, KC_1, KC_2, KC_3, KC_PAST,
        _______, _______, _______, _______, KC_UNDS, ADJUST, KC_0),

    /* ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

      ┌─────────────────────────────────────────────────┐
      │ r a i s e                                       │
      └─────────────────────────────────────────────────┘
    */
    // Raise
    //  ,-----------------------------------------------------.
    //  ,-----------------------------------------------------. |   ~    |    !
    //  |   @    |   #    |   $    |   %    |                    |    ^   │    Ü
    //  │    &   │    °   │    Ö   │   Del  |
    //  |--------+--------+--------+--------+--------+--------|
    //  |--------+--------+--------+--------+--------+--------| |        │    Ä
    //  │   SZ   │   è    │   é    │    ç   │                    │    /   │    £
    //  │    €   │        │    µ   │   \    |
    //  |--------+--------+--------+--------+--------+--------|
    //  |--------+--------+--------+--------+--------+--------| |        │    `
    //  │        │   CUE  │        │        │                    │    |   │ │ ²
    //  │   ³    │        │        │
    //  `--------+--------+--------+--------+--------+--------+--------.
    //  .--------+--------+--------+--------+--------+--------+--------'
    //                                      |        │ ADJUST │    -   │  │    ▼
    //                                      │    ▼   │    ▼   │
    //                                      `--------------------------'
    //                                      `--------------------------'
    [_RAISE] = LAYOUT_split_3x6_3(
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, RALT(KC_Y),
        KC_AMPR, Celsius, RALT(KC_P), KC_DEL, _______, RALT(KC_Q), RALT(KC_S),
        RALT(KC_F), RALT(KC_E), LSFT(RALT(KC_COMM)), KC_BSLS, LSFT(RALT(KC_4)),
        RALT(KC_5), RALT(KC_4), RALT(KC_M), KC_BSLS, _______, LSFT(KC_GRV),
        _______, RALT(KC_C), XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX, RALT(KC_2),
        RALT(KC_3), XXXXXXX, _______, _______, ADJUST, KC_UNDS, _______,
        _______, _______),

    /*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

      ┌─────────────────────────────────────────────────┐
      │ a d j u s t                                     │
      └─────────────────────────────────────────────────┘
       */
    // Adjust
    //  ,-----------------------------------------------------.
    //  ,-----------------------------------------------------. | Reset  |
    //  On/Off | Cycle  | Brght ↓| Brght ↑| Print  |                    |  Hue ↑
    //  |   F7   |   F8   |   F9   |  F12   |  Sat ↑ |
    //  |--------+--------+--------+--------+--------+--------|
    //  |--------+--------+--------+--------+--------+--------| | Debug  | | |
    //  Stop  | Next   |  VOL↑  |                    |  Hue ↓ |   F4   |   F5 |
    //  F6   |  F11   |  Sat ↓ |
    //  |--------+--------+--------+--------+--------+--------|
    //  |--------+--------+--------+--------+--------+--------| |        | | |
    //  Play  |  Prv   |  VOL↓  |                    |        |   F1   |   F2 |
    //  F3   |  F10   |        |
    //  `--------+--------+--------+--------+--------+--------+--------.
    //  .--------+--------+--------+--------+--------+--------+--------'
    //                                      │    ▼   │    ▼   │    ▼   │  │    ▼
    //                                      │    ▼   │    ▼   │
    //                                      `--------------------------'
    //                                      `--------------------------'
    [_ADJUST] =
        LAYOUT_split_3x6_3(
            QK_BOOT, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, KC_PSCR, RGB_HUI,
            KC_F7, KC_F8, KC_F9, KC_F12, RGB_SAI, DB_TOGG, XXXXXXX, XXXXXXX,
            KC_MSTP, KC_MNXT, KC_VOLU, RGB_HUD, KC_F4, KC_F5, KC_F6, KC_F11,
            RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_VOLD,
            XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F10, _______, _______, _______,
            _______, _______, _______, _______)};
/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
#include "features/tapping_term.c"
/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/
#include "features/oled.c"
/* ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
