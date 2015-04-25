#include <pebble.h>
static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *date_layer;
static TextLayer *day_layer;
static GFont s_time_font;
static GFont date_font;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;
int index = 1; 
int loop = 10; 

static void update_time() {  
  
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  // Create a long-lived buffers
  static char buffer[] = "00:00";
	static char date_buffer[10];
  static char date_day[] = "XXX";

  //Time Handler
  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }
  //Date Handler
  strftime(date_buffer, sizeof(date_buffer), "%b %e", tick_time);
	text_layer_set_text(date_layer, date_buffer);  
  
  //Day Handler
  strftime(date_day,sizeof(date_day),"%a",tick_time);
  text_layer_set_text(day_layer, date_day);
  
  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, buffer);
 
  
  
 
}

static void updateAnimation(void *data){
  
gbitmap_destroy(s_background_bitmap);
bitmap_layer_destroy(s_background_layer);
text_layer_destroy(s_time_layer);
text_layer_destroy(date_layer);
text_layer_destroy(day_layer);
fonts_unload_custom_font(s_time_font);
fonts_unload_custom_font(date_font); 

if(index == 1){
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G2);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_background_layer));
index = 3;
}else if(index == 3){
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G3);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_background_layer));
index = 5;
}else if(index == 5){
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G4);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_background_layer));
index = 7;
}else if(index == 7){
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G5);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_background_layer));
index = 9;
}else if(index == 9){
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G6);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_background_layer));
index = 11;
}else if(index == 11){
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G1);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(s_main_window), bitmap_layer_get_layer(s_background_layer));
index = 1;
}
  
  s_time_layer = text_layer_create(GRect(6, 136, 81, 20));
  text_layer_set_background_color(s_time_layer, GColorBlack);
  text_layer_set_text_color(s_time_layer, GColorClear);
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_TRIFORCE_17));
  text_layer_set_font(s_time_layer, s_time_font);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_main_window), text_layer_get_layer(s_time_layer));
  date_layer = text_layer_create(GRect(87, 136, 52, 20));
	text_layer_set_background_color(date_layer, GColorBlack);
  text_layer_set_text_color(date_layer, GColorClear);
  date_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_TRIFORCE_15));
  text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(s_main_window), text_layer_get_layer(date_layer));
  day_layer = text_layer_create(GRect(108, 116, 33, 20));
  text_layer_set_background_color(day_layer, GColorBlack);
  text_layer_set_text_color(day_layer, GColorClear);
	text_layer_set_font(day_layer, date_font);
  text_layer_set_text_alignment(day_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(s_main_window), text_layer_get_layer(day_layer));
update_time();
  }


static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {  
 
  update_time();
  
}

static void main_window_load(Window *window){
 
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_G1);
s_background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap); 
layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_background_layer));


 
  s_time_layer = text_layer_create(GRect(6, 136, 81, 20));
  text_layer_set_background_color(s_time_layer, GColorBlack);
  text_layer_set_text_color(s_time_layer, GColorClear);
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_TRIFORCE_17));
  text_layer_set_font(s_time_layer, s_time_font);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
  date_layer = text_layer_create(GRect(87, 136, 52, 20));
	text_layer_set_background_color(date_layer, GColorBlack);
  text_layer_set_text_color(date_layer, GColorClear);
  date_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_TRIFORCE_15));
  text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(date_layer));
  day_layer = text_layer_create(GRect(108, 116, 33, 20));
  text_layer_set_background_color(day_layer, GColorBlack);
  text_layer_set_text_color(day_layer, GColorClear);
	text_layer_set_font(day_layer, date_font);
  text_layer_set_text_alignment(day_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(day_layer));
  
  
}


static void main_window_unload(Window *window){
 // Destroy GBitmap
gbitmap_destroy(s_background_bitmap);

// Destroy BitmapLayer
bitmap_layer_destroy(s_background_layer);
  text_layer_destroy(s_time_layer);
  text_layer_destroy(date_layer);
  text_layer_destroy(day_layer);
  fonts_unload_custom_font(s_time_font);
  fonts_unload_custom_font(date_font);
}


static void init(){
  s_main_window = window_create();
  
tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  
  window_stack_push(s_main_window, true);
  //accel_tap_service_subscribe(handle_tap);
  uint32_t refresh_rate = 50;
  for(int x = 0; x <84; x++){
 // while(1){
    app_timer_register(refresh_rate, updateAnimation, NULL);
    refresh_rate = refresh_rate + 50; 
  }
  //update_time();
 // updateAnimation(NULL);
}

static void deinit(){  
  window_destroy(s_main_window);
}


int main(void){
  init();
  app_event_loop();
  deinit();
}
