#include QMK_KEYBOARD_H

enum iris_layers {
  _QWERTY,
  _QWERTY_MODS,
  _COLEMAK,
  _COLEMAK_MODS,
  _RSTHD,
  _RSTHD_MODS,
  _GAMER,
  _TOUHOU,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  KC_CLMK = SAFE_RANGE,
  KC_RSTH,
  KC_HMOD,
};

#define KC_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP

#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_LOTG TG(_LOWER)
#define KC_RATG TG(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_LWRE LT(_LOWER, KC_E)

#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_BSPC

#define TG_GAME TG(_GAMER)
#define TG_TOHO TG(_TOUHOU)

// FB2K global hotkeys
#define KC_FBVU A(S(KC_EQL))
#define KC_FBVD A(S(KC_MINS))
#define KC_FBNX A(S(KC_RGHT))
#define KC_FBPR A(S(KC_LEFT))
#define KC_FBRN A(S(KC_DOWN))
#define KC_FBPL A(S(KC_ENT))

// QWERTY Homerow Mods
#define KC_LG_A MT(MOD_LGUI, KC_A)
#define KC_LA_S MT(MOD_LALT, KC_S)
#define KC_LC_D MT(MOD_LCTL, KC_D)
#define KC_LS_F MT(MOD_LSFT, KC_F)
#define KC_RS_J MT(MOD_RSFT, KC_J)
#define KC_RC_K MT(MOD_RCTL, KC_K)
#define KC_RA_L MT(MOD_RALT, KC_L)
#define KC_RGSC MT(MOD_RGUI, KC_SCLN)

// Colemak Homerow Mods
#define KC_LA_R MT(MOD_LALT, KC_R)
#define KC_LC_S MT(MOD_LCTL, KC_S)
#define KC_LS_T MT(MOD_LSFT, KC_T)
#define KC_RS_N MT(MOD_RSFT, KC_N)
#define KC_RC_E MT(MOD_RCTL, KC_E)
#define KC_RA_I MT(MOD_RALT, KC_I)
#define KC_RG_O MT(MOD_RGUI, KC_O)

