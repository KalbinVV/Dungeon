#include "MainState.h"

MainState::MainState(Game* game){
    this->game = game;
}

void MainState::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) game->getWindow()->close();
    }
}

void MainState::render(){
    Renderer* renderer = game->getRenderer();
    renderer->clear(SDL_Color{
        r: 0,
        g: 255,
        b: 0
    });
    renderer->update();
}
