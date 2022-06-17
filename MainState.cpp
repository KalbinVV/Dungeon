#include "MainState.h"
#include "Tile.h"
#include <iostream>
#include "RenderException.h"
#include "Text.h"
#include "InventoryState.h"

MainState::MainState(Game* game){
    this->game = game;
    updateScreen();
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
                        break;
                    }
                }
                case SDL_SCANCODE_I:{
                    game->setStateWithoutMemoryFree(new InventoryState(game, game->getPlayer(), this));
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

void MainState::updateScreen(){
    view();
    game->getRenderer()->update();
}

void MainState::view() {
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
            Tile* tile = game->getTileAt(i, j);
            tile->draw(renderer, &dstRect);
            std::vector<Item*> items = tile->getItems();
            if(items.size() > 0){
                items[items.size() - 1]->draw(renderer, &dstRect);
            }
        }
    }
    SDL_Rect dstRect{
        x: viewRange / 2 * spriteWidth,
        y: viewRange / 2 * spriteHeight,
        w: spriteWidth,
        h: spriteHeight
    };
    std::vector<Item*> items = game->getTileAt(coords.y, coords.x)->getItems();
    if(items.size() != 0){
        std::string infoText = "Подобрать предмет - P";
        SDL_Rect textDstRect{
            x: 0,
            y: 0,
            w: spriteWidth / 8 * static_cast<int>(infoText.size()) / 40 * 24,
            h: spriteHeight / 3
        };
        std::string itemsText = "Предметы на клетке: ";
        for(Item* item : items){
            itemsText += item->getName() + " ";
        }
        Text text(infoText, game->getFont(), TextRenderType::Quality);
        text.draw(renderer, &textDstRect);
        text.setString(itemsText);
        textDstRect.y += textDstRect.h + 5;
        textDstRect.w = spriteWidth / 8 * static_cast<int>(itemsText.size()) / 40 * 24;
        text.draw(renderer, &textDstRect);
    }
    game->getPlayer()->draw(renderer, &dstRect);
}
