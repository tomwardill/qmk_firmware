#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _BL = 0,
  _RJ,
  _NV,
  _FN
};

enum custom_keycodes {
  KC_SMILE = SAFE_RANGE,
  KC_PLUSONE,
  KC_SHRUG,
  KC_LAUGHING,
  KC_R_SMILE,
  KC_R_PLUSONE,
  KC_R_SHRUG,
  KC_R_LAUGHING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * ,-------------------.
 * | NV | /  | *  |-/FN|
 * |----|----|----|----|
 * | 7  | 8  | 9  |    |
 * |----|----|----| +  |
 * | 4  | 5  | 6  |    |
 * |----|----|----|----|
 * | 1  | 2  | 3  |    |
 * |----|----|----| En |
 * | 0  | 00 | .  |    |
 * `-------------------'
 */
  [_BL] = LAYOUT(
    MO(_RJ),  KC_PSLS,  KC_PAST,   LT(_FN, KC_PMNS), \
    KC_P7,    KC_P8,    KC_P9,              \
    KC_P4,    KC_P5,    KC_P6,     KC_PPLS, \
    KC_P1,    KC_P2,    KC_LAUGHING,              \
    KC_SHRUG,    KC_SMILE,  KC_PLUSONE,   KC_PENT
  ),

  [_RJ] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, TG(_BL), \
    KC_A, XXXXXXX, XXXXXXX,          \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, KC_R_LAUGHING,          \
    KC_R_SHRUG, KC_R_SMILE, KC_R_PLUSONE, XXXXXXX
  ),

/* Keymap _NV: Navigation layer
 * ,-------------------.
 * |INS |HOME|PGUP|    |
 * |----|----|----|----|
 * |DEL |END |PGDN|    |
 * |----|----|----|    |
 * |    |    |    |    |
 * |----|----|----|----|
 * |    | UP |    |    |
 * |----|----|----|    |
 * |LEFT|DOWN|RIGH|    |
 * `-------------------'
 */
  [_NV] = LAYOUT(
    KC_INS,   KC_HOME,  KC_PGUP,   TG(_NV), \
    KC_DEL,   KC_END,   KC_PGDN,            \
    XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, \
    XXXXXXX,  KC_UP,    XXXXXXX,            \
    KC_LEFT,  KC_DOWN,  KC_RGHT,   XXXXXXX
  ),

/* Keymap _FN: RGB Function Layer
 * ,-------------------.
 * |RMOD|RGBP|RTOG| FN |
 * |----|----|----|----|
 * |HUD |HUI |    |    |
 * |----|----|----|    |
 * |SAD |SAI |    |    |
 * |----|----|----|----|
 * |VAD |VAS |    |    |
 * |----|----|----|    |
 * |RST |    |    |    |
 * `-------------------'
 */
  [_FN] = LAYOUT(
    RGB_MOD,  RGB_M_P,  RGB_TOG,   _______, \
    RGB_HUD,  RGB_HUI,  XXXXXXX,            \
    RGB_SAD,  RGB_SAI,  XXXXXXX,   XXXXXXX, \
    RGB_VAD,  RGB_VAI,  XXXXXXX,            \
    RESET,    XXXXXXX,  XXXXXXX,   XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SMILE:
      if (record->event.pressed) {
        SEND_STRING(":smile:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_PLUSONE:
      if (record->event.pressed) {
        SEND_STRING(":+1:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_SHRUG:
      if (record->event.pressed) {
        SEND_STRING(":man_shrugging:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_LAUGHING:
      if (record->event.pressed) {
        SEND_STRING(":laughing:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;

    case KC_R_SMILE:
      if (record->event.pressed) {
        SEND_STRING("+:smile:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_R_PLUSONE:
      if (record->event.pressed) {
        SEND_STRING("+:+1:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_R_SHRUG:
      if (record->event.pressed) {
        SEND_STRING("+:man_shrugging:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_R_LAUGHING:
      if (record->event.pressed) {
        SEND_STRING("+:laughing:");
        tap_code(KC_ENTER);
      } else {
        // when keycode KC_DBL0 is released
      }
      break;

  }
  return true;
};

#ifdef OLED_DRIVER_ENABLE
extern rgblight_config_t rgblight_config;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 270 degrees
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer"), false);
  switch (biton32(layer_state)) {
    case _BL:
      oled_write_ln_P(PSTR(" EMJ"), false);
      break;
    case _RJ:
      oled_write_ln_P(PSTR(" REA"), false);
      break;
    case _NV:
      oled_write_ln_P(PSTR(" NAV"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR(" RGB"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR(" UND"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Stats"), false);
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("num:*") : PSTR("num:."), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("cap:*") : PSTR("cap:."), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("scr:*") : PSTR("scr:."), false);

  // Host Keyboard RGB backlight status
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Light"), false);

  static char led_buf[30];
  snprintf(led_buf, sizeof(led_buf) - 1, "RGB:%cM: %2d\nh: %2ds: %2dv: %2d\n",
      rgblight_config.enable ? '*' : '.', (uint8_t)rgblight_config.mode,
      (uint8_t)(rgblight_config.hue / RGBLIGHT_HUE_STEP),
      (uint8_t)(rgblight_config.sat / RGBLIGHT_SAT_STEP),
      (uint8_t)(rgblight_config.val / RGBLIGHT_VAL_STEP));
  oled_write(led_buf, false);
}
#endif
