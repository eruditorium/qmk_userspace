/*
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

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_SINGLE_TAP, // send three single taps
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
  T_NEW,
  C_COPY,
  V_PASTE,
  CTRL_X,
//  CTRL_L,
//  LEFT,
//  RIGHT,
  CTRL_W,
//  CTRL_Z,
  TD_EXPLORER,
//  TD_ALTF4,
//  ENTER_RALT
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the t tap dance. Put it here so it can be used in any keymap
void t_finished(qk_tap_dance_state_t *state, void *user_data);
void t_reset(qk_tap_dance_state_t *state, void *user_data);
// For the c tap dance. Put it here so it can be used in any keymap
void c_finished(qk_tap_dance_state_t *state, void *user_data);
void c_reset(qk_tap_dance_state_t *state, void *user_data);
// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);
// For the v tap dance. Put it here so it can be used in any keymap
void v_finished(qk_tap_dance_state_t *state, void *user_data);
void v_reset(qk_tap_dance_state_t *state, void *user_data);
// For the l tap dance. Put it here so it can be used in any keymap
//void l_finished(qk_tap_dance_state_t *state, void *user_data);
//void l_reset(qk_tap_dance_state_t *state, void *user_data);
// For the left tap dance. Put it here so it can be used in any keymap
//void left_finished(qk_tap_dance_state_t *state, void *user_data);
//void left_reset(qk_tap_dance_state_t *state, void *user_data);
// For the right tap dance. Put it here so it can be used in any keymap
//void right_finished(qk_tap_dance_state_t *state, void *user_data);
//void right_reset(qk_tap_dance_state_t *state, void *user_data);
// For the W tap dance. Put it here so it can be used in any keymap
void w_finished(qk_tap_dance_state_t *state, void *user_data);
void w_reset(qk_tap_dance_state_t *state, void *user_data);
// For the Z tap dance. Put it here so it can be used in any keymap
//void z_finished(qk_tap_dance_state_t *state, void *user_data);
//void z_reset(qk_tap_dance_state_t *state, void *user_data);
// For the enter tap dance. Put it here so it can be used in any keymap
//void enter_finished(qk_tap_dance_state_t *state, void *user_data);
//void enter_reset(qk_tap_dance_state_t *state, void *user_data);

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define FN_DEL LT(MO(_FN), KC_DEL)

#define J_RAISE LT(_RAISE, KC_J)
#define K_LOWER LT(_LOWER, KC_K)

#define D_LOWER LT(_LOWER, KC_D)
#define F_RAISE LT(_RAISE, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |   Q   |   W*  |   E   |   R   |   T*  |  Esc  |  Bksp |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   A*  |   S*  |   D*  |   F*  |   G   |  Tab  | Enter |   H   |   J*  |   K*  |   L*  |   ;*  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Z   |   X*  |   C*  |   V*  |   B   |  Del  |   '   |   N   |   M   |   ,   |   .   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Ctrl |  GUI* |  FN*  | AltGr | Lower |     Space     | Raise |  Left |  Down |   Up  | Right |
 * '-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
/*    1                 2                   3               4              5              *6*           *7*          8            9           10         11                 12  */
    KC_Q,           TD(CTRL_W),         KC_E,           KC_R,           TD(T_NEW),      KC_ESC,     KC_BSPC,        KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,
    LALT_T(KC_A),   LSFT_T(KC_S),       D_LOWER,        F_RAISE,        KC_G,           KC_TAB,     KC_ENTER,       KC_H,       J_RAISE,    K_LOWER,    RSFT_T(KC_L),   RALT_T(KC_SCLN),
    KC_Z,           TD(CTRL_X),         TD(C_COPY),     TD(V_PASTE),    KC_B,           KC_DEL,     KC_QUOT,        KC_N,       KC_M,       KC_COMM,    KC_DOT,         KC_SLSH,
    KC_LCTL,        TD(TD_EXPLORER),    FN_DEL,         KC_RALT,        LOWER,                KC_SPC,               RAISE,    KC_LEFT,    KC_DOWN,    KC_UP,          KC_RIGHT
  ),

/* --------------------------------------------------------------------------------------------------------------------- */
/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |   1   |   2   |   3   |   4   |   5   |  Esc  | BkSpc |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |  Tab  | Enter |   +   | WHL_U | WHL_U |   -   |   *   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |  Del  |       |   -   | WHL_D | WHL_D |   _   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |  Low  |     SPACE     | Raise |       |       |       |   =   |
 * '-----------------------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT_planck_mit(
