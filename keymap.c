#include QMK_KEYBOARD_H
#include <quantum/pointing_device.h>
#include "version.h"

#include "arbitrary_keycode/include.h"

#define CUSTOM_SAFE_RANGE ML_SAFE_RANGE
#include "lang_shift/include.h"
#include "combo/include.h"
#include "color/include.h"
#include "tt/include.h"
#include "repeat/include.h"

enum custom_keycodes {
  KEYCODES_START = CUSTOM_SAFE_RANGE,

  // Wow, such empty

  NEW_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE NEW_NEW_SAFE_RANGE
};

#define MY_layout( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
    k53, \
    k50, k51, k52, \
    \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k91, k92, k93, k94, k95, k96, \
    ka2, ka3, ka4, ka5, ka6, \
    kb3,\
    kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

// Gui keys
#define WN_1 LGUI(KC_1)
#define WN_2 LGUI(KC_2)
#define WN_3 LGUI(KC_3)
#define WN_4 LGUI(KC_4)
#define WN_5 LGUI(KC_5)
#define WN_6 LGUI(KC_6)
#define WN_7 LGUI(KC_7)
#define WN_8 LGUI(KC_8)
#define WN_9 LGUI(KC_9)

// Ctrl keys
#define CT_LEFT LCTL(KC_LEFT)
#define CT_UP LCTL(KC_UP)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_RGHT LCTL(KC_RGHT)
#define CT_BSPC LCTL(KC_BSPC)
#define CT_PSCR LCTL(KC_PSCR)
#define CT_GRV LCTL(KC_GRV)

#define RGB_LYR TOGGLE_LAYER_COLOR

// Define good names for keys that will be used for chords
// Left thumb
#define CMB_DEL CMB_000
#define CMB_BSP CMB_001
#define CMB_SFT CMB_002
#define CMB_CTL CMB_003

// Left left thumb
#define CMB_LYV CMB_004
#define CMB_LYG CMB_005

// Right thumb
#define CMB_LAN CMB_006
#define CMB_ENT CMB_007
#define CMB_SPC CMB_008
#define CMB_ALT CMB_009

// Right right thumb
#define CMB_LYR CMB_010

// Russian index keys on letters
#define CMS_JE  CMB_012 // Е
#define CMS_P   CMB_013 // П
#define CMS_SJE CMB_014 // Shift+Е
#define CMS_S_P CMB_015 // Shift+П
#define CMS_O   CMB_016 // О
#define CMS_SF  CMB_017 // Мягкий знак
#define CMS_S_O CMB_018 // Shift+О
#define CMS_SSF CMB_019 // Shift+мягкий знак

// Number row + inner index buttons
#define CMB_QUE CMB_020 // ?
#define CMB_SLS CMB_021 // /
#define CMB_GRV CMB_022 // `
#define CMB_MIN CMB_023 // -
#define CMB_PLU CMB_024 // +

// Special buttons
#define CMB_PRS CMB_025 // Ctrl+PrintScreen
//26
//27

// Brackets on red layer, order: 1 - (), 2 - [], 3 - {}, 4 - <>
#define CMB_LB1 CMB_028
#define CMB_RB1 CMB_029
#define CMB_LB2 CMB_030
#define CMB_RB2 CMB_031
#define CMB_LB3 CMB_032
#define CMB_RB3 CMB_033
#define CMB_LB4 CMB_034
#define CMB_RB4 CMB_035

// Max combo=50

// Подключаем обработку кастомных кейкодов
#include "xcompose.h"
#include "custom_lang.h"
#include "custom_hotkeys.h"
#include "moonlander_leds.h"
#include "mouse_pixel_move.h"
#include "song_keys.h"

enum Layers {
  L_EN = 0,
  L_EN_S,

  L_RU,
  L_RU_S,

  L_RED,
  L_GREN,
  L_VIOL,

  L_SPCL,
};

#define TG_RED TG(L_RED)
#define TG_GREN TG(L_GREN)
#define TG_VIOL TG(L_VIOL)
#define TG_SPCL TG(L_SPCL)

#define MO_RED MO(L_RED)
#define MO_GREN MO(L_GREN)
#define MO_VIOL MO(L_VIOL)
#define MO_SPCL MO(L_SPCL)

