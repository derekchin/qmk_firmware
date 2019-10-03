#include QMK_KEYBOARD_H

#include "quantum.h"
#include "action_layer.h"
#include "keymap_steno.h"

#define _QWERTY 0
#define _LAUNCHERL 1
#define _LAUNCHERR 2
#define _NUMBERS 3
#define _MOUSE 4
#define _ARROWS 5
#define _WINDOWS1 6
#define _WINDOWS2 7
#define _SYMBOLSL 8
#define _SYMBOLSR 9
#define _STENO 10
#define _KINESIS 11


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

  [_QWERTY] = LAYOUT_pretty(
    TG(_STENO),      KC_F1,    KC_F2,              KC_F3,              KC_F4,              KC_F5,   KC_F6,    KC_F7,               KC_F8,                KC_F9,              KC_F10,           KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  TG(_MOUSE),  TG(_KINESIS),   RESET,
    KC_EQL,         KC_1,     MT(MOD_LSFT, KC_2), MT(MOD_LCTL,KC_3),  MT(MOD_LALT,KC_4),  KC_5,    KC_6,     MT(MOD_RALT, KC_7),  MT(MOD_RCTL, KC_8),   MT(MOD_RSFT, KC_9), KC_0,             KC_MINS,
    KC_TAB,         KC_Q,     KC_W,               KC_E,               KC_R,               KC_T,    KC_Y,     KC_U,                KC_I,                 KC_O,               KC_P,             KC_BSLS,
    CTL_T(KC_ESC),  KC_A,     KC_S,               KC_D,               KC_F,               KC_G,    KC_H,     KC_J,                KC_K,                 KC_L,               LT(_MOUSE, KC_SCOLON), CTL_T(KC_QUOTE),
    KC_LSFT,        KC_Z,     KC_X,               KC_C,               KC_V,               KC_B,    KC_N,     KC_M,                KC_COMM,              KC_DOT,             KC_SLSH,          KC_RSFT,
                    MO(_NUMBERS),    MO(_SYMBOLSL),             CTL_T(KC_F18),       ALT_T(KC_F19),                                 ALT_T(KC_F20),       CTL_T(KC_F21),       LT(_SYMBOLSL, KC_TRNS),     KC_MEH,
                                               MO(_LAUNCHERL), MO(_LAUNCHERL),                           RCTL(RSFT(KC_RALT)), MO(_LAUNCHERR),
                                                                RGUI(KC_RSFT),                                  RGUI(KC_RCTL),
                            GUI_T(KC_SPACE), LT(_LAUNCHERL, KC_SPACE), RCTL(KC_LALT),                                 RCTL(KC_LALT), LT(_LAUNCHERR,KC_BSPACE), LT(_LAUNCHERL, KC_SPACE)
  ),
  [_LAUNCHERL] = LAYOUT_pretty(
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    MO(_ARROWS),     KC_TRNS,   MO(_NUMBERS),      MO(_SYMBOLSL),      KC_TRNS,       KC_TRNS,  MO(_SYMBOLSR),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   MO(_WINDOWS2),    MO(_WINDOWS1), KC_TRNS,                   KC_TRNS,  MO(_WINDOWS1),  MO(_WINDOWS2),  KC_TRNS,  KC_TRNS,  KC_TRNS,
          OSM(MOD_LSFT),   OSM(MOD_LCTL),   OSM(MOD_LALT),    OSM(MOD_LGUI),                      OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RSFT),
                                                  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,                              KC_TRNS,
                                        KC_ENT,  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [_LAUNCHERR] = LAYOUT_pretty(
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  RESET,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  MO(_SYMBOLSR),    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                                        OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RSFT),
                                                  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,                              KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [_NUMBERS] = LAYOUT_pretty(
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


  [_MOUSE] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  TG(_MOUSE),  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,       KC_TRNS,                           KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   HYPR(KC_F1), KC_MS_UP,   HYPR(KC_F2),   KC_TRNS,                           KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_ACL1,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   KC_TRNS,                           KC_TRNS,  KC_MS_BTN1, KC_MS_BTN2,  KC_ACL0,   KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   HYPR(KC_F3), KC_TRNS,    HYPR(KC_F4),   KC_TRNS,                           KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_ACL2,   KC_TRNS,   KC_TRNS,
              KC_TRNS,   KC_TRNS,     KC_TRNS,        KC_TRNS,                                                KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,  KC_TRNS,                                    KC_TRNS,  KC_TRNS,
                                                                  KC_TRNS,                                    KC_TRNS,
                                            KC_ENTER,  KC_TRNS,   KC_TRNS,                                    KC_TRNS,  LGUI(LSFT(KC_LBRACKET)),LGUI(LSFT(KC_RBRACKET))
  ),



  [_ARROWS] = LAYOUT_pretty(
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

  [_WINDOWS1] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                          KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                          KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                         LSFT(LALT(KC_H)),   LSFT(LALT(KC_J)), LSFT(LALT(KC_K)), LSFT(LALT(KC_L)), KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                         KC_TRNS,   LCAG(KC_2), LCAG(KC_DOWN), LCAG(KC_4), KC_TRNS,  KC_TRNS,
              KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,                                                             KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                              KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,                             KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [_WINDOWS2] = LAYOUT_pretty(
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                          KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                          KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                         SGUI(KC_H),   SGUI(KC_J), SGUI(KC_K), SGUI(KC_L), KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,                                         KC_TRNS,   SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), KC_TRNS,  KC_TRNS,
              KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,                                                             KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                              KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                              KC_TRNS,
                                            KC_TRNS,  KC_TRNS,   KC_TRNS,                             KC_TRNS,  KC_TRNS, KC_TRNS
  ),


  [_SYMBOLSL] = LAYOUT_pretty(
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

  [_SYMBOLSR] = LAYOUT_pretty(
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


  [_STENO] = LAYOUT_pretty(
    TG(_STENO), KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   RESET,
    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,                                                                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   STN_S1,   STN_TL,    STN_PL,   STN_HL,    STN_ST1,                                                                     STN_ST3,   STN_FR,   STN_PR,  STN_LR,  STN_TR,  STN_DR,
    KC_TRNS,   STN_S2,   STN_KL,    STN_WL,   STN_RL,    STN_ST2,                                                                     STN_ST4,   STN_RR,   STN_BR,  STN_GR,  STN_SR,  STN_ZR,
               KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,                                                                                           KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,                                               KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,                                               KC_TRNS,
                                            STN_A,  STN_O,  KC_TRNS,                                               KC_TRNS,  STN_E, STN_U
  ),


  [_KINESIS] = LAYOUT_pretty(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,         KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS,  TG(_KINESIS),   RESET,
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
