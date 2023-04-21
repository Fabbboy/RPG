#include "../RPGInput.h"

void __InternalKeyboardListener(struct mfb_window *window, mfb_key key, mfb_key_mod mod, bool isPressed){
    RPGWindow* win = mfb_get_user_data(window);
    if (win->__keyCallback != NULL) {
        win->__keyCallback(win, (RPGKey) key, (RPGKeyMod) mod, isPressed);
    }
};


void RPGKeyboardListener(RPGWindow * window,void (*callback)(RPGWindow* window, RPGKey, RPGKeyMod, bool)){
    //mfb_set_keyboard_callback(mfb_window *window, mfb_keyboard_func callback
    window->__keyCallback = callback;
    mfb_set_keyboard_callback(window->window, __InternalKeyboardListener);
}



void RPGMouseButtonListener(RPGWindow * window,void (*callback)(RPGWindow* window, RPGKey, RPGKeyMod, bool)){
    //mfb_set_mouse_callback(mfb_window *window, mfb_mouse_func callback)
    mfb_set_mouse_move_callback(window->window, (mfb_mouse_move_func) callback);
}

void RPGScrollListener(RPGWindow * window,void (*callback)(RPGWindow* window, RPGKeyMod, float, float)){
    //mfb_set_scroll_callback(mfb_window *window, mfb_scroll_func callback)
    mfb_set_mouse_scroll_callback(window->window, (mfb_mouse_scroll_func) callback);
}

void RPGMouseMoveListener(RPGWindow * window,void (*callback)(RPGWindow* window, float, float)){
    //mfb_set_mouse_move_callback(mfb_window *window, mfb_mouse_move_func callback)
    mfb_set_mouse_move_callback(window->window, (mfb_mouse_move_func) callback);
}

void RPGCharListener(RPGWindow * window,void (*callback)(RPGWindow* window, unsigned int)){
    //mfb_set_char_callback(mfb_window *window, mfb_char_func callback)
    mfb_set_char_input_callback(window->window, (mfb_char_input_func) callback);
}