#include "InventoryState.h"
#include "Text.h"

InventoryState::InventoryState(Game* game, Player* player, IState* backgroundState){
    this->game = game;
    this->player = player;
    this->backgroundState = backgroundState;
    backgroundState->view();
    view();
}

void InventoryState::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) game->getWindow()->close();
        if(event.type == SDL_WINDOWEVENT){
            if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                Window* window = game->getWindow();
                window->setWidth(event.window.data1);
                window->setHeight(event.window.data2);
                backgroundState->view();
                view();
            }
        }
        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                backgroundState->view();
                game->getRenderer()->update();
                game->setState(backgroundState);
            }
        }
    }
}

//Нет активного рендера
void InventoryState::render(){}

void InventoryState::view(){
    std::string inventorySrc = "Вещи в инвентаре: ";
    for(Item* item : game->getPlayer()->getInventory()){
        inventorySrc += item->getName() + " ";
    }
    Text text(inventorySrc, game->getFont(), TextRenderType::Quality);
    SDL_Rect dstRect{
        x: 0,
        y: 0,
        w: inventorySrc.size() * 24 / 3,
        h: 50
    };
    text.draw(game->getRenderer(), &dstRect);
    game->getRenderer()->update();
}
