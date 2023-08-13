#pragma once
#include "keycodes.h"
#include "keymap_german_mac_iso.h"
#include QMK_KEYBOARD_H
#include "version.h"
#include "ergodox_ez.h"

/*
#define RGBLIGHT_COLOR_LAYER_0 0xFF, 0x40, 0x00
#define RGBLIGHT_COLOR_LAYER_1 0x00, 0x00, 0xFF
#define RGBLIGHT_COLOR_LAYER_2 0xFF, 0x00, 0x00
#define RGBLIGHT_COLOR_LAYER_3 0x00, 0xFF, 0x00
*/
// #define RGBLIGHT_COLOR_LAYER_4 0xFF, 0xFF, 0x00
// #define RGBLIGHT_COLOR_LAYER_5 0x00, 0xFF, 0xFF
// #define RGBLIGHT_COLOR_LAYER_6 0xFF, 0x00, 0xFF
// #define RGBLIGHT_COLOR_LAYER_7 0xFF, 0xFF, 0xFF

// Utilities for defining combos:
#define LAYER_COMBO(n, layer, a, b) \
    const uint16_t PROGMEM COMBO_ ## layer ## _ ## n[] = {layer ## _ ## a, layer ## _ ## b, COMBO_END}
#define DEF_COMBO(layer, n, key_a, key_b) LAYER_COMBO(n, layer, key_a, key_b)

enum custom_keycodes {
// Macros:
    MACRO_MENU = SAFE_RANGE,
    VRSN
};

// Layers:
enum layers {
    PUQ,
    SYM,
    NAV,
    FCT
};

#define PUQ_MASK (1 << PUQ)
#define SYM_MASK (1 << SYM)
#define NAV_MASK (1 << NAV)
#define FCT_MASK (1 << FCT)

/* naming scheme for Key #defines:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │ L7 │ L8 │ L9 ├────┐           ┌────┤ R7 │ R8 │ R9 │
       ├────┼────┼────┤ LA │           │ RA ├────┼────┼────┤
  ┌────┤ L4 │ L5 │ L6 ├────┤           ├────┤ R4 │ R5 │ R6 ├────┐
  │ LP ├────┼────┼────┤ LB │           │ RB ├────┼────┼────┤ RP │
  └────┤ L1 │ L2 │ L3 ├────┘           └────┤ R1 │ R2 │ R3 ├────┘
       └────┴────┴────┼────┬────┐ ┌────┬────┼────┴────┴────┘
                      │ LS │ LE │ │ RE │ RS │
                      └────┴────┘ └────┴────┘
Example: PUQ_LP refers to the binding for the left-hand pinky on the "PUQ" layer.
*/

