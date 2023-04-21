#include "../Pixel.h"

Pixel* CreatePixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool renderBlock){
    Pixel* pixel = malloc(sizeof(Pixel));
    pixel->r = r;
    pixel->g = g;
    pixel->b = b;
    pixel->a = a;
    pixel->renderBlock = renderBlock;
    return pixel;
};
void TerminatePixel(Pixel* pixel){
    free(pixel);
};