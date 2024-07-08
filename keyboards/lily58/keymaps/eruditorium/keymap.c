// qmk compile -j 0 -kb crkbd -km nico
// qmk flash -j 0 -kb crkbd -km nico
// qmk c2json -o ~/crkbd-nico.json -km nico -kb crkbd keymap.c --no-cpp

#include QMK_KEYBOARD_H
#include "features/select_word.h"

enum layer_number {
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.
     * ,-----------------------------------------. | ESC  |   1  |   2  |   3  |
     * 4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  - |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| | Tab  |   Q  |   W  |   E  |
     * R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  | |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |LShift|   A  |   S  |   D
     * |F/SFT |   G  |-------.    ,-------|   H  |J/SFT |  K   |  L   |   ;  |
     * '   |
     * |------+------+------+------+------+------|   [   |    |    ]
     * |------+------+------+------+------+------| |LCtrl |Z/Ctrl|X/GUI |C/Alt |
     * V  |   B  |-------|    |-------|   N  |   M  |,/AltG|./Gui
     * |//Strg|RShift|
     * `-----------------------------------------/       /
     * \      \-----------------------------------------' | LGUI | BSPC |RAISE |
     * /Enter  /       \Space \  |LOWER |  Del | AltGr| |      |      |ESC   |/
     * /         \      \ |Tab   |      |      |
     *                   `----------------------------'
     * '------''--------------------'
     */

    [_QWERTY] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
        KC_P, KC_PIPE, KC_LSFT, KC_A, KC_S, KC_D, SHT_F, KC_G, KC_H, SHT_J,
        KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, CTL_Z, GUI_X, ALT_C, KC_V, KC_B,
        KC_LBRC, KC_RBRC, KC_N, KC_M, ALT_COMM, GUI_DOT, CTL_SLSH, KC_RSFT,
        KC_LGUI, KC_BSPC, RAISE, KC_ENT, KC_SPC, LOWER, KC_DEL, KC_RALT),
    /* LOWER
     * ,-----------------------------------------.
     * ,-----------------------------------------. |  F11 |  F1  |  F2  |  F3  |
     * F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | F12
     * |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |   `  | VolUp| Home |  Up  |
     * PgUp |      |                    |      |      |  End | Home |      | |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |VolDwn| Left | Down |
     * Right|      |-------.    ,-------|      | Left | Down |  Up  |Right | |
     * |------+------+------+------+------+------|   [   |    |    ]
     * |------+------+------+------+------+------| |      | Mute | End  |      |
     * PgDn |      |-------|    |-------|      |      | PgDn | PgUp |      | |
     * `-----------------------------------------/       /
     * \      \-----------------------------------------' | RGUI | BSPC |RAISE |
     * /       /       \      \  |LOWER |  Del | AltGr| |      |      |ESC   |/
     * /         \      \ |Tab   |      |      |
     *                   `----------------------------'
     * '------''--------------------'
     */
    [_LOWER] = LAYOUT(
        KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,
        KC_F10, KC_F12, KC_GRV, KC_VOLU, KC_HOME, KC_UP, KC_PGUP, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_END, KC_HOME, XXXXXXX, _______, _______, KC_VOLD,
        KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,
        KC_RGHT, _______, _______, KC_MUTE, KC_END, XXXXXXX, KC_PGDN, XXXXXXX,
        _______, _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, _______,
        _______, _______, ADJUST, _______, _______, _______, _______, _______),
    /* RAISE
     * ,-----------------------------------------.
     * ,-----------------------------------------. |  F11 |  F1  |  F2  |  F3  |
     * F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | F12
     * |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |   `  | VolUp| Home |  Up  |
     * PgUp |      |                    |      |      |  End | Home |      |   +
     * |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |VolDwn| Left | Down |
     * Right|      |-------.    ,-------|      | Left | Down |  Up  |Right |   =
     * |
     * |------+------+------+------+------+------|   [   |    |    ]
     * |------+------+------+------+------+------| |      | Mute | End  |      |
     * PgDn |      |-------|    |-------|      |      | PgDn | PgUp |      | |
     * `-----------------------------------------/       /
     * \      \-----------------------------------------' | RGUI | BSPC |RAISE |
     * /       /       \      \  |LOWER |  Del | AltGr| |      |      |ESC   |/
     * /         \      \ |Tab   |      |      |
     *                   `----------------------------'
     * '------''--------------------'
     */
    [_RAISE] = LAYOUT(
        KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,
        KC_F10, KC_F12, KC_GRV, KC_VOLU, KC_HOME, KC_UP, KC_PGUP, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_END, KC_HOME, XXXXXXX, KC_PLUS, _______, KC_VOLD,
        KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,
        KC_RGHT, KC_EQL, _______, KC_MUTE, KC_END, XXXXXXX, KC_PGDN, XXXXXXX,
        _______, _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, _______,
        _______, _______, _______, _______, _______, ADJUST, _______, _______),
    /* ADJUST
     * ,-----------------------------------------.
     * ,-----------------------------------------. |      |      |      |      |
     * |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|       |    |
     * |------+------+------+------+------+------| |      |      |      |      |
     * |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/       /
     * \      \-----------------------------------------' | RGUI | BSPC |RAISE |
     * /       /       \      \  |LOWER |  Del | AltGr| |      |      |ESC   |/
     * /         \      \ |Tab   |      |      |
     *                   `----------------------------'
     * '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD,
        RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______,
        _______, _______)};

/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/

/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
#include "features/tapping_term.c"
/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/
#include "features/oled.c"
/* ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