/* Layer PUQ:

   Legend:
   - Capital letters indicate ordinary characters
   - Lower case letters:
       ⎈: CTRL
       ⌥: Alt
       ⌘: GUI key (CMD on Mac)
       ⇧: Shift
   - `⎄` is the compose key. Used to type German umlauts (and lots of other stuff when used with
         SHFT).

          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ●┈┈ , ┈┈◐┈┈ ⌦ ┈┈○   │                           │   ●┈┈ ⌫ ┈┈◐┈┈ . ┈┈○   │
          │   M   │   L   │   C   ├───────┐           ┌───────┤   F   │   ⎄   │   U   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   G   │           │   Q   ├───────┼───────┼───────┤
          │   ●┈┈NAV┈┈◐┈┈SYM┈┈○   │ ⌥ ⎈ ⌘ │           │ ⌥ ⎈ ⌘ │   ●┈┈SYM┈┈◐┈┈NAV┈┈○   │
          │   N   │   R   │   T   ├───────┤           ├───────┤   A   │   E   │   I   │
          │   ●┈┈┈┈┈ FCT ┈┈┈┈┈●   │       │           │       │   ●┈┈┈┈┈ FCT ┈┈┈┈┈●   │
  ┌───────┼───────┼───────┼───────┤   D   │           │   O   ├───────┼───────┼───────┼───────┐
  │       │   ●┈┈ Z ┈┈◐┈┈ J ┈┈○   │ ⎈     │           │ ⎈     │   ●┈┈ X ┈┈◐┈┈ K ┈┈○   │       │
  │   S   │   B   │   W   │   V   ├───────┘           └───────┤   _   │   P   │   Y   │   H   │
  │ ⌥     │       │       │       │                           │       │       │       │ ⌥     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │   ␣   │  Esc  │ │   ⏎   │   ␣   │
                               │ ⇧     │ ⌘     │ │ ⌘     │ ⇧     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define PUQ_LP MT(MOD_LALT, DE_S)
#define PUQ_L1 DE_B
#define PUQ_L2 DE_W
#define PUQ_L3 DE_V
#define PUQ_L4 DE_N
#define PUQ_L5 DE_R
#define PUQ_L6 DE_T
#define PUQ_L7 DE_M
#define PUQ_L8 DE_L
#define PUQ_L9 DE_C
#define PUQ_LA MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_G)
#define PUQ_LB MT(MOD_LCTL, DE_D)
#define PUQ_LS MT(MOD_LSFT, KC_SPACE)
#define PUQ_LE MT(MOD_LGUI, KC_ESCAPE)
#define PUQ_RP MT(MOD_LALT, DE_H)
#define PUQ_R1 DE_UNDS
#define PUQ_R2 DE_P
#define PUQ_R3 DE_Y
#define PUQ_R4 DE_A
#define PUQ_R5 DE_E
#define PUQ_R6 DE_I
#define PUQ_R7 DE_F
#define PUQ_R8 C(KC_F13) // quick-compose key. add SHIFT for full compose key
#define PUQ_R9 DE_U
#define PUQ_RA MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_Q)
#define PUQ_RB MT(MOD_LCTL, DE_O)
#define PUQ_RS MT(MOD_LSFT, KC_SPACE)
#define PUQ_RE MT(MOD_LGUI, KC_ENTER)

#define PUQL12 DE_Z
#define PUQL23 DE_J
#define PUQL45 MO(NAV)
#define PUQL46 OSL(FCT)
#define PUQL56 MO(SYM)
#define PUQL78 DE_COMM
#define PUQL89 KC_DELETE
#define PUQR12 DE_X
#define PUQR23 DE_K
#define PUQR45 PUQL56
#define PUQR46 PUQL46
#define PUQR56 PUQL45
#define PUQR78 KC_BACKSPACE
#define PUQR89 DE_DOT
DEF_COMBO(PUQ, 01, L1, L2);
#define COMBO_PUQ_01_ACTION PUQL12
DEF_COMBO(PUQ, 02, L2, L3);
#define COMBO_PUQ_02_ACTION PUQL23
DEF_COMBO(PUQ, 03, L4, L5);
#define COMBO_PUQ_03_ACTION PUQL45
DEF_COMBO(PUQ, 04, L4, L6);
#define COMBO_PUQ_04_ACTION PUQL46
DEF_COMBO(PUQ, 05, L5, L6);
#define COMBO_PUQ_05_ACTION PUQL56
DEF_COMBO(PUQ, 06, L7, L8);
#define COMBO_PUQ_06_ACTION PUQL78
DEF_COMBO(PUQ, 07, L8, L9);
#define COMBO_PUQ_07_ACTION PUQL89
DEF_COMBO(PUQ, 08, R1, R2);
#define COMBO_PUQ_08_ACTION PUQR12
DEF_COMBO(PUQ, 09, R2, R3);
#define COMBO_PUQ_09_ACTION PUQR23
DEF_COMBO(PUQ, 10, R4, R5);
#define COMBO_PUQ_10_ACTION PUQR45
DEF_COMBO(PUQ, 11, R4, R6);
#define COMBO_PUQ_11_ACTION PUQR46
DEF_COMBO(PUQ, 12, R5, R6);
#define COMBO_PUQ_12_ACTION PUQR56
DEF_COMBO(PUQ, 13, R7, R8);
#define COMBO_PUQ_13_ACTION PUQR78
DEF_COMBO(PUQ, 14, R8, R9);
#define COMBO_PUQ_14_ACTION PUQR89

const key_override_t shift_comma_is_dash = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        DE_COMM,
        DE_NDSH,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );
const key_override_t shift_dot_is_bullet = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        DE_DOT,
        DE_BULT,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );

/* Layer SYM:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ○┈┈ … ┈┈◑┈┈ ⌦ ┈┈●   │                           │   ●┈┈ ⌫ ┈┈●   │       │
          │   &   │   [   │   ]   ├───────┐           ┌───────┤   <   │   >   │   =   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   ^   │           │   !   ├───────┼───────┼───────┤
          │       │       │       │       │           │       │       │       │       │
          │   /   │   {   │   }   ├───────┤           ├───────┤   (   │   )   │   -   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤   *   │           │   ?   ├───────┼───────┼───────┼───────┐
  │       │       │       │       │       │           │       │       │       │       │       │
  │   \   │   $   │   |   │   ~   ├───────┘           └───────┤   %   │   "   │   '   │   :   │
  │       │       │       │       │                           │       │       │       │       │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │   #   │   `   │ │   +   │   ;   │
                               │       │       │ │       │       │
                               └───────┴───────┘ └───────┴───────┘
*/

