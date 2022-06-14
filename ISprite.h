#ifndef ISPRITE_H_INCLUDED
#define ISPRITE_H_INCLUDED

#include "Renderer.h"

class ISprite{
public:
    virtual void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL) = 0;
};

#endif // ISPRITE_H_INCLUDED
