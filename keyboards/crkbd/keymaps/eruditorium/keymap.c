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

#include "features/combos.c"
#include "features/oled.c"
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
//enum crkbd_layers {
//    _QWERTY = 0,
//    _LOWER,
//    _RAISE,
//    _ADJUST,
//};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    MC_QUOT,
    SNAP,
    SELWORD,
};


// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS QWERTY ├──────────────────
#define CTL_Z LCTL_T(KC_Z)
#define GUI_X LGUI_T(KC_X)
#define ALT_C LALT_T(KC_C)
#define SHT_F LSFT_T(KC_F)

// RIGHT HAND HOME ROW MODS QWERTY ├─────────────────┐
#define SHT_J RSFT_T(KC_J)
#define ALT_COMM RALT_T(KC_COMM)
#define GUI_DOT RGUI_T(KC_DOT)
#define CTL_SLSH RCTL_T(KC_SLSH)


// GENERAL ├─────────────────┐
#define Celsius RALT(LSFT(KC_SCLN))
#define CTL_MNS LCTL_T(KC_MINS)
#define ALT_DEL RALT_T(KC_DEL)
#define LOWER LT(_LOWER, KC_ESC)
#define RAISE LT(_RAISE, KC_TAB)
#define ADJUST MO(_ADJUST)
#define QWERTY DF(_QWERTY)

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
   ┌─────────────────────────────────────────────────┐
   │ q w e r t y                                     │      
   └─────────────────────────────────────────────────┘

  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
  |   ESC  |   Q    |   W    |   E    |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    |  BSPC  |
  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  |   Tab  |   A    |   S    |   D    | F/Shft |   G    |                    |   H    | J/Shft |   K    |   L    |   ;/:  |  '/"   |
  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  | Ctrl/- | Z/Ctrl | X/Gui  |  C/Alt |   V    |   B    |                    |   N    |   M    | ,/RAlt | ./Gui  | //Ctrl | Shift  |
  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
                                      |  BSPC  | LW/ESC | ENTER  |  |  SPACE | RS/TAB |RAlt/Del|
                                      `--------------------------'  `--------------------------'    
*/                                      
  [_QWERTY] = LAYOUT_split_3x6_3(
    QK_GESC,   KC_Q,    KC_W,    KC_E,   KC_R,      KC_T,                        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_BSPC,
    KC_TAB,    KC_A,    KC_S,    KC_D,   SHT_F,     KC_G,                        KC_H,    SHT_J,   KC_K,     KC_L,    KC_SCLN,  MC_QUOT,
    CTL_MNS,   CTL_Z,   GUI_X,   ALT_C,  KC_V,      KC_B,                        KC_N,    KC_M,    ALT_COMM, GUI_DOT, CTL_SLSH, KC_RSFT,
                                         KC_BSPC,   LOWER,  KC_ENTER,  KC_SPACE, RAISE,   ALT_DEL
  ),

/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


   ┌─────────────────────────────────────────────────┐
   │ l o w e r                                       │
   └─────────────────────────────────────────────────┘
*/
// Lower
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |    ▼   | CAPSLCK|  Home  |   ↑    |   Pg↑  |   {    |                    |    }   |   7    |   8    |   9    |   +    |  Del   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |    ▼   | NUMLCK |   ←    │   ↓    │    →   |   [    |                    |    ]   |   4    |   5    |   6    |   -    |   =    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |    ▼   | SCRNSHT|  End   |  SAVE  |   Pg↓  |   (    |                    |    )   |   1    |   2    |   3    |   *    |   ▼    |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |    ▼   |   ▼    |    ▼   |  |   -    | Adjust |   0    |
//                                      `--------------------------'  `--------------------------'
  [_LOWER] = LAYOUT_split_3x6_3(
    _______, KC_CAPS, KC_HOME, KC_UP,   KC_PGUP,  KC_LCBR,                   KC_RCBR,   KC_7,   KC_8,   KC_9,   KC_PPLS,  KC_DEL,
    _______, KC_QUOT, KC_LEFT, KC_DOWN, KC_RGHT,  KC_LBRC,                   KC_RBRC,   KC_4,   KC_5,   KC_6,   KC_MINS,  KC_EQL,
    _______, SNAP,    KC_END,  C(KC_S), KC_PGDN,  KC_LPRN,                   KC_RPRN,   KC_1,   KC_2,   KC_3,   KC_PAST,  _______,
                                        _______,  _______, _______, KC_UNDS, ADJUST,    KC_0
  ),