/*      1         2       3        4          5        *6*        *7*      8      9        10       11        12  */
      KC_1,     KC_2,    KC_3,    KC_4,     KC_5,    _______,  _______, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______,  _______, KC_PLUS, KC_WH_U,  KC_WH_U, KC_MINS, KC_ASTR,
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______,  _______, KC_MINS, KC_WH_D,  KC_WH_D, KC_UNDS, KC_SLSH,
      _______,  _______, _______, _______,  _______,      _______,      _______, _______,  _______, _______, KC_EQL
  ),


/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |   !   |   @   |   #   |   $   |   %   |  (    |   )   |   ^   |   &   |  *    |   (   |   )   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   ~   | MS_UP | MS_B3 | MS_B1 |   \   |  [    |   ]   |   +   |       |       |   -   |   *   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | MS_L  | MS_DN | MS_R  | MS_B2 |   |   |   {   |   }   |   -   |       |       |   _   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       | Lower |    Space      | Raise |       |       |       |   =   |
 * '-----------------------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_mit(
 /*     1         2         3          4        5        *6*       *7*       8      9         10        11          12  */
      KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,  KC_LPRN,  KC_RPRN, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,
      KC_TILD,  KC_MS_U,  KC_BTN3,  KC_BTN1, KC_BSLS,  KC_LBRC,  KC_RBRC, KC_PLUS, XXXXXXX, XXXXXXX,  KC_MINS,  KC_AMPR,
      KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2, KC_PIPE,  KC_LCBR,  KC_RCBR, KC_MINS, XXXXXXX, XXXXXXX,  KC_UNDS,  KC_SLSH,
      _______,  _______,  _______,  _______, _______,         _______,    _______, _______, _______,  _______,  KC_EQL
  ),
/* --------------------------------------------------------------------------------------------------------------------- */


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------------------.
 * | Reset | Debug |       |  RGB  | RGBMOD|       |       |       |  HUE+ |  HUE- |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |  SAT+ |  SAT- |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |  VAI+ |  VAI- |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * '-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    RESET,   DEBUG,   _______, RGB_TOG, RGB_MOD, _______, _______, RGB_HUI, RGB_HUD, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, RGB_SAI, RGB_SAD, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, RGB_VAI, RGB_VAD, _______, _______, _______,
    _______, _______, _______, _______, _______,       _______,    _______, _______, _______, _______, _______
),

  /* fn
 * ,-----------------------------------------------------------------------------------------------.
 * |PrntSC | PgUp  |       |       |       |       |       |   F1  |   F2  |   F3  |   F4  |  F5   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Home |PgDown |   End |       |       |       |       |   F6  |   F7  |   F8  |   F9  | F10   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |  F11  |  F12  |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |  Mute |  Vol- | Vol+  | Stop  |
 * '-----------------------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_planck_mit(
            KC_PSCR, KC_PGUP,   XXXXXXX, XXXXXXX, XXXXXXX,  _______,  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
            KC_HOME, KC_PGDOWN, KC_END,  XXXXXXX, XXXXXXX,  _______,  _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
            XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,  _______,  _______,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,
            _______, _______,   _______, _______, _______,        _______,      _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;

    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted || !state->pressed) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_SINGLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// *****************************************************************

// ** T_NEW **
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t ttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void t_finished(qk_tap_dance_state_t *state, void *user_data) {
    ttap_state.state = cur_dance(state);
    switch (ttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_T); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_T); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_T); register_code(KC_T);
        default: break;
    }
}

void t_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_T); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_T); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_T);
        default: break;

    }
    ttap_state.state = TD_NONE;
}
// ****************************************

// C copy
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t ctap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void c_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctap_state.state = cur_dance(state);
    switch (ctap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_C); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_C); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_C); register_code(KC_C);
        default: break;
    }
}

void c_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_C); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_C); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_C);
        default: break;

    }
    ctap_state.state = TD_NONE;
}
// ****************************************

// X cut
// ****************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_X); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_X); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
        default: break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X);
        default: break;

    }
    xtap_state.state = TD_NONE;
}
// ****************************************

// ENTER RALT
// ****************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
/*static td_tap_t entertap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void enter_finished(qk_tap_dance_state_t *state, void *user_data) {
    entertap_state.state = cur_dance(state);
    switch (entertap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ENTER); break;
        case TD_SINGLE_HOLD: register_code(KC_RALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_ENTER); register_code(KC_ENTER);
        default: break;
    }
}

void enter_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (entertap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ENTER); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_ENTER);
        default: break;

    }
    entertap_state.state = TD_NONE;
}*/
// ****************************************





