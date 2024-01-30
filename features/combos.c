// 
// ┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
//
#include QMK_KEYBOARD_H
enum combos {
  QA_ESC,
  WS_HOME,
  SX_END,
  SD_WRDLFT,
  FD_WRDRGHT,
  RF_PGUP,
  FV_PGDWN,
};

const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM ws_combo[] = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM sx_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};

combo_t key_combos[] = {
  [QA_ESC] = COMBO(qa_combo, KC_ESC),
  [SD_WRDLFT] = COMBO(sd_combo, LCTL_T(KC_LEFT)),
  [FD_WRDRGHT] = COMBO(fd_combo, LCTL_T(KC_RIGHT)),
  [WS_HOME] = COMBO(ws_combo, KC_HOME),
  [SX_END] = COMBO(sx_combo, KC_END),
  [RF_PGUP] = COMBO(rf_combo, KC_PGUP),
  [FV_PGDWN] = COMBO(fv_combo, KC_PGDN),
};
