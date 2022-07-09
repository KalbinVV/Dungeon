#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "Vec2i.h"

class Utils{
public:
    static std::vector<std::string> splitString(std::string str, std::string separator);
    static SDL_Rect convertVec2iToSdlRect(int spriteSize, Vec2i vec2i);
};

#endif // UTILS_H_INCLUDED
