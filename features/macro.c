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
#define LOWER LT(_LOWER, KC_MINUS)
#define RAISE LT(_RAISE, KC_TAB)
#define ADJUST MO(_ADJUST)
#define QWERTY DF(_QWERTY)

