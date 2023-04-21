#include "../RPGWindow.h"


WindowStates update(RPGWindow* window){
    _WindowState state = mfb_update(window->window, window->buffer);
    return (WindowStates) state;
};

void closeWindow(struct RPGWindow* window){
    mfb_close(window->window);
    window->state = STATE_EXIT;
};

void clearWindow(struct RPGWindow* window){
    memset(window->buffer, 0, window->width * window->height * sizeof(uint32_t));
};

/*
void setResizeCallback(struct RPGWindow* window, void (*callback)(struct RPGWindow* window, uint32_t width, uint32_t height)){
    mfb_resize_func resize = (mfb_resize_func) callback;
    mfb_set_resize_callback(window->window, resize);
}*/

void setCloseCallback(struct RPGWindow* window, bool (*callback)(struct RPGWindow* window)){
    mfb_close_func close = (mfb_close_func) callback;
    mfb_set_close_callback(window->window, close);
}

RPGWindow* CreateRPGWindow(uint32_t width, uint32_t height, const char* title, WindowFlags windowMode){
    RPGWindow* window = malloc(sizeof(RPGWindow));
    window->width = width;
    window->height = height;
    window->title = title;
    window->buffer = malloc(width * height * sizeof(uint32_t));
    window->state = STATE_OK;
    if(windowMode == NULL){
        window->window = mfb_open(title, width, height);
    }else{
        window->window = mfb_open_ex(title, width, height, windowMode);
    }

    mfb_set_user_data(window->window, window);

    window->update = update;
    window->close = closeWindow;
    //window->setResizeCallback = setResizeCallback;
    window->setCloseCallback = setCloseCallback;
    window->clear = clearWindow;

    return window;
};

void TerminateRPGWindow(RPGWindow* window){
    mfb_close(window->window);
    free(window->buffer);
    free(window);
};
