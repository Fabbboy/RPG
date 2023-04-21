#pragma once

#include "../../Global.h"

typedef struct Pixel{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    bool renderBlock;
}Pixel;

Pixel* CreatePixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool renderBlock);
void TerminatePixel(Pixel* pixel);
uint32_t PixelToHex(Pixel* pixel);