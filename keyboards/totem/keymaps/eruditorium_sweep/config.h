#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT


//#define TAPPING_TERM 170
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

#define TAPPING_TERM_PER_KEY

// https://precondition.github.io/home-row-mods
#define TAPPING_FORCE_HOLD  // make tap-then-hold _not_ do key auto repeat
#define TAPPING_FORCE_HOLD_PER_KEY  // ... but do it for some!
#define HOLD_ON_OTHER_KEY_PRESS  // obsolete my LT_NUM_BSPC
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY  // ... but not for mod-taps!
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD  // I don't think this works for me, hence I rolled my own implementation.


// source: https://jasoncarloscox.com/blog/combo-mods/
#define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger
