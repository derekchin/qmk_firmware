#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


//#include "ergodox.h"
#include "keymap_steno.h"

#define _QWERTY 0 // default QWERTY layer
#define _SYMBOLS 1 // far-right side keys shifted onto the existing keys
#define _NUMBERPAD 2  // numpad on the right along with the arithetic operations
#define _ARROWS 3 // cursor on the left, mouse on the right
#define _WINDOWS 4 // numbers and F-keys
#define _MOUSE 5 // cursor on the right, mouse on the left
#define _PLOVER 6 // plover STENO layout
#define _STENO_TXBOLT 7 //Plover STENO layout for TX Bolt communication protocol

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  QWERTY = SAFE_RANGE,
  NUMBERPAD,
// These three wiil work as RAISE, LOWER  and ADJUST in the original PLANCK
  CURSORRGHT = LT(_MOUSE,KC_SPC),
  CURSORLEFT = LT(_ARROWS,KC_BSPC),
  NUMBERS,
// These two are to activate/deactivate PLOVER layer
  PLOVER,
  STENO_TXBOLT,
  EXT_PLV,
  EXT_PLV2
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


//Tap Dance Declarations
enum {
  TD_PLNUMBAR_PLEXIT = 0,
  TD_PLNUMBAR_PLEXIT2 = 2,
};
//Tap Dance Definitions
/* qk_tap_dance_action_t tap_dance_actions[] = { */
  //Tap once for PloverNumBar, twice or more for exiting PLOVER
  /* [TD_PLNUMBAR_PLEXIT] = ACTION_TAP_DANCE_DOUBLE(KC_1, EXT_PLV), */
  /* [TD_PLNUMBAR_PLEXIT2] = ACTION_TAP_DANCE_DOUBLE(STN_NUM, EXT_PLV2), */
// Other declarations would go here, separated by commas, if you have them
/* }; */

enum process_combo_event{
  VM_RETURN,
};

