#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BkSp |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |; / L2|'/Cmd |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|Z/Ctrl|   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |//Ctrl|RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |Grv/L1|  '"  |AltShf| Left | Right|                                  |  Up  | Down |   [  |   ]  | ~L1  |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | App  | LGui |  | Alt  | ^/Esc|
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Home |  | PgUp |      |      |
 *                               | Space|Backsp|------|  |------|  Tab |Enter |
 *                               |      |ace   | End  |  | PgDn |      |      |
 *                               `--------------------'  `--------------------'
 */
[BASE] = LAYOUT_dactyl(  // layer 0 : default
        // left hand
          KC_GRV,      KC_1,     KC_2,     KC_3,    KC_4,  KC_5,
          KC_TAB,      KC_Q,     KC_W,     KC_E,    KC_R,  KC_T,
          KC_CAPS,     KC_A,     KC_S,     KC_D,    KC_F,  KC_G,
          KC_LSFT,     KC_Z,     KC_X,     KC_C,    KC_V,  KC_B,
          KC_LCTL,  KC_SLSH,  KC_LGUI,  KC_LALT,  KC_ESC,
                                                                  LCTL(KC_C),    MO(SYMB),
                                                                               LCTL(KC_V),
                                                             KC_APP, KC_BSPC,      KC_DEL,
        // right hand
                             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_MINS,
                             KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,        KC_LBRC,
                             KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,        KC_QUOT,
                             KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_RBRC,        KC_RSFT,
                                    KC_LEFT,    KC_UP,  KC_RGHT,  KC_DOWN,  KC_NONUS_HASH,
          MO(MDIA),  KC_PGUP,
           KC_PSCR,
            KC_ENT,   KC_SPC,  KC_PGDN
    ),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Versn |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |                    |  Up  |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |                    | Down |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |                    |   &  |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |RESET |      |      |      |      |                                  |      |   .  |   0  |   =  |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_dactyl(
       // left hand
       _______,       _______,        _______,        _______,       _______,        _______,
       _______,    ALGR(KC_6),     ALGR(KC_7),     ALGR(KC_8),  LSFT(KC_EQL),        _______,
       _______,        KC_EQL,  ALGR(KC_LBRC),  ALGR(KC_QUOT),    LSFT(KC_8),        KC_NUBS,
       _______,  ALGR(KC_EQL),  ALGR(KC_RBRC),  ALGR(KC_NUHS),    LSFT(KC_9),  LSFT(KC_NUBS),
       _______,       _______,        _______,        _______,       _______,
                                                                                           _______,  _______,
                                                                                                     _______,
                                                                                 _______,  _______,  _______,
       // right hand   
                _______,    KC_P7,    KC_P8,    KC_P9,  KC_PSLS,  _______,
                _______,    KC_P4,    KC_P5,    KC_P6,  KC_PAST,  _______,
                _______,    KC_P1,    KC_P2,    KC_P3,  KC_PMNS,  _______,
                _______,    KC_P0,  KC_PDOT,  KC_PENT,  KC_PPLS,  _______,
                          _______,  _______,  _______,  _______,  _______,
      _______,  _______,
      _______,
      _______,  _______,  _______
),
/* Keymap 2: Media and mouse keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | MsUp |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      |                    |      |      |      |      |      | Play |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | Prev | Next |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      | Lclk | Rclk |                                  | VolUp| VolDn| Mute |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |Brwser|
 *                               |      |      |------|  |------|      |Back  |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_dactyl(
       _______,        _______,     KC_MUTE,     KC_VOLD,     KC_VOLU,  _______,
       _______,        _______,     _______,  ALGR(KC_E),     _______,  _______,
       _______,  ALGR(KC_NUBS),  ALGR(KC_1),  ALGR(KC_2),  ALGR(KC_3),  KC_PGUP,
       _______,        _______,      KC_INS,     KC_HOME,      KC_END,  KC_PGDN,
       _______,        _______,     _______,     _______,     _______,
                                                         _______,  _______,
                                                                   _______,
                                               _______,  _______,  _______,
    // right hand
                _______,  _______,  _______,  _______,  _______,  _______,
                _______,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______,
                _______,    KC_F5,    KC_F6,    KC_F7,    KC_F8,  _______,
                _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,  _______,
                          _______,  _______,  _______,  _______,  _______,
      _______,  _______,
      _______,
      _______,  _______,  KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};
