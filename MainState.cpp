#include "MainState.h"
#include "Tile.h"
#include <iostream>
#include "RenderException.h"
#include "Text.h"
#include "InventoryState.h"
#include "PauseState.h"

MainState::MainState(Game* game){
    this->game = game;
    updateScreen();
}

void MainState::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) game->getWindow()->close();
        else if(event.type == SDL_WINDOWEVENT){
            if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                Window* window = game->getWindow();
                window->setWidth(event.window.data1);
                window->setHeight(event.window.data2);
                updateScreen();
            }
        }
        else if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.scancode){
                case SDL_SCANCODE_RIGHT:
                case SDL_SCANCODE_D:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addX(1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_LEFT:
                case SDL_SCANCODE_A:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addX(-1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_DOWN:
                case SDL_SCANCODE_S:{
                    game->getPlayer()->move(game->getPlayer()->getCoords().addY(1));
                    updateScreen();
                    break;
                }
                case SDL_SCANCODE_UP:
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
                case SDL_SCANCODE_P:{
                    Vec2i coords = game->getPlayer()->getCoords();
                    std::vector<Item*> items = game->getTileAt(coords.y, coords.x)->getItems();
                    if(items.size() != 0){
                        Item* item = items[0];
                        game->getPlayer()->addItem(item);
                        game->getTileAt(coords.y, coords.x)->removeItem(item);
                        updateScreen();
                    }
                    break;
                }
                case SDL_SCANCODE_I:{
                    game->setStateWithoutMemoryFree(new InventoryState(game, game->getPlayer(), this));
                    break;
                }
                case SDL_SCANCODE_ESCAPE:
                    game->setStateWithoutMemoryFree(new PauseState(game, this));
                    break;
                default:
                    break;
            }
        }
    }
}

//Нет активного рендера.
void MainState::render() {}

void MainState::updateScreen(){
    view();
    game->getRenderer()->update();
}

void MainState::drawMap(){
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
            //if(i == coords.y && j == coords.x) continue;
            SDL_Rect dstRect{
                x: (j - coords.x + (viewRange / 2) ) * spriteWidth,
                y: (i - coords.y + (viewRange / 2) ) * spriteHeight,
                w: spriteWidth,
                h: spriteHeight
            };
            Tile* tile = game->getTileAt(i, j);
            tile->draw(renderer, &dstRect);
            std::vector<Item*> items = tile->getItems();
            if(items.size() > 0){
                items[items.size() - 1]->draw(renderer, &dstRect);
            }
        }
    }
}

void MainState::drawPickupInfoIfItemExists(){
    Renderer* renderer = game->getRenderer();
    Vec2i coords = game->getPlayer()->getCoords();
    std::vector<Item*> items = game->getTileAt(coords.y, coords.x)->getItems();
    if(items.size() != 0){
        SDL_Rect rectDstRect{
            x: 0,
            y: 0,
            w: game->getWindow()->getWidth(),
            h: 70
        };
        SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 200);
        SDL_RenderFillRect(renderer->getSdlRenderer(), &rectDstRect);
        std::string infoText = "Подобрать предмет - P";
        SDL_Rect textDstRect{
            x: 0,
            y: 5,
            w: static_cast<int>(infoText.size()) * 8,
            h: 16
        };
        std::string itemsText = "Предметы на клетке: ";
        for(Item* item : items){
            itemsText += item->getName() + " ";
        }
        Text text(infoText, game->getFont(), TextRenderType::Quality);
        text.draw(renderer, &textDstRect);
        text.setString(itemsText);
        textDstRect.y += textDstRect.h + 15;
        textDstRect.w = static_cast<int>(itemsText.size()) * 5;
        text.draw(renderer, &textDstRect);
    }
}

void MainState::drawPlayer(){
    int viewRange = game->getViewRange();
    int spriteWidth = game->getWindow()->getWidth() / viewRange;
    int spriteHeight = game->getWindow()->getHeight() / viewRange;
    SDL_Rect dstRect{
        x: viewRange / 2 * spriteWidth,
        y: viewRange / 2 * spriteHeight,
        w: spriteWidth,
        h: spriteHeight
    };
    game->getPlayer()->draw(game->getRenderer(), &dstRect);
}

void MainState::drawStats(){
    Stats stats = game->getPlayer()->getStats();
    Renderer* renderer = game->getRenderer();
    Stats bonusStats = game->getPlayer()->getBonusStats();
    Text text("Сила: " + std::to_string(stats.strength)
        + " +" + std::to_string(bonusStats.strength), game->getFont(), TextRenderType::Quality);
    SDL_Rect backgroundDstRect{
        x: 0,
        y: game->getWindow()->getHeight() - 90,
        w: game->getWindow()->getWidth() / 4,
        h: 90
    };
    SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 100);
    SDL_RenderFillRect(renderer->getSdlRenderer(), &backgroundDstRect);
    SDL_Rect dstRect{
        x: 0,
        y: game->getWindow()->getHeight() - 80,
        w: static_cast<int>(text.getString().size()) * 7,
        h: 16
    };
    text.draw(renderer, &dstRect);
    text.setString("Ловкость: " + std::to_string(stats.dexterity)
        + " +" + std::to_string(bonusStats.dexterity));
    dstRect.w = static_cast<int>(text.getString().size()) * 6;
    dstRect.y += 20;
    text.draw(renderer, &dstRect);
    text.setString("Выносливость: " + std::to_string(stats.stamina)
        + " +" + std::to_string(bonusStats.stamina));
    dstRect.w = static_cast<int>(text.getString().size()) * 6;
    dstRect.y += 20;
    text.draw(renderer, &dstRect);
    text.setString("Интеллект: " + std::to_string(stats.intelligence)
        + " +" + std::to_string(bonusStats.intelligence));
    dstRect.w = static_cast<int>(text.getString().size()) * 6;
    dstRect.y += 20;
    text.draw(renderer, &dstRect);
}

void MainState::view(){
    drawMap();
    drawPickupInfoIfItemExists();
    drawPlayer();
    drawStats();
}
