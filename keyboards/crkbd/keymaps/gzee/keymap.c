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

#include QMK_KEYBOARD_H
#include "keymap_belgian.h"

enum casing{
    CASE_NONE = 0,
    CASE_CAMEL = 1,
    CASE_PASCAL = 2,
    CASE_SNAKE = 3
};

enum my_keycodes {
    CKC_NONE = SAFE_RANGE,
    CKC_CAMEL,
    CKC_PASCAL,
    CKC_SNAKE
};
enum casing currentCasing = CASE_CAMEL;

enum layer_number {
  _ALPHA  = 0,
  _FUN  = 1,
  _SYMNAV  = 2
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

const uint16_t PROGMEM ze_combo[] = { KC_W, RALT_T(KC_E), COMBO_END };
const uint16_t PROGMEM io_combo[] = { KC_I, KC_O, COMBO_END };
const uint16_t PROGMEM sd_combo[] = { LGUI_T(KC_S), LALT_T(KC_D), COMBO_END };
const uint16_t PROGMEM kl_combo[] = { RALT_T(KC_K), RGUI_T(KC_L), COMBO_END };
const uint16_t PROGMEM er_combo[] = { RALT_T(KC_E), KC_R, COMBO_END };
const uint16_t PROGMEM ui_combo[] = { KC_U, KC_I, COMBO_END };
const uint16_t PROGMEM df_combo[] = { LALT_T(KC_D), LCTL_T(KC_F), COMBO_END };
const uint16_t PROGMEM jk_combo[] = { RCTL_T(KC_J), RALT_T(KC_K), COMBO_END };
const uint16_t PROGMEM fg_combo[] = { LCTL_T(KC_F), KC_G, COMBO_END };
const uint16_t PROGMEM hj_combo[] = { KC_H, RCTL_T(KC_J), COMBO_END };

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
// ALPHA
// ,-----------------------------------------.                    ,-----------------------------------------.
// |      |   Q  |   W  [   E  <   R  |   T  |                    |   Y  |   U  >   I  ]   O  |   P  |      |
// |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// |      |   A  |   S  {   D  (   F  ^   G  |                    |   H  $   J  )   K  }   L  |   M  |      |
// |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// |      |   Z  |   X  |   C  |   V  |   B  |-------.    ,-------|   N  |   ,  |   ;  |   :  |   =  |      |
// `-----------------------------------------/       /     \      \-----------------------------------------'
//                          | Tab  | Esc  | / Space /       \Enter \  | <--  | DEL  |
//                          | L3   | L2   |/  L1   /         \ L1   \ | L2   | L3   |
//                          `---------------------'           '------''-------------'
//
 [_ALPHA] = LAYOUT(
      XXXXXXX, KC_Q, KC_W, RALT_T(KC_E), KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
      XXXXXXX, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RSFT_T(KC_SCLN), XXXXXXX,
      RGB_MOD, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
      LT(3,KC_TAB), LT(2,KC_ESC), LT(1,KC_SPC), LT(1,KC_ENT), LT(2,KC_BSPC), LT(3,KC_DEL)
),
// FUNUM
// ,-----------------------------------------.                    ,-----------------------------------------.
// |      |  F1  |  F2  |  F3  |  F4  |      |                    |   /  |   7  |   8  |   9  |   -  |      |
// |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// |      |  F5  |  F6  |  F7  |  F8  |      |                    |   *  |   4  |   5  |   6  |   +  |      |
// |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// |      |  F9  |  F10 |  F11 |  F12 |      |-------.    ,-------|   0  |   1  |   2  |   3  |   .  |      |
// `-----------------------------------------/       /     \      \-----------------------------------------'
//                          | Tab  | Esc  | / Space /       \Enter \  | <--  | DEL  |
//                          | L3   | L2   |/  L1   /         \ L1   \ | L2   | L3   |
//                          `---------------------'           '------''-------------'
//
 [_FUN] = LAYOUT(
      XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX, KC_KP_SLASH, KC_AMPR, KC_ASTR, KC_LPRN, KC_KP_MINUS, XXXXXXX,
      XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, KC_KP_ASTERISK, KC_DLR, KC_PERC, KC_CIRC, KC_KP_PLUS, XXXXXXX,
      XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, KC_RPRN, KC_EXLM, KC_AT, KC_HASH, KC_KP_DOT, XXXXXXX,
      LT(3,KC_TAB), LT(2,KC_ESC), LT(1,KC_SPC), LT(1,KC_ENT), LT(2,KC_BSPC), LT(3,KC_DEL)
),
// SYMNAV
// ,-----------------------------------------.                    ,-----------------------------------------.
// |      |      |      |      |      |      |                    | Home |PgDown| Pg Up| End  |      |      |
// |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// |      |      |      |      |      |      |                    | Left | Down |  Up  | Right|      |      |
// |------+------+------+------+------+------|                    |------+------+------+------+------+------|
// |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
// `-----------------------------------------/       /     \      \-----------------------------------------'
//                          | Tab  | Esc  | / Space /       \Enter \  | <--  | DEL  |
//                          | L3   | L2   |/  L1   /         \ L1   \ | L2   | L3   |
//                          `---------------------'           '------''-------------'
//
 [_SYMNAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      LT(3,KC_TAB), LT(2,KC_ESC), LT(1,KC_SPC), LT(1,KC_ENT), LT(2,KC_BSPC), LT(3,KC_DEL)
)
};

//bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//    for (uint8_t i = led_min; i < led_max; i++) {
//    //for (uint8_t i = 0; i < 27; i++) {
//        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
//            //rgb_matrix_set_color(i, RGB_YELLOW);
//            rgb_matrix_set_color(i, 113, 219, 212);
//        }
//        else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
//            rgb_matrix_set_color(i, RGB_RED);
//        }
//        else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
//            rgb_matrix_set_color(i, RGB_BLUE);
//        }
//        else{
//            //rgb_matrix_set_color(i, RGB_GREEN);
//            rgb_matrix_set_color(i, 199, 36, 177);
//        }
//        //         switch(get_highest_layer(layer_state|default_layer_state)) {
//        //             case 2:
//        //                 rgb_matrix_set_color(i, RGB_BLUE);
//        //                 break;
//        //             case 1:
//        //                 rgb_matrix_set_color(i, RGB_YELLOW);
//        //                 break;
//        //             default:
//        //                 rgb_matrix_set_color(i, RGB_AZURE);
//        //                 break;
//        //         }
//    }
//    return false;
//}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool delkey_registered;
    switch (keycode) {
        case CKC_NONE:
            currentCasing = CASE_NONE;
            return false;
        case CKC_CAMEL:
            currentCasing = CASE_CAMEL;
            return false;
        case KC_SLSH:
            //          replace key
            //          if(record->event.pressed){
            //            register_code(KC_MINUS);
            //          }
            //          else{
            //            unregister_code(KC_MINUS);
            //          }

            if(record->event.pressed){
                delkey_registered = true;
            }
            return false;
         default:
            if(delkey_registered)
            {
                if(record->event.pressed)
                {
                    add_mods(MOD_MASK_SHIFT) ;
                    //register_code16(S(keycode));
                }
                else{
                    delkey_registered = false;
                    //unregister_code16(S(keycode));
                    del_mods(MOD_MASK_SHIFT);
                }
                return true;
            }

            return true;
    }
}
//https://docs.qmk.fm/feature_macros#register-code-kc
//https://docs.qmk.fm/feature_advanced_keycodes#shift-backspace-for-delete
//TODO: Handle simultaneous key presses
