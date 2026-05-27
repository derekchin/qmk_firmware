#include "derek.h"

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

#ifdef MOUSEKEY_ENABLE
#include "host.h"
#endif

static uint16_t mouse_timer = 0;
static int8_t mouse_dir = 0;
static uint32_t last_mouse_report = 0;



void leader_start_user(void) {
#ifdef RGB_MATRIX_ENABLE
    // Visual feedback: Keyboard turns Blue while waiting for sequence
    rgb_matrix_set_color_all(RGB_BLUE);
#endif
}

void leader_end_user(void) {
    // <Leader> L N sequence for Numbers Layer
    if (leader_sequence_two_keys(KC_L, KC_N)) {
        layer_on(_NUMBERS);
    }
    // <Leader> L A sequence for Arrows Layer
    else if (leader_sequence_two_keys(KC_L, KC_A)) {
        layer_on(_ARROWS);
    }
    // <Leader> L M sequence for Mouse Layer
    else if (leader_sequence_two_keys(KC_L, KC_M)) {
        layer_on(_MOUSE);
    }
    else if (leader_sequence_two_keys(KC_L, KC_G)) {
        layer_on(_GAMING);
    }
    else if (leader_sequence_one_key(KC_T)) {
        layer_on(_TABWINDOW);
    }
    // <Leader> Q to go back to QWERTY (clear all layers)
    else if (leader_sequence_one_key(KC_Q)) {
        layer_move(_QWERTY);
    }
    // <Leader> mj / mk for Mouse Jump (Left / Right)
    else if (leader_sequence_two_keys(KC_M, KC_H)) {
        mouse_timer = timer_read();
        mouse_dir = -1;
    }
    else if (leader_sequence_two_keys(KC_M, KC_L)) {
        mouse_timer = timer_read();
        mouse_dir = 1;
    }
    else {
#ifdef RGB_MATRIX_ENABLE
        // FLASH RED if the sequence failed/timed out
        rgb_matrix_set_color_all(RGB_RED);
#endif
    }
}

void matrix_scan_user(void) {
#ifdef MOUSEKEY_ENABLE
    if (mouse_dir != 0) {
        if (timer_elapsed(mouse_timer) < 300) { // 0.3 seconds
            if (timer_elapsed32(last_mouse_report) >= 10) { // 100Hz
                report_mouse_t report = {0};
                report.x = mouse_dir * 127;
                host_mouse_send(&report);
                last_mouse_report = timer_read32();
            }
        } else {
            mouse_dir = 0;
        }
    }
#endif
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keypos_t event_key = record->event.key;

        // Iterate through the key matrix to see if any momentary layer key is physically held
        for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
            for (uint8_t c = 0; c < MATRIX_COLS; c++) {
                // If a key is down, and it's not the key currently being pressed
                if (matrix_is_on(r, c) && !(r == event_key.row && c == event_key.col)) {
                    keypos_t held_key = {.row = r, .col = c};
                    // Get the keycode for the held key under the currently active layer state
                    uint16_t held_keycode = keymap_key_to_keycode(layer_switch_get_layer(held_key), held_key);

                    // Check if it's a momentary layer switch key (e.g. MO(layer))
                    if (IS_QK_MOMENTARY(held_keycode)) {
                        uint8_t target_layer = QK_MOMENTARY_GET_LAYER(held_keycode);
                        // If the target layer hasn't been activated in QMK's state yet
                        if (!layer_state_is(target_layer)) {
                            // Look up what the incoming key should do on that target layer
                            uint16_t override_keycode = keymap_key_to_keycode(target_layer, event_key);
                            if (override_keycode != KC_TRNS) {
                                record->keycode = override_keycode;
                                update_source_layers_cache(event_key, target_layer);
                                return true; // Match found, override applied
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}
