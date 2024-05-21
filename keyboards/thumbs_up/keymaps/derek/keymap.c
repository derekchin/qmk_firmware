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

// #include "keymap_steno.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LAUNCHERL,
    _LAUNCHERR,
    _NUMBERS,
    _MOUSE,
    _ARROWS,
    _WINDOWS1,
    _WINDOWS2,
    _SYMBOLSL,
    _SYMBOLSR,
    _CMDNUM,
    // _PLOVER,
    // _STENO_TXBOLT,
    // These are the same plover/txbolt layers
    // with the letters moved to the top two rows
    // and the number bar pushed down to the third row.
    // _PLOVER2,
    // _STENO_TXBOLT2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    KC_TAB,         KC_Q,   KC_W,               KC_E,               KC_R,               KC_T,    KC_Y,     KC_U,                        KC_I,                       KC_O,               KC_P,                   KC_BSLS,
    CTL_T(KC_ESC),  KC_A,   KC_S,               KC_D,               KC_F,               KC_G,    KC_H,     KC_J,                        KC_K,                       KC_L,               LT(_MOUSE, KC_SCLN),  CTL_T(KC_QUOTE),
    KC_LSFT,        KC_Z,   KC_X,               KC_C,               KC_V,               KC_B,    KC_N,     KC_M,                        KC_COMM,                    KC_DOT,             KC_SLSH,                KC_RSFT,
                            CTL_T(KC_F18),      ALT_T(KC_F19),      GUI_T(KC_SPACE),    MO(_LAUNCHERL),    LT(_LAUNCHERR,KC_BSPC),    LT(_LAUNCHERL, KC_SPACE),   ALT_T(KC_F20),      CTL_T(KC_F21)
    ),

    [_LAUNCHERL] = LAYOUT(
    KC_TRNS,    KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LCMD,        KC_TAB,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    MO(_ARROWS),    KC_TRNS,        MO(_NUMBERS),   MO(_SYMBOLSL),  MO(_CMDNUM),    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,        KC_TRNS,        MO(_WINDOWS2),  MO(_WINDOWS1),  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,
                OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_ENT,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS

    ),

    [_LAUNCHERR] = LAYOUT(
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,          LSFT(KC_TAB),          KC_RCMD,        KC_RALT,  KC_RCTL,  KC_RSFT,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,          KC_TRNS,          MO(_SYMBOLSR),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,          KC_TRNS,          KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,          OSM(MOD_RGUI),    OSM(MOD_RALT),  KC_TRNS,  KC_TRNS

    ),

    [_NUMBERS] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_EQUAL, KC_7,    KC_8,     KC_9,     KC_ASTR,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_PLUS,  KC_4,    KC_5,     KC_6,     KC_PLUS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_MINUS, KC_1,    KC_2,     KC_3,     KC_BSLS,   KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_0,    KC_EQUAL, KC_TRNS
    ),

    [_MOUSE] = LAYOUT(
    KC_TRNS,  KC_TRNS,   HYPR(KC_F1), KC_MS_UP,   HYPR(KC_F2),   KC_TRNS,           KC_TRNS,                 KC_TRNS,                    KC_TRNS,     KC_ACL0,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   KC_TRNS,           KC_TRNS,                 KC_MS_BTN1,                 KC_MS_BTN2,  KC_ACL1,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   HYPR(KC_F3), KC_TRNS,    HYPR(KC_F4),   KC_TRNS,           KC_TRNS,                 KC_TRNS,                    KC_TRNS,     KC_ACL2,   KC_TRNS,   KC_TRNS,
                         KC_ENTER,    KC_TRNS,    KC_TRNS,       KC_TRNS,           LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)),    KC_TRNS,     KC_TRNS
    ),

    [_ARROWS] = LAYOUT(
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,          KC_TRNS,              KC_PGDN,            KC_PGUP,        KC_TRNS,     KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,          KC_LEFT,              KC_DOWN,            KC_UP,          KC_RIGHT,    KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,          KC_TRNS,              KC_TRNS,            KC_TRNS,        KC_TRNS,     KC_TRNS,  KC_TRNS,
                         KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,          LGUI(KC_LBRC),    LGUI(KC_RBRC),  KC_TRNS,        KC_TRNS
    ),


    [_WINDOWS1] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          KC_TRNS,            LCTL(LALT(KC_U)),   LCTL(LALT(KC_UP)),      LCTL(LALT(KC_I)), KC_TRNS,          KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          LCTL(LALT(KC_E)),   LCTL(LALT(KC_D)),   LCTL(LALT(KC_F)),       LCTL(LALT(KC_G)), LCTL(LALT(KC_T)), KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          KC_TRNS,            LCTL(LALT(KC_J)),   LCTL(LALT(KC_DOWN)),    LCTL(LALT(KC_K)),  LSFT(LGUI(KC_GRV)),          KC_TRNS,
              KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          KC_TRNS,            KC_TRNS,            KC_TRNS
    ),


    [_WINDOWS2] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          KC_TRNS,   LCTL(LALT(KC_U)),      LCTL(LALT(KC_UP)),      LCTL(LALT(KC_I)),       KC_F3,    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          KC_TRNS,   LCTL(LALT(KC_LEFT)),   LCTL(LALT(KC_ENTER)),   LCTL(LALT(KC_RIGHT)),   LGUI(KC_GRV),    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,          KC_TRNS,   LCTL(LALT(KC_J)),      LCTL(LALT(KC_DOWN)),    LCTL(LALT(KC_K)),       LSFT(LGUI(KC_GRV)),    KC_TRNS,
              KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,                        KC_TRNS,   LGUI(KC_0),            KC_TRNS,                KC_TRNS
    ),

    [_SYMBOLSL] = LAYOUT(
    KC_TILD,   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,                KC_CIRC,    KC_AMPR,    KC_ASTR,  KC_LPRN,       KC_RPRN,      KC_UNDS,
    KC_GRAVE,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                KC_QUOT,    KC_TRNS,    KC_TRNS,  KC_LCBR,       KC_RCBR,      KC_KP_PLUS,
    KC_TRNS,   KC_GRAVE,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                KC_UNDS,    KC_MINUS,   KC_EQUAL, KC_LBRC,   KC_RBRC,  KC_MINUS,
                           KC_ENTER,   KC_TRNS,    KC_TRNS,    KC_TRNS,               KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    [_SYMBOLSR] = LAYOUT(
    KC_TILD,   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,                KC_CIRC,    KC_AMPR,    KC_ASTR,  KC_LPRN,       KC_RPRN,      KC_UNDS,
    KC_GRAVE,  KC_TILD,    KC_GRV,    KC_TRNS,    KC_PIPE,   KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_LCBR,       KC_RCBR,      KC_KP_PLUS,
    KC_TRNS,   KC_BSLS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,                KC_TRNS,    KC_MINUS,   KC_EQUAL, KC_LBRC,   KC_RBRC,  KC_MINUS,
               KC_ENTER,   KC_TRNS,   KC_TRNS,  KC_TRNS,                              KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS
    ),

    [_CMDNUM] =LAYOUT(
    QK_BOOT,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,              KC_TRNS,            LGUI(KC_7),     LGUI(KC_8),  LGUI(KC_9),      KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,              LGUI(KC_PLUS),      LGUI(KC_4),     LGUI(KC_5),  LGUI(KC_6),      KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,              LGUI(KC_MINUS),     LGUI(KC_1),     LGUI(KC_2),  LGUI(KC_3),      KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,              KC_TRNS,            LGUI(KC_KP_0),  KC_TRNS,     KC_TRNS
    ),

    /* Plover layer (http://opensteno.org)
    This layer remains on until EXIT key is pressed or the keyboard is reconnected.
    No other layers/modifiers to be used with it - it is self-sufficient.
    All other STENO/PLOVER layers defind below implement the same map with minor variances:
        - TX Bolt protocol over COM port is used instead of acting as a regular keyboard.
            - NumBar keys are moved below the alpha-keys.

     * ,-----------------------------------------------------------------------------------.
     * | EXIT |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | xxxx |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | xxxx |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
     * +------+------+------+------+------+------+------+------+------+------+------+------+
             | xxxx | xxxx |      |      ||      |      | xxxx| xxx  |
                 +------+------+      |      ||      |      +-----+------+
                           |   A  |   O  ||   E  |   U  |
                           +------+------||------+------+
     */

    // [_PLOVER] = LAYOUT(EXT_PLV, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, XXXXXXX, XXXXXXX, KC_C, KC_V, KC_N, KC_M, XXXXXXX, XXXXXXX),
    // The same as the one above, but the numbar moved down,
    // and the CTRLs acting as O/E, ESC - as numbar, just want to try them in those positions,
    // like in the compact steno boards I saw on the internet.
    // [_PLOVER2] = LAYOUT(EXT_PLV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, XXXXXXX, XXXXXXX, KC_C, KC_V, KC_N, KC_M, XXXXXXX, XXXXXXX),

    /* Plover Layer via TX Bolt interface.
       The layout is the same as for Plover above, just different key codes
    */

    // [_STENO_TXBOLT] = LAYOUT(EXT_PLV2, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_SL, STN_SL, STN_TL, STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, STN_SL, STN_SL, STN_KL, STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, XXXXXXX, XXXXXXX, STN_A, STN_O, STN_E, STN_U, XXXXXXX, XXXXXXX),

    /*  TX Bolt with the alpha rows moved up, numbar below them.
     */
    // [_STENO_TXBOLT2] = LAYOUT(EXT_PLV2, STN_SL, STN_TL, STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, STN_SL, STN_SL, STN_KL, STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, XXXXXXX, XXXXXXX, STN_A, STN_O, STN_E, STN_U, XXXXXXX, XXXXXXX)

};


