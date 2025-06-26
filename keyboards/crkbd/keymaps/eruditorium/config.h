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
#pragma once

#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//----------------------------------------------------------------------------
// home row mods
//----------------------------------------------------------------------------
// https://sunaku.github.io/home-row-mods.html
// https://github.com/manna-harbour/qmk_firmware/pull/56
// https://github.com/manna-harbour/qmk_firmware/issues/29

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 225
//#define TAPPING_TERM_PER_KEY
//#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define QUICK_TAP_TERM 150
// #define QUICK_TAP_TERM_PER_KEY


#define COMBO_COUNT 10

// Activate CAPS WORD by pressing Left Shift + Right Shift
// https://docs.qmk.fm/#/feature_caps_word
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// Activate by double tapping Left Shift:-
//alternative:
//#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Holding Shift while Caps Word is active inverts the shift state.
//#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
// #define CAPS_WORD_IDLE_TIMEOUT 5000

// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE

// source: https://jasoncarloscox.com/blog/combo-mods/
// #define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
// #define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
// #define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger

#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_LIMIT_VAL 40
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#undef OLED_FONT_H
#undef OLED_FONT_WIDTH
#undef OLED_FONT_HEIGHT
#undef OLED_FONT_END

#define OLED_FONT_H "features/glcdfont.c"
#define OLED_FONT_WIDTH 8
#define OLED_FONT_HEIGHT 8
//#define OLED_FONT_START 65  // 'A'
//#define OLED_FONT_END   87  // 'W'
//#define OLED_FONT_WIDTH 8   // 8x8
#define OLED_FONT_END 0x9F

#define OLED_DISABLE_TIMEOUT
#define OLED_DISABLE_SCROLL

// Add these flags to your rules.mk file:
// This enables Link Time Optimization, saving a significant amount of space.
// Because the Macro and Function features are incompatible with Link Time Optimization,
// disable those features in config.h:
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// Drashna, on QMK issue 3224, paraphrased
#define NO_ACTION_ONESHOT
#define DISABLE_LEADER

// configure the amount of keys a combo can be composed of
#define EXTRA_SHORT_COMBOS