#define SYM_LP DE_BSLS
#define SYM_L1 DE_DLR
#define SYM_L2 DE_PIPE
#define SYM_L3 DE_TILD
#define SYM_L4 DE_SLSH
#define SYM_L5 DE_LCBR
#define SYM_L6 DE_RCBR
#define SYM_L7 DE_AMPR
#define SYM_L8 DE_LBRC
#define SYM_L9 DE_RBRC
#define SYM_LA DE_CIRC
#define SYM_LB DE_ASTR
#define SYM_LS DE_HASH
#define SYM_LE DE_GRV
#define SYM_RP DE_COLN
#define SYM_R1 DE_PERC
#define SYM_R2 DE_DQUO
#define SYM_R3 DE_QUOT
#define SYM_R4 DE_LPRN
#define SYM_R5 DE_RPRN
#define SYM_R6 DE_MINS
#define SYM_R7 DE_LABK
#define SYM_R8 DE_RABK
#define SYM_R9 DE_EQL
#define SYM_RA DE_EXLM
#define SYM_RB DE_QUES
#define SYM_RS DE_SCLN
#define SYM_RE DE_PLUS

DEF_COMBO(SYM, 01, L7, L8);
#define COMBO_SYM_01_ACTION DE_ELLP
DEF_COMBO(SYM, 02, L8, L9);
#define COMBO_SYM_02_ACTION KC_DELETE
DEF_COMBO(SYM, 03, R7, R8);
#define COMBO_SYM_03_ACTION KC_BACKSPACE

