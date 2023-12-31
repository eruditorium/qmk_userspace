// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,         KC_W,     KC_E,           KC_R,           KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,         KC_S,     KC_D,           KC_F,           KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z), KC_X,     KC_C,           KC_V,           KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH) ,
    KC_LCTL,      KC_LGUI,  LALT_T(KC_ESC), LSFT_T(KC_TAB), KC_BSPC,  OSL(_LW), OSL(_RS),KC_SPC,  RALT_T(KC_DEL), KC_MINS, KC_QUOT, KC_ENT
  ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_DLR,       KC_PERC,                      KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT,      KC_RPRN,                      KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR,      KC_RCBR,                      KC_ASTR, KC_1,    KC_2,   KC_3, KC_EQL,
    KC_LCTL, KC_INS,  KC_ESC,  KC_TAB,       KC_BSPC,  OSL(_LW), OSL(_RS), KC_SPC,  TO(0),   KC_DOT, KC_0, KC_ENT
  ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,          KC_END,         KC_PGUP,                      KC_UP,   KC_F7,  KC_F8,   KC_F9,   KC_F10,
    KC_DEL,  KC_LEFT, KC_DOWN,        KC_RGHT,        KC_PGDN,                      KC_DOWN, KC_F4,  KC_F5,   KC_F6,   KC_F11,
    KC_NO,   KC_VOLU, KC_NO,          KC_NO,          QK_BOOT,                      KC_NO,   KC_F1,  KC_F2,   KC_F3,   KC_F12,
    KC_LCTL, KC_VOLD, KC_ESC,         KC_TAB,         KC_BSPC,  OSL(_LW), OSL(_RS), KC_SPC,  TO(0),  KC_PSCR, KC_LSCR, KC_MPLY
  )

};
