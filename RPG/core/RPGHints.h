#pragma once

#include "../Global.h"


typedef enum WindowFlags{
    RPG_RESIZABLE = WF_RESIZABLE,
    RPG_FULLSCREEN = WF_FULLSCREEN,
    RPG_FULLSCREEN_DESKTOP = WF_FULLSCREEN_DESKTOP,
    RPG_BORDERLESS = WF_BORDERLESS,
    RPG_ALWAYS_ON_TOP = WF_ALWAYS_ON_TOP
}WindowFlags;

typedef enum WindowStates{
    RPG_OK = STATE_OK,
    RPG_EXIT = STATE_EXIT,
    RPG_INVALID_WINDOW = STATE_INVALID_WINDOW,
    RPG_INVALID_BUFFER = STATE_INVALID_BUFFER,
    RPG_INTERNAL_ERROR = STATE_INTERNAL_ERROR
}WindowStates;