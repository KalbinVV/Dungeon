#include "MainState.h"
#include "Tile.h"

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
    SpriteAtlas* spriteAtlas = game->getSpriteAtlas();
    renderer->clear(SDL_Color{
        r: 0,
        g: 0,
        b: 0
    });
    Tile tile(spriteAtlas, 2, 6, "1", "1");
    tile.draw(renderer);
    renderer->update();
}
