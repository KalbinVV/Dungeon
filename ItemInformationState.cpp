#include "ItemInformationState.h"
#include "Text.h"
#include "InventoryState.h"

ItemInformationState::ItemInformationState(Item* item, Game* game, IState* backgroundState){
    this->item = item;
    this->game = game;
    this->backgroundState = backgroundState;
    view();
}

void ItemInformationState::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) game->getWindow()->close();
        else if(event.type == SDL_WINDOWEVENT){
            if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                Window* window = game->getWindow();
                window->setWidth(event.window.data1);
                window->setHeight(event.window.data2);
                view();
            }
        }else if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.scancode){
                case SDL_SCANCODE_ESCAPE:
                    game->setState(new InventoryState(game, game->getPlayer(), backgroundState));
                default:
                    break;
            }
        }
    }
}

void ItemInformationState::view(){
    Renderer* renderer = game->getRenderer();
    backgroundState->view();
    SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 210);
    SDL_RenderFillRect(renderer->getSdlRenderer(), NULL);
    std::string titleTextStr = item->getName();
    Text titleText(titleTextStr, game->getFont(), TextRenderType::Quality);
    SDL_Rect dstRect{
        x: game->getWindow()->getWidth() / 2,
        y: 0,
        w: static_cast<int>(titleTextStr.size()) * game->getWindow()->getWidth() / 150,
        h: 24
    };
    dstRect.x -= dstRect.w / 2;
    titleText.draw(renderer, &dstRect);
    dstRect.x += dstRect.w + 5;
    dstRect.h = 24;
    dstRect.w = 24;
    item->draw(renderer, &dstRect);
    std::string itemDescriptionStr = item->getDescription();
    int yPos = 0;
    const int charPerLine = 100;
    while(itemDescriptionStr.size() > 0){
        yPos += 40;
        Text descriptionText(itemDescriptionStr.substr(0, charPerLine), game->getFont(), TextRenderType::Quality);
        SDL_Rect descriptionTextDstRect{
            x: 0,
            y: yPos,
            w: charPerLine * game->getWindow()->getWidth() / 120,
            h: 24
        };
        if(static_cast<int>(itemDescriptionStr.size()) < charPerLine){
            descriptionTextDstRect.w = static_cast<int>(itemDescriptionStr.size()) * game->getWindow()->getWidth() / 150;
        }
        descriptionText.draw(renderer, &descriptionTextDstRect);
        itemDescriptionStr.erase(0, charPerLine);
    }
    Text footerText("ESC - Вернуться в инвентарь", game->getFont(), TextRenderType::Quality);
    SDL_Rect footerTextDstRect{
        x: 0,
        y: yPos + 40,
        w: static_cast<int>(footerText.getString().size()) * game->getWindow()->getWidth() / 190,
        h: 16
    };
    footerText.draw(renderer, &footerTextDstRect);
    renderer->update();
}

void ItemInformationState::render(){}
