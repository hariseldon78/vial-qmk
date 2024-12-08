/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum layer_number {
    _BASE   = 0,
    _SYMBOL = 1,
    _ARROWS = 2,
    _FN     = 3,
    _MOUSE  = 4,
    _MACRO  = 5,

};

#define ESC_FN LT(3, KC_ESC)

#define I_CTL LCTL_T(KC_I)
#define E_ALT LALT_T(KC_E)
#define A_SFT LSFT_T(KC_A)

#define S_SFT RSFT_T(KC_S)
#define T_ALT LALT_T(KC_T)
#define N_CTL LCTL_T(KC_N)
#define MOUSE TG(_MOUSE)

#define EQL_GUI LGUI_T(KC_EQL)
#define CLN_MCR LT(_MACRO, KC_COLN)
#define LEAD_MCR LT(_MACRO, QK_LEAD)
#define SPC_SYM LT(_SYMBOL, KC_SPC)
#define MINS_SYM LT(_SYMBOL, KC_MINS)
#define SCLN_ARR LT(_ARROWS, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BEAKL 15
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BckSpc|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   H  |   O  |   U  |   X  |                    |   G  |   C  |   R  |   F  |   Z  |BckSpc|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |ESC_FN|   Y  | I+ctl| E+alt|A+shft|  '"  |-------.    ,-------|   D  |S+shft|T+alt |N+ctl |   B  |Enter |
     * |------+------+------+------+------+------|ScrlLck|    |ScrlLck|------+------+------+------+------+------|
     * |MOUSE |   J  |  /?  |   .  |   ,  |   K  |-------|    |-------|   W  |   M  |   L  |   P  |   V  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |  -   | /   =   /       \  :   \  |Space |  ;   |  ;   |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_BASE] = LAYOUT(

        /*---*/ KC_1, KC_2, KC_3, KC_4, KC_5, /*-----------------------------*/ KC_6, KC_7, KC_8, KC_9, KC_0,

        KC_TAB, KC_Q, KC_H, KC_O, KC_U, KC_X, /*-----------------------------*/ KC_G, KC_C, KC_R, KC_F, KC_Z, KC_BSPC,

        ESC_FN, KC_Y, I_CTL, E_ALT, A_SFT, KC_QUOT, /*-----------------------*/ KC_D, S_SFT, T_ALT, N_CTL, KC_B, KC_ENT,

        /*---*/ KC_J, KC_SLSH, KC_DOT, KC_COMM, KC_K, /*---------------------*/ KC_W, KC_M, KC_L, KC_P, KC_V,

        /*-----------*/ QK_LEAD, LEAD_MCR, MINS_SYM, EQL_GUI, /*----*/ CLN_MCR, SPC_SYM, SCLN_ARR, SCLN_ARR),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) {
        return false;
    }
    return true;
}
