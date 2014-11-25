#include <pebble.h>

// Window resource management
static Window *s_main_window;

static void main_window_load( Window *window ) {
  // TODO: things
}

static void main_window_unload( Window *window ) {
  // TODO: things
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