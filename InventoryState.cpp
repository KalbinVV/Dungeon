#include "InventoryState.h"
#include "Text.h"
#include "ItemInformationState.h"
#include "Weapon.h"
#include "Utils.h"

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
                    break;
                }
                case SDL_SCANCODE_E:{
                    std::vector<Item*> items = game->getPlayer()->getInventory();
                    if(items.size() != 0){
                        items[currentItemIndex]->onUse(game->getPlayer());
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}

//Нет активного рендера
void InventoryState::render(){}

void InventoryState::drawStats(Stats stats, Renderer* renderer, int yPos){
    Text statsText("Сила: " + std::to_string(stats.strength) + "; Ловкость: " + std::to_string(stats.dexterity) +
        "; Выносливость: " + std::to_string(stats.stamina) + "; Интеллект: " + std::to_string(stats.intelligence),
        game->getFont(), TextRenderType::Quality);
    statsText.setPosition(Vec2i(0, yPos));
    statsText.setCharacterSize(12);
    statsText.setAlign(TextAlign::center);
    statsText.draw(renderer);
}

void InventoryState::view(){
    Renderer* renderer = game->getRenderer();
    SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 210);
    SDL_RenderFillRect(renderer->getSdlRenderer(), NULL);
    Text titleText("Инвентарь", game->getFont(), TextRenderType::Quality);
    titleText.setCharacterSize(14);
    titleText.setAlign(TextAlign::center);
    titleText.draw(renderer);
    std::vector<Item*> items = game->getPlayer()->getInventory();
    for(int i = 0; i < static_cast<int>(items.size()); i++){
        Item* item = items[i];
        SDL_Color color{r: 255,g: 255,b: 255};
        if(i == currentItemIndex) color = {r: 0,g: 0,b: 255};
        Text itemText(item->getName(), game->getFont(), TextRenderType::Quality, color);
        itemText.setPosition(Vec2i(0, (i + 1) * 60));
        itemText.setCharacterSize(12);
        itemText.setAlign(TextAlign::center);
        SDL_Rect itemSpriteDstRect = Utils::convertVec2iToSdlRect(12, Vec2i(itemText.getX() + itemText.getWidth() / 2 + 5,
            (i + 1) * 60));
        itemText.draw(renderer);
        item->draw(renderer, &itemSpriteDstRect);
        if(item->getType() == ItemType::Weapon){
            Text itemTypeText("Тип: Оружие", game->getFont(), TextRenderType::Quality);
            itemTypeText.setPosition(itemText.getPosition().addY(15));
            itemTypeText.setAlign(TextAlign::center);
            itemTypeText.draw(renderer);
            Stats stats = ( (Weapon*) item )->getStats();
            drawStats(stats, renderer, (i + 1) * 60 + 30);
        }
    }
    Text infoInventoryText("i - информация о предмете; e - использовать/экипировать предмет; d - выкинуть предмет",
        game->getFont(), TextRenderType::Quality);
    infoInventoryText.setCharacterSize(12);
    infoInventoryText.setPosition(Vec2i(0, game->getWindow()->getHeight() - 50));
    infoInventoryText.draw(renderer);
    renderer->update();
}

void InventoryState::updateMenu(){
    backgroundState->view();
    view();
}
