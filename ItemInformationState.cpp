#include "ItemInformationState.h"
#include "Text.h"
#include "InventoryState.h"
#include "Weapon.h"

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

void ItemInformationState::drawStat(std::string statsValue, Renderer* renderer, int yPos){
    Text statsText(statsValue, game->getFont(), TextRenderType::Quality);
    statsText.setCharacterSize(12);
    statsText.setPosition(Vec2i(0, yPos));
    statsText.draw(renderer);
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
        h: 16
    };
    dstRect.x -= dstRect.w / 2;
    titleText.draw(renderer, &dstRect);
    dstRect.x += dstRect.w + 5;
    dstRect.h = 16;
    dstRect.w = 16;
    item->draw(renderer, &dstRect);
    std::string itemDescriptionStr = item->getDescription();
    const int charPerLine = 100;
    Text descriptionText(itemDescriptionStr, game->getFont(), TextRenderType::Quality);
    descriptionText.setCharacterSize(16);
    descriptionText.setCharPerLine(charPerLine);
    descriptionText.setPosition(Vec2i(0, 40));
    descriptionText.draw(renderer);
    int yPos = descriptionText.getHeight() + descriptionText.getPosition().y;
    if(item->getType() == ItemType::Weapon){
        Stats stats = ((Weapon*) item)->getStats();
        drawStat("Сила - " + std::to_string(stats.strength), renderer, yPos);
        yPos += 40;
        drawStat("Ловкость - " + std::to_string(stats.dexterity), renderer, yPos);
        yPos += 40;
        drawStat("Выносливость - " + std::to_string(stats.stamina), renderer, yPos);
        yPos += 40;
        drawStat("Интеллект - " + std::to_string(stats.intelligence), renderer, yPos);
        yPos += 40;
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
