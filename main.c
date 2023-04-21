#include <stdio.h>
#include <stdlib.h>

#include "RPG/core/RPGWindow.h"
#include "RPG/Input/RPGInput.h"



void keyCallback(RPGWindow* window, RPGKey key, RPGKeyMod mod, bool isPressed){
    if(key == RPG_KEY_ESCAPE){
        window->close(window);
    }
}

bool closeCallback(RPGWindow* window){
    return true;
}



int main() {
    RPGWindow* window = CreateRPGWindow(800, 600, "RPG",RPG_RESIZABLE);

    window->setCloseCallback(window, closeCallback);

    RPGKeyboardListener(window, keyCallback);

    while (window->state == STATE_OK) {
        WindowStates state = window->update(window);

        if (state == RPG_EXIT) {
            window->close(window);
            break;
        }
    }



    return 0;
}

