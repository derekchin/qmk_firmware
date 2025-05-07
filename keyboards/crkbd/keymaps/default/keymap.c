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

#include "action_layer.h"
#include "process_combo.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { _QWERTY, _LAUNCHERL, _LAUNCHERR, _NUMBERS, _MOUSE, _ARROWS, _WINDOWS, _SYMBOLSL, _SYMBOLSR, _GAMING };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x6_3_ex2(
        KC_TAB,        KC_Q,    KC_W, KC_E, KC_R,   KC_T,            KC_ESC,         KC_ENT,                 KC_Y,                     KC_U,    KC_I,   KC_O,    KC_P,                KC_BSLS,
        CTL_T(KC_ESC), KC_A,    KC_S, KC_D, KC_F,   KC_G,            TO(_MOUSE),     KC_BSPC,                KC_H,                     KC_J,    KC_K,   KC_L,    LT(_MOUSE, KC_SCLN), CTL_T(KC_QUOTE),
                       KC_LSFT, KC_Z, KC_X, KC_C,   KC_V,            KC_B,           KC_N,                   KC_M,                     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                            KC_ESC, GUI_T(KC_SPACE), MO(_LAUNCHERL), LT(_LAUNCHERR,KC_BSPC), LT(_LAUNCHERL, KC_SPACE), KC_F20
    ),

    [_LAUNCHERL] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_LSFT,     KC_LCTL,     KC_LALT,      KC_LCMD,       KC_TAB,  KC_ESC,      KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, TT(_ARROWS), KC_TRNS,     TT(_NUMBERS), TT(_SYMBOLSL), KC_TRNS, KC_LCTL,     KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS,     TT(_GAMING), KC_TRNS,      TT(_WINDOWS),  KC_TRNS, TG(_ARROWS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                         OSM(MOD_LGUI), KC_ENT,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_LAUNCHERR] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_ESC,        LSFT(KC_TAB),  KC_RCMD,       KC_RALT, KC_RCTL, KC_RSFT,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_RCTL,       KC_TRNS,       TT(_SYMBOLSR), KC_TRNS, KC_TRNS, TT(_MOUSE), TT(_MOUSE),
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_MOUSE),    KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_RGUI), OSM(MOD_RALT), KC_TRNS
    ),

    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_QWERTY), KC_RCTL,  KC_EQUAL, KC_7,    KC_8, KC_9,    KC_ASTR, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL,     KC_RCTL,  KC_PLUS,  KC_4,    KC_5, KC_6,    KC_PLUS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_MINUS, KC_1,     KC_2,    KC_3, KC_BSLS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_0,     KC_EQUAL
    ),

    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_TRNS, HYPR(KC_F1), KC_MS_UP,    HYPR(KC_F2), KC_TRNS,     TO(_QWERTY), KC_RCTL,             KC_TRNS,             KC_TRNS,    KC_TRNS,    KC_ACL0, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, KC_TRNS,     KC_LCTL,     KC_RCTL,             KC_TRNS,             KC_MS_BTN1, KC_MS_BTN2, KC_ACL1, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS,     HYPR(KC_F3), KC_TRNS,     HYPR(KC_F4), KC_TRNS,     KC_TRNS,             KC_TRNS,             KC_TRNS,    KC_ACL2,    KC_TRNS, KC_TRNS,
                                                    KC_TRNS,     KC_TRNS,     KC_TRNS,     LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), KC_TRNS
    ),

    [_ARROWS] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_QWERTY), KC_KB_VOLUME_UP,   KC_TRNS,       KC_PGDN, KC_PGUP, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KB_MUTE,  KC_KB_VOLUME_DOWN, KC_LEFT,       KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,           KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,     LGUI(KC_LBRC),     LGUI(KC_RBRC), KC_TRNS
    ),

    [_WINDOWS] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_QWERTY), KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,            KC_F3,        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL,     KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS,      LSFT(LGUI(KC_TAB)), LGUI(KC_TAB), KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_GRV), LSFT(LGUI(KC_GRV)), KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_SYMBOLSL] = LAYOUT_split_3x6_3_ex2(
        KC_TILD,  KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, TO(_QWERTY), KC_RCTL, KC_CIRC,  KC_AMPR,  KC_ASTR,       KC_LPRN, KC_RPRN,  KC_UNDS,
        KC_GRAVE, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL,     KC_RCTL, KC_QUOT,  KC_PLUS,  RSFT(KC_QUOT), KC_LCBR, KC_RCBR,  KC_KP_PLUS,
                  KC_TRNS, KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_UNDS, KC_MINUS, KC_EQUAL, KC_LBRC,       KC_RBRC, KC_MINUS,
                                              KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS
    ),

    [_SYMBOLSR] = LAYOUT_split_3x6_3_ex2(
        KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, TO(_QWERTY), KC_RCTL, KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_UNDS,
        KC_GRAVE, KC_TILD, KC_GRV,  KC_TRNS, KC_PIPE, KC_TRNS, KC_LCTL,     KC_RCTL, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_LCBR, KC_RCBR,  KC_KP_PLUS,
                  KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC, KC_MINUS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS
    ),

    [_GAMING] = LAYOUT_split_3x6_3_ex2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, TO(_QWERTY), KC_TRNS, KC_TRNS,  KC_U,    KC_I,    KC_O,    KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_J,    KC_K,    KC_SCLN, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_MINUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS,  KC_TRNS, KC_UP,       KC_TRNS, KC_TRNS,  KC_TRNS
    ),
  };

const uint16_t PROGMEM key_esc[]   = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM km_picker[] = {KC_J, KC_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(key_esc, KC_ESC),
    COMBO(km_picker, KC_F20),
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
}

// #ifdef ENCODER_MAP_ENABLE
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//   [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
//   [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
//   [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
//   [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
// };
// #endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case 9:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 8:
                rgb_matrix_set_color(i, RGB_PURPLE);
                break;
            case 7:
                rgb_matrix_set_color(i, RGB_PURPLE);
                break;
            case 6:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case 5:
                rgb_matrix_set_color(i, RGB_PINK);
                break;
            case 4:
                rgb_matrix_set_color(i, RGB_ORANGE);
                break;
            case 3:
                rgb_matrix_set_color(i, RGB_GREEN);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_CYAN);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_CYAN);
                break;
            default:
                // rgb_matrix_set_color(i, RGB_AZURE);
                break;
        }
    }
    return false;
}