/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ r a i s e                                       │
   └─────────────────────────────────────────────────┘
*/
// Raise
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   ~    |    !   |   @    |   #    |   $    |   %    |                    |    ^   │    &   │    Ü   │    °   │    /   │   Del  |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        │    Ä   │    è   │   SZ   │   é    │    ç   │                    │    µ   │    £   │    €   │        │    Ö   │   \    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        │    `   │    ~   │   CUE  │        │        │                    │    |   │        │    ²   │   ³    │        │        │
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        │ ADJUST │    -   │  │    ▼   │    ▼   │    ▼   │
//                                      `--------------------------'  `--------------------------'
  [_RAISE] = LAYOUT_split_3x6_3(
    _______, KC_EXLM,      KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                    KC_CIRC,    KC_AMPR,          RALT(KC_Y), Celsius,    KC_BSLS,    KC_DEL,
    _______, RALT(KC_Q),   RALT(KC_F), RALT(KC_S), RALT(KC_E), LSFT(RALT(KC_COMM)),        RALT(KC_M), LSFT(RALT(KC_4)), RALT(KC_5), RALT(KC_4), RALT(KC_P), KC_BSLS,
    _______, LSFT(KC_GRV), KC_TILD,    RALT(KC_C), XXXXXXX,    XXXXXXX,                    KC_PIPE,    XXXXXXX,          RALT(KC_2), RALT(KC_3), XXXXXXX,    _______,
                                                   _______,    ADJUST,  KC_UNDS,  _______, _______,    _______
  ),
 

/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ a d j u s t                                     │
   └─────────────────────────────────────────────────┘
   */
// Adjust
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  | Reset  | On/Off | Cycle  | Brght ↓| Brght ↑| Print  |                    |  Hue ↑ |   F7   |   F8   |   F9   |  F12   |  Sat ↑ |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Debug  |        |        |  Stop  | Next   |  VOL↑  |                    |  Hue ↓ |   F4   |   F5   |   F6   |  F11   |  Sat ↓ |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |  Play  |  Prv   |  VOL↓  |                    |        |   F1   |   F2   |   F3   |  F10   |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      │    ▼   │    ▼   │    ▼   │  │    ▼   │    ▼   │    ▼   │ 
//                                      `--------------------------'  `--------------------------'
  [_ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, KC_PSCR,                   RGB_HUI, KC_F7,   KC_F8,   KC_F9,   KC_F12,  RGB_SAI,
    DB_TOGG, XXXXXXX, XXXXXXX, KC_MSTP, KC_MNXT, KC_VOLU,                   RGB_HUD, KC_F4,   KC_F5,   KC_F6,   KC_F11,  RGB_SAD,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_VOLD,                   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                                        _______, _______, _______, _______, _______, _______
  )
};
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H O M E  R O W  M O D S                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef TAPPING_TERM_PER_KEY                                                                                                                                                              
    uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_F:
        case SHT_J:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }   
}       
#endif  

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    if (record->event.pressed) {
        animation_timeout = timer_read32();
        frame_timer       = timer_read32();
        oled_on();
    }

    //if (!process_select_word(keycode, record, SELWORD)) { return false; }
    
    switch (keycode) {

        // ┌─────────────────────────────────────────────────┐
        // │ d e a d   k e y s                               │
        // └─────────────────────────────────────────────────┘
        case MC_QUOT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
            }
            break;

        // ┌─────────────────────────────────────────────────┐
        // │ p r o d u c t i v i t y                         │
        // └─────────────────────────────────────────────────┘

      case SNAP:
          if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
          }
          break;
    }
    return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_raw_P(shuttle, sizeof(shuttle));
        render_animation(launch_frames, sizeof(launch_1), 5, 0, 5);
        fp_render_layer_state();
        fp_render_modifier_state();
    } else {
        render_animation(space_frames, sizeof(space_1), 5, 0, 0);
    }

    return false;
}

bool should_process_keypress(void) {
    return true;
}

#endif
/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/
