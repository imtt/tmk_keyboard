#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,    RSFT, UP,\
        LCTL,LGUI,LALT,          SPC,                     RCTL, LEFT,RGHT, DOWN),
    /* 2: Poker Fn
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
     * |-----------------------------------------------------------|
     * |     |FnQ| Up|   |   |   |   |   |   |Cal|   |Hom|Ins|FnL  |
     * |-----------------------------------------------------------|
     * |      |Lef|Dow|Rig|   |   |Psc|Slk|Pau|   |Tsk|End|        |
     * |-----------------------------------------------------------|
     * |        |Del|   |Web|Mut|VoU|VoD|   |PgU|PgD|Del|          |
     * |-----------------------------------------------------------|
     * |    |    |    |         FnS            |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,BSPC, \
        TAB,PGDN, UP, PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,INS, PSCR,  \
        FN1,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,      ENT, \
        LSFT,TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,END,PGDN,      ,UP, RSFT, \
        LCTL,CAPS,LALT,          SPC,                     RCTL,LEFT,DOWN,RGHT),
};
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(1);
    [1] = ACTION_DEFAULT_LAYER_SET(0);
};
