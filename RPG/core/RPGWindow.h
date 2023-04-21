#pragma once

#include "../Global.h"

#include "RPGHints.h"
#include "../Input/InputEnums.h"

typedef struct RPGWindow{
    uint32_t width;
    uint32_t height;
    const char* title;

    uint32_t* buffer;
    mfb_update_state state;
    WindowHandler* window;

    //Window control
    WindowStates (*update)(struct RPGWindow* window);
    void (*close)(struct RPGWindow* window);

    //callbacks
    //void (*setResizeCallback)(struct RPGWindow* window, void (*callback)(struct RPGWindow* window, uint32_t width, uint32_t height));
    void (*setCloseCallback)(struct RPGWindow* window, bool (*callback)(struct RPGWindow* window));


    //private
    void (*__keyCallback)(struct RPGWindow* window, RPGKey key, RPGKeyMod mod, bool isPressed);


}RPGWindow;

RPGWindow* CreateRPGWindow(uint32_t width, uint32_t height, const char* title, WindowFlags WindowMode);
void TerminateRPGWindow(RPGWindow* window);