// V paste
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t vtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void v_finished(qk_tap_dance_state_t *state, void *user_data) {
    vtap_state.state = cur_dance(state);
    switch (vtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_V); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_V); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_V); register_code(KC_V);
        default: break;
    }
}

void v_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (vtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_V); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_V); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_V);
        default: break;

    }
    vtap_state.state = TD_NONE;
}
// ****************************************

// L URL-Leiste
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
/*static td_tap_t ltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void l_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltap_state.state = cur_dance(state);
    switch (ltap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_L); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_L); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_L); register_code(KC_L);
        default: break;
    }
}

void l_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_L); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_L); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_L);
        default: break;

    }
    ltap_state.state = TD_NONE;
}*/
// ****************************************



// LEFT CTRL-LEFT
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
/*static td_tap_t lefttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void left_finished(qk_tap_dance_state_t *state, void *user_data) {
    lefttap_state.state = cur_dance(state);
    switch (lefttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LEFT); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_LEFT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LEFT); register_code(KC_LEFT);
        default: break;
    }
}

void left_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lefttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_LEFT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_LEFT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LEFT);
        default: break;

    }
    lefttap_state.state = TD_NONE;
}

// RIGHT CTRL-RIGHT
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t righttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void right_finished(qk_tap_dance_state_t *state, void *user_data) {
    righttap_state.state = cur_dance(state);
    switch (righttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_RIGHT); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_RIGHT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_RIGHT); register_code(KC_RIGHT);
        default: break;
    }
}

void right_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (righttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_RIGHT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_RIGHT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_RIGHT);
        default: break;

    }
    righttap_state.state = TD_NONE;
}*/

// W CTRL-W
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t wtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void w_finished(qk_tap_dance_state_t *state, void *user_data) {
    wtap_state.state = cur_dance(state);
    switch (wtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_W); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_W); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_W); register_code(KC_W);
        case TD_TRIPLE_SINGLE_TAP: register_code(KC_W); register_code(KC_W); register_code(KC_W);
        default: break;
    }
}

void w_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (wtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_W); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); unregister_code(KC_W); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_W); unregister_code(KC_W);
        case TD_TRIPLE_SINGLE_TAP: unregister_code(KC_W); unregister_code(KC_W); unregister_code(KC_W);
        default: break;

    }
    wtap_state.state = TD_NONE;
}


// Z CTRL-Z
// *****************************************************************
// Create an instance of 'td_tap_t' for the 't' tap dance.
/*static td_tap_t ztap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void z_finished(qk_tap_dance_state_t *state, void *user_data) {
    ztap_state.state = cur_dance(state);
    switch (ztap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_Z); break;
        case TD_DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_Z); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_Z); register_code(KC_Z);
        default: break;
    }
}

void z_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ztap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_Z); break;
        case TD_DOUBLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_Z); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_Z);
        default: break;

    }
    ztap_state.state = TD_NONE;
}
*/

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [T_NEW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_finished, t_reset),
  [C_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c_finished, c_reset),
  [V_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),
  [CTRL_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
  //[CTRL_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_finished, l_reset),
  //[LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_finished, left_reset),
  //[RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_finished, right_reset),
  [CTRL_W] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_finished, w_reset),
  //[CTRL_Z] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_finished, z_reset),
  //[ENTER_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter_finished, enter_reset),
  [TD_EXPLORER] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
  //[TD_ALTF4] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_F4)),
};

void keyboard_post_init_rgb(void) {
    rgb_matrix_mode(RGB_MATRIX_BREATHING);
}

// source https://www.bjoreman.com/diary/2021/2021-01-24.html
// and https://github.com/bjoreman/qmk_firmware/blob/master/keyboards/kyria/keymaps/bjoreman/config.h
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_A):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case D_LOWER:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case F_RAISE:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case J_RAISE:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case K_LOWER:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(KC_L):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_SCLN):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

/* fn
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * '-----------------------------------------------------------------------------------------------'
  */