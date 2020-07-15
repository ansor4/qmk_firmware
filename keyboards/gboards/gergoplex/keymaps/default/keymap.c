/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

enum custom_keycodes {
  ONEPASS = SAFE_RANGE
};

/* Combomap
 *
 * ,------------------------------.      ,--------------------------------.
 * |      |    ESC   |     |      |      |    PLUS   |    DQO    |        |
 * |------+-----+----+-----+------|      |--------------------------------|
 * |      |    BSP  LCBR  RCBR    |      |    MIN   ENTR  QUO   QUES      | 
 * |------+-----+----+--RMB+-LMB--+		 |--------------------------------|
 * |      |     |    |     |      |      |    LES   GRT   UNDS   |        |
 * `------+-----+----+-----+------'		 `--------------------------------'
 *      .-------------------------.      .-----------------.   
 *      |        |       |        |      |        |    |   |
 *      '-------------------------'      '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |    ;   | 
 * |-----+-----+-----+-----+------+		 |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  | SHFT// |
 * `------+-----+-----+------+----'		 `--------------------------------'
 *  .-------------------------.           .--------------------------.   
 *  |DEL/ALT |BSP/CMD|SPC(SYM)|           |ENT(NUM)|SPC/CMD| TAB/SHFT|
 *  '-------------------------'           '--------------------------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,               KC_W, KC_E, KC_R, KC_T,  	KC_Y, KC_U, KC_I,    KC_O, 	 KC_P, 
    MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,  	KC_H, KC_J, KC_K,    KC_L, 	 KC_SCLN,
    MT(MOD_RSFT, KC_Z), KC_X, KC_C, KC_V, KC_B,  	KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

        // Left
        MT(MOD_LALT, KC_DEL), MT(MOD_LGUI, KC_BSPC), LT(SYMB, KC_ESC),
        // Right
        LT(NUMB, KC_ENT), MT(MOD_RGUI, KC_SPC), MT(MOD_RSFT, KC_TAB)
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.      ,--------------------------------.
 * |  !  |  @  |  #  |  $  |  %   |     |  ^  |  &  |  *  |  -  |   +   |
 * |-----+-----+-----+-----+------|     |-------------------------------|
 * |  `  |  ~  |  (  |  )  | RMB  |     |     |     |     |  |  |   \   | 
 * |-----+-----+-----+-----+------+	    |-------------------------------|
 * |     |     |  [  |  ]  | LMB  |     |     |     |     |     |       |
 * `-----+-----+-----+-----+------'	    `-------------------------------'
 *             .------------------.     .------------------.   
 *             | MMB |     	|     |		  |  =  |     |  DEL |
 *             '------------------'     '------------------' 
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS,
    KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_BTN1,   KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_BSLS,
    KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_BTN2,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      CMB_TOG, KC_TRNS, KC_TRNS,   KC_EQL,  KC_TRNS, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP | 
 * |-----+-----+-----+-----+------+	  	 |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'		   `-------------------------------'
 *  			.-----------------.         .-----------------.   
 *  			| F11 | F12|	    |   			|     | PLY | SKP |
 *  			'-----------------'         '-----------------' 
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,		 	KC_6,  	KC_7, 	 KC_8, 		KC_9, 	 KC_0,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   		KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ONEPASS,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  		KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
                 KC_F11,KC_F12,KC_TRNS,  	KC_TRNS,KC_MPLY,KC_MNXT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ONEPASS:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING(SS_LGUI("\\"));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
};