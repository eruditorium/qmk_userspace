#pragma once

// from https://precondition.github.io/home-row-mods
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// source https://www.bjoreman.com/diary/2021/2021-01-24.html
// and https://github.com/bjoreman/qmk_firmware/blob/master/keyboards/kyria/keymaps/bjoreman/config.h
#define TAPPING_TERM_PER_KEY
#define LONG_TAPPING_TERM 500

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
