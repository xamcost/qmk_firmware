#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HO_A LCTL_T(KC_A)
#define HO_S LALT_T(KC_S)
#define HO_D LGUI_T(KC_D)
#define HO_F LSFT_T(KC_F)

// Right-hand home row mods
#define HO_J RSFT_T(KC_J)
#define HO_K RGUI_T(KC_K)
#define HO_L LALT_T(KC_L)
#define HO_SCLN RCTL_T(KC_SCLN)

// custom keycodes
#define KCX_CUT LT(0,KC_X)
#define KCC_COPY LT(0,KC_C)
#define KCV_PASTE LT(0,KC_V)

enum custom_keycodes {
   KC_BACKTAB
};

// macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KCX_CUT:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_X)); // Intercept hold function to send CMD-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case KCC_COPY:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_C)); // Intercept hold function to send CMD-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case KCV_PASTE:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_V)); // Intercept hold function to send CMD-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case KC_BACKTAB:
            if (record->event.pressed) {
                tap_code16(S(KC_TAB)); // Intercept hold function to send CMD-V
                return false;
            }
            break;             // Return true for normal processing of tap keycode
    }
    return true;
}

// combos
enum myCombos {
    CAPS_UI,
    ESC_JK,
    BTAB_CV,
    BSPC_DF,
    TAB_ER,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {HO_J, HO_K, COMBO_END};
const uint16_t PROGMEM btab_combo[] = {KCC_COPY, KCV_PASTE, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {HO_D, HO_F, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_E, KC_R, COMBO_END};

combo_t key_combos[] = {
  [CAPS_UI] = COMBO(caps_ui_combo, KC_CAPS),
  [ESC_JK] = COMBO(esc_combo, KC_ESC),
  [BTAB_CV] = COMBO(btab_combo, KC_BACKTAB),
  [BSPC_DF] = COMBO(bspc_combo, KC_BSPC),
  [TAB_ER] = COMBO(tab_combo, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
  //,--------------------------------------------------------------------------.        ,--------------------------------------------------------------------------------.
      KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,           KC_Y,    KC_U,            KC_I,            KC_O,            KC_P,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
      HO_A,            HO_S,            HO_D,            HO_F,            KC_G,           KC_H,    HO_J,            HO_K,            HO_L,            HO_SCLN,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
      KC_Z,            KCX_CUT,         KCC_COPY,        KCV_PASTE,      KC_B,           KC_N,    KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
                                                         MO(2),           KC_ENT,         KC_SPC,  MO(1)
  ),
    [1] = LAYOUT_split_3x5_2(
  //,--------------------------------------------------------------------------.        ,--------------------------------------------------------------------------------.
      KC_GRV,          KC_LBRC,         KC_RBRC,         KC_DLR,          KC_ESC,         KC_CIRC, KC_7,            KC_8,            KC_9,            KC_0,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
      KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_BSPC,        KC_MINS, KC_4,            KC_5,            KC_6,            KC_QUOT,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
      KC_TILD,         KC_LPRN,         KC_RPRN,         KC_UNDS,         KC_TAB,         KC_EQL,  KC_1,            KC_2,            KC_3,            KC_BSLS,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
                                                         KC_TRNS,         KC_TRNS,        KC_TRNS,  KC_TRNS
  ),
    [2] = LAYOUT_split_3x5_2(
  //,--------------------------------------------------------------------------.        ,--------------------------------------------------------------------------------.
      KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,          KC_F6,   KC_F7,           KC_F8,           KC_F9,           KC_F10,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
      KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_BSPC,        KC_LEFT, KC_DOWN,         KC_UP,         KC_RGHT,           KC_F11,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
      KC_BRID,         KC_BRIU,         KC_MRWD,         KC_MPLY,         KC_MFFD,        KC_EJCT, KC_VOLD,         KC_VOLU,       KC_MUTE,           KC_F12,
  //|--------------------------------------------------------------------------|        |--------------------------------------------------------------------------------|
                                                         KC_TRNS,         KC_TRNS,        KC_TRNS,  KC_TRNS
  ),
};

