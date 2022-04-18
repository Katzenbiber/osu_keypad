#include QMK_KEYBOARD_H

enum {
    TD_ESC_RESET = 0,
};

void on_each_tap_fn(qk_tap_dance_state_t *state, void *user_data) {
    register_code(KC_ESC);
}

void on_dance_finished_fn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 5) {
        reset_keyboard();
    }
}

void on_dance_reset_fn(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_ESC);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_RESET] = ACTION_TAP_DANCE_FN_ADVANCED(on_each_tap_fn, on_dance_finished_fn, on_dance_reset_fn),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ESC│ Z │ X │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_osu_keypad(
        TD(TD_ESC_RESET),   KC_Z,   KC_X
    )
};
