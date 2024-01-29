// 
// ┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
//
enum combos {
  QW_ESC,
  UL_HOME,
  UR_END,
  DL_WRDLFT,
  DR_WRDRGHT,
  UD_PGUP,
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM dl_combo[] = {KC_DOWN, KC_LEFT, COMBO_END};
const uint16_t PROGMEM dr_combo[] = {KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM ul_combo[] = {KC_UP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM ur_combo[] = {KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM ud_combo[] = {KC_UP, KC_DOWN, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC),
  [DL_WRDLFT] = COMBO(dl_combo, LCTL_T(KC_LEFT)),
  [DR_WRDRGHT] = COMBO(dr_combo, LCTL_T(KC_RIGHT)),
  [UL_HOME] = COMBO(ul_combo, KC_HOME),
  [UR_END] = COMBO(ur_combo, KC_END),
  [UD_PGUP] = COMBO(ud_combo, KC_PGUP),
};
