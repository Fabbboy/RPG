#include <stdio.h>
#include <stdlib.h>

#include "RPG/core/RPGWindow.h"
#include "RPG/Input/RPGInput.h"
#include "RPG/core/renderer/Pixel.h"
#include "RPG/core/renderer/RPGRenderer.h"


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

    int counter = 0;

    while (window->state == STATE_OK) {
        counter++;
        window->clear(window);

        // start top eft and print over the sreen to the right using the counter
        for (int i = 0; i < window->width; i++) {
            for (int j = 0; j < window->height; j++) {
                Pixel* pixel = CreatePixel(255, 255, 255, 100,false);
                window->buffer[i + j * window->width] = PixelToHex(pixel);
            }
        }

        WindowStates state = window->update(window);
        if (state == RPG_EXIT) {
            window->close(window);
            break;
        }
    }



    return 0;
}

