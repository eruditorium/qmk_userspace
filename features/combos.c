//
// ┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
//
#include QMK_KEYBOARD_H

enum combos {
  QA_ESC,
  PSCLN_TAB,

  RT_LEFTBRACE,
  FG_LEFTBRACKET,
  VB_LEFTPARENTHESIS,

  YU_RIGHTBRACE,
  HJ_RIGHTBRACKET,
  NM_RIGHTPARENTHESIS,

  DF_MINUS,
  CV_DOUBLEQUOTE,
  JK_UNDERSCORE,
  MCOMMA_QUOTE,

  ZX_UNDO,
  //AS_SELECTLINE
};

//const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM pscln_combo[] = {KC_P, KC_SCLN, COMBO_END};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {SHT_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, SHT_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM cv_combo[] = {ALT_C, KC_V, COMBO_END};
const uint16_t PROGMEM mc_combo[] = {KC_M, ALT_COMM, COMBO_END};

const uint16_t PROGMEM df_combo[] = {SHT_F, KC_D, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {SHT_J, KC_K, COMBO_END};

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[] = {
  [QA_ESC] = COMBO(qa_combo, KC_ESC),
  [PSCLN_TAB] = COMBO(pscln_combo, KC_TAB),

  [RT_LEFTBRACE] = COMBO(rt_combo, KC_LCBR),
  [FG_LEFTBRACKET] = COMBO(fg_combo, KC_LBRC),
  [VB_LEFTPARENTHESIS] = COMBO(vb_combo, KC_LPRN),

  [YU_RIGHTBRACE] = COMBO(yu_combo, KC_RCBR),
  [HJ_RIGHTBRACKET] = COMBO(hj_combo, KC_RBRC),
  [NM_RIGHTPARENTHESIS] = COMBO(nm_combo, KC_RPRN),

  [DF_MINUS] = COMBO(df_combo, KC_MINS),
  [JK_UNDERSCORE] = COMBO(jk_combo, KC_UNDS),

  [CV_DOUBLEQUOTE] = COMBO(cv_combo, KC_DQT),
  [MCOMMA_QUOTE] = COMBO(mc_combo, KC_QUOT),
  [ZX_UNDO] = COMBO(zx_combo, KC_UNDO),
  //[AS_SELECTLINE] = COMBO(as_combo, SELECTLINE)
};