// RSTHD Homerow Mods
#define KC_LG_R MT(MOD_LGUI, KC_R)
#define KC_LC_T MT(MOD_LCTL, KC_T)
#define KC_LS_H MT(MOD_LSFT, KC_H)
#define KC_RS_N MT(MOD_RSFT, KC_N)
#define KC_RC_A MT(MOD_RCTL, KC_A)

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  // Basic QWERTY layout.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , GRV,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,MUTE,     HMOD, N  , M  ,COMM, DOT,SLSH, ENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LALT, LOWR, BSPC,        SPC, RASE, LGUI
  //                   `----+----+----'        `----+----+----'
  ),

  [_QWERTY_MODS] = LAYOUT_kc(
  // Homerow mods for QWERTY
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LG_A,LA_S,LC_D,LS_F,    ,                   ,RS_J,RC_K,RA_L,RGSC,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_COLEMAK] = LAYOUT_kc(
  // Colemak DHm, for when you don't want anyone else to use your keyboard.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , Q  , W  , F  , P  , B  ,                J  , L  , U  , Y  ,SCLN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , A  , R  , S  , T  , G  ,                M  , N  , E  , I  , O  ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , Z  , X  , C  , D  , V  ,    ,         , K  , H  ,COMM, DOT,SLSH,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_COLEMAK_MODS] = LAYOUT_kc(
  // Homerow mods for Colemak DHm
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LG_A,LA_R,LC_S,LS_T,    ,                   ,RS_N,RC_E,RA_I,RG_O,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RSTHD] = LAYOUT_kc(
  // It's like Maltron, but better!
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , J  , C  , Y  , F  , K  ,                Z  , L  ,COMM, U  , Q  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , R  , S  , T  , H  , D  ,                M  , N  , A  , I  , O  ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,SLSH, V  , G  , P  , B  ,    ,         , X  , W  , DOT,SCLN,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,LWRE,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RSTHD_MODS] = LAYOUT_kc(
  // Homerow mods for RSTHD
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LG_R,LA_S,LC_T,LS_H,    ,                   ,RS_N,RC_A,RA_I,RG_O,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAMER] = LAYOUT_kc(
  // Moves space to the left thumb since that usually does things in games.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,  SPC,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_TOUHOU] = LAYOUT_kc(
  // See @zun_code on Twitter for why I need to do this.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    , UP ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LCTL,LSFT, Z  , X  , C  ,                   ,LEFT,DOWN,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  // matthewrobo nav cluster on left, symbols on right, funtion keys everywhere.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PGUP,HOME, UP , END,LBRC,               RBRC,UNDS,PLUS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,PGDN,LEFT,DOWN,RGHT,LPRN,               RPRN,MINS, EQL,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 , F5 ,    ,         , F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,LOTG,     ,       BSPC ,ADJS,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  // Media controls on left, numpad on right.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,               NLCK, P7 , P8 , P9 ,PSLS,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,FBVU,FBPL,LBRC,               RBRC, P4 , P5 , P6 ,PAST,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,FBRN,FBPR,FBVD,FBNX,LPRN,               RPRN, P1 , P2 , P3 ,PMNS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,MPRV,MPLY,MNXT,MUTE,    ,         , INS, P0 ,COMM,PDOT,PPLS,PENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,ADJS,  DEL,           , RATG,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  // Rarely used, but useful to have setting toggles.
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      RESET  , DEBUG  , _______, _______, _______, _______,                            _______, _______, _______, _______, _______, A(KC_PSCR),
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      VLK_TOG, _______, _______, _______, _______, _______,                            _______, KC_RSTH, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  BL_INC,                            KC_HMOD, KC_CLMK, TG_GAME, TG_TOHO, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_TOGG, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,  BL_DEC, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, V_V_V_V, _______,                  _______, V_V_V_V, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case KC_CLMK:
        // turn off any other active typing layers first
        layer_off(_RSTHD);
        if (IS_LAYER_ON(_COLEMAK)) { // toggle off
          layer_off(_COLEMAK);
          layer_off(_COLEMAK_MODS);
        }
        else { // toggle on
          if (IS_LAYER_ON(_QWERTY_MODS)) { // set homerow mods as needed
            layer_on(_COLEMAK_MODS);
            layer_off(_RSTHD_MODS);
          }
          layer_on(_COLEMAK);
        }
        return false;
      case KC_RSTH:
        // turn off any other active typing layers first
        layer_off(_COLEMAK);
        if (IS_LAYER_ON(_RSTHD)) { // toggle off
          layer_off(_RSTHD);
          layer_off(_RSTHD_MODS);
        }
        else { // toggle on
          if (IS_LAYER_ON(_QWERTY_MODS)) { // set homerow mods as needed
            layer_on(_RSTHD_MODS);
            layer_off(_COLEMAK_MODS);
          }
          layer_on(_RSTHD);
        }
        return false;
      case KC_HMOD:
        if (IS_LAYER_ON(_QWERTY_MODS)) { // toggle off
          layer_off(_QWERTY_MODS);
          layer_off(_COLEMAK_MODS);
          layer_off(_RSTHD_MODS);
        }
        else { // toggle on
          layer_on(_QWERTY_MODS);
          // determine current active typing layer, turn on mods for that layer
          if (IS_LAYER_ON(_COLEMAK)) {
            layer_on(_COLEMAK_MODS);
          } else if (IS_LAYER_ON(_RSTHD)) {
            layer_on(_RSTHD_MODS);
          }
        }
        return false;
    }
  }

  return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _TOUHOU:
                clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
                break;
            case _LOWER:
                clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
                break;
            case _RAISE:
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                break;
            default:
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                clockwise ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
                alt_tab_timer = timer_read();
                break;
            // default:
            //     clockwise ? tap_code(KC_1) : tap_code(KC_2);
            //     break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case _TOUHOU:
                clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                break;
            case _LOWER:
                clockwise ? tap_code16(A(KC_DOWN)) : tap_code16(A(KC_UP));
                break;
            case _RAISE:
                clockwise ? tap_code16(C(A(KC_DOWN))) : tap_code16(C(A(KC_UP)));
                break;
            default:
                clockwise ? tap_code16(C(KC_PGDN)) : tap_code16(C(KC_PGUP));
                break;
            // default:
            //     clockwise ? tap_code(KC_3) : tap_code(KC_4);
            //     break;
        }
    }
}
#endif
