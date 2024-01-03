// Copyright 2022 Conor Burns (@Conor-Burns)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
// clang-format off
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 1
 * ,-----------------------------------------------------.     ,-------------------------------------------------------.
 * |    Q    |      W     |     E     |    R   |    T    |     |   Y  |      U     |     I     |      O     |     P    |
 * |---------+------------+-----------+--------+---------|     |------+------------+-----------+------------+----------|
 * |  A/GUI  |    S/ALT   |  D/SHIFT  |    F   |    G    |     |   H  |   J/SHIFT  |   K/CTRL  |    L/ALT   |   ;/GUI  |
 * |---------+------------+-----------+--------+---------|     |------+------------+-----------+------------+----------|
 * |    Z    |   X/ALTGR  |     C     |    V   |    B    |     |   N  |      M     |     ,     |   ./ALTGR  |     /    |
 * `---------+------------+-----------+------------------|     |------+------------+-----------+------------+----------'
 *                  |  ESC   | TAB/L1 | SPC/L2 |  MUTE   |     |  Ent |    BSPC    |   DEL/L3  |
 *                  `------------------------------------'     `-------------------------------'
 */
[0] = LAYOUT(
    KC_Q,         KC_W,         KC_E,          KC_R,          KC_T,                    KC_Y,    KC_U,          KC_I,         KC_O,           KC_P, 
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),  LSFT_T(KC_F),  KC_G,                    KC_H,    LSFT_T(KC_J),  LCTL_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_SCLN), 
    KC_Z,         ALGR_T(KC_X), KC_C,          KC_V,          KC_B,                    KC_N,    KC_M,          KC_COMM,      ALGR_T(KC_DOT), KC_SLSH, 
                                KC_ESC,       LT(1,KC_TAB),   LT(2,KC_SPC),  KC_MUTE,  KC_ENT,  KC_BSPC,       LT(3,KC_DEL)
),
[1] = LAYOUT(
    KC_ESC,       KC_NO,        KC_NO,         KC_NO,         KC_NO,                   KC_LBRC, KC_7,          KC_8,         KC_9,           KC_RBRC, 
    KC_LGUI,      KC_LALT,      KC_LCTL,       KC_LSFT,       KC_NO,                   KC_EQL,  KC_4,          KC_5,         KC_6,           KC_QUOT, 
    KC_NO,        KC_ALGR,      KC_NO,         KC_NO,         KC_NO,                   KC_BSLS, KC_1,          KC_2,         KC_3,           KC_GRV, 
                                KC_NO,         KC_TRNS,       KC_SPC,        KC_MPLY,  KC_MINS, KC_0,          KC_DOT
),
[2] = LAYOUT(
    KC_ESC,       KC_NO,        KC_NO,         KC_NO,         KC_NO,                   KC_LCBR, KC_AMPR,       KC_ASTR,      KC_LPRN,        KC_RCBR, 
    KC_LGUI,      KC_LALT,      KC_LCTL,       KC_LSFT,       KC_NO,                   KC_PLUS, KC_DLR,        KC_PERC,      KC_CIRC,        KC_COLN, 
    KC_NO,        KC_ALGR,      KC_NO,         KC_NO,         KC_NO,                   KC_PIPE, KC_EXLM,       KC_AT,        KC_HASH,        KC_TILD, 
                                KC_NO,         KC_TAB,       KC_TRNS,        KC_MPLY,  KC_UNDS, KC_LPRN,       KC_RPRN
),
[3] = LAYOUT(
    KC_ESC,       KC_NO,        KC_NO,         KC_NO,         KC_NO,                   KC_INS,  KC_HOME,       KC_UP,        KC_END,         KC_PGUP, 
    KC_LGUI,      KC_LALT,      KC_LCTL,       KC_LSFT,       KC_NO,                   CW_TOGG, KC_LEFT,       KC_DOWN,      KC_RGHT,        KC_PGDN, 
    KC_NO,        KC_ALGR,      KC_NO,         KC_NO,         KC_NO,                   U_RDO,   U_PST,         U_CPY,        U_CUT,          U_UND, 
                                KC_NO,         KC_TAB,        KC_SPC,        KC_MPLY,  KC_ENT,  KC_BSPC,       KC_TRNS
)
};
// clang-format on
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] =   { ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [2] =   { ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
    [3] =   { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    //[_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    setPinOutput(GP25);
    writePinHigh(GP25);
    debug_keyboard=true;
    // debug_mouse=true;
}
