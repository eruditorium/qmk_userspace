//
// ┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
//
#include QMK_KEYBOARD_H
enum combos {
  QA_ESC,

  RT_LEFTBRACE,
  FG_LEFTBRACKET,
  VB_LEFTPARENTHESIS,

  YU_RIGHTBRACE,
  HJ_RIGHTBRACKET,
  NM_RIGHTPARENTHESIS,

  GB_MINUS,
  FV_DOUBLEQUOTE,
  HN_UNDERSCORE,
  JM_QUOTE
};

const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {SHT_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, SHT_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};

const uint16_t PROGMEM fv_combo[] = {SHT_F, KC_V, COMBO_END};
const uint16_t PROGMEM jm_combo[] = {SHT_J, KC_M, COMBO_END};

combo_t key_combos[] = {
  [QA_ESC] = COMBO(qa_combo, KC_ESC),

  [RT_LEFTBRACE] = COMBO(rt_combo, KC_LCBR),
  [FG_LEFTBRACKET] = COMBO(fg_combo, KC_LBRC),
  [VB_LEFTPARENTHESIS] = COMBO(vb_combo, KC_LPRN),

  [YU_RIGHTBRACE] = COMBO(yu_combo, KC_RCBR),
  [HJ_RIGHTBRACKET] = COMBO(hj_combo, KC_RBRC),
  [NM_RIGHTPARENTHESIS] = COMBO(nm_combo, KC_RPRN),

  [GB_MINUS] = COMBO(gb_combo, KC_MINS),
  [HN_UNDERSCORE] = COMBO(hn_combo, KC_UNDS),

  [FV_DOUBLEQUOTE] = COMBO(fv_combo, KC_DQT),
  [JM_QUOTE] = COMBO(jm_combo, KC_QUOT),
};