const uint16_t PROGMEM fn_actions[] = {

};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
enum combos {
  FJ_ESC,
  JL_KM
};

const uint16_t PROGMEM key_esc[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM km_picker[] = {KC_J, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [FJ_ESC] = COMBO(key_esc, KC_ESC),
    [JL_KM] = COMBO(km_picker, KC_F20),
};


// void matrix_init_user() {
//     //   persistent_default_layer_set(1UL<<_QWERTY);
//     steno_set_mode(STENO_MODE_BOLT);  // or STENO_MODE_BOLT
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case NUMPAD:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
// #endif
//                 layer_invert(_QWERTY);
//                 layer_invert(_ARROWS);
//             }
//             return false;
//             break;

//         case CURSORRGHT:
//             if (record->event.pressed) {
//                 layer_on(_LAUNCHERL);
//                 update_tri_layer(_LAUNCHERL, _LAUNCHERR, _NUMBERS);
//             } else {
//                 layer_off(_LAUNCHERL);
//                 update_tri_layer(_LAUNCHERL, _LAUNCHERR, _NUMBERS);
//             }
//             return true;  // false;
//             break;
//         case CURSORLEFT:
//             if (record->event.pressed) {
//                 layer_on(_LAUNCHERR);
//                 update_tri_layer(_LAUNCHERL, _LAUNCHERR, _NUMBERS);
//             } else {
//                 layer_off(_LAUNCHERR);
//                 update_tri_layer(_LAUNCHERL, _LAUNCHERR, _NUMBERS);
//             }
//             return true;  // 	false;
//             break;

//         case QWERTY:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
// #endif
//                 layer_off(_LAUNCHERL);
//                 layer_off(_LAUNCHERR);
//                 layer_off(_NUMBERS);
//                 layer_off(_MOUSE);
//                 layer_off(_ARROWS);
//                 layer_off(_PLOVER);
//                 layer_off(_PLOVER2);
//                 layer_on(_QWERTY);

//                 // persistent_default_layer_set(1UL<<_QWERTY);
//                 set_single_persistent_default_layer(_QWERTY);
//             }
//             return false;
//             break;

//         case PLOVER:
//             if (record->event.pressed) {
//                 layer_off(_QWERTY);
//                 layer_off(_LAUNCHERL);
//                 layer_off(_LAUNCHERR);
//                 layer_off(_NUMBERS);
//                 layer_off(_MOUSE);
//                 layer_off(_ARROWS);
//                 layer_on(_PLOVER);

//                 if (!eeconfig_is_enabled()) {
//                     eeconfig_init();
//                 }
//                 keymap_config.raw  = eeconfig_read_keymap();
//                 keymap_config.nkro = 1;
//                 eeconfig_update_keymap(keymap_config.raw);
//             }
//             return false;
//             break;

//         case PLOVER2:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 stop_all_notes();
//                 PLAY_NOTE_ARRAY(tone_plover, false, 0);
// #endif
//                 layer_off(_LAUNCHERL);
//                 layer_off(_LAUNCHERR);
//                 layer_off(_NUMBERS);
//                 layer_off(_MOUSE);
//                 layer_off(_ARROWS);
//                 layer_off(_STENO_TXBOLT);
//                 layer_on(_PLOVER2);

//                 if (!eeconfig_is_enabled()) {
//                     eeconfig_init();
//                 }
//                 keymap_config.raw  = eeconfig_read_keymap();
//                 keymap_config.nkro = 1;
//                 eeconfig_update_keymap(keymap_config.raw);
//             }
//             return false;
//             break;

//         case EXT_PLV:
//             if (record->event.pressed) {
//                 layer_off(_PLOVER);
//                 layer_on(_QWERTY);
//             }
//             return false;
//             break;

//         case STENO_TXBOLT:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 stop_all_notes();
//                 PLAY_NOTE_ARRAY(tone_plover, false, 0);
// #endif
//                 layer_off(_LAUNCHERL);
//                 layer_off(_LAUNCHERR);
//                 layer_off(_NUMBERS);
//                 layer_off(_MOUSE);
//                 layer_off(_ARROWS);
//                 layer_off(_PLOVER);
//                 layer_off(_STENO_TXBOLT2);
//                 layer_on(_STENO_TXBOLT);
//                 if (!eeconfig_is_enabled()) {
//                     eeconfig_init();
//                 }
//                 keymap_config.raw  = eeconfig_read_keymap();
//                 keymap_config.nkro = 1;
//                 eeconfig_update_keymap(keymap_config.raw);
//             }
//             return false;
//             break;

//         case STENO_TXBOLT2:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 stop_all_notes();
//                 PLAY_NOTE_ARRAY(tone_plover, false, 0);
// #endif
//                 layer_off(_LAUNCHERL);
//                 layer_off(_LAUNCHERR);
//                 layer_off(_NUMBERS);
//                 layer_off(_MOUSE);
//                 layer_off(_ARROWS);
//                 layer_off(_PLOVER);
//                 layer_off(_STENO_TXBOLT);
//                 layer_on(_STENO_TXBOLT2);
//                 if (!eeconfig_is_enabled()) {
//                     eeconfig_init();
//                 }
//                 keymap_config.raw  = eeconfig_read_keymap();
//                 keymap_config.nkro = 1;
//                 eeconfig_update_keymap(keymap_config.raw);
//             }
//             return false;
//             break;

//         case EXT_PLV2:
//             if (record->event.pressed) {
// #ifdef AUDIO_ENABLE
//                 PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
// #endif
//                 layer_off(_STENO_TXBOLT);
//                 layer_off(_STENO_TXBOLT2);
//                 layer_on(_QWERTY);
//             }
//             return false;
//             break;
//     }
//     return true;
// }
