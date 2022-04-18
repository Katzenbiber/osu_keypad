#include QMK_KEYBOARD_H

const uint16_t PROGMEM reset_combo[] = {KC_ESC, KC_X, KC_Z, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(reset_combo, RESET),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ESC│ Z │ X │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_osu_keypad(
        KC_ESC,   KC_Z,   KC_X
    )
};
