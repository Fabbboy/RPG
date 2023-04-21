#include "../RPGRenderer.h"

void renderPixel(RPGWindow* window, Pixel* pixel, uint32_t x, uint32_t y){
    //if render block then render a 2x2 pixel block else render a single pixel
    if (pixel->renderBlock){
        window->buffer[(y * window->width) + x] = (pixel->r << 16) | (pixel->g << 8) | (pixel->b << 0);
        window->buffer[(y * window->width) + x + 1] = (pixel->r << 16) | (pixel->g << 8) | (pixel->b << 0);
        window->buffer[((y + 1) * window->width) + x] = (pixel->r << 16) | (pixel->g << 8) | (pixel->b << 0);
        window->buffer[((y + 1) * window->width) + x + 1] = (pixel->r << 16) | (pixel->g << 8) | (pixel->b << 0);
    }else{
        window->buffer[(y * window->width) + x] = (pixel->r << 16) | (pixel->g << 8) | (pixel->b << 0);
    }
};

uint32_t PixelToHex(Pixel* pixel){
    return (pixel->r << 16) | (pixel->g << 8) | (pixel->b << 0);
};