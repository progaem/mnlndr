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

// Shift keys
#define SH_TAB S(KC_TAB)

// Ctrl+Shift keys
#define CS_T LCTL(S(KC_T))
#define CS_K LCTL(S(KC_K))
#define CS_M LCTL(S(KC_M))
#define CS_P LCTL(S(KC_P))

// Alt keys
#define AL_UP LALT(KC_UP)
#define AL_PSCR LALT(KC_PSCR)

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
#define WN_F1 LGUI(KC_F1)
#define WN_F2 LGUI(KC_F2)
#define WN_F3 LGUI(KC_F3)
#define WN_Q LGUI(KC_Q)
#define WN_L LGUI(KC_L)

// Ctrl keys
#define CT_LEFT LCTL(KC_LEFT)
#define CT_UP LCTL(KC_UP)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_RGHT LCTL(KC_RGHT)
#define CT_ENT LCTL(KC_ENT)
#define CT_BSPC LCTL(KC_BSPC)
#define CT_1 LCTL(KC_1)
#define CT_2 LCTL(KC_2)
#define CT_T LCTL(KC_T)
#define CT_W LCTL(KC_W)
#define CT_J LCTL(KC_J)
#define CT_G LCTL(KC_G)
#define CT_S LCTL(KC_S)
#define CT_F LCTL(KC_F)
#define CT_A LCTL(KC_A)
#define CT_S LCTL(KC_S)
#define CT_F5 LCTL(KC_F5)
#define CT_PGUP LCTL(KC_PGUP)
#define CT_PGDN LCTL(KC_PGDN)
#define CT_X LCTL(KC_X)
#define CT_C LCTL(KC_C)
#define CT_V LCTL(KC_V)
#define CT_PLUS LCTL(KC_EQL)
#define CT_MINS LCTL(KC_MINS)
#define CT_BSLS LCTL(KC_BSLS)

#define RGB_LYR TOGGLE_LAYER_COLOR

// Define good names for keys that will be used for chords
// Left Index
#define CMB_CTC CMB_000
#define CMB_CTV CMB_001
// Left Thumb
#define CMB_SFT CMB_002
#define CMB_BSP CMB_003
#define CMB_ENT CMB_004
#define CMB_CTL CMB_005
// Left Left Thumb
#define CMB_LYV CMB_006
#define CMB_LYG CMB_007
// Right Thumb
#define CMB_LAN CMB_008
#define CMB_DOT CMB_009
#define CMB_SPC CMB_010
#define CMB_ALT CMB_011

// Shifted index keys
#define CMB_CAC CMB_012
#define CMB_CAV CMB_013

// Russian index keys on letters
#define CMS_O   CMB_014
#define CMS_SF  CMB_015
#define CMS_S_O CMB_016
#define CMS_SSF CMB_017

// Left number-row
#define CMB_PLS CMB_018
#define CMB_SCL CMB_019
#define CMB_GRV CMB_020
#define CMB_EXL CMB_021
#define CMB_ASR CMB_022
// Right number-row
#define CMB_EQL CMB_023
#define CMB_CLN CMB_024
#define CMB_CMM CMB_025
#define CMB_QUE CMB_026
#define CMB_SLS CMB_027

// Brackets on red layer, order: 1 - (), 2 - [], 3 - {}, 4 - <>
#define CMB_LB1 CMB_028
#define CMB_RB1 CMB_029
#define CMB_LB2 CMB_030
#define CMB_RB2 CMB_031
#define CMB_LB3 CMB_032
#define CMB_RB3 CMB_033
#define CMB_LB4 CMB_034
#define CMB_RB4 CMB_035

// Brackets on XCompose layer
#define CMB_LTR CMB_036
#define CMB_RTR CMB_037
#define CMB_LCR CMB_038
#define CMB_RCR CMB_039

