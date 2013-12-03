/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K2C, K0C,  K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K3C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A,      K4C, K3D, \
    K40, K41, K42,           K45,                K49, K4A,      K5C, K4D  \
) { \
    { KC_NO,   K40,   K30,   K20,   K10,   K00 }, \
    { K41,     K31,   K21,   K11,   K01,   KC_NO }, \
    { K42,     K32,   K22,   K12,   K02,   KC_NO }, \
    { KC_NO,   K33,   K23,   K13,   K03,   KC_NO }, \
    { KC_NO,   K34,   K24,   K14,   K04,   KC_NO }, \
    { K45,     K35,   K25,   K15,   K05,   KC_NO }, \
    { KC_NO,   K36,   K26,   K16,   K06,   KC_NO }, \
    { KC_NO,   K37,   K27,   K17,   K07,   KC_NO }, \
    { KC_NO,   K38,   K28,   K18,   K08,   KC_NO }, \
    { K49,     K39,   K29,   K19,   K09,   KC_NO }, \
    { K4A,     K3A,   K2A,   K1A,   K0A,   KC_NO }, \
    { KC_NO,   KC_NO, K2B,   K1B,   K0B,   KC_NO }, \
    { K5C,     K4C,   KC_NO, K3C,   K2C,   K0C }, \
    { K4D,     K3D,   K2D,   K1D,   K0D,   KC_NO } \
}

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // KEYMAP(
    //     ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV, BSPC, 
    //     TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, 
    //     FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  
    //     LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,    RSFT, UP,
    //     LCTL,LGUI,LALT,          SPC,                     RCTL, LEFT,RGHT, DOWN),
    // KEYMAP(
    //     ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,BSPC, 
    //     TAB,PGDN, UP, PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,INS, PSCR,  
    //     FN1,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,      ENT, 
    //     LSFT,TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,END,PGDN      ,UP, RSFT, 
    //     LCTL,CAPS,LALT,          SPC,                     RCTL,LEFT,DOWN,RGHT),


KEYMAP(  
        KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSPC, \
        KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_LBRC,KC_RBRC,      KC_BSLS, \
        KC_FN0,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN, KC_QUOT,           KC_ENT, \
        KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,      KC_RSFT,      KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,             KC_SPC,               KC_RCTL, KC_LEFT,KC_RGHT,      KC_DOWN),
    KEYMAP(
        KC_ESC,  KC_F1,    KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,  KC_F8,  KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL, KC_BSPC, \
        KC_TAB,  KC_PGUP,  KC_UP,   KC_PGDN,  KC_NO, KC_NO, KC_NO,  KC_NO,KC_NO,KC_NO,  KC_NO,    KC_NO,    KC_INS,          KC_PSCR, \
        KC_FN1,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_NO, KC_NO, KC_NO,  KC_NO,KC_NO,KC_NO,  KC_HOME,    KC_PGUP,                      KC_ENT, \
        KC_LSFT, KC_NO,    KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_END,  KC_PGDN,            KC_UP,          KC_RSFT, \
        KC_LCTL, KC_CAPS,  KC_LALT,           KC_SPC,                    KC_RCTL,           KC_LEFT,            KC_DOWN,          KC_RGHT),



};
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(1),
    [1] = ACTION_DEFAULT_LAYER_SET(0)
};
#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))
/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, key_t key)
{
    return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return (action_t){ .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]) };
}
