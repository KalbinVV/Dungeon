#include "Renderer.h"
#include "InitException.h"

Renderer::Renderer(){
    sdlRenderer = nullptr;
}

void Renderer::init(Window* window){
    sdlRenderer = SDL_CreateRenderer(window->getSdlWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(sdlRenderer == NULL){
        throw InitException(SDL_GetError());
    }
    SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
}

void Renderer::unInit(){
    if(sdlRenderer) SDL_DestroyRenderer(sdlRenderer);
    sdlRenderer = nullptr;
}

SDL_Renderer* Renderer::getSdlRenderer(){
    return sdlRenderer;
}

void Renderer::clear(SDL_Color color){
    SDL_SetRenderDrawColor(sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(sdlRenderer);
}

void Renderer::update(){
    SDL_RenderPresent(sdlRenderer);
}

Renderer::~Renderer(){
    unInit();
}
