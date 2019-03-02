#include QMK_KEYBOARD_H

// #define QWERTY 0 // Base qwerty


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
[0] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           CTL_T(KC_ESCAPE),KC_A   ,KC_S   ,KC_D   ,KC_F,KC_G,
           KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),

[1] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_TRANSPARENT,KC_RPRN,KC_GRAVE,
           KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),

[2] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_TRANSPARENT,KC_RPRN,KC_GRAVE,
           KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),
[3] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_TRANSPARENT,KC_RPRN,KC_GRAVE,
           KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),
[4] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_TRANSPARENT,KC_RPRN,KC_GRAVE,
           KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),
[5] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_TRANSPARENT,KC_RPRN,KC_GRAVE,
           KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),
[6] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_TRANSPARENT,KC_RPRN,KC_GRAVE,
           KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,
                  LT(1,KC_NO),LT(5,KC_NO),ALT_T(KC_F19),LT(4,KC_F20),
                          LT(5,KC_F21),LT(3,KC_F22),
                                    GUI_T(KC_SPACE),
          LT(3,KC_SPACE) LT(4,KC_F23), ,LT(3,KC_F24),

          KC_F9  ,KC_F10  ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
          KC_6   ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
          KC_Y   ,KC_U    ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
          KC_H   ,KC_J    ,KC_K   ,KC_L,LT(2,KC_SCOLON),LT(2,KC_QUOTE),
          KC_N   ,KC_M    ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
          KC_UP  ,KC_DOWN ,KC_LBRC,KC_RBRC,
          LALT(LCTL(LGUI(LSFT(KC_EQUAL)))),LCTL(LSFT(KC_RALT)),LT(5,KC_NO),KC_MEH,
          LT(2,KC_F17),LT(5,KC_F16),
          KC_F18,
          KC_F19, KC_BSPACE,LT(5,KC_SPACE)
    ),
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
