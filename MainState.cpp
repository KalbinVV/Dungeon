#include "MainState.h"
#include "Tile.h"
#include <iostream>

MainState::MainState(Game* game){
    this->game = game;
    updateScreen();
}

void MainState::updateScreen(){
    Renderer* renderer = game->getRenderer();
    Player* player = game->getPlayer();
    Vec2i coords = player->getCoords();
    int viewRange = game->getViewRange();
    renderer->clear(SDL_Color{
        r: 32,
        g: 18,
        b: 8
    });
    int worldWidth = game->getWorldWidth();
    int worldHeight = game->getWorldHeight();
    int spriteWidth = game->getWindow()->getWidth() / viewRange;
    int spriteHeight = game->getWindow()->getHeight() / viewRange;
    for(int i = coords.y - viewRange / 2; i <= coords.y + viewRange / 2; i++){
        for(int j = coords.x - viewRange / 2; j <= coords.x + viewRange / 2; j++){
            if(i < 0 || j < 0 || i >= worldHeight || j >= worldWidth) continue;
            if(i == coords.y && j == coords.x) continue;
            SDL_Rect dstRect{
                x: (j - coords.x + (viewRange / 2) ) * spriteWidth,
                y: (i - coords.y + (viewRange / 2) ) * spriteHeight,
                w: spriteWidth,
                h: spriteHeight
            };
            game->getTileAt(i, j)->draw(renderer, &dstRect);
        }
    }
    SDL_Rect dstRect{
        x: viewRange / 2 * spriteWidth,
        y: viewRange / 2 * spriteHeight,
        w: spriteWidth,
        h: spriteHeight
    };
    game->getPlayer()->draw(renderer, &dstRect);
    renderer->update();
}

void MainState::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) game->getWindow()->close();
        if(event.type == SDL_WINDOWEVENT){
            if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                Window* window = game->getWindow();
                window->setWidth(event.window.data1);
                window->setHeight(event.window.data2);
                updateScreen();
            }
        }
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.scancode){
                case SDL_SCANCODE_D:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addX(1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_A:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addX(-1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_S:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addY(1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_W:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addY(-1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_E:{
                    Vec2i coords = game->getPlayer()->getCoords();
                    std::cout << game->getTileAt(coords.y, coords.x)->getName() << std::endl;
                    break;
                }
                default:
                    break;
            }
        }
    }
}

//Нет активного рендера.
void MainState::render() {}
