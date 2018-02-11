// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _DEFAULT 0
#define _LAYERPICKER 1
#define _MOUSE 2
#define _ARROWS 3
#define _WIN 4
#define _NUM 5
#define _SYMBOL 6
#define _MACROS1 7
#define _MACROS2 8
#define _MACROS3 9
#define _RESET 10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
  { KC_GRAVE,          LT(_MACROS1,KC_1),  LT(_MACROS2,KC_2),  LT(_MACROS3,KC_3),     LT(_SYMBOL,KC_4),   LT(_SYMBOL,KC_5),   KC_TRNS,   KC_6,    KC_7,             KC_8,    KC_9,      KC_0,                    KC_MINS},
  { KC_TAB,            KC_Q,               KC_W,               KC_E,                  KC_R,               KC_T,               KC_TRNS,   KC_Y,    KC_U,             KC_I,    KC_O,      KC_P,                    KC_BSLASH},
  { CTL_T(KC_ESCAPE),  KC_A,               KC_S,               LT(_NUM,KC_D),         LT(_SYMBOL,KC_F),   KC_G,               KC_TRNS,   KC_H,    LT(_SYMBOL,KC_J), KC_K,    KC_L,      LT(_MOUSE, KC_SCLN),     KC_QUOT},
  { KC_LSFT,           LT(_ARROWS,KC_Z),   KC_X,               KC_C,                  KC_V,               KC_B,               KC_SPC,    KC_N,    KC_M,             KC_COMM, KC_DOT,    KC_SLSH,                 KC_RSFT},
  { OSM(MOD_HYPR),     OSM(MOD_MEH),       KC_LALT,            KC_F19,                LT(_WIN,KC_F20),    KC_LGUI,            KC_BSPC,   KC_SPC,  KC_EQL,           KC_LBRC, KC_RBRC,   OSM(MOD_MEH),            OSM(MOD_HYPR) }
},


[_LAYERPICKER] = {
  { KC_TRNS,              KC_TRNS,            KC_TRNS,           KC_TRNS,             KC_TRNS,           KC_TRNS,             KC_TRNS,  KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS,   KC_TRNS,                 KC_TRNS },
  { KC_TRNS,              KC_TRNS,            KC_TRNS,           KC_TRNS,             KC_TRNS,           KC_TRNS,             KC_TRNS,  KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS,   KC_TRNS,                 KC_TRNS },
  { TO(_DEFAULT),         TO(_ARROWS),        KC_TRNS,           TO(_NUM),            TO(_SYMBOL),       KC_TRNS,             KC_TRNS,  KC_TRNS,   TO(_SYMBOL),     KC_TRNS, KC_TRNS,   TO(_MOUSE),              KC_TRNS },
  { KC_TRNS,              KC_TRNS,            KC_TRNS,           KC_TRNS,             KC_TRNS,           KC_TRNS,             KC_TRNS,  KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS,   KC_TRNS,                 KC_TRNS },
  { KC_TRNS,              KC_TRNS,            KC_TRNS,           KC_TRNS,             KC_TRNS,           KC_TRNS,             KC_TRNS,  KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS,   KC_TRNS,                 KC_TRNS }
},


[_MOUSE] = {
  { TO(_DEFAULT),  KC_F1,   KC_F2,        KC_F3,   KC_F4,       KC_F5,   KC_TRNS,                 KC_F6,                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
  { KC_TRNS,       KC_TRNS, HYPR(KC_F1),  KC_MS_U, HYPR(KC_F2), KC_TRNS, KC_TRNS,                 KC_F12,                   KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS },
  { TO(_DEFAULT),  KC_TRNS, KC_MS_L,      KC_MS_D, KC_MS_R,     KC_TRNS, KC_TRNS,                 KC_TRNS,                  KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS },
  { TO(_RESET),    KC_TRNS, HYPR(KC_F3),  KC_TRNS, HYPR(KC_F4), KC_TRNS, KC_TRNS,                 KC_TRNS,                  KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,       KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,     KC_ENT,  LGUI(LSFT(KC_LBRACKET)), LGUI(LSFT(KC_RBRACKET)),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_ARROWS] = {
  { TO(_DEFAULT),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { TO(_DEFAULT),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_LEFT,           KC_DOWN,  KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS },
  { KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_LBRACKET), LGUI(KC_RBRACKET), KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_WIN] = {
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, LCTL(KC_4),     LCTL(KC_5),     LCTL(KC_6),     KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, LCAG(KC_1),     LCAG(KC_UP),    LCAG(KC_3),     KC_TRNS, KC_TRNS },
  { TO(_DEFAULT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, LCAG(KC_LEFT),  LCAG(KC_M),     LCAG(KC_RIGHT), KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, LCAG(KC_2),     LCAG(KC_DOWN),  LCAG(KC_4),     KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS }
},

[_NUM] = {
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS },
  { TO(_DEFAULT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_0, KC_0, KC_KP_DOT, KC_PENT, KC_PENT }
},

[_SYMBOL] = {
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS },
  { TO(_DEFAULT), KC_LABK, KC_LCBR, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_RBRC, KC_RCBR, KC_RABK, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_MACROS1] = {
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { TO(_DEFAULT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_MACROS2] = {

  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { TO(_DEFAULT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_MACROS3] = {
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { TO(_DEFAULT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},



[_RESET] = {
  { TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
  { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
  { TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
  { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
  { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
}


/*
[_TRNS] = {
  { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};
