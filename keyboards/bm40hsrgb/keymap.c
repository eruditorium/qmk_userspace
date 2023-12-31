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
  CTRL_W,
  TD_EXPLORER
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
// For the W tap dance. Put it here so it can be used in any keymap
void w_finished(qk_tap_dance_state_t *state, void *user_data);
void w_reset(qk_tap_dance_state_t *state, void *user_data);

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};

// from github.com/WemansG90
#define KC_CAPW LCTL(LALT(KC_2))    // Capture whole screen
#define KC_CAPA LCTL(LALT(KC_3))    // Capture active window
#define KC_CAPP LCTL(LALT(KC_4))    // Capture portion of screen
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define DEGREE UC(0xC2B0)

#define FN_DEL LT(MO(_FN), KC_DEL)

#define ESC_RALT RALT_T(KC_ESC)

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
	        switch (get_highest_layer(layer_state|default_layer_state)) {
		        case _LOWER:
			        rgb_matrix_set_color(i, 50, 0, 0);
			        break;
		        case _RAISE:
			        rgb_matrix_set_color(i, 0, 40, 50);
			        break;
		        case _FN:
			        rgb_matrix_set_color(i, 0, 0, 50);
			        break;
		        case _ADJUST:
			        rgb_matrix_set_color(i, 0, 50, 1.9);
			        break;	
                default:
                    break;
	        }
        }   
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc* |   Q  |  W*  |   E  |   R  |  T*  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  A   |  S   |  D   |  F   |   G  |   H  |  J   |  K   |  L   |  ;   |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift*|  Z   |  X*  |  C*  |  V+  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter*|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI* | FN*  | Alt  | Lower|   Space*    | Raise| Left |  Up  | Down |Right |
 * '-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
 /*    1                2                   3               4             5            *6*         *7*       8        9        10         11          12  */
    ESC_RALT,       KC_Q,             TD(CTRL_W),     KC_E,          KC_R,         TD(T_NEW),    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSPC,
    KC_TAB,         KC_A,             KC_S,           KC_D,          KC_F,         KC_G,         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
    LSFT_T(KC_DEL), KC_Z,             TD(CTRL_X),     TD(C_COPY),    TD(V_PASTE),  KC_B,         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   RSFT_T(KC_ENT), KC_LCTL,        TD(TD_EXPLORER),  FN_DEL,         KC_LALT,       LOWER,               KC_SPC,          RAISE,    KC_LEFT,  KC_DOWN,  KC_UP,     KC_RIGHT
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |  _   |  +   |  {   |   }  |  \   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |  -   |  =   |  [   |   ]  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      | Lower|    Space    | Raise|      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_mit(
      _______, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     _______, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_UNDS,  KC_PLUS, KC_LCBR,  KC_RCBR,  KC_BSLS, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  _______, 
      _______, _______, _______, _______, _______,      KC_SPC,        _______,  _______,  _______,  _______, _______
  ),

/* Raise
  * ,-----------------------------------------------------------------------------------.
  * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |  UP  |      |      |      |      |   _  |   +  |   {  |   }  |   |  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | LEFT | DOWN |RIGHT |      |      |      |   -  |   =  |   [  |  ]   |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      | Lower|    Space    | Raise|      |      |      |      |            
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_mit(
      _______,  KC_EXLM, KC_AT,     KC_HASH,    KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,    KC_ASTR,     KC_LPRN, KC_RPRN, _______,
      _______,  XXXXXXX, KC_MS_U,   XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UNDS,    KC_PLUS,     KC_LCBR, KC_RCBR, KC_PIPE, 
      _______,  KC_MS_L, KC_MS_D,   KC_MS_R,    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,    KC_EQL,      KC_LBRC, KC_RBRC, _______, 
      _______,  _______, _______,   _______,    _______,        KC_SPC,       _______,    _______,     _______, _______, _______
  ),
 

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |RGRMOD|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, QK_BOOT,   DEBUG, RGB_TOG, RGB_MOD,  RGB_HUI,  RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD,  _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

  /* fn
  * ,-----------------------------------------------------------------------------------.
  * |PrntSc|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      | F11  | F12  |      |      |      |      |      |      |      | MS_U |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      | MS_D |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    Space    |      | Mute | Vol- | Vol+ | Stop |
  * `-----------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_planck_mit(
      KC_PSCR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______, 
      _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,  XXXXXXX,   KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  KC_MS_U, _______, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_MS_D, _______,
      _______, _______, _______, _______, _______,       KC_SPC,        _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP
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

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [T_NEW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_finished, t_reset),
  [C_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c_finished, c_reset),
  [V_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),
  [CTRL_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
  [CTRL_W] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_finished, w_reset),
  [TD_EXPLORER] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
};

void keyboard_post_init_rgb(void) {
    rgb_matrix_mode(RGB_MATRIX_HUE_BREATHING);
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
