#include QMK_KEYBOARD_H

enum combos {
  ER_COPY,
  WE_SQUO,
  WR_DQUO,
  UI_CTRS,
  UNDERSC,
};

const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM uo_combo[] = {KC_U, KC_O, COMBO_END};

combo_t key_combos[] = {
  [ER_COPY] = COMBO(er_combo, LCTL(KC_C)),
  [WE_SQUO] = COMBO(we_combo, KC_QUOTE),
  [WR_DQUO] = COMBO(wr_combo, LSFT(KC_QUOTE)),
  [UI_CTRS] = COMBO(ui_combo, LCTL(KC_S)),
  [UNDERSC] = COMBO(uo_combo, LSFT(KC_MINUS)),
};

enum dasbob_layers {
  BASE,
  MEDIA,
  NAVIGATION,
  MOUSE,
  SYMBOLS,
  NUMBERS,
  FUNCTIONS
};

#define ESC_MED LT(MEDIA, KC_ESC)
#define SPC_NAV LT(NAVIGATION, KC_SPC)
#define TAB_CUR LT(MOUSE, KC_TAB)
#define ENT_SYM LT(SYMBOLS, KC_ENT)
#define BSP_NUM LT(NUMBERS, KC_BSPC)
#define DEL_FUN LT(FUNCTIONS, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *         ┌───┐                           ┌───┐
     *     ┌───┤ E ├───┬───┐           ┌───┬───┤ I ├───┐
     * ┌───┤ W ├───┤ R │ T │           │ Y │ U ├───┤ O ├───┐
     * │ Q ├───┤ D ├───┼───┤           ├───┼───┤ K ├───┤ P │
     * ├───┤ S ├───┤ F │ G │           │ H │ J ├───┤ L ├───┤
     * │ A ├───┤ C ├───┼───┤           ├───┼───┤ , ├───┤ ; │
     * ├───┤ X ├───┤ V │ B │           │ N │ M ├───┤ . ├───┤
     * │ Z ├───┘   └───┴───┘           └───┴───┘   └───┤ / │
     * └───┘       ┌───┐                   ┌───┐       └───┘
     *             │ESC├───┐           ┌───┤DEL│
     *             └───┤SPC├───┐   ┌───┤BSP├───┘
     *                 └───┤TAB│   │RET├───┘
     *                     └───┘   └───┘
     *
     * More on the available keycodes at:
     *   https://docs.qmk.fm/keycodes_basic
     */

    [BASE] = LAYOUT_split_3x5_3(
            KC_Q,           KC_W,         KC_E,         KC_R,         KC_T,              KC_Y,         KC_U,         KC_I,           KC_O,         KC_P,
            KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), LGUI_T(KC_G),              LGUI_T(KC_H), LSFT_T(KC_J), LCTL_T(KC_K),   LALT_T(KC_L), KC_SCLN,
            RALT_T(KC_Z),   KC_X,         KC_C,         KC_V,         KC_B,              KC_N,         KC_M,         KC_COMMA,       KC_DOT,       RALT_T(KC_SLASH),
                                          ESC_MED,      SPC_NAV,      TAB_CUR,           ENT_SYM,      BSP_NUM,      DEL_FUN
    ),

    // the following three layers are related to the left thumb
    [MEDIA] = LAYOUT_split_3x5_3(
            KC_NO,          KC_NO,        KC_NO,        KC_NO,        KC_NO,             RGB_TOG,      RGB_MOD,      RGB_HUI,        RGB_SAI,      RGB_SPI,
            KC_NO,          KC_LALT,      KC_LCTL,      KC_LSFT,      KC_LGUI,           RGB_VAI,      KC_MPRV,      KC_VOLD,        KC_VOLU,      KC_MNXT,
            KC_RALT,        KC_NO,        KC_NO,        KC_NO,        KC_NO,             KC_NO,        KC_NO,        KC_BRID,        KC_BRIU,      KC_NO,
                                          KC_NO,        KC_NO,        KC_NO,             KC_MSTP,      KC_MPLY,      KC_MUTE
    ),

    [NAVIGATION] = LAYOUT_split_3x5_3(
            KC_NO,          KC_NO,        KC_NO,        KC_NO,        KC_NO,             KC_AGIN,      KC_PSTE,      KC_COPY,        KC_CUT,       KC_UNDO,
            KC_NO,          KC_LALT,      KC_LCTL,      KC_LSFT,      KC_LGUI,           KC_LEFT,      KC_DOWN,      KC_UP,          KC_RIGHT,     KC_CAPS, 
            KC_RALT,        KC_NO,        KC_NO,        KC_NO,        KC_NO,             KC_HOME,      KC_PGDN,      KC_PGUP,        KC_END,       KC_INSERT,
                                          KC_NO,        KC_NO,        KC_NO,             KC_ENTER,     KC_BSPC,      KC_DELETE
    ),

    [MOUSE] = LAYOUT_split_3x5_3(
            KC_NO,          KC_NO,        KC_NO,        KC_NO,        KC_NO,             LGUI(KC_S),   LGUI(KC_V),   LGUI(KC_C),     LGUI(KC_X),   LGUI(KC_Z),
            KC_NO,          KC_LALT,      KC_LCTL,      KC_LSFT,      KC_LGUI,           KC_MS_L,      KC_MS_D,      KC_MS_U,        KC_MS_R,      KC_NO, 
            KC_RALT,        KC_NO,        KC_NO,        KC_NO,        KC_NO,             KC_WH_L,      KC_WH_D,      KC_WH_U,        KC_WH_R,      KC_NO,  
                                          KC_NO,        KC_NO,        KC_NO,             KC_BTN2,      KC_BTN1,      KC_BTN3
    ),

    // and the following three are from the right thumb
    [SYMBOLS] = LAYOUT_split_3x5_3(
            KC_LCBR,        LSFT(KC_7),   LSFT(KC_8),   LSFT(KC_9),   KC_RCBR,           KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_NO,
            LSFT(KC_QUOTE), LSFT(KC_4),   LSFT(KC_5),   LSFT(KC_6),   LSFT(KC_EQL),      KC_LGUI,      KC_LSFT,      KC_LCTL,        KC_LALT,      KC_NO,
            LSFT(KC_GRAVE), LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),   LSFT(KC_BSLS),     KC_NO,        KC_NO,        LSFT(KC_COMMA), LSFT(KC_DOT), KC_RALT,
                                          LSFT(KC_9),   LSFT(KC_0),   LSFT(KC_MINUS),    KC_NO,        KC_NO,        KC_NO
    ),

    [NUMBERS] = LAYOUT_split_3x5_3(
            KC_LBRC,        KC_7,         KC_8,         KC_9,         KC_RBRC,           KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_NO,
            KC_QUOTE,       KC_4,         KC_5,         KC_6,         KC_EQUAL,          KC_LGUI,      KC_LSFT,      KC_LCTL,        KC_LALT,      KC_NO,
            KC_GRAVE,       KC_1,         KC_2,         KC_3,         KC_BSLS,           KC_NO,        KC_NO,        KC_COMMA,       KC_DOT,       KC_RALT,
                                          KC_DOT,       KC_0,         KC_MINUS,          KC_NO,        KC_NO,        KC_NO
    ),

    [FUNCTIONS] = LAYOUT_split_3x5_3(
            KC_F12,         KC_F7,        KC_F8,        KC_F9,        KC_PSCR,           KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_NO,
            KC_F11,         KC_F4,        KC_F5,        KC_F6,        KC_SCRL,           KC_LGUI,      KC_LSFT,      KC_LCTL,        KC_LALT,      KC_NO,
            KC_F10,         KC_F1,        KC_F2,        KC_F3,        KC_PAUSE,          KC_NO,        KC_NO,        KC_NO,          KC_NO,        KC_RALT,
                                          KC_NO,        KC_APP,       KC_NO,             KC_NO,        KC_NO,        KC_NO
    ),
};