#define TT_CTJ TT_000

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
    KC_ESC,  AG_1,    AG_2,    AG_3,    AG_4,    AG_5,    EN_GRV, 
    KC_TAB,  EN_Q,    EN_W,    EN_E,    EN_R,    EN_T,    XXXXXXX, 
    XXXXXXX, EN_A,    EN_S,    EN_D,    EN_F,    EN_G,    XXXXXXX, 
    XXXXXXX, EN_Z,    EN_X,    EN_C,    EN_V,    EN_B, 
    XXXXXXX, TT_YELW, XXXXXXX, CMB_LYG, CMB_LYV, 
    CMB_CTL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_ENT, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    EN_EQL,  AG_6,    AG_7,    AG_8,    AG_9,    AG_0,    EN_MINS, 
    XXXXXXX, EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,    EN_BSLS, 
    XXXXXXX, EN_H,    EN_J,    EN_K,    EN_L,    EN_SCLN, EN_QUOT, 
             EN_N,    EN_M,    EN_COMM, EN_DOT,  EN_SLSH, XXXXXXX, 
                      TT_RED,  XXXXXXX, XXXXXXX, XXXXXXX, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_LAN, CMB_DOT, CMB_SPC /* RIGHT THUMB KEYS */ 
  )

  // English with Shift
  [L_EN_S] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  EN_EXCL, EN_AT,   EN_HASH, EN_DLR,  EN_PERC, EN_TILD, 
    KC_TAB,  EN_S_Q,  EN_S_W,  EN_S_E,  EN_S_R,  EN_S_T,  XXXXXXX, 
    XXXXXXX, EN_S_A,  EN_S_S,  EN_S_D,  EN_S_F,  EN_S_G,  XXXXXXX, 
    XXXXXXX, EN_S_Z,  EN_S_X,  EN_S_C,  EN_S_V,  EN_S_B, 
    XXXXXXX, TT_YELW, XXXXXXX, CMB_LYG, CMB_LYV, 
    CMB_CTL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_ENT, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    EN_PLUS, EN_CIRC, EN_AMPR, EN_ASTR, EN_LPRN, EN_RPRN, EN_UNDS, 
    XXXXXXX, EN_S_Y,  EN_S_U,  EN_S_I,  EN_S_O,  EN_S_P,  EN_PIPE, 
    XXXXXXX, EN_S_H,  EN_S_J,  EN_S_K,  EN_S_L,  EN_COLN, EN_DQUO, 
             EN_S_N,  EN_S_M,  EN_LT,   EN_GT,   EN_QUES, XXXXXXX, 
                      TT_RED,  XXXXXXX, XXXXXXX, XXXXXXX, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_LAN, CMB_DOT, CMB_SPC /* RIGHT THUMB KEYS */ 
  )
  
  // Russian without Shift
  [L_RU] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  AG_1,    AG_2,    AG_3,    AG_4,    AG_5,    RU_JO, 
    KC_TAB,  RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,   XXXXXXX, 
    XXXXXXX, RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,    XXXXXXX, 
    XXXXXXX, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I, 
    XXXXXXX, TT_YELW, XXXXXXX, CMB_LYG, CMB_LYV, 
    CMB_CTL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_ENT, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    RU_EQL,  AG_6,    AG_7,    AG_8,    AG_9,    AG_0,    RU_MINS, 
    XXXXXXX, RU_N,    RU_G,    RU_SH,   RU_SC,   RU_Z,    RU_H, 
    XXXXXXX, RU_R,    CMS_O,   RU_L,    RU_D,    RU_ZH,   RU_E, 
             RU_T,    CMS_SF,  RU_B,    RU_JU,   RU_DOT, XXXXXXX, 
                      TT_RED,  XXXXXXX, XXXXXXX, XXXXXXX, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_LAN, CMB_DOT, CMB_SPC /* RIGHT THUMB KEYS */ 
  )

  [L_RU_S] = MY_layout( 
    /* LEFT HALF */ 
    KC_ESC,  RU_EXCL, RU_DQUO, RU_NUME, RU_SCLN, RU_PERC, RU_S_JO, 
    KC_TAB,  RU_S_J,  RU_S_TS, RU_S_U,  RU_S_K,  RU_S_JE, XXXXXXX, 
    XXXXXXX, RU_S_F,  RU_S_Y,  RU_S_V,  RU_S_A,  RU_S_P,  XXXXXXX, 
    XXXXXXX, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_M,  RU_S_I, 
    XXXXXXX, TT_YELW, XXXXXXX, CMB_LYG, CMB_LYV, 
    CMB_CTL, /* LEFT RED THUMB KEY */ 
    CMB_SFT, CMB_BSP, CMB_ENT, /* LEFT THUMB KEYS */ 
    
    /* RIGHT HALF */ 
    RU_PLUS, RU_COLN, RU_QUES, RU_ASTR, RU_LPRN, RU_RPRN, RU_UNDS, 
    XXXXXXX, RU_S_N,  RU_S_G,  RU_S_SH, RU_S_SC, RU_S_Z,  RU_S_H, 
    XXXXXXX, RU_S_R,  CMS_S_O, RU_S_L,  RU_S_D,  RU_S_ZH, RU_S_E, 
             RU_S_T,  CMS_SSF, RU_S_B,  RU_S_JU, RU_COMM, XXXXXXX, 
                      TT_RED,  XXXXXXX, XXXXXXX, XXXXXXX, TT_SPCL, 
                      CMB_ALT, /* RIGHT RED THUMB KEY */ 
                      CMB_LAN, CMB_DOT, CMB_SPC /* RIGHT THUMB KEYS */ 
  )

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
    _______, _______, _______, KC_HOME, KC_PGUP, _______, _______,
    _______, _______, _______,  KC_END, KC_PGDN, _______, _______,
    _______, _______, _______,   KC_UP, _______, _______, _______,
             _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
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
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, AG_7,    AG_8,    AG_9,    _______, _______,
    _______, _______, AG_4,    AG_5,    AG_6,    _______, _______,
             _______, AG_1,    AG_2,    AG_3,    _______, _______,
                      AG_0, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [L_VIOL] = MY_layout(
    // LEFT HALF
    TG_VIOL, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
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
    TG_SPCL, KC_SLCK, KC_CAPS, KC_INS,  KC_PAUS, KC_PSCR, KC_APP,
    _______, _______, _______, _______, _______, _______, _______,
    _______, MU_LAN1, MU_LAN2, MU_LAN3, MU_LAN4, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, KC_RGUI,
    _______, // LEFT RED THUMB KEY
    KC_RCTL, KC_RSFT, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, RESET,
    _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PENT, _______,
             _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,
                      KC_P0,   KC_PDOT, KC_PCMM, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),
};

