/* Copyright 2022
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "process_combo.h"
#include "action_layer.h"

#include "../../../../users/derek/derek.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_TAB,        KC_Q, KC_W,          KC_E,          KC_R,            KC_T,           KC_Y,                   KC_U,                     KC_I,          KC_O,         KC_P,                KC_BSLS,
        CTL_T(KC_ESC), KC_A, KC_S,          KC_D,          KC_F,            KC_G,           KC_H,                   KC_J,                     KC_K,          KC_L,         LT(_MOUSE, KC_SCLN), CTL_T(KC_QUOTE),
        KC_LSFT,       KC_Z, KC_X,          KC_C,          KC_V,            KC_B,           KC_N,                   KC_M,                     KC_COMM,       KC_DOT,       KC_SLSH,             KC_RSFT,
                             KC_ESC, QK_LEAD, GUI_T(KC_SPACE), MO(_LAUNCHERL), MO(_LAUNCHERR), KC_SPACE, LCTL(KC_SLSH), KC_ENT
    ),

    [_LAUNCHERL] = LAYOUT(
        KC_TRNS, KC_LSFT,     KC_LCTL,        KC_LALT,      KC_LCMD,       KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MO(_ARROWS), MO(_TABWINDOW), MO(_NUMBERS), MO(_SYMBOLSL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,     KC_TRNS,        KC_TRNS,      MO(_ARROWS),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TO(_QWERTY)      , _______     , _______, _______     , _______      , _______, _______, _______
    ),

    [_LAUNCHERR] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_TAB),  KC_RCMD,       KC_RALT, KC_RCTL, KC_RSFT,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC     ,  MO(_SYMBOLSR), KC_TRNS, KC_TRNS, TT(_MOUSE), TT(_MOUSE),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_MOUSE),    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
        TO(_QWERTY)      , _______     , _______, _______     , _______      , _______, _______, _______
    ),

    [_NUMBERS] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQUAL, KC_7, KC_8,     KC_9,   KC_ASTR, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS,  KC_4, KC_5,     KC_6,   KC_PLUS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINUS, KC_1, KC_2,     KC_3,   KC_BSLS, KC_TRNS,
        TO(_QWERTY)      , _______     , _______, _______     , _______      , _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,     KC_MS_UP,   KC_TRNS,     KC_TRNS, KC_TRNS,             KC_TRNS,             KC_TRNS,    KC_ACL0, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_TRNS,             KC_MS_BTN1,          KC_MS_BTN2, KC_ACL1, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,             KC_TRNS,             KC_TRNS,    KC_ACL2, KC_TRNS, KC_TRNS,
        TO(_QWERTY), _______, _______, _______    , LGUI(LSFT(KC_LBRC)),    LGUI(LSFT(KC_RBRC)) , _______, _______
    ),

    [_ARROWS] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_PGDN,       KC_PGUP, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT,       KC_DOWN,       KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        TO(_QWERTY)      , _______     , _______, _______     , _______      , _______, _______, _______
    ),

    [_TABWINDOW] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,       LGUI(KC_EQL),   KC_TRNS, KC_TRNS,             KC_TRNS,             KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,       LGUI(KC_MINUS), KC_TRNS, LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,        KC_TRNS, KC_TRNS,             KC_TRNS,             KC_TRNS,
                          TO(_QWERTY), KC_TRNS, KC_UP,   KC_TRNS, LGUI(KC_0), KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_SYMBOLSL] = LAYOUT(
        KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,       KC_LPRN, KC_RPRN, KC_UNDS,
        KC_GRAVE, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_PLUS,  RSFT(KC_QUOT), KC_LCBR, KC_RCBR, KC_KP_PLUS,
        KC_TRNS,  KC_GRAVE, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_MINUS, KC_EQUAL,      KC_LBRC, KC_RBRC, KC_MINUS,
        TO(_QWERTY)      , _______     , _______, _______     , _______      , _______, _______, _______
    ),

    [_SYMBOLSR] = LAYOUT(
        KC_TILD,  KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_UNDS,
        KC_GRAVE, KC_TILD, KC_GRV,   KC_TRNS, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_LCBR, KC_RCBR, KC_KP_PLUS,
        KC_TRNS,  KC_BSLS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC, KC_MINUS,
        TO(_QWERTY)      , _______     , _______, _______     , _______      , _______, _______, _______
    ),

    [_GAMING] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_U,    KC_I,    KC_O,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_J,    KC_K,    KC_L,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

const uint16_t PROGMEM key_esc[]   = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM km_picker[] = {KC_J, KC_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(key_esc, KC_ESC),
    COMBO(km_picker, KC_F20),
};

