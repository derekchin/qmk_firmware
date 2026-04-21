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
        KC_TAB       , KC_Q           , KC_W          , KC_E                  , KC_R                    , KC_T  , KC_ESC    , KC_ENT , KC_Y   , KC_U  , KC_I   , KC_O   , KC_P               , KC_BSLS        ,
        CTL_T(KC_ESC), KC_A           , KC_S          , KC_D                  , KC_F                    , KC_G  , TO(_MOUSE), LCTL(KC_SLSH), KC_H   , KC_J  , KC_K   , KC_L   , LT(_MOUSE, KC_SCLN), CTL_T(KC_QUOTE),
        KC_LSFT      , KC_Z           , KC_X          , KC_C                  , KC_V                    , KC_B  , KC_N      , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_ESC       , GUI_T(KC_SPACE), MO(_LAUNCHERL), MO(_LAUNCHERR), LT(_LAUNCHERL, KC_SPACE), KC_ENT
    ),

    [_LAUNCHERL] = LAYOUT_split_3x6_3_ex2(
        _______      , KC_LSFT    , KC_LCTL, KC_LALT     , KC_LCMD      , KC_TAB     , KC_ESC , KC_ENT , _______, _______, _______, _______, _______, _______,
        _______      , TT(_ARROWS), _______, TT(_NUMBERS), TT(_SYMBOLSL), _______    , KC_LCTL, KC_RCTL, _______, _______, _______, _______, _______, _______,
        _______      , TT(_GAMING), _______, TT(_WINDOWS), TT(_ARROWS), _______, _______, _______, _______, _______, _______, _______,
        OSM(MOD_LGUI), KC_ENT     , _______, _______     , _______      , _______
    ),

    [_LAUNCHERR] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______      , _______      , _______, KC_LCTL   , KC_ESC , LSFT(KC_TAB), KC_RCMD      , KC_RALT, KC_RCTL, KC_RSFT   , _______   ,
        _______, _______, _______, _______      , _______      , _______, KC_LCTL   , KC_RCTL, KC_BSPC     , TT(_SYMBOLSR), _______, _______, TT(_MOUSE), TT(_MOUSE),
        _______, _______, _______, _______      , _______      , _______, TG(_MOUSE), _______, _______     , _______      , _______, _______,
        _______, _______, _______, OSM(MOD_RGUI), OSM(MOD_RALT), _______
    ),

    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______, _______, _______ , TO(_QWERTY), KC_RCTL, KC_EQUAL, KC_7, KC_8   , KC_9   , KC_ASTR, _______,
        _______, _______, _______, _______, _______, _______ , KC_LCTL    , KC_RCTL, KC_PLUS , KC_4, KC_5   , KC_6   , KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______ , KC_MINUS   , KC_1   , KC_2    , KC_3, KC_BSLS, _______,
        _______, _______, _______, _______, KC_0   , KC_EQUAL
    ),

    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
        _______, _______, HYPR(KC_F1), KC_MS_UP           , HYPR(KC_F2)        , _______, TO(_QWERTY), KC_RCTL, _______, _______   , _______   , KC_ACL0, _______, _______,
        _______, _______, KC_MS_LEFT , KC_MS_DOWN         , KC_MS_RIGHT        , _______, KC_LCTL    , KC_RCTL, _______, KC_MS_BTN1, KC_MS_BTN2, KC_ACL1, _______, _______,
        _______, _______, HYPR(KC_F3), _______            , HYPR(KC_F4)        , _______, _______    , _______, _______, KC_ACL2   , _______   , _______,
        _______, _______, _______    , LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), _______
    ),

    [_ARROWS] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______      , _______      , _______, TO(_QWERTY), KC_KB_VOLUME_UP  , _______, KC_PGDN, KC_PGUP, _______ , _______, _______,
        _______, _______, _______, _______      , _______      , _______, KC_KB_MUTE , KC_KB_VOLUME_DOWN, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______,
        _______, _______, _______, _______      , _______      , _______, _______    , _______          , _______, _______, _______, _______ ,
        _______, _______, _______, LGUI(KC_LBRC), LGUI(KC_RBRC), _______
    ),

    [_WINDOWS] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______, _______, _______, TO(_QWERTY), KC_RCTL, _______, _______     , _______           , _______           , KC_F3       , _______,
        _______, _______, _______, _______, _______, _______, KC_LCTL    , KC_RCTL, _______, _______     , _______           , LSFT(LGUI(KC_TAB)), LGUI(KC_TAB), _______,
        _______, _______, _______, _______, _______, _______, _______    , _______, _______, LGUI(KC_GRV), LSFT(LGUI(KC_GRV)), _______           ,
        _______, _______, _______, _______, _______, _______
    ),

    [_SYMBOLSL] = LAYOUT_split_3x6_3_ex2(
        KC_TILD , KC_EXLM , KC_AT  , KC_HASH, KC_DLR , KC_PERC, TO(_QWERTY), KC_RCTL , KC_CIRC , KC_AMPR, KC_ASTR      , KC_LPRN , KC_RPRN, KC_UNDS   ,
        KC_GRAVE, _______ , _______, _______, _______, _______, KC_LCTL    , KC_RCTL , KC_QUOT , KC_PLUS, RSFT(KC_QUOT), KC_LCBR , KC_RCBR, KC_KP_PLUS,
        _______ , KC_GRAVE, _______, _______, _______, _______, KC_UNDS    , KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC      , KC_MINUS,
        _______ , _______ , _______, _______, _______, _______
    ),

    [_SYMBOLSR] = LAYOUT_split_3x6_3_ex2(
        KC_TILD , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, TO(_QWERTY), KC_RCTL , KC_CIRC , KC_AMPR, KC_ASTR, KC_LPRN , KC_RPRN, KC_UNDS   ,
        KC_GRAVE, KC_TILD, KC_GRV , _______, KC_PIPE, _______, KC_LCTL    , KC_RCTL , _______ , _______, _______, KC_LCBR , KC_RCBR, KC_KP_PLUS,
        _______ , KC_BSLS, _______, _______, _______, _______, _______    , KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC, KC_MINUS,
        _______ , _______, _______, _______, _______, _______
    ),

    [_GAMING] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, KC_UP  , _______ , _______, TO(_QWERTY), _______ , _______, KC_U   , KC_I   , KC_O   , _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______    , _______ , _______, KC_J   , KC_K   , KC_SCLN, _______, _______,
        _______, _______, _______, _______, _______ , _______, _______    , KC_MINUS, _______, _______, _______, _______,
        _______, _______, KC_UP  , _______, _______ , _______
    )
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

