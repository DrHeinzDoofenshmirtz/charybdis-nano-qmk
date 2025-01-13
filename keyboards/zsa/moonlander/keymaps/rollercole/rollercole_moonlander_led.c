struct Color {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

struct Color red = { .red = 255, .green = 0, .blue = 0 };
struct Color black = { .red = 0, .green = 0, .blue = 0 };
struct Color green = { .red = 0, .green = 255, .blue = 0 };
struct Color pink = { .red = 255, .green = 0, .blue = 255 };
struct Color blue = { .red = 0, .green = 0, .blue = 255 };
struct Color white = { .red = 255, .green = 255, .blue = 255 };
struct Color orange = { .red = 255, .green = 100, .blue = 0 };

void paint(uint16_t led_index, struct Color c)
{
    rgb_matrix_set_color(led_index, c.red, c.green, c.blue);
}

// Function to extract the base keycode
uint16_t get_base_keycode(uint16_t keycode) {
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        // It's a mod-tap key (mod + keycode)
        return keycode & 0xFF;
    } else if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
        // It's a layer-tap key (layer + keycode)
        return keycode & 0xFF;
    } else if (keycode >= QK_MODS && keycode <= QK_MODS_MAX) {
        // It's a mod key
        return keycode & 0xFF;
    }
    return keycode;  // It's a basic keycode
}

bool is_key_in_range(uint16_t keycode_in_question, uint16_t min_key, uint16_t max_key)
{
     uint16_t base_keycode = get_base_keycode(keycode_in_question);
     if(base_keycode < min_key || base_keycode > max_key){
        return false;
     }
     return (
        keycode_in_question == base_keycode
        || keycode_in_question == _A(base_keycode)
        || keycode_in_question == _C(base_keycode)
        || keycode_in_question == _S(base_keycode)
        || keycode_in_question == _W(base_keycode));
}

bool is_key(uint16_t keycode_in_question, uint16_t key_to_match)
{
     return is_key_in_range(keycode_in_question, key_to_match, key_to_match);
}

uint8_t last_detected_layer = 99;
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);
    if(current_layer != last_detected_layer)
    {
         last_detected_layer = current_layer;

         rgb_matrix_set_flags(LED_FLAG_NONE);
         keyboard_config.rgb_matrix_enable = false;

         rgb_matrix_set_color(2, 100, 50, 0);
         bool caps_lock_on = host_keyboard_led_state().caps_lock;
         for(uint8_t row = 0; row < MATRIX_ROWS; row ++)
         {
               for(uint8_t col = 0; col < MATRIX_COLS; col ++ )
               {

                   uint16_t led_index = g_led_config.matrix_co[row][col];

                   if(caps_lock_on)
                   {
                        paint(led_index, white);
                        continue;
                   }

                   uint16_t keycode = keymaps[current_layer][row][col];
                   uint16_t base_keycode = get_base_keycode(keycode);

                   if(keycode == _______ || keycode == KC_LALT || keycode == KC_LCTL || keycode == KC_LSFT || keycode == KC_LGUI) {
                     paint(led_index, black);
                   }else if(keycode == LALT(KC_F4) || base_keycode == KC_BS || base_keycode == KC_DELETE || keycode == LCTL(KC_W) || keycode == CLOSE_WIN){
                     paint(led_index, red);
                   }else if(keycode == LALT(KC_PSCR)){
                     paint(led_index, pink);
                   }else if(keycode == QK_BOOT){
                     paint(led_index, green);
                   }else if(is_key_in_range(base_keycode, KC_1, KC_0) || is_key_in_range(base_keycode, KC_RIGHT, KC_UP)){
                     paint(led_index, white);
                   }else if(is_key_in_range(keycode, KC_F1, KC_F9)){
                     paint(led_index, blue);
                   }else if(is_key_in_range(keycode, KC_F10, KC_F12)){
                     paint(led_index, white);
                   }else if(keycode != _______){
                     paint(led_index, orange);
                   }
               }

         }
    }
    return state;
}
//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* example of debug writing:
  if (record->event.pressed) {
        // On key press
        uint8_t row = record->event.key.row;
        uint8_t col = record->event.key.col;
        uprintf("Row: %u, Col: %u\n", row, col);
    }
   */