/* Layer NAV:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ○┈┈ ⌫ ┈┈◑┈┈ ⌦ ┈┈●   │                           │   ●┈┈ ⌫ ┈┈●   │       │
          │   ⇞   │   ↑   │   ⇟   ├───────┐           ┌───────┤   7   │   8   │   9   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤       │           │   *   ├───────┼───────┼───────┤
          │       │       │       │       │           │       │       │   ●┈┈ = ┈┈●   │
          │   ←   │   ↓   │   →   ├───────┤           ├───────┤   4   │   5   │   6   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤   ↠   │           │   /   ├───────┼───────┼───────┼───────┐
  │       │       │       │       │       │           │ ⎈     │   ●┈┈ . ┈┈◐┈┈ - ┈┈○   │       │
  │   ↞   │   ⇥   │   ⎀   │   ⏎   ├───────┘           └───────┤   1   │   2   │   3   │   +   │
  │       │       │       │       │                           │       │       │       │ ⌥     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │   ␣   │  Esc  │ │   ⏎   │   0   │
                               │ ⇧     │ ⌘     │ │ ⌘     │ ⇧     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define NAV_LP G(KC_LEFT)
#define NAV_L1 KC_TAB
#define NAV_L2 KC_INSERT
#define NAV_L3 KC_ENTER
#define NAV_L4 KC_LEFT
#define NAV_L5 KC_DOWN
#define NAV_L6 KC_RIGHT
#define NAV_L7 KC_PAGE_UP
#define NAV_L8 KC_UP
#define NAV_L9 KC_PAGE_DOWN
#define NAV_LA XXXXXXX
#define NAV_LB G(KC_RIGHT)
#define NAV_LS MT(MOD_LSFT, KC_SPACE)
#define NAV_LE MT(MOD_LGUI, KC_ESCAPE)
#define NAV_RP MT(MOD_LALT, KC_KP_PLUS)
// We don't use the keypad numbers (KC_KP_...) here, because the normal number keys are more
// universal. Some apps may have special semantics for keypad numbers, and bindings in
// DefaultKeyBindings.dict are based on the normal numbers, as well.
#define NAV_R1 KC_1
#define NAV_R2 KC_2
#define NAV_R3 KC_3
#define NAV_R4 KC_4
#define NAV_R5 KC_5
#define NAV_R6 KC_6
#define NAV_R7 KC_7
#define NAV_R8 KC_8
#define NAV_R9 KC_9
#define NAV_RA KC_KP_ASTERISK
#define NAV_RB MT(MOD_LCTL, KC_KP_SLASH)
#define NAV_RS MT(MOD_LSFT, KC_0)
#define NAV_RE MT(MOD_LGUI, KC_ENTER)

#define NAVL78 KC_BACKSPACE
#define NAVL89 KC_DELETE
#define NAVR12 KC_KP_DOT
#define NAVR23 KC_KP_MINUS
#define NAVR56 DE_EQL
#define NAVR78 KC_BACKSPACE
DEF_COMBO(NAV, 01, L7, L8);
#define COMBO_NAV_01_ACTION NAVL78
DEF_COMBO(NAV, 02, L8, L9);
#define COMBO_NAV_02_ACTION NAVL89
DEF_COMBO(NAV, 03, R1, R2);
#define COMBO_NAV_03_ACTION NAVR12
DEF_COMBO(NAV, 04, R2, R3);
#define COMBO_NAV_04_ACTION NAVR23
DEF_COMBO(NAV, 05, R5, R6);
#define COMBO_NAV_05_ACTION NAVR56
DEF_COMBO(NAV, 06, R7, R8);
#define COMBO_NAV_06_ACTION NAVR78

/* Layer FCT:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │       │       │       │                           │       │       │       │
          │   F7  │   F8  │   F9  ├───────┐           ┌───────┤   🔉  │   🔇  │   🔊  │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤  F10  │           │       ├───────┼───────┼───────┤
          │       │       │       │ ⌥ ⎈ ⌘ │           │ ⌥ ⎈ ⌘ │       │       │       │
          │   F4  │   F5  │   F6  ├───────┤           ├───────┤   ⏮   │   ⏯   │   ⏭   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤  F11  │           │       ├───────┼───────┼───────┼───────┐
  │       │       │       │       │ ⎈     │           │ ⎈     │       │       │       │       │
  │  F12  │   F1  │   F2  │   F3  ├───────┘           └───────┤   🔅  │  F20  │   🔆  │   ☰   │
  │ ⌥     │       │       │       │                           │       │       │       │ ⌥     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │  L-🐭 │  R-🐭 │ │  L-🐭 │  R-🐭 │
                               │ ⇧     │ ⌘     │ │ ⌘     │ ⇧     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define FCT_LP MT(MOD_LALT, KC_F12)
#define FCT_L1 KC_F1
#define FCT_L2 KC_F2
#define FCT_L3 KC_F3
#define FCT_L4 KC_F4
#define FCT_L5 KC_F5
#define FCT_L6 KC_F6
#define FCT_L7 KC_F7
#define FCT_L8 KC_F8
#define FCT_L9 KC_F9
#define FCT_LA MT(MOD_LCTL|MOD_LALT|MOD_LGUI, KC_F10)
#define FCT_LB MT(MOD_LCTL, KC_F11)
#define FCT_LS MT(MOD_LSFT, KC_MS_BTN1)
#define FCT_LE MT(MOD_LGUI, KC_MS_BTN2)
#define FCT_RP MT(MOD_LALT, MACRO_MENU)
#define MACRO_MENU_KEY FCT_RP
#define FCT_R1 KC_BRIGHTNESS_DOWN
#define FCT_R2 KC_F20 // mapped to `mic key` in BetterTouchTool
#define FCT_R3 KC_BRIGHTNESS_UP
#define FCT_R4 KC_MEDIA_PREV_TRACK
#define FCT_R5 KC_MEDIA_PLAY_PAUSE
#define FCT_R6 KC_MEDIA_NEXT_TRACK
#define FCT_R7 KC_AUDIO_VOL_DOWN
#define FCT_R8 KC_AUDIO_MUTE
#define FCT_R9 KC_AUDIO_VOL_UP
#define FCT_RA C(A(KC_LGUI))
#define FCT_RB KC_LCTL
#define FCT_RS MT(MOD_LSFT, KC_MS_BTN2)
#define FCT_RE MT(MOD_LGUI, KC_MS_BTN1)

// We want HOLD_ON_OTHER_KEY_PRESS for all combos, but not for the single-finger CTRL and ALT mod-taps:
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PUQ_LP:
        case PUQ_RP:
        case PUQ_LA:
        case PUQ_RA:
        case PUQ_LB:
        case PUQ_RB:
            return false;
        default:
            return true;
    }
}

uint8_t color_wheel;
uint16_t energy;

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    color_wheel = 0;
    energy = 256;
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
void wheel( uint8_t wheel_pos ) {
  wheel_pos = 255 - wheel_pos;

  if ( wheel_pos < 85 ) {
    rgblight_setrgb( 255 - wheel_pos * 3, 0, wheel_pos * 3 );
  } else if( wheel_pos < 170 ) {
    wheel_pos -= 85;
    rgblight_setrgb( 0, wheel_pos * 3, 255 - wheel_pos * 3 );
  } else {
    wheel_pos -= 170;
    rgblight_setrgb( wheel_pos * 3, 255 - wheel_pos * 3, 0 );
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        energy += 100;
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;

            case MACRO_MENU_KEY:
                // I have mapped double tapping the CMD key to show the context menu in BetterTouchTool.
                tap_code(KC_LGUI);
                tap_code(KC_LGUI);
                // Since not all apps seem to define a propper context menu, we try S(KC_F10) as
                // well:
                tap_code16(S(KC_F10));
                return false;
        }
    }
    return true;
}

void matrix_scan_user(void) {
    if (energy > 0) {
        wheel(color_wheel);
        color_wheel = (color_wheel + 1) % 256;
        energy -= 1;
    }
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

// Key Overrides:
const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_comma_is_dash,
    &shift_dot_is_bullet,
    NULL // terminator
};

#define __xx__ XXXXXXX

// Keymaps (not much info here):
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PUQ] = LAYOUT_ergodox_pretty(
      __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,     __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
      __xx__, __xx__, PUQ_L7, PUQ_L8, PUQ_L9, PUQ_LA, __xx__,     __xx__, PUQ_RA, PUQ_R7, PUQ_R8, PUQ_R9, __xx__, __xx__,
      __xx__, PUQL78, PUQ_L4, PUQ_L5, PUQ_L6, PUQ_LB,                     PUQ_RB, PUQ_R4, PUQ_R5, PUQ_R6, PUQR89, __xx__,
      PUQL56, PUQ_LP, PUQ_L1, PUQ_L2, PUQ_L3, PUQL23, __xx__,     __xx__, PUQR12, PUQ_R1, PUQ_R2, PUQ_R3, PUQ_RP, PUQR45,
      __xx__, PUQL12, __xx__, PUQL45, PUQ_LS,                                     PUQ_RS, PUQR56, __xx__, PUQR23, __xx__,
                                              __xx__, __xx__,     __xx__, __xx__,
                                                      __xx__,     __xx__,
                                      PUQ_LS, PUQ_LE, __xx__,     __xx__, PUQ_RE, PUQ_RS
    ),

    [SYM] = LAYOUT_ergodox_pretty(
      __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,     __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
      __xx__, __xx__, SYM_L7, SYM_L8, SYM_L9, SYM_LA, __xx__,     __xx__, SYM_RA, SYM_R7, SYM_R8, SYM_R9, __xx__, __xx__,
      __xx__, __xx__, SYM_L4, SYM_L5, SYM_L6, SYM_LB,                     SYM_RB, SYM_R4, SYM_R5, SYM_R6, __xx__, __xx__,
      __xx__, SYM_LP, SYM_L1, SYM_L2, SYM_L3, __xx__, __xx__,     __xx__, __xx__, SYM_R1, SYM_R2, SYM_R3, SYM_RP, __xx__,
      __xx__, __xx__, __xx__, __xx__, SYM_LS,                                     SYM_RS, __xx__, __xx__, __xx__, __xx__,
                                              __xx__, __xx__,     __xx__, __xx__,
                                                      __xx__,     __xx__,
                                      SYM_LS, SYM_LE, __xx__,     __xx__, SYM_RE, SYM_RS
    ),

    [NAV] = LAYOUT_ergodox_pretty(
      __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,     __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
      __xx__, __xx__, NAV_L7, NAV_L8, NAV_L9, NAVL89, __xx__,     __xx__, NAV_RA, NAV_R7, NAV_R8, NAV_R9, __xx__, __xx__,
      __xx__, NAVR78, NAV_L4, NAV_L5, NAV_L6, NAV_LB,                     NAV_RB, NAV_R4, NAV_R5, NAV_R6, __xx__, __xx__,
      __xx__, NAV_LP, NAV_L1, NAV_L2, NAV_L3, __xx__, __xx__,     __xx__, __xx__, NAV_R1, NAV_R2, NAV_R3, NAV_RP, __xx__,
      __xx__, __xx__, __xx__, __xx__, NAV_LS,                                     NAV_RS, __xx__, __xx__, __xx__, __xx__,
                                              __xx__, __xx__,     __xx__, __xx__,
                                                      __xx__,     __xx__,
                                      NAV_LS, NAV_LE, __xx__,     __xx__, NAV_RE, NAV_RS
    ),

    [FCT] = LAYOUT_ergodox_pretty(
      __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,     __xx__, __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
      __xx__, __xx__, FCT_L7, FCT_L8, FCT_L9, FCT_LA, __xx__,     __xx__, FCT_RA, FCT_R7, FCT_R8, FCT_R9, __xx__, __xx__,
      __xx__, __xx__, FCT_L4, FCT_L5, FCT_L6, FCT_LB,                     FCT_RB, FCT_R4, FCT_R5, FCT_R6, __xx__, __xx__,
      __xx__, FCT_LP, FCT_L1, FCT_L2, FCT_L3, __xx__, __xx__,     __xx__, __xx__, FCT_R1, FCT_R2, FCT_R3, FCT_RP, __xx__,
      __xx__, __xx__, __xx__, __xx__, FCT_LS,                                     FCT_RS, __xx__, __xx__, __xx__, __xx__,
                                              __xx__, __xx__,     __xx__, __xx__,
                                                      __xx__,     __xx__,
                                      FCT_LS, FCT_LE, __xx__,     __xx__, FCT_RE, FCT_RS
    ),

};
// clang-format on

// Combos:
combo_t key_combos[] = {
    COMBO(COMBO_PUQ_01, COMBO_PUQ_01_ACTION),
    COMBO(COMBO_PUQ_02, COMBO_PUQ_02_ACTION),
    COMBO(COMBO_PUQ_03, COMBO_PUQ_03_ACTION),
    COMBO(COMBO_PUQ_04, COMBO_PUQ_04_ACTION),
    COMBO(COMBO_PUQ_05, COMBO_PUQ_05_ACTION),
    COMBO(COMBO_PUQ_06, COMBO_PUQ_06_ACTION),
    COMBO(COMBO_PUQ_07, COMBO_PUQ_07_ACTION),
    COMBO(COMBO_PUQ_08, COMBO_PUQ_08_ACTION),
    COMBO(COMBO_PUQ_09, COMBO_PUQ_09_ACTION),
    COMBO(COMBO_PUQ_10, COMBO_PUQ_10_ACTION),
    COMBO(COMBO_PUQ_11, COMBO_PUQ_11_ACTION),
    COMBO(COMBO_PUQ_12, COMBO_PUQ_12_ACTION),
    COMBO(COMBO_PUQ_13, COMBO_PUQ_13_ACTION),
    COMBO(COMBO_PUQ_14, COMBO_PUQ_14_ACTION),

    COMBO(COMBO_SYM_01, COMBO_SYM_01_ACTION),
    COMBO(COMBO_SYM_02, COMBO_SYM_02_ACTION),
    COMBO(COMBO_SYM_03, COMBO_SYM_03_ACTION),

    COMBO(COMBO_NAV_01, COMBO_NAV_01_ACTION),
    COMBO(COMBO_NAV_02, COMBO_NAV_02_ACTION),
    COMBO(COMBO_NAV_03, COMBO_NAV_03_ACTION),
    COMBO(COMBO_NAV_04, COMBO_NAV_04_ACTION),
    COMBO(COMBO_NAV_05, COMBO_NAV_05_ACTION),
    COMBO(COMBO_NAV_06, COMBO_NAV_06_ACTION),
};

