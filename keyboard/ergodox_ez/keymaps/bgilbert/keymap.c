#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMR 2 // numeric keypad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | L2   |           |  `   |   6  |   7  |   8  |   9  |   0  |  Home  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | VolUp  |   Q  |   W  |   E  |   R  |   T  | Del  |           | Bksp |   Y  |   U  |   I  |   O  |   P  |  PgUp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | VolDn  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  PgDn  |
 * |--------+------+------+------+------+------|      |           | Tab  |------+------+------+------+------+--------|
 * | Mute   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  End   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Play | Trk< | Trk> | LGui | Bksp |                                       |  L1  |  Up  | Down | Left | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Space|      |       | RCtl | RShift |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Shift| Ctrl | Menu |       |      | Enter  |Space |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      | Alt  |       | RAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(NUMR),
        KC_VOLU, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,
        KC_VOLD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_MUTE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
        KC_MPLY, KC_MPRV, KC_MNXT, KC_LGUI, KC_BSPC,
                                                    KC_SPC,  KC_NO,
                                                             KC_APP,
                                           KC_LSFT, KC_LCTL, KC_LALT,
        // right hand
        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_HOME,
        KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PGUP,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_PGDN,
        KC_TAB,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_END,
                          MO(SYMB),KC_UP,   KC_DOWN, KC_LEFT, KC_RGHT,
        KC_RCTL, KC_RSFT,
        KC_NO,
        KC_RALT,   KC_ENT,  KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |      |           |      |      |  =   |  -   |  _   |  +   |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ^   |  &   |  *   |  :   |  ~   |------|           |------|      |  (   |  )   |  [   |  ]   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  \   |  |   |  "   |  '   |  ?   |      |           |      |      |  {   |  }   |  <   |  >   |  Calc  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_COLN, KC_TILD,
       KC_TRNS, KC_BSLS, KC_PIPE, KC_DQUO, KC_QUOT, KC_QUES, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_EQL,  KC_MINS, KC_UNDS, KC_PLUS, KC_F12,
                KC_TRNS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_CALC,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Numeric keypad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |   (  |   )  |      |   /  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   +  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |  Ent |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[NUMR] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_NO,   KC_SLSH, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_TRNS, KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_TRNS,
                         KC_0,    KC_ENT,  KC_DOT,  KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NUMR:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }
};
