#include QMK_KEYBOARD_H
#include "keymap_belgian.h"

#define MY_E RALT_T(KC_E)
#define MY_S LGUI_T(KC_S)
#define MY_D LALT_T(KC_D)
#define MY_K RALT_T(KC_K)
#define MY_L RGUI_T(KC_L)
#define MY_F LCTL_T(KC_F)
#define MY_J RCTL_T(KC_J)
#define MY_A LSFT_T(KC_A)
#define MY_M RSFT_T(KC_SCLN)

enum layer_number {
  _ALPHA  = 0,
  _LOWER  = 1,
  _RAISE  = 2,
  _ADJUST = 3,
  _GAMING = 4
};

enum combos
{
  CURLY_OPEN,
  CURLY_CLOSE,
  BRACKET_OPEN,
  BRACKET_CLOSE,
  ANGLE_OPEN,
  ANGLE_CLOSE,
  PAREN_OPEN,
  PAREN_CLOSE,
  CARET,
  DOLLARD
};

const uint16_t PROGMEM ze_combo[] = { KC_W, MY_E, COMBO_END };
const uint16_t PROGMEM io_combo[] = { KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM sd_combo[] = { MY_S, MY_D, COMBO_END };
const uint16_t PROGMEM kl_combo[] = { MY_K, MY_L, COMBO_END };
const uint16_t PROGMEM er_combo[] = { MY_E, KC_R, COMBO_END };
const uint16_t PROGMEM ui_combo[] = { KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM df_combo[] = { MY_D, MY_F, COMBO_END };
const uint16_t PROGMEM jk_combo[] = { MY_J, MY_K, COMBO_END };
const uint16_t PROGMEM fg_combo[] = { MY_F, KC_G, COMBO_END };
const uint16_t PROGMEM hj_combo[] = { KC_H, MY_J, COMBO_END };

combo_t key_combos[] = {
  [CURLY_OPEN]    = COMBO(sd_combo, BE_LCBR),
  [CURLY_CLOSE]   = COMBO(kl_combo, BE_RCBR),
  [BRACKET_OPEN]  = COMBO(ze_combo, BE_LBRC),
  [BRACKET_CLOSE] = COMBO(io_combo, BE_RBRC),
  [ANGLE_OPEN]    = COMBO(er_combo, BE_LABK),
  [ANGLE_CLOSE]   = COMBO(ui_combo, BE_RABK),
  [PAREN_OPEN]    = COMBO(df_combo, BE_LPRN),
  [PAREN_CLOSE]   = COMBO(jk_combo, BE_RPRN),
  [CARET]         = COMBO(fg_combo, BE_DCIR),
  [DOLLARD]       = COMBO(hj_combo, BE_DLR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   &  |   é  |   "  |   '  |   (  |                    |   §  |   è  |   !  |   ç  |   à  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  [   E  <   R  |   T  |                    |   Y  |   U  >   I  ]   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  {   D  (   F  ^   G  |-------.    ,-------|   H  $   J  )   K  }   L  |   ;  |  ù   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Tab  | ESC  | /Space  /       \Enter \  |BackSP| DEL  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_ALPHA] = LAYOUT(
      KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
      KC_NO, KC_Q, KC_W, MY_E, KC_R, KC_T,                             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
      KC_NO, MY_A, MY_S, MY_D, MY_F, KC_G,                             KC_H, MY_J, MY_K, MY_L, MY_M, KC_QUOT,
      KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,               KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
      KC_NO, LT(3,KC_TAB), LT(2,KC_ESC), LT(1,KC_SPC),          LT(1,KC_ENT), LT(2,KC_BSPC), LT(3,KC_DEL), KC_NO
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F 1 |  F 2 |  F 3 |  F 4 |      |                    |   /  |   7  |   8  |   9  |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F 5 |  F 6 |  F 7 |  F 8 |      |-------.    ,-------|   *  |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F 9 |  F10 |  F11 |  F12 |      |-------|    |-------|   0  |   1  |   2  |   3  |  .   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Tab  | ESC  | /Space  /       \Enter \  |BackSP| DEL  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(
      KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO,                 KC_KP_SLASH, KC_AMPR, KC_ASTR, KC_LPRN, KC_KP_MINUS, KC_NO,
      KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO,                 KC_KP_ASTERISK, KC_DLR, KC_PERC, KC_CIRC, KC_KP_PLUS, KC_NO,
      KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,   KC_NO, KC_RPRN, KC_EXLM, KC_AT, KC_HASH, KC_PDOT, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Home |PgDown| PgUp | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Tab  | ESC  | /Space  /       \Enter \  |BackSP| DEL  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO,   KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,   KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | Tab  | ESC  | /Space  /       \Enter \  |BackSP| DEL  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_ADJUST] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_WH_D, KC_WH_U, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1, KC_BTN3,               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

[_GAMING] = LAYOUT(
   KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                        KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
   KC_TAB, KC_A, KC_Z, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
   KC_LSFT, KC_Q, KC_S, KC_D, KC_F, KC_G,                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
   KC_LCTL, KC_W, KC_X, KC_C, KC_V, KC_B, KC_NO,            KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, DF(0),
          KC_LGUI, KC_NO, KC_SPC, KC_SPC,                       KC_ENT, KC_BSPC, KC_DEL, KC_NO
)
};

