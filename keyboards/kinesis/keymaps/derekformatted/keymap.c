#include QMK_KEYBOARD_H

#define QWERTY 0 
#define NUMBERS 1 
#define MOUSE 2 
#define ARROWS 3 
#define WINDOWS 4 
#define SYMBOLS 5 
#define STENO 6 
#define KINESIS 7 


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
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  TG(KINESIS),   RESET,
    KC_EQL,   KC_1,     MT(MOD_LSFT, KC_2),     MT(MOD_LCTL,KC_3),     MT(MOD_LALT,KC_4),     KC_5,    KC_6,     MT(MOD_RALT, KC_7),     MT(MOD_RCTL, KC_8),     MT(MOD_RSFT, KC_9),     KC_0,     KC_MINS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    CTL_T(KC_ESCAPE),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                             KC_H,     KC_J,     KC_K,     KC_L,     LT(2, KC_SCOLON), LT(2, KC_QUOTE),
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
               LT(1, KC_TRNS), LT(5, KC_TRNS), ALT_T(KC_F19), LT(4, KC_F20),                                                                       HYPR(KC_EQUAL), LSFT(KC_RALT), LT(5, KC_TRNS), KC_MEH, 
                                               LSFT(KC_LALT), LT(3, KC_F22),                                                LT(2, KC_F17), RSFT(KC_RALT),
                                                              LT(4, KC_F23),                                                KC_F18,
                            GUI_T(KC_SPACE), LT(3, KC_SPACE), LT(3, KC_F24),                                                KC_F19, KC_BSPACE, LT(5, KC_SPACE)
  ),

  [NUMBERS] = LAYOUT_pretty(
    KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,
    KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                                                                   KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   KC_EXLM,   KC_AT,     KC_LCBR,  KC_RCBR,  KC_PIPE,                                                                 KC_TRNS,   KC_7,  KC_8,   KC_9,   KC_ASTR,  KC_TRNS,
    KC_TRNS,   KC_HASH,   KC_DLR,    KC_LPRN,  KC_RPRN,  KC_GRAVE,                                                                KC_TRNS,   KC_4,  KC_5,   KC_6,   KC_PLUS,  KC_TRNS,
    KC_TRNS,   KC_PERC,   KC_CIRC,   KC_LBRACKET,KC_RBRACKET,KC_TILD,                                                             KC_AMPR, KC_1,  KC_2,   KC_3,   KC_BSLASH,  KC_TRNS,
             KC_TRANSPARENT,     KC_TRNS,     KC_TRNS,    KC_TRNS,                                                                                      KC_TRNS, KC_DOT,  KC_EQUAL,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,                                                KC_TRNS,  KC_TRNS, KC_0
  ),


  [MOUSE] = LAYOUT_pretty(
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,   KC_TRNS,     HYPR(KC_F1),KC_MS_UP,HYPR(KC_F2), KC_TRNS,                                KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,     KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT, KC_TRNS,                                                                    KC_TRNS,     KC_MS_BTN1,KC_MS_BTN2,KC_TRNS,     KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,     HYPR(KC_F3),KC_TRANSPARENT,HYPR(KC_F4), KC_TRNS,                           KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,                                                                                      KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_ENTER,  KC_TRNS,   KC_TRNS,                                                KC_TRNS,  LGUI(LSFT(KC_LBRACKET)),LGUI(LSFT(KC_RBRACKET))
  ),

  

  [ARROWS] = LAYOUT_pretty(
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                           KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,                                                                                       KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,                                              KC_TRNS,  LGUI(KC_LBRACKET), LGUI(KC_RBRACKET)
                                            
  ),

  [WINDOWS] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                          KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  LCTL(KC_4),    LCTL(KC_5),    LCTL(KC_6),   KC_TRNS,                                          KC_TRNS,   LALT(LCTL(LGUI(KC_1))), LALT(LCTL(LGUI(KC_UP))), LALT(LCTL(LGUI(KC_3))), KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  LCTL(KC_KP_7), LCTL(KC_KP_8), LCTL(KC_KP_9), KC_TRNS,                                         KC_TRNS,   LALT(LCTL(LGUI(KC_LEFT))), LALT(LCTL(LGUI(KC_M))), LALT(LCTL(LGUI(KC_RIGHT))), KC_TRNS, KC_TRNS,    
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                         KC_TRNS,   LALT(LCTL(LGUI(KC_2))), LALT(LCTL(LGUI(KC_DOWN))), LALT(LCTL(LGUI(KC_4))), KC_TRNS,  KC_TRNS,
              KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,                                                             KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                              KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,                             KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [SYMBOLS] = LAYOUT_pretty(
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,                                                                       KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,
    KC_GRAVE,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                      KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_LCBR,KC_RCBR,KC_KP_PLUS, 
    KC_TRNS,  KC_GRAVE,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                                                      KC_TRNS,    KC_MINUS,KC_EQUAL,KC_LBRACKET,KC_RBRACKET,KC_MINUS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,                                                                                       KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_ENTER,  KC_TRNS,   KC_TRNS,                                                KC_TRNS,  KC_TRNS, KC_TRNS  
  ),

  [STENO] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
              KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,                                                                                           KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS, KC_TRNS
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
