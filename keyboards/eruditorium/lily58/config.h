/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* QMK */
// Tap-hold configuration for home row mods.
#define TAPPING_TERM 160
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY


#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSACTION_IDS_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_TRANSPORT_MIRROR

#undef OLED_FONT_H
#undef OLED_FONT_WIDTH
#undef OLED_FONT_HEIGHT
#undef OLED_FONT_END

#define OLED_FONT_H "keyboards/lily58/keymaps/eruditorium/glcdfont.c"
#define OLED_FONT_WIDTH 8
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_END 0x9F


//----------------------------------------------------------------------------
// home row mods
//----------------------------------------------------------------------------
// https://sunaku.github.io/home-row-mods.html
// https://github.com/manna-harbour/qmk_firmware/pull/56
// https://github.com/manna-harbour/qmk_firmware/issues/29



/* Miryoku */
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)


// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// #define NO_ACTION_ONESHOT

// source: https://jasoncarloscox.com/blog/combo-mods/
// #define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
// #define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
// #define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger

// Add these flags to your rules.mk file:
// This enables Link Time Optimization, saving a significant amount of space. Because the Macro and Function features are incompatible with Link Time Optimization, disable those features in config.h:
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// Drashna, on QMK issue 3224, paraphrased
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Activate CAPS WORD by pressing Left Shift + Right Shift
// https://docs.qmk.fm/#/feature_caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// Activate by double tapping Left Shift:
// alternative: #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD