#include <pebble.h>

// Layers
static TextLayer *s_time_layer;
  
// Window resource management
static Window *s_main_window;

static void main_window_load( Window *window ) {
  // Create time_layer TextLayer
  s_time_layer = text_layer_create(GRect(0,55,144,50));
  text_layer_set_background_color(s_time_layer, GColorBlack);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
  // Add text_layer as a child to the Window's root
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
}

static void main_window_unload( Window *window ) {
  // TODO: things
  text_layer_destroy(s_time_layer);
}

// App resource management

static void init() {
  // Create main window
  s_main_window = window_create();
  window_set_window_handlers(
    s_main_window,
    (WindowHandlers) {
      .load = main_window_load,
      .unload = main_window_unload
    });
    
    // Show window on the watch, animated
    window_stack_push( s_main_window, true );
}

static void deinit() {
  // Destroy window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}