#define TT_RED (TT_000 + L_RED)
#define TT_GREN (TT_000 + L_GREN)
#define TT_VIOL (TT_000 + L_VIOL)
#define TT_SPCL (TT_000 + L_SPCL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // English without Shift
  [L_EN] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  AG_EXCL, EN_AT,   EN_HASH, EN_DLR,  AG_PERC, AG_DQUO, 
    KC_TAB,  EN_Q,    EN_W,    EN_E,    EN_R,    EN_T,    CMB_GRV, 
    SFT_N_O, EN_A,    EN_S,    EN_D,    EN_F,    EN_G,    EN_EQL, 
    SFT_N_O, EN_Z,    EN_X,    EN_C,    EN_V,    EN_B, 
    KC_LCTL, KC_LGUI, KC_LALT, CMB_LYV, CMB_LYG, 
    CMB_DEL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_CTL, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    EN_CIRC, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, CMB_QUE, CMB_SLS, 
    CMB_PLU, EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,    EN_BSLS, 
    CMB_MIN, EN_H,    EN_J,    EN_K,    EN_L,    EN_SCLN, EN_QUOT, 
             EN_N,    EN_M,    EN_COMM, EN_DOT,  EN_SLSH, XXXXXXX, 
                      CMB_LYR, CMB_LYG, WIN_EN,  CMB_PRS, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_ENT, CMB_LAN, CMB_SPC /* RIGHT THUMB KEYS */ 
  ),

  // English with Shift
  [L_EN_S] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  AG_EXCL, EN_AT,   RU_NUME, EN_DLR,  AG_PERC, EN_QUOT, 
    KC_TAB,  EN_S_Q,  EN_S_W,  EN_S_E,  EN_S_R,  EN_S_T,  CMB_GRV, 
    SFT_N_O, EN_S_A,  EN_S_S,  EN_S_D,  EN_S_F,  EN_S_G,  EN_EQL, 
    SFT_N_O, EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_V,  EN_S_B, 
    KC_LCTL, KC_LGUI, KC_LALT, CMB_LYV, CMB_LYG, 
    CMB_DEL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_CTL, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    EN_TILD, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, CMB_QUE, EN_BSLS, 
    CMB_PLU, EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,  EN_S_P,  EN_PIPE, 
    CMB_MIN, EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L,  EN_COLN, EN_DQUO, 
             EN_S_N,  EN_S_M,  EN_LT,   EN_GT,   EN_QUES, XXXXXXX, 
                      CMB_LYR, CMB_LYG, WIN_EN,  CMB_PRS, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_ENT, CMB_LAN, CMB_SPC /* RIGHT THUMB KEYS */ 
  ),
  
  // Russian without Shift
  [L_RU] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  AG_EXCL, EN_AT,   EN_HASH, EN_DLR,  AG_PERC, AG_DQUO, 
    KC_TAB,  RU_J,    RU_TS,   RU_U,    RU_K,    CMS_JE,  CMB_GRV, 
    SFT_N_O, RU_F,    RU_Y,    RU_V,    RU_A,    CMS_P,   RU_EQL, 
    SFT_N_O, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I, 
    KC_LCTL, KC_LGUI, KC_LALT, CMB_LYV, CMB_LYG, 
    CMB_DEL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_CTL, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    EN_CIRC, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, CMB_QUE, CMB_SLS, 
    CMB_PLU, RU_N,    RU_G,    RU_SH,   RU_SC,   RU_Z,    RU_H, 
    CMB_MIN, RU_R,    CMS_O,   RU_L,    RU_D,    RU_ZH,   RU_E, 
             RU_T,    CMS_SF,  RU_B,    RU_JU,   RU_DOT,  XXXXXXX, 
                      CMB_LYR, CMB_LYG, WIN_EN,  CMB_PRS, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_ENT, CMB_LAN, CMB_SPC /* RIGHT THUMB KEYS */ 
  ),

  [L_RU_S] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  AG_EXCL, EN_AT,   RU_NUME, EN_DLR,  AG_PERC, EN_QUOT, 
    KC_TAB,  RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  CMS_SJE, CMB_GRV, 
    SFT_N_O, RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  CMS_S_P, RU_EQL, 
    SFT_N_O, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I, 
    KC_LCTL, KC_LGUI, KC_LALT, CMB_LYV, CMB_LYG, 
    CMB_DEL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_CTL, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    EN_TILD, AG_SCLN, EN_AMPR, AG_ASTR, AG_COLN, CMB_QUE, EN_BSLS, 
    CMB_PLU, RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC, RU_S_Z,  RU_S_H, 
    CMB_MIN, RU_S_R,  CMS_S_O, RU_S_L,  RU_S_D,  RU_S_ZH, RU_S_E, 
             RU_S_T,  CMS_SSF, RU_S_B,  RU_S_JU, RU_COMM, XXXXXXX, 
                      CMB_LYR, CMB_LYG, WIN_EN,  CMB_PRS, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_ENT, CMB_LAN, CMB_SPC /* RIGHT THUMB KEYS */ 
  ),

  //---------------------------------------------------------------------------
  [L_RED] = MY_layout(
    // LEFT HALF
    TG_RED,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, CMB_LB2, CMB_RB2, _______, _______,
    _______, CMB_LB4, CMB_RB4, CMB_LB1, CMB_RB1, _______, _______,
    _______, _______, _______, CMB_LB3, CMB_RB3, _______,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_BSPC,
    _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_ENT,
             _______, CT_LEFT, CT_UP,   CT_DOWN, CT_RGHT, KC_SPC,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [L_GREN] = MY_layout(
    // LEFT HALF
    TG_GREN, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, 
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, EN_SLSH, _______,
    _______, _______, AG_7,    AG_8,    AG_9,    EN_ASTR, KC_BSPC,
    _______, AG_0,    AG_4,    AG_5,    AG_6,    EN_MINS, KC_ENT,
             EN_DOT,  AG_1,    AG_2,    AG_3,    EN_PLUS, KC_SPC,
                      AG_0, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [L_VIOL] = MY_layout(
    // LEFT HALF
    TG_VIOL, WN_4,    KC_F10,  KC_F11,  KC_F12,  _______, _______,
    WN_1,    WN_5,    KC_F7,   KC_F8,   KC_F9,   _______, _______,
    WN_2,    WN_6,    KC_F4,   KC_F5,   KC_F6,   _______, _______,
    WN_3,    WN_7,    KC_F1,   KC_F2,   KC_F3,   _______,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______,
    _______, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______,
    _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,
             _______, KC_F1,   KC_F2,   KC_F3,   _______, _______,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [L_SPCL] = MY_layout(
    // LEFT HALF
    TG_SPCL, MU_LAN1, MU_LAN2, MU_LAN3, MU_LAN4, MU_LAN5, MU_LAN6,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, KC_MNXT, KC_VOLU,
    _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE,
             _______, _______, _______, _______, KC_MPRV, KC_VOLD,
                      _______, _______, _______, CT_GRV,  _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),
};

const ComboWithKeycode combos[] PROGMEM = {
  // Left Thumb
  IMMEDIATE_CHORD(SFT_N, SFT_N,     /* <-! */ CMB_SFT),
  IMMEDIATE_CHORD(KC_LCTL, KC_LCTL,     /* <-! */ CMB_CTL),
  CHORD(KC_BSPC, /* <- */ CMB_BSP),
  CHORD(KC_DEL,  /* <- */ CMB_DEL),
  CHORD(CT_BSPC, /* <- */ CMB_SFT, CMB_BSP),

  // Left Left Thumb
  IMMEDIATE_CHORD(TT_VIOL, TT_UNDO, /* <-! */ CMB_LYV),
  IMMEDIATE_CHORD(TT_GREN, TT_UNDO, /* <-! */ CMB_LYG),
  IMMEDIATE_CHORD(TT_RED,  TT_UNDO, /* <-! */ CMB_LYV, CMB_LYG),

  // Right Thumb
  CHORD(LA_CHNG, /* <- */ CMB_LAN),
  CHORD(KC_SPC,  /* <- */ CMB_SPC),
  CHORD(KC_ENT,  /* <- */ CMB_ENT),
  CHORD(ALT_EN,  /* <- */ CMB_ALT),
  CHORD(LA_SYNC, /* <- */ CMB_LAN, CMB_ENT),
  
  // Right right thumb
  IMMEDIATE_CHORD(TT_RED,  TT_UNDO, /* <-! */ CMB_LYR),
  IMMEDIATE_CHORD(TT_VIOL, TT_UNDO, /* <-! */ CMB_LYR, CMB_LYG),

  // -------------------------------------------------------------------------
  // Russian combos on letters
  CHORD(RU_O,    /* <- */ CMS_O),
  CHORD(RU_SF,   /* <- */ CMS_SF),
  CHORD(RU_HD,   /* <- */ CMS_O, CMS_SF),
  CHORD(RU_S_O,  /* <- */ CMS_S_O),
  CHORD(RU_S_SF, /* <- */ CMS_SSF),
  CHORD(RU_S_HD, /* <- */ CMS_S_O, CMS_SSF),

  CHORD(RU_JE,   /* <- */ CMS_JE),
  CHORD(RU_P,    /* <- */ CMS_P),
  CHORD(RU_JO,   /* <- */ CMS_JE, CMS_P),
  CHORD(RU_S_JE, /* <- */ CMS_SJE),
  CHORD(RU_S_P,  /* <- */ CMS_S_P),
  CHORD(RU_S_JO, /* <- */ CMS_SJE, CMS_S_P),
  
  // -------------------------------------------------------------------------
  // Number row
  CHORD(AG_QUES, /* <- */ CMB_QUE),
  CHORD(EN_SLSH, /* <- */ CMB_SLS),
  CHORD(EN_PIPE, /* <- */ CMB_SLS, CMB_QUE),
  
  // -------------------------------------------------------------------------
  // Inner index fingers
  CHORD(AG_MINS, /* <- */ CMB_MIN),
  CHORD(AG_PLUS, /* <- */ CMB_PLU),
  CHORD(AG_UNDS, /* <- */ CMB_MIN, CMB_PLU),  
  
  CHORD(EN_GRV,  /* <- */ CMB_GRV),
  CHORD(LCTL(KC_GRV), CMB_GRV, CMB_CTL),

  // -------------------------------------------------------------------------
  // Brackets on red layer
  CHORD(AG_LPRN, /* <- */ CMB_LB1),
  CHORD(AG_RPRN, /* <- */ CMB_RB1),
  CHORD(EN_LBRC, /* <- */ CMB_LB2),
  CHORD(EN_RBRC, /* <- */ CMB_RB2),
  CHORD(EN_LCBR, /* <- */ CMB_LB3),
  CHORD(EN_RCBR, /* <- */ CMB_RB3),
  CHORD(EN_LT,   /* <- */ CMB_LB4),
  CHORD(EN_GT,   /* <- */ CMB_RB4),
  CHORD(AG_2B1,  /* <- */ CMB_LB1, CMB_RB1),
  CHORD(EN_2B2,  /* <- */ CMB_LB2, CMB_RB2),
  CHORD(EN_2B3,  /* <- */ CMB_LB3, CMB_RB3),
  CHORD(EN_2B4,  /* <- */ CMB_LB4, CMB_RB4),

  // -------------------------------------------------------------------------
  // Special keys
  CHORD(CT_PSCR, /* <- */ CMB_PRS)
};
const uint8_t combos_size = sizeof(combos)/sizeof(ComboWithKeycode);

const uint16_t tt_keys[][3] = {
  { TT_RED,  MO_RED,  TG_RED },
  { TT_GREN, MO_GREN, TG_GREN },
  { TT_VIOL, MO_VIOL, TG_VIOL },
  { TT_SPCL, MO_SPCL, TG_SPCL },
};
const uint8_t tt_size = sizeof(tt_keys)/(sizeof(uint16_t) * 3);

const uint16_t repeat_keys[][2] = {
  { RP_000, AR_L5 },
  { RP_001, MS_LF_1 },
  { RP_002, MS_UP_1 },
  { RP_003, MS_DN_1 },
  { RP_004, MS_RG_1 },
  { RP_005, MS_LF10 },
  { RP_006, MS_UP10 },
  { RP_007, MS_DN10 },
  { RP_008, MS_RG10 },
};
const uint8_t repeat_size = sizeof(repeat_keys)/(sizeof(uint16_t) * 2);

enum ledmap_colors {
  COLOR_BLACK = COLOR_SAFE_RANGE, // Чёрный цвет
  COLOR_ANYFN, // Цвет для кнопки, нажимаемой любым пальцем
  COLOR_PINKY, // Для кнопки нажимаемой мизинцем
  COLOR_ANNUL, // Безымянным
  COLOR_MIDDL, // Средним
  COLOR_INDEX, // Указательным
  COLOR_THUMB, // Большим пальцем
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL] = {
    [0] = {
      COLOR_ANYFN, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANYFN,
      COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_THUMB,
      COLOR_THUMB, COLOR_THUMB, COLOR_THUMB, 

      COLOR_ANYFN, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANYFN,
      COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_THUMB,
      COLOR_THUMB, COLOR_THUMB, COLOR_THUMB
    },

    [1] = {
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, 
      ___________, ___________, ___________, 
      COLOR_LAYER,
      COLOR_LAYER, COLOR_LAYER, COLOR_LAYER, 

      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, 
      ___________, ___________, ___________, 
      COLOR_LAYER,
      COLOR_LAYER, COLOR_LAYER, COLOR_LAYER
    },
};
const uint8_t ledmap_size = sizeof(ledmap)/(sizeof(uint8_t) * DRIVER_LED_TOTAL);

const uint8_t PROGMEM colormap[][3] = {
  [COLOR_BLACK] = { 0, 0, 0 },
  [COLOR_ANYFN] = { 0, 0, 255 },
  [COLOR_PINKY] = { 31, 255, 255 },
  [COLOR_ANNUL] = { 164, 255, 255 },
  [COLOR_MIDDL] = { 76, 255, 255 },
  [COLOR_INDEX] = { 224, 255, 255 },
  [COLOR_THUMB] = { 8, 255, 255 },
};
const uint8_t colormap_size = sizeof(colormap)/(sizeof(uint8_t) * 3);

const uint8_t PROGMEM layermap[][3] = {
  [L_EN] = { 0, 0, 255 },
  [L_EN_S] = { 0, 0, 192 },

  [L_RU] = { 164, 255, 255 },
  [L_RU_S] = { 164, 255, 192 },

  [L_RED] = { 0, 255, 210 },
  [L_GREN] = { 76, 255, 255 },
  [L_VIOL] = { 188, 255, 255 },

  [L_SPCL] = { 8, 255, 255 },
};
const uint8_t layermap_size = sizeof(layermap)/(sizeof(uint8_t) * 3);

bool initted_for_layer_state = false;
layer_state_t layer_state_set_user(layer_state_t state) {
  if (initted_for_layer_state) {
    // Выключаем все леды, потому что они только просвечивают своим некрасивым цветом через прозрачные кейкапы, а для чего их использовать можно я не придумал
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    uint8_t layer = get_highest_layer(state);

    // Устанавливаем текущий цвет клавиатуры таким же какой сейчас цвет у слоя. Это создаёт красивый эффект для подсветок, которые используют текущий цвет.
    rgb_matrix_sethsv_noeeprom(
      pgm_read_byte(&layermap[layer][0]),
      pgm_read_byte(&layermap[layer][1]),
      pgm_read_byte(&layermap[layer][2])
    );
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  initted_for_layer_state = true;

  if (!process_my_music_keys(keycode, record)) {
    return false;
  }

  if (!combo_process_record(keycode, record)) {
    return false;
  }

  if (!tt_process_record(keycode, record)) {
    return false;
  }

  if (!rp_process_record(keycode, record)) {
    return false;
  }

  if (!process_my_lang_keys(keycode, record)) {
    return false;
  }

  if (!process_my_xcompose(keycode, record)) {
    return false;
  }

  if (!lang_shift_process_record(keycode, record)) {
    return false;
  }

  if (!color_process_record(keycode, record)) {
    return false;
  }

  if (!process_my_hotkeys(keycode, record)) {
    return false;
  }

  if (!process_moonlander_leds(keycode, record)) {
    return false;
  }

  if (!process_mouse_pixel_move(keycode, record)) {
    return false;
  }

  return true;
}

float error_song1[][2] = SONG(MUSIC_OFF_SOUND);
void combo_max_count_error(void) {
  PLAY_SONG(error_song1);
  uprintf("COMBO ERROR: MAX COMBOS COUNT HAS REACHED\n");
}

float error_song2[][2] = SONG(VOICE_CHANGE_SOUND);
void combo_max_size_error(void) {
  PLAY_SONG(error_song2); 
  uprintf("COMBO ERROR: MAX COMBO SIZE HAS REACHED\n");
}

void repeated_key_error(void) {
  PLAY_SONG(error_song2); 
  uprintf("REPEATED KEY ERROR\n"); 
}

void user_timer(void) {
  combo_user_timer();
  lang_shift_user_timer();
  rp_timer();
}

void matrix_scan_user(void) {
  user_timer();
}

// Нужно для color.h
void rgb_matrix_indicators_user(void) {
  color_rgb_matrix_indicators();
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}
