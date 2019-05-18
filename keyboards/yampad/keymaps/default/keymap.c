#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _BL = 0,
  _FL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * ,-------------------.
 * | MO | /  | *  | -  |
 * |----|----|----|----|
 * | 7  | 8  | 9  |    |
 * |----|----|----| +  |
 * | 4  | 5  | 6  |    |
 * |----|----|----|----|
 * | 1  | 2  | 3  |    |
 * |----|----|----| En |
 * |   0     | .  |    |
 * `-------------------'
 */
  [_BL] = LAYOUT(
    MO(_FL),  KC_PSLS,  KC_PAST,   KC_PMNS, \
    KC_P7,    KC_P8,    KC_P9,              \
    KC_P4,    KC_P5,    KC_P6,     KC_PPLS, \
    KC_P1,    KC_P2,    KC_P3,              \
    KC_P0,    KC_P0,    KC_PDOT,   KC_PENT
  ),

/* Keymap _FL: Function Layer
 * ,-------------------.
 * |    |RGBP|RTOG|    |
 * |----|----|----|----|
 * |HUD |HUI |RMOD|    |
 * |----|----|----|    |
 * |SAD |SAI |    |    |
 * |----|----|----|----|
 * |VAD |VAS |    |    |
 * |----|----|----|    |
 * |         |RST |    |
 * `-------------------'
 */
  [_FL] = LAYOUT(
    _______,  RGB_M_P,  RGB_TOG,   _______, \
    RGB_HUD,  RGB_HUI,  RGB_MOD,            \
    RGB_SAD,  RGB_SAI,  _______,   _______, \
    RGB_VAD,  RGB_VAI,  _______,            \
    _______,  _______,  RESET,     _______
  ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  switch (biton32(layer_state)) {
    case _BL:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _FL:
      oled_write_P(PSTR("Function\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif
