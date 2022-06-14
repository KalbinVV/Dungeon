#include "Game.h"
#include "InitException.h"
#include "MainState.h"

void Game::initModules(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) throw InitException(SDL_GetError());
}

void Game::unInitModules(){
    SDL_Quit();
}

Game::Game(const char* title, int width, int height){
    state = nullptr;
    window.open(title, width, height);
    renderer.init(&window);
}

Window* Game::getWindow(){
    return &window;
}

Renderer* Game::getRenderer(){
    return &renderer;
}

void Game::setState(IState* newState){
    if(state) delete state;
    state = newState;
}

void Game::run(){
    setState(new MainState(this));
    while(window.isOpen()){
        state->handleEvents();
        state->render();
    }
}