const uint16_t PROGMEM return_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM tenkey_combo[] = {KC_V, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [VM_RETURN] = COMBO_ACTION(return_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
    case VM_RETURN:
        if (pressed) {
                register_code(KC_ENT);
                unregister_code(KC_ENT);
                send_keyboard_report();
        }
        break;

    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * Note that "x" marks the keys non-existing in this short 4x6 version of Dactyl/ManuForm.
 *
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |Tab/ExRt|   Q  |   W  |   E  |   R  |   T  | x |           | x |   Y  |   U  |   I  |   O  |   P  | \      |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * | Esc/Ctl|   A  |   S  |   D  |   F  |   G  | x |           | x |   H  |   J  |   K  |   L  |   ;  | '      |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * | LShft  |   Z  |   X  |   C  |   V  |   B  | x |           | x |   N  |   M  |   ,  |   .  |   /  | RShft  |
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |  Alt | F20  |                                        | AltGr| Menu |
 *                 `-------------'                                        `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 | GUI  | CCLt |         | CCRt |Space |
 *                                 |      | Space|         |Space |      |
 *                                 ,------|------|         |------+------|
 *                                 |LAlt  |LCtrl |         | RCtrl|RAlt  |
 *                                 ,------|------|         |------+------|
 *                                 | GUI  |ExtRt |         |Menu  | GUI  |
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_QWERTY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,                KC_NO,            KC_NO,          KC_NO,                KC_NO,              KC_NO,  KC_NO,
        LT(_SYMBOLS,KC_TAB),  KC_Q,             KC_W,           KC_E,                 KC_R,               KC_T,   KC_NO,
        LCTL_T(KC_ESC),       KC_A,             KC_S,           LT(_NUMBERPAD,KC_D),  LT(_SYMBOLS,KC_F),  KC_G,   KC_NO,
        SFT_T(KC_LBRACKET),   LT(_ARROWS,KC_Z), KC_X,           KC_C,                 KC_V,               KC_B,   KC_NO,
                                                ALT_T(KC_F19),  LT(_WINDOWS,KC_F20),
                                            GUI_T(KC_SPACE),  LT(_WINDOWS,KC_SPC),
                                            MEH_T(KC_F21),    LT(_ARROWS,KC_F22),
                                            ALL_T(KC_F20),    LT(_SYMBOLS,KC_SPC),

        // right hand
                       KC_NO, KC_NO,  KC_NO, KC_NO,         KC_NO,  KC_NO,   KC_NO,
                       KC_NO, KC_Y,   KC_U,  KC_I,          KC_O,   KC_P,    KC_BSLASH,
                       KC_NO, KC_H,   LT(_SYMBOLS,KC_J),    KC_K,   KC_L,    LT(_MOUSE,KC_SCLN), LT(_MOUSE,KC_QUOT),
                       KC_NO, KC_N,   KC_M,  KC_COMM,       KC_DOT, KC_SLSH, KC_RSFT,
                                      HYPR(KC_EQL),  KC_F17,
                      ALT_T(KC_BSPACE),   KC_SPACE,
                      LT(_MOUSE,KC_F17),        OSM(MOD_MEH),
                      KC_F18,                   OSM(MOD_HYPR)
    )

/* Keymap 1: CURSORRGHT - cursor on the right, mouse on the left
 * Note that "x" marks the keys non-existing in this short version for ManuForm.
 *
 * This is my original Planck version, the Ergodox derived one is below it.
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |Break |WheelD|MousUp|WheelU| Del  |  Ins | Home |  Up  | End  |   `  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Enter|SelAll|MousLt|MousDn|MousRt|      | Left | Down | Up   |Right |      |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Undo | Cut  | Copy | Paste|RShift| PgDn |MsBtLe|MsBtMi|MsBtRt|      |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |   X  |      |      |      |      |RCtrl |
 * `-----------------------------------------------------------------------------------'
 *
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |   Esc  |Break |WheelD|MousUp|WheelU| Del  | x |           | x |  Ins | Home |  Up  | End  |   `  | Del    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |   Enter|SelAll|MousLt|MousDn|MousRt|  ... | x |           | x | PgUp | Left | Down |Right |  ... |        |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        | Undo | Cut  | Copy | Paste|RShift| x |           | x | PgDn |MsBtLe|MsBtMi|MsBtRt|  ... |        |
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |ExtRt | GUI  |                                        | Space| Menu |
 *                 `-------------'                                        `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |      |         |   X  |      |
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'


 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
,[_MOUSE] = KEYMAP(  // Layer 1: CURSORRGHT - cursor on the right, mouse on the left
        // left hand
        _______,   KC_NO,      KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
        RESET, KC_BRK,     LALT(LCTL(LGUI(LSFT(KC_F1)))),      KC_MS_U,      LALT(LCTL(LGUI(LSFT(KC_F2)))),      KC_DEL,  KC_NO,
        KC_ENT,  LCTL(KC_A), KC_MS_L,      KC_MS_D,      KC_MS_R,      XXXXXXX, KC_NO,
        _______, LCTL(KC_Z), LALT(LCTL(LGUI(LSFT(KC_F3)))), LCTL(KC_INS), LALT(LCTL(LGUI(LSFT(KC_F3)))), KC_RSFT, KC_NO,
                               _______, _______,
                                                KC_ENT, _______,
                                                _______, _______,
                                                _______, _______,


        // right hand
                       KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                       KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
                       KC_NO, KC_NO,    KC_MS_BTN1, KC_MS_BTN3,   KC_NO, KC_NO, KC_NO,
                       KC_NO, KC_NO,    KC_ACL2,   KC_NO, KC_NO, XXXXXXX, _______,
                                       _______, _______,
           LSFT(RCMD(KC_LBRACKET)), LSFT(RCMD(KC_RBRACKET)),
           _______, _______,
           _______, _______
    )





/* Keymap 2: CURSORLEFT - cursor on the left, mouse on the right
 * Note that "x" marks the keys non-existing in this short version for ManuForm.
 *
 * This is my original Planck version, the Ergodox derived one is below it.
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |Break | Home |  Up  | End  |  Ins | Del  |WheelU|MousUp|WheelD|   `  | Del  |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Enter|SelAll|Right | Down | Left | PgUp |      |MousLt|MousDn|MousRt|      |Enter |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * | Shift|      |MsBtRt|MsBtMi|MsBtLe| PgDn |RShift| Cut  | Copy | Paste|      |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |   X  |	    |      |      |      |      |RCtrl |
 * `-----------------------------------------------------------------------------------'
 *
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |   Esc  |Break | Home |  Up  | End  |  Ins | x |           | x | Del  |WheelU|MousUp|WheelD|   `  | Del    |
 * |--------+------+------+------+------+------+---|           |---+-------------+------+------+------+--------|
 * |   Enter|SelAll|Right | Down | Left | PgUp | x |           | x |  xxx |MousLt|MousDn|MousRt| xxx  |        |
 * |--------+------+------+------+------+------+---|           |---+------|------+------+------+------+--------|
 * |        |      |MsBtRt|MsBtMi|MsBtLe| PgDn | x |           | x |RShift| Cut  | Copy | Paste| xxx  |        |
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |      |      |                                               |      |       |
 *                 `-------------'                                                `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |   X  |         |      |      |
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'


 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
,[_ARROWS] = KEYMAP(  // layer 2: CURSORLEFT - cursor on the left, mouse on the right
        // left hand
          KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, KC_BRK,     KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_NO,
        KC_ENT,  LCTL(KC_A), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_NO,
        _______, XXXXXXX,    KC_BTN2, KC_BTN3, KC_BTN1, KC_PGDN, KC_NO,
                               _______, _______,
 				           _______, _______,
				           _______, _______,
 				           _______, _______,
        // right hand
                       KC_NO, KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
                       KC_NO, KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,
                       KC_NO, KC_LEFT, KC_DOWN,      KC_UP,        KC_RGHT,      _______, KC_NO,
                       KC_NO, KC_RSFT, LCTL(KC_DEL), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX, _______,
                                       _______, _______,
           RCMD(KC_LBRACKET), RCMD(KC_RBRACKET),
           _______, _______,
           _______, _______
    )


/* Keymap 3: NUMBERS // numbers and F-keys
 * Note that "x" marks the keys non-existing in this short version for ManuForm.
 *
 * This is my original Planck version, the Ergodox derived one is below it.
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BackSp|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |ExtRt |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |   F10| Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|  F11 |  F12 | LAlt |LShift| LAlt | RAlt |RShift|   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   X  |NUMPAD|      | LAlt |   X2 |   X2 |RAlt  |      |   -  |   =  |RCtrl |
 * `-----------------------------------------------------------------------------------'
 *
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |   Esc  |   1  |   2  |   3  |   4  |   5  | x |           | x |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        |   F1 |   F2 |   F3 |   F4 |   F5 | x |           | x |   F6 |   F7 |   F8 |   F9 |   F10|        |
When held:   LShift                                                                             RShift
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        |  F11 |  F12 |LCtrl |LShift| LAlt | x |           | x | RAlt |RShift|   ,  |   .  |   /  |        |
When held:   LShift  LCtrl                                                               RCtrl  RShift
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |      |      |                                               |      |      |
 *                 `-------------'                                               `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |  X1  |         |   X2 |      |
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'


 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
,[_WINDOWS] = KEYMAP(  // Layer 3: NUMBERS // numbers and F-keys
        // left hand
        KC_NO,    KC_NO,   KC_NO,       KC_NO,        KC_NO,   KC_NO,   KC_NO,
        LGUI(KC_GRV),    KC_NO,   LCTL(KC_P4),  LCTL(KC_P5),   LCTL(KC_P6),   KC_NO, KC_NO,
        _______,  KC_NO,   LCTL(KC_P7),  LCTL(KC_P8),   LCTL(KC_P9),   KC_NO, KC_NO,
        _______,  KC_NO,   KC_NO,       KC_LCTL,      KC_LSFT, KC_LALT, KC_NO,
                                                  _______, _______,
                                                                    _______, _______,
                                                                    _______, _______,
                                                                    _______, _______,


        // right hand
                       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,          KC_NO,
                       KC_NO, KC_6,    LALT(LCTL(LGUI(KC_1))),LALT(LCTL(LGUI(KC_UP))),LALT(LCTL(LGUI(KC_3))), KC_0, KC_BSPC,
                       KC_NO, KC_F6,   LALT(LCTL(LGUI(KC_LEFT))),LALT(LCTL(LGUI(KC_M))),LALT(LCTL(LGUI(KC_RIGHT))) ,  KC_F10,  _______,
                       KC_NO, KC_RALT, LALT(LCTL(LGUI(KC_2))),LALT(LCTL(LGUI(KC_DOWN))),LALT(LCTL(LGUI(KC_4))),  SFT_T(KC_SLSH), _______,
                                       _______ ,_______,
           _______, _______,
           _______, _______,
           _______, _______
    )





/* Keymap 4: NUMBERPAD - numpad on the right along with the arithetic operations
 * Note that "x" marks the keys non-existing in this short version for ManuForm.
 *
 * This is my original Planck version, the Ergodox derived one is below it.
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BackSp|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   +  |   4  |   5  |   6  |   *  | Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|      |      |      |LShift| LAlt | RAlt |   1  |   2  |   3  |   \  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  X   |NumLoc|      | LAlt |      |CCRt  |   0  |   .  |   -  |   =  |RCtrl |
 * `-----------------------------------------------------------------------------------'
 *
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  | x |           | x |   6  |   7  |   8  |   9  |   0  | Del    |
 * |--------+------+------+------+------+------|---|           |---+------+------+------+------+------+--------|
 * |        | ...  | ...  | ...  | ...  | ...  | x |           | x |   +  |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+----------|           |---+------+------+------+------+------+--------|
 * |        | ...  | ...  | ...  |LShift| LAlt | x |           | x | RAlt |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |      |      |                                               |   0  |   .  |
 *                 `-------------'                                               `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |      |         |      |      |
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'


 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
,[_NUMBERPAD] = KEYMAP(  // Layer 4 NUMBERPAD - numpad on the right along with the arithetic operations

        // left hand
	KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, KC_LALT, KC_NO,
                               _______, _______,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______,


        // right hand
                       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                       KC_NO, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                       KC_NO, KC_PPLS, KC_4,    KC_5,    KC_6,    KC_PAST, KC_PENT,
                       KC_NO, KC_MINS, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_EQL,
                                       KC_0,    KC_KP_DOT,
           _______, KC_0,
           _______, _______,
           _______, _______
    )




/* Keymap 5: EXTRARIGHT // far-right side keys shifted onto the existing keys
 * Note that "x" marks the keys non-existing in this short version for ManuForm.
 *
 * This is my original Planck version, the Ergodox derived one is below it.
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   `  |      |      |      |      |   `  |   (  |   )  |   -  |   =  |BkSpc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   X  |PLOVER|      |      |      |      |      |      |      |      |  '   | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      | LShft| LAlt | RAlt | RShft|   [  |   ]  |  \   |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |   X  |      | LAlt |      |      | RAlt |      |   -  |   =  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 *
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        |   `  |  ... |  ... |  ... |  ... | x |           | x |   `  |   (  |   )  |   -  |   =  | Del    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |    X   |CAPSLK|NUMPAD|PLOVER|TXBOLT|  ... | x |           | x | ...  | ...  | ...  | ...  |  '   |        |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |   Shift|  ... |  ... |  ... | LShft| LAlt | x |           | x | RAlt | RShft|   [  |   ]  |  \   |        |
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |      |      |                                               |      |      |
 *                 `-------------'                                               `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |      |      |         |      |      |
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |      |      |         |      |      |
 *                                 `-------------'         `-------------'


 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*




,[_SYMBOLS] = KEYMAP(  // Layer 5: EXTRARIGHT - far-right side keys shifted onto the existing keys
        // left hand
        KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TILD, KC_EXLM,    KC_AT,     KC_HASH, KC_DLR,  KC_PERC, KC_NO,
        KC_GRV, _______,   XXXXXXX,   KC_LSHIFT, XXXXXXX, XXXXXXX, KC_NO,
        _______, KC_GRAVE,  KC_NO,     PLOVER,  STENO_TXBOLT, XXXXXXX, KC_NO,
                               _______, _______,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______,


        // right hand
                       KC_NO, KC_NO,  KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
                       KC_NO, KC_CIRC,KC_AMPR,  KC_ASTR,    KC_LPRN,  KC_RPRN,  KC_UNDS,
                       KC_NO, KC_NO,  KC_NO,    KC_NO,      KC_LCBR,  KC_RCBR,  KC_PLUS,
                       KC_NO, KC_NO,  KC_MINS,  KC_EQL,      KC_LBRC,  KC_RBRC,  KC_NO,
                                       _______, _______,
                  _______, _______,
                  _______, _______,
                  _______, _______
    )





/* Keymap 6: PLOVER - plover STENO layout
 * Note that "x" marks the keys non-existing in this short version for ManuForm.
 *
 * This is my original Planck version, the Ergodox derived one is below it.

 Plover layer (http://opensteno.org)
AK: note I moved them around a bit:
    - the consonants row up so the distance betwen the thumb keys
      and the upper rows is more comfortable.
    - moved the thumb keys closer to the center, to the more natural position of the thumbs.
 * ,-----------------------------------------------------------------------------------.
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Exit |      |      |      |   A  |   O  |   E  |   U  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *

AK: In this version the rows moved a line down, to the original Plover form
 * ,-----------------------------------------------.           ,----------------------------------------------.
 * |    x   |   x  |   x  |   x  |   x  |   x  | x |           | x |   x  |   x  |   x  |   x  |   x  |   x    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |    #   |   #  |   #  |   #  |   #  |   #  | x |           | x |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  | x |           | x |   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------+---|           |---+------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  | x |           | x |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+------+---'           `---+------+------+------+------+------+--------'
 *                 |   #  |   #  |                                               |   #  |   #  |
 *                 `-------------'                                               `-------------'
 *                                 ,-------------.         ,-------------.
 *                                 |   A  |   O  |         |   E  |   U  |
 *                                 |      |      |         |      |      |
 *                                 ,------|------|         |------+------|
 *                                 |   #  |   #  |         |   #  |   #  |
 *                                 ,------|------|         |------+------|
 *                                 |   #  | EXIT |         | EXIT |   #  |
 *                                 `-------------'         `-------------'


 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
,[_PLOVER] = KEYMAP(  // Layer PLOVER 6 -  Plover STENO layout
        // left hand
	KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_NO,
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,
                                XXXXXXX, XXXXXXX,
 		                               KC_C,    KC_V,
                                                XXXXXXX, XXXXXXX,
                                                XXXXXXX, EXT_PLV,


        // right hand
                       KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                       KC_NO, KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
                       KC_NO, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
                       KC_NO, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		           XXXXXXX, XXXXXXX,
           KC_N,    KC_M,
           XXXXXXX, XXXXXXX,
           EXT_PLV, XXXXXXX
    )

// Plover for TX Bolt communication protocol
/* Plover Layer via TX Bolt interface.
   The layout is the same as for Plover above, just different key codes
*/
/* Here is the layout from Planck and Soft/Hruf
[_STENO_TXBOLT] = {
   {STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, TD(TD_PLNUMBAR_PLEXIT2), STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, XXXXXXX},
   {STN_SL,  STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                 STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  XXXXXXX },
   {STN_SL,  STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                 STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  XXXXXXX },
   {XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX,                 STN_E,   STN_U,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
 },
*/


,[_STENO_TXBOLT] = KEYMAP(  // Layer PLOVER-TX BOLT --> 7 -  Plover STENO layout
        // left hand
	KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
	STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, KC_NO,
	STN_SL,  STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_STR, KC_NO,
  STN_SL,  STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_STR, KC_NO,
                                XXXXXXX, XXXXXXX,
 		                               STN_A,   STN_O,
                                                XXXXXXX, XXXXXXX,
                                                XXXXXXX, EXT_PLV,


        // right hand
                       KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		       KC_NO, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM,
		       KC_NO, STN_STR, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
		       KC_NO, STN_STR, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
		           XXXXXXX, XXXXXXX,
           STN_E,   STN_U,
           XXXXXXX, XXXXXXX,
           EXT_PLV, XXXXXXX
    )


//--------------------------------------


};

