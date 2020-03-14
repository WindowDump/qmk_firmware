#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _GAMER 2
#define _TOUHOU 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 6

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
// };

#define KC_ KC_TRNS

#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_LOTG TG(_LOWER)
#define KC_RATG TG(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_V_V_ KC_TRNS
#define V_V_V_V KC_TRNS
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_NVBS LT(_NAV, KC_BSPC)

#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_BSPC

#define TG_CLMK TG(_COLEMAK)
#define TG_GAME TG(_GAMER)
#define TG_TOHO TG(_TOUHOU)

#define KC_FBVU A(S(KC_EQL))
#define KC_FBVD A(S(KC_MINS))
#define KC_FBNX A(S(KC_RGHT))
#define KC_FBPR A(S(KC_LEFT))
#define KC_FBRN A(S(KC_DOWN))
#define KC_FBPL A(S(KC_ENT))

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  // Basic QWERTY layout.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , GRV,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,MUTE,     ASTG, N  , M  ,COMM, DOT,SLSH, ENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      LALT, LOWR, BSPC,        SPC, RASE, LGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_COLEMAK] = LAYOUT_kc(
  // Colemak DHm, for when you don't want anyone else to use your keyboard.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , Q  , W  , F  , P  , B  ,                J  , L  , U  , Y  ,SCLN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , A  , R  , S  , T  , G  ,                M  , N  , E  , I  , O  ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , Z  , X  , C  , D  , V  ,    ,         , K  , H  ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,           ,     ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAMER] = LAYOUT_kc(
  // Moves space to the left thumb since that usually does things in games.
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
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
  // Rarely used but useful to have firmware setting toggles.
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      RESET  , DEBUG  , _______, _______, _______, _______,                            KC_ASRP, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      VLK_TOG, _______, _______, _______, _______, _______,                            KC_ASUP, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  BL_INC,                            KC_ASTG, TG_CLMK, TG_GAME, TG_TOHO, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_TOGG, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,  BL_DEC, _______,          _______, KC_ASDN, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, V_V_V_V, _______,                  _______, V_V_V_V, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

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
