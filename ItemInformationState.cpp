#include "ItemInformationState.h"
#include "Text.h"
#include "InventoryState.h"
#include "Weapon.h"
#include "Utils.h"
#include "EquipmentItem.h"

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
    std::string itemName = item->getName();
    Player* player = game->getPlayer();
    if(item == player->getWeapon() || item == player->getArmor()){
        itemName += " [Экипировано]";
    }
    Text titleText(itemName, game->getFont(), TextRenderType::Quality);
    titleText.setCharacterSize(16);
    titleText.setPosition(Vec2i(0, 0));
    titleText.setAlign(TextAlign::center);
    titleText.draw(renderer);
    SDL_Rect spriteItemRect = Utils::convertVec2iToSdlRect(12, Vec2i(titleText.getX() + titleText.getWidth() / 2, 0));
    item->draw(renderer, &spriteItemRect);
    std::string itemDescriptionStr = item->getDescription();
    const int charPerLine = 100;
    Text descriptionText(itemDescriptionStr, game->getFont(), TextRenderType::Quality);
    descriptionText.setCharacterSize(18);
    descriptionText.setCharPerLine(charPerLine);
    descriptionText.setPosition(Vec2i(0, 40));
    descriptionText.setAlign(TextAlign::center);
    descriptionText.setConsideredByScreenResolution(false);
    descriptionText.draw(renderer);
    int yPos = descriptionText.getHeight() + descriptionText.getPosition().y + 40;
    ItemType itemType = item->getType();
    if(itemType == ItemType::Weapon || itemType == ItemType::Armor){
        Stats stats = dynamic_cast<EquipmentItem*>(item)->getStats();
        drawStat("Сила - " + std::to_string(stats.strength), renderer, yPos);
        yPos += 20;
        drawStat("Ловкость - " + std::to_string(stats.dexterity), renderer, yPos);
        yPos += 20;
        drawStat("Выносливость - " + std::to_string(stats.stamina), renderer, yPos);
        yPos += 20;
        drawStat("Интеллект - " + std::to_string(stats.intelligence), renderer, yPos);
        yPos += 20;
    }
    Text footerText("ESC - Вернуться в инвентарь", game->getFont(), TextRenderType::Quality);
    footerText.setCharacterSize(12);
    footerText.setPosition(Vec2i(0, yPos));
    footerText.draw(renderer);
    renderer->update();
}

void ItemInformationState::render(){}