const ComboWithKeycode combos[] PROGMEM = {
  // Left Index
  // CHORD(CT_C,    /* <- */ CMB_CTC),
  // CHORD(CT_V,    /* <- */ CMB_CTV),
  // CHORD(CT_X,    /* <- */ CMB_CTC, CMB_CTV),

  // Left Thumb
  IMMEDIATE_CHORD(SFT_N, SFT_N,     /* <-! */ CMB_SFT),
  CHORD(KC_BSPC, /* <- */ CMB_BSP),
  CHORD(KC_ENT,  /* <- */ CMB_ENT),
  IMMEDIATE_CHORD(CTRL_EN, CTRL_EN, /* <-! */ CMB_CTL),
  CHORD(CT_A,    /* <- */ CMB_SFT, CMB_CTL),
  // IMMEDIATE_CHORD(TT_GRAY, TT_UNDO, /* <-! */ CMB_SFT, CMB_BSP),
  CHORD(KC_DEL,  /* <- */ CMB_BSP, CMB_CTL),
  CHORD(CT_BSPC, /* <- */ CMB_BSP, CMB_ENT),
  CHORD(CTSH_EN, /* <- */ CMB_SFT, CMB_BSP, CMB_CTL),
  CHORD(AL_PSCR,  /* <- */ CMB_BSP, CMB_ENT, CMB_CTL),

  // Left Left Thumb
  IMMEDIATE_CHORD(TT_VIOL, TT_UNDO, /* <-! */ CMB_LYV),
  IMMEDIATE_CHORD(TT_GREN, TT_UNDO, /* <-! */ CMB_LYG),
  IMMEDIATE_CHORD(TT_RED,  TT_UNDO, /* <-! */ CMB_LYV, CMB_LYG),

  // Right Thumb
  CHORD(MU_LANG, /* <- */ CMB_LAN),
  CHORD(AG_DOT,  /* <- */ CMB_DOT),
  CHORD(KC_SPC,  /* <- */ CMB_SPC),
  CHORD(ALT_EN,  /* <- */ CMB_ALT),
  CHORD(AG_SDOT, /* <- */ CMB_DOT, CMB_SPC),
  CHORD(LA_SYNC, /* <- */ CMB_LAN, CMB_DOT),
  CHORD(CTAL_EN, /* <- */ CMB_SPC, CMB_ALT),
  CHORD(SHAL_EN, /* <- */ CMB_DOT, CMB_ALT),
  CHORD(WIN_EN,  /* <- */ CMB_SPC, CMB_DOT, CMB_ALT),
  CHORD(MU_WNL,  /* <- */ CMB_LAN, CMB_DOT, CMB_ALT),

  // -------------------------------------------------------------------------
  // Shifted index keys

  // Left Index
  // CHORD(CT_A_C,  /* <- */ CMB_CAC),
  // CHORD(CT_A_V,  /* <- */ CMB_CAV),
  // CHORD(CT_A_X,  /* <- */ CMB_CAC, CMB_CAV),

  // -------------------------------------------------------------------------
  // Russian combos on letters
  CHORD(RU_O,    /* <- */ CMS_O),
  CHORD(RU_SF,   /* <- */ CMS_SF),
  CHORD(RU_HD,   /* <- */ CMS_O, CMS_SF),
  CHORD(RU_S_O,  /* <- */ CMS_S_O),
  CHORD(RU_S_SF, /* <- */ CMS_SSF),
  CHORD(RU_S_HD, /* <- */ CMS_S_O, CMS_SSF),

  // -------------------------------------------------------------------------
  // Number row

  // Left hand
  // CHORD(AG_PLUS, /* <- */ CMB_PLS),
  // CHORD(AG_SCLN, /* <- */ CMB_SCL),
  // CHORD(EN_GRV,  /* <- */ CMB_GRV),
  // CHORD(AG_EXCL, /* <- */ CMB_EXL),
  // CHORD(AG_ASTR, /* <- */ CMB_ASR),
  // CHORD(EN_TILD, /* <- */ CMB_PLS, CMB_EXL),
  // CHORD(RU_NUME, /* <- */ CMB_PLS, CMB_ASR),
  // CHORD(EN_QUOT, /* <- */ CMB_GRV, CMB_EXL),
  // CHORD(AG_DQUO, /* <- */ CMB_SCL, CMB_GRV),
  // CHORD(AG_PERC, /* <- */ CMB_SCL, CMB_EXL),
  // CHORD(EN2QUOT, /* <- */ CMB_SCL, CMB_ASR),
  // CHORD(AG2DQUO, /* <- */ CMB_SCL, CMB_GRV, CMB_EXL),

  // Right hand
  // CHORD(AG_SLSH, /* <- */ CMB_SLS),
  // CHORD(AG_QUES, /* <- */ CMB_QUE),
  // CHORD(AG_CMSP, /* <- */ CMB_CMM),
  // CHORD(AG_COLN, /* <- */ CMB_CLN),
  // CHORD(AG_EQL,  /* <- */ CMB_EQL),
  // CHORD(EN_DLR,  /* <- */ CMB_SLS, CMB_CLN),
  // CHORD(EN_HASH, /* <- */ CMB_SLS, CMB_EQL),
  // CHORD(EN_PIPE, /* <- */ CMB_CMM, CMB_CLN),
  // CHORD(EN_AMPR, /* <- */ CMB_QUE, CMB_CMM),
  // CHORD(AG_BSLS, /* <- */ CMB_QUE, CMB_CLN),
  // CHORD(EN2PIPE, /* <- */ CMB_QUE, CMB_EQL),
  // CHORD(EN2AMPR, /* <- */ CMB_QUE, CMB_CMM, CMB_CLN),

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
  // Brackets on XCompose layer

  // CHORD(XC_LTRE, /* <- */ CMB_LTR),
  // CHORD(XC_RTRE, /* <- */ CMB_RTR),
  // CHORD(XC_BTRE, /* <- */ CMB_LTR, CMB_RTR),

  // CHORD(XC_LCRN, /* <- */ CMB_LCR),
  // CHORD(XC_RCRN, /* <- */ CMB_RCR),
  // CHORD(XC_BCRN, /* <- */ CMB_LCR, CMB_RCR),
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
