// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
enum layer_names {
    BASE_LAYER = 0, // Base layer
    WIN        = 1, // Window layer
    FN         = 2, // Function layer
    SUP        = 3, // Super layer
    VIM        = 4, // Vim layer
};

#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define _______ KC_TRNS

#define XXXX KC_NO
#define XXXXX KC_NO
#define XXXXXX KC_NO
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │BLD|WIN|VIM|   │   │   │   │   |   |   |   |   |   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   |
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    |    |    │                        │   │   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [SUP] = LAYOUT_75_ansi(
        QK_BOOT, TG(WIN), TG(VIM), XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXX,   XXXXX,   XXXXX,
        XXXXXX,  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXX,  XXXXXXX,          XXXXXXX,
        XXXXXX,  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXXX,          XXXXXX,           XXXXXXX,
        XXXXXXX,          XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXX,  XXXXXXX,          XXXXXXX, XXXXX,   XXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │B- |B+ |   │   │   │   │<< |>| |>> |Vx |V- |V+ │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   |
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    |    |    │                        │   │   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [FN] = LAYOUT_75_ansi(
        XXXXXX,  KC_BRID, KC_BRIU, XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXX,   XXXXX,   XXXXX,
        XXXXXX,  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXX,  XXXXXXX,          XXXXXXX,
        XXXXXX,  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXXX,          XXXXXX,           XXXXXXX,
        XXXXXXX,          XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXXXXX, XXXXXX,  XXXXXXX,          XXXXXXX, XXXXX,   XXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXX,                             XXXXXXX, XXXXXXX, MO(SUP), XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ESC   │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   |
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    |    |    │                        │   │   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [VIM] = LAYOUT_75_ansi(
        ______,  _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,
        ______,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, ______,  _______,          _______,
        ______,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, _______, _______,          _______,
        KC_ESC,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, _______,          ______,           _______,
        _______,          ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, ______,  _______,          _______, _____,   ______,
        _______, _______, _______,                            ______,                             _______, _______, _______, _______, _______, _______
    ),
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │   |
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    |GUI |Alt │                        │Alt│   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [WIN] = LAYOUT_75_ansi(
        ______,  _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,
        ______,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, ______,  _______,          _______,
        ______,  ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, _______, _______,          _______,
        _______, ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, _______,          ______,           _______,
        _______,          ____,    ____,    ____,    ____,    ____,    ____,    ____,    _______, ______,  _______,          _______, _____,   ______,
        _______, KC_LGUI, KC_LALT,                            ______,                             KC_RALT, _______, _______, _______, _______, _______
    ),
     /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│Pse│Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │Hom│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │End│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│Alt │GUI │                        │Alt│Fn │Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [BASE_LAYER] = LAYOUT_75_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______, KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(FN),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    )
};

#ifdef RGB_MATRIX_ENABLE
// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case BASE_LAYER:
//             break;
//         case FN:
//             rgb_matrix_set_color(1, RGB_CYAN);
//             rgb_matrix_set_color(2, RGB_CYAN);
//             rgb_matrix_set_color(7, RGB_CYAN);
//             rgb_matrix_set_color(8, RGB_CYAN);
//             rgb_matrix_set_color(9, RGB_CYAN);
//             rgb_matrix_set_color(10, RGB_CYAN);
//             rgb_matrix_set_color(11, RGB_CYAN);
//             rgb_matrix_set_color(12, RGB_CYAN);
//             break;
//     }
//     return state;
// }

bool rgb_matrix_indicators_user(void) {
    // sn32f2xx_set_color(1, RGB_CYAN);
    // sn32f2xx_set_color(2, RGB_CYAN);
    // sn32f2xx_set_color(7, RGB_CYAN);
    // sn32f2xx_set_color(8, RGB_CYAN);
    // sn32f2xx_set_color(9, RGB_CYAN);
    // sn32f2xx_set_color(10, RGB_CYAN);
    // sn32f2xx_set_color(11, RGB_CYAN);
    // sn32f2xx_set_color(12, RGB_CYAN);

    // rgb_matrix_set_color(0, 0, 255, 0);
    // rgb_matrix_set_color(1, 0, 0, 255);
    // rgb_matrix_set_color(20, 255, 0, 0);
    // rgb_matrix_set_color(60, 255, 0, 0);
    // rgb_matrix_set_color(61, 0, 255, 0);

    sn32f2xx_set_color(0, 0, 255, 0);
    sn32f2xx_set_color(1, 0, 0, 255);
    sn32f2xx_set_color(20, 255, 0, 0);
    sn32f2xx_set_color(60, 255, 0, 0);
    sn32f2xx_set_color(61, 0, 255, 0);

    return true;
}
#endif

typedef union {
    uint32_t raw;
    struct {
        bool vim_mode : 1;
        bool win_mode : 1;
    };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;

    user_config.raw = eeconfig_read_user();
    
    if (user_config.vim_mode) {
        layer_on(VIM);
    }
    if (user_config.win_mode) {
        layer_on(WIN);
    }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
    user_config.raw = 0;
    user_config.vim_mode = true;
    user_config.win_mode = true;
    eeconfig_update_user(user_config.raw);
    
    layer_on(VIM);
    layer_on(WIN);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG(WIN):
            if (record->event.pressed) {
                user_config.win_mode ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return true;
        case TG(VIM):
            if (record->event.pressed) {
                user_config.vim_mode ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return true;
        default:
            return true;
    }
}
