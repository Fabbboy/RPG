cmake_minimum_required(VERSION 3.24)
project(RPG C)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/minifb/include)

# Check if building on macOS
if (APPLE)
    find_library(APPKIT_LIBRARY AppKit)
    find_library(METAL_LIBRARY Metal)
    find_library(METALKIT_LIBRARY MetalKit) # Add this line
    find_library(QUARTZCORE_LIBRARY QuartzCore)
endif ()

add_executable(RPG main.c RPG/core/RPGWindow.h RPG/core/src/RPGWindow.c RPG/core/RPGHints.h RPG/Global.h RPG/Input/RPGInput.h RPG/Input/src/RPGInput.c RPG/Input/InputEnums.h RPG/core/renderer/RPGRenderer.h RPG/core/renderer/Pixel.h RPG/core/renderer/src/Pixel.c RPG/core/renderer/src/RGBRenderer.c)
target_link_libraries(RPG ${CMAKE_SOURCE_DIR}/minifb/lib/libminifb.a)

# Link necessary frameworks if building on macOS
if (APPLE)
    target_link_libraries(RPG ${APPKIT_LIBRARY} ${METAL_LIBRARY} ${METALKIT_LIBRARY} ${QUARTZCORE_LIBRARY})
endif ()
