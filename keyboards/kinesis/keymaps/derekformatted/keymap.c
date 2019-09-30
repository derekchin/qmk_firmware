#include QMK_KEYBOARD_H

#include "quantum.h"
#include "action_layer.h"
#include "keymap_steno.h"

#define QWERTY 0
#define LEFTSWITCHER 1
#define RIGHTSWITCHER 2
#define NUMBERS 3
#define MOUSE 4
#define ARROWS 5
#define WINDOWS 6
#define SYMBOLSL 7
#define SYMBOLSR 8
#define STENO 9
#define KINESIS 10 


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_pretty(
    TG(STENO),      KC_F1,    KC_F2,              KC_F3,              KC_F4,              KC_F5,   KC_F6,    KC_F7,               KC_F8,                KC_F9,              KC_F10,           KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  TG(MOUSE),  TG(KINESIS),   RESET,
    KC_EQL,         KC_1,     MT(MOD_LSFT, KC_2), MT(MOD_LCTL,KC_3),  MT(MOD_LALT,KC_4),  KC_5,    KC_6,     MT(MOD_RALT, KC_7),  MT(MOD_RCTL, KC_8),   MT(MOD_RSFT, KC_9), KC_0,             KC_MINS,
    KC_TAB,         KC_Q,     KC_W,               KC_E,               KC_R,               KC_T,    KC_Y,     KC_U,                KC_I,                 KC_O,               KC_P,             KC_BSLS,
    CTL_T(KC_ESC),  KC_A,     KC_S,               KC_D,               KC_F,               KC_G,    KC_H,     KC_J,                KC_K,                 KC_L,               LT(4, KC_SCOLON), CTL_T(KC_QUOTE),
    KC_LSFT,        KC_Z,     KC_X,               KC_C,               KC_V,               KC_B,    KC_N,     KC_M,                KC_COMM,              KC_DOT,             KC_SLSH,          KC_RSFT,
                    MO(3),    MO(7),             CTL_T(KC_F18),       ALT_T(KC_F19),                                 ALT_T(KC_F20),       CTL_T(KC_F21),       LT(7, KC_TRNS),     KC_MEH,
                                               MO(1), MO(1),                           RCTL(RSFT(KC_RALT)), MO(2),
                                                                RGUI(KC_RSFT),                                  RGUI(KC_RCTL),
                            GUI_T(KC_SPACE), LT(1, KC_SPACE), RCTL(KC_LALT),                                 RCTL(KC_LALT), LT(2,KC_BSPACE), LT(1, KC_SPACE)
  ),
  [LEFTSWITCHER] = LAYOUT_pretty(
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   MO(3),      MO(7),      KC_TRNS,                            KC_TRNS,  MO(8),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    MO(5),                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
          OSM(MOD_LSFT),   OSM(MOD_LCTL),   OSM(MOD_LALT),    OSM(MOD_LGUI),                      OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RSFT),
                                                  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,                              KC_TRNS,
                                        KC_ENT,  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [RIGHTSWITCHER] = LAYOUT_pretty(
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  MO(8),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                                        OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RSFT),
                                                  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,                              KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [NUMBERS] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_7,    KC_8,     KC_9,     KC_ASTR,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_4,    KC_5,     KC_6,     KC_PLUS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,                            KC_AMPR,  KC_1,    KC_2,     KC_3,     KC_BSLASH,   KC_TRNS,
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                        KC_NO,    KC_DOT,  KC_EQUAL, KC_DOT,
                                                      KC_TRNS,  KC_TRNS,                             KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                             KC_TRNS,
                                           KC_TRNS,  KC_TRNS,   KC_TRNS,                            KC_TRNS,  KC_TRNS, KC_0
  ),


  [MOUSE] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  TG(MOUSE),  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,       KC_TRNS,                           KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   HYPR(KC_F1), KC_MS_UP,   HYPR(KC_F2),   KC_TRNS,                           KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_ACL1,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   KC_TRNS,                           KC_TRNS,  KC_MS_BTN1, KC_MS_BTN2,  KC_ACL0,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   HYPR(KC_F3), KC_TRNS,    HYPR(KC_F4),   KC_TRNS,                           KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_ACL2,   KC_TRNS,   KC_TRNS,
              KC_TRNS,   KC_TRNS,     KC_TRNS,        KC_TRNS,                                                KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,  KC_TRNS,                                    KC_TRNS,  KC_TRNS,
                                                                  KC_TRNS,                                    KC_TRNS,
                                            KC_ENTER,  KC_TRNS,   KC_TRNS,                                    KC_TRNS,  LGUI(LSFT(KC_LBRACKET)),LGUI(LSFT(KC_RBRACKET))
  ),



  [ARROWS] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,                            KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                       KC_TRNS,  KC_TRNS,         KC_TRNS,   KC_TRNS,
                                                                 KC_TRNS,         KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,         KC_TRNS,  LGUI(KC_LBRACKET), LGUI(KC_RBRACKET)

  ),

  [WINDOWS] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                          KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  LCTL(KC_4),    LCTL(KC_5),    LCTL(KC_6),   KC_TRNS,                                          KC_TRNS,   LCAG(KC_1), LCAG(KC_UP), LCAG(KC_3), KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  LCTL(KC_KP_7), LCTL(KC_KP_8), LCTL(KC_KP_9), KC_TRNS,                                         KC_TRNS,   LCAG(KC_LEFT), LCAG(KC_M), LCAG(KC_RIGHT), KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                         KC_TRNS,   LCAG(KC_2), LCAG(KC_DOWN), LCAG(KC_4), KC_TRNS,  KC_TRNS,
              KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,                                                             KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                              KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,                             KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [SYMBOLSL] = LAYOUT_pretty(
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                            KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,       KC_TRNS,      KC_TRNS,
    KC_TILD,   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,                            KC_CIRC,    KC_AMPR,    KC_ASTR,  KC_LPRN,       KC_RPRN,      KC_UNDS,
    KC_GRAVE,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                            KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_LCBR,       KC_RCBR,      KC_KP_PLUS,
    KC_TRNS,   KC_GRAVE,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                            KC_TRNS,    KC_MINUS,   KC_EQUAL, KC_LBRACKET,   KC_RBRACKET,  KC_MINUS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,                                            KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_ENTER,  KC_TRNS,   KC_TRNS,                                             KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [SYMBOLSR] = LAYOUT_pretty(
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                            KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,       KC_TRNS,      KC_TRNS,
    KC_TILD,   KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,                            KC_CIRC,    KC_AMPR,    KC_ASTR,  KC_LPRN,       KC_RPRN,      KC_UNDS,
    KC_GRAVE,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                            KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_LCBR,       KC_RCBR,      KC_KP_PLUS,
    KC_TRNS,   KC_GRAVE,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                            KC_TRNS,    KC_MINUS,   KC_EQUAL, KC_LBRACKET,   KC_RBRACKET,  KC_MINUS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,                                            KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_ENTER,  KC_TRNS,   KC_TRNS,                                             KC_TRNS,  KC_TRNS, KC_TRNS
  ),


  [STENO] = LAYOUT_pretty(
    TG(STENO), KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   STN_S1,   STN_TL,    STN_PL,   STN_HL,    STN_ST1,                                                                     STN_ST3,   STN_FR,   STN_PR,  STN_LR,  STN_TR,  STN_DR,
    KC_TRNS,   STN_S2,   STN_KL,    STN_WL,   STN_RL,    STN_ST2,                                                                     STN_ST4,   STN_RR,   STN_BR,  STN_GR,  STN_SR,  STN_ZR,
               KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,                                                                                           KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            STN_A,  STN_O,  KC_TRNS,                                               KC_TRNS,  STN_E, STN_U
  ),


  [KINESIS] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  TG(KINESIS),   RESET,
    KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                                      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
              KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                       KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,
                                                      KC_LCTL,  KC_LALT,                                               KC_RGUI,  KC_RCTL,
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
  )


};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
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
