#include "InventoryState.h"
#include "Text.h"
#include "ItemInformationState.h"

InventoryState::InventoryState(Game* game, Player* player, IState* backgroundState){
    currentItemIndex = 0;
    this->game = game;
    this->player = player;
    this->backgroundState = backgroundState;
    updateMenu();
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
                updateMenu();
            }
        }
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.scancode){
                case SDL_SCANCODE_ESCAPE:
                    backgroundState->view();
                    game->getRenderer()->update();
                    game->setState(backgroundState);
                    break;
                case SDL_SCANCODE_UP:
                    if(currentItemIndex > 0){
                        currentItemIndex--;
                        updateMenu();
                    }
                    break;
                case SDL_SCANCODE_DOWN:{
                    std::vector<Item*> items = game->getPlayer()->getInventory();
                    if(currentItemIndex < static_cast<int>(items.size()) - 1){
                        currentItemIndex++;
                        updateMenu();
                    }
                    break;
                }
                case SDL_SCANCODE_D:{
                    std::vector<Item*> items = game->getPlayer()->getInventory();
                    if(items.size() > 0){
                        Item* item = items[currentItemIndex];
                        game->getPlayer()->removeItem(item);
                        Vec2i coords = game->getPlayer()->getCoords();
                        game->getTileAt(coords.y, coords.x)->addItem(item);
                        updateMenu();
                    }
                    break;
                }
                case SDL_SCANCODE_I:{
                    std::vector<Item*> items = game->getPlayer()->getInventory();
                    if(items.size() != 0){
                        game->setState(new ItemInformationState(items[currentItemIndex], game, backgroundState));
                    }
                }
                default:
                    break;
            }
        }
    }
}

//Нет активного рендера
void InventoryState::render(){}

void InventoryState::view(){
    Renderer* renderer = game->getRenderer();
    SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 210);
    SDL_RenderFillRect(renderer->getSdlRenderer(), NULL);
    Text titleText("Инвентарь", game->getFont(), TextRenderType::Quality);
    SDL_Rect dstRect{
        x: game->getWindow()->getWidth() / 2,
        y: 0,
        w: static_cast<int>(titleText.getString().size()) * game->getWindow()->getWidth() / 210,
        h: 24
    };
    dstRect.x -= dstRect.w / 2;
    titleText.draw(renderer, &dstRect);
    std::vector<Item*> items = game->getPlayer()->getInventory();
    for(int i = 0; i < static_cast<int>(items.size()); i++){
        Item* item = items[i];
        SDL_Rect itemTextDstRect{
            x: 0,
            y: (i + 1) * 27,
            w: static_cast<int>(item->getName().size()) * 6,
            h: 24
        };
        SDL_Rect itemSpriteDstRect{
            x: itemTextDstRect.w + 5,
            y: (i + 1) * 27,
            w: 20,
            h: 20
        };
        SDL_Color color{
            r: 255,
            g: 255,
            b: 255
        };
        if(i == currentItemIndex){
            color = {
                r: 0,
                g: 0,
                b: 255
            };
        }
        Text itemText(item->getName(), game->getFont(), TextRenderType::Quality, color);
        itemText.draw(renderer, &itemTextDstRect);
        item->draw(renderer, &itemSpriteDstRect);
    }
    Text infoInventoryText("i - информация о предмете; e - использовать предмет; d - выкинуть предмет; стрелки вверх/вниз - изменить текущий предмет", game->getFont(), TextRenderType::Quality);
    SDL_Rect infoInventoryTextDstRect{
        x: 0,
        y: game->getWindow()->getHeight() - 30,
        w: static_cast<int>(infoInventoryText.getString().size()) * game->getWindow()->getWidth() / 220,
        h: 25
    };
    infoInventoryText.draw(renderer, &infoInventoryTextDstRect);
    renderer->update();
}

void InventoryState::updateMenu(){
    backgroundState->view();
    view();
}
