#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "Window.h"

class Renderer{
private:
    SDL_Renderer* sdlRenderer;
public:
    Renderer();
    void init(Window* window);
    void unInit();
    SDL_Renderer* getSdlRenderer();
    void clear(SDL_Color color);
    void update();
    ~Renderer();
};

#endif // RENDERER_H_INCLUDED
