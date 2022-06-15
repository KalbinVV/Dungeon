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
    renderer->clear(SDL_Color{
        r: 255,
        g: 255,
        b: 255
    });
    int spriteWidth = game->getWindow()->getWidth() / 20;
    int spriteHeight = game->getWindow()->getHeight() / 20;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            SDL_Rect dstRect{
                x: j * spriteWidth,
                y: i * spriteHeight,
                w: spriteWidth,
                h: spriteHeight
            };
            game->getTileAt(i, j)->draw(renderer, &dstRect);
        }
    }
    renderer->update();
}