//const uint16_t PROGMEM fn_actions[] = {
//    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
//};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case NUMBERPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
	layer_invert(_QWERTY);
	layer_invert(_NUMBERPAD);
      }
      return false;
      break;
    case CURSORRGHT:
      if (record->event.pressed) {
        layer_on(_MOUSE);
        update_tri_layer(_MOUSE, _ARROWS, _WINDOWS);
      } else {
        layer_off(_MOUSE);
        update_tri_layer(_MOUSE, _ARROWS, _WINDOWS);
       }
      return true;// false;
      break;
    case CURSORLEFT:
      if (record->event.pressed) {
        layer_on(_ARROWS);
        update_tri_layer(_MOUSE, _ARROWS, _WINDOWS);
      } else {
        layer_off(_ARROWS);
        update_tri_layer(_MOUSE, _ARROWS, _WINDOWS);
      }
      return true;// 	false;
      break;


     case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_QWERTY);
        layer_off(_MOUSE);
        layer_off(_ARROWS);
        layer_off(_WINDOWS);
        layer_off(_SYMBOLS);
        layer_off(_NUMBERPAD);
        layer_off(_STENO_TXBOLT);
        layer_on(_PLOVER);
        //persistent_default_layer_set(1UL<<_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case STENO_TXBOLT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_QWERTY);
        layer_off(_MOUSE);
        layer_off(_ARROWS);
        layer_off(_WINDOWS);
        layer_off(_SYMBOLS);
        layer_off(_NUMBERPAD);
        layer_off(_PLOVER);
        layer_on(_STENO_TXBOLT);
        //persistent_default_layer_set(1UL<<_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_PLOVER);
        layer_off(_STENO_TXBOLT);
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;

  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
   persistent_default_layer_set(1UL<<_QWERTY);
   steno_set_mode(STENO_MODE_BOLT);

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

