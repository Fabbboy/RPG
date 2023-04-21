#include "../Global.h"
#include "../core/RPGWindow.h"

void RPGKeyboardListener(RPGWindow * window,void (*callback)(RPGWindow* window, RPGKey, RPGKeyMod, bool));
void __InternalKeyboardListener(struct mfb_window *window, mfb_key key, mfb_key_mod mod, bool isPressed);

void RPGMouseButtonListener(RPGWindow * window,void (*callback)(RPGWindow* window, RPGKey, RPGKeyMod, bool));
void RPGScrollListener(RPGWindow * window,void (*callback)(RPGWindow* window, RPGKeyMod, float, float));
void RPGMouseMoveListener(RPGWindow * window,void (*callback)(RPGWindow* window, float, float));
void RPGCharListener(RPGWindow * window,void (*callback)(RPGWindow* window, unsigned int));