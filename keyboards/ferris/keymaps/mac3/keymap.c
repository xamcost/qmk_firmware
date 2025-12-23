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
   KC_BACKTAB,
   KC_GR,
   KC_SHARP,
   KC_CFLEX,
   KC_TREMA
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
                tap_code16(G(KC_C));
                return false;
            }
            return true;
        case KCV_PASTE:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_V));
                return false;
            }
            return true;
        case KC_BACKTAB:
            if (record->event.pressed) {
                tap_code16(S(KC_TAB));
                return false;
            }
            break;
        case KC_GR:
            if (record->event.pressed) {
                tap_code16(RALT(KC_GRAVE));
                return false;
            }
            break;
        case KC_SHARP:
            if (record->event.pressed) {
                tap_code16(A(KC_E));
                return false;
            }
            break;
        case KC_CFLEX:
            if (record->event.pressed) {
                tap_code16(A(KC_I));
                return false;
            }
            break;
        case KC_TREMA:
            if (record->event.pressed) {
                tap_code16(A(KC_U));
                return false;
            }
            break;
    }
    return true;
}

// combos
enum myCombos {
    CAPS_UI,
    ESC_JK,
    BTAB_CV,
    ESC_DF,
    ENT_THUMBS,
    TAB_ER,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM escr_combo[] = {HO_J, HO_K, COMBO_END};
const uint16_t PROGMEM btab_combo[] = {KCC_COPY, KCV_PASTE, COMBO_END};
const uint16_t PROGMEM escl_combo[] = {HO_D, HO_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_E, KC_R, COMBO_END};

combo_t key_combos[] = {
  [CAPS_UI] = COMBO(caps_ui_combo, KC_CAPS),
  [ESC_JK] = COMBO(escr_combo, KC_ESC),
  [BTAB_CV] = COMBO(btab_combo, KC_BACKTAB),
  [ESC_DF] = COMBO(escl_combo, KC_ESC),
  [ENT_THUMBS] = COMBO(enter_combo, KC_ENT),
  [TAB_ER] = COMBO(tab_combo, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
  //,----------------------------------------------.        ,-------------------------------------------.
      KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
  //|----------------------------------------------|        |-------------------------------------------|
      HO_A,     HO_S,     HO_D,     HO_F,      KC_G,        KC_H,    HO_J,    HO_K,     HO_L,    HO_SCLN,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_Z,     KCX_CUT,  KCC_COPY, KCV_PASTE, KC_B,        KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
  //|----------------------------------------------|        |-------------------------------------------|
                                   MO(2),    KC_BSPC,        KC_SPC,  TT(1)
  ),
    [1] = LAYOUT_split_3x5_2(
  //,----------------------------------------------.        ,-------------------------------------------.
      KC_GRV,   KC_LCBR,  KC_LPRN, KC_LBRC,   KC_LT,        KC_PLUS, KC_7,    KC_8,     KC_9,    KC_PIPE,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_UNDS,        KC_MINS, KC_4,    KC_5,     KC_6,    KC_EQL,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_TILD,  KC_RCBR,  KC_RPRN, KC_RBRC,   KC_GT,          KC_0,  KC_1,    KC_2,     KC_3,    KC_BSLS,
  //|----------------------------------------------|        |-------------------------------------------|
                                   MO(3),    KC_BSPC,        KC_SPC,  TT(1)
  ),
    [2] = LAYOUT_split_3x5_2(
  //,----------------------------------------------.        ,-------------------------------------------.
      KC_EXLM,    KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR,  KC_TILD, MS_BTN1,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_QUOT,       KC_LEFT, KC_DOWN,   KC_UP,  KC_RGHT, KC_COLN,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_TREMA, KC_CFLEX, KC_SHARP, KC_GR,   KC_DQUO,       MS_LEFT, MS_DOWN,   MS_UP,  MS_RGHT, MS_BTN2,
  //|----------------------------------------------|        |-------------------------------------------|
                                   KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS
  ),
    [3] = LAYOUT_split_3x5_2(
  //,----------------------------------------------.        ,-------------------------------------------.
      KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_MRWD,  KC_MPRV,  KC_MPLY,  KC_MNXT, KC_MFFD,       KC_EJCT, KC_VOLD, KC_VOLU,  KC_MUTE, KC_F11,
  //|----------------------------------------------|        |-------------------------------------------|
      QK_BOOT,  QK_RBT,   KC_WAKE,  KC_SLEP,  TG(4),        KC_MCTL, KC_BRID, KC_BRIU,  KC_LPAD, KC_F12,
  //|----------------------------------------------|        |-------------------------------------------|
                                   KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS
  ),
    [4] = LAYOUT_split_3x5_2(
  //,----------------------------------------------.        ,-------------------------------------------.
      KC_TAB,   KC_Q,     KC_W,     KC_E,      KC_R,        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_CAPS,  KC_A,     KC_S,     KC_D,      KC_F,        KC_H,    HO_J,    HO_K,     HO_L,    HO_SCLN,
  //|----------------------------------------------|        |-------------------------------------------|
      KC_LSFT,  KC_X,     KC_C,     KC_V,      KC_B,        KC_N,    KC_M,    KC_T,     KC_G,    TG(4),
  //|----------------------------------------------|        |-------------------------------------------|
                                   KC_LSFT,    KC_BSPC,     KC_SPC,  KC_ESC
  ),
};

