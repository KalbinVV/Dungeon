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
        std::string itemsText = "";
        for(Item* item : items){
            itemsText += item->getName() + " ";
        }
        Text text("Подобрать предмет - P", game->getFont(), TextRenderType::Quality);
        text.setCharacterSize(14);
        text.setPosition(Vec2i(0, 5));
        text.draw(renderer);
        text.setString(itemsText);
        text.setPosition(text.getPosition().addY(20));
        text.draw(renderer);
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
    Player* player = game->getPlayer();
    Stats stats = player->getStats();
    Renderer* renderer = game->getRenderer();
    Stats bonusStats = player->getBonusStats();
    Text text("Здоровье: " + std::to_string(player->getCurrentHp()), game->getFont(), TextRenderType::Quality);
    text.setCharacterSize(12);
    SDL_Rect backgroundDstRect{
        x: 0,
        y: game->getWindow()->getHeight() - 110,
        w: game->getWindow()->getWidth() / 4,
        h: 110
    };
    SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 100);
    SDL_RenderFillRect(renderer->getSdlRenderer(), &backgroundDstRect);
    text.setPosition(Vec2i(0, game->getWindow()->getHeight() - 100));
    text.draw(renderer);
    text.setPosition(text.getPosition().addY(20));
    text.setString("Сила: " + std::to_string(stats.strength)
        + " +" + std::to_string(bonusStats.strength));
    text.draw(renderer);
    text.setString("Ловкость: " + std::to_string(stats.dexterity)
        + " +" + std::to_string(bonusStats.dexterity));
    text.setPosition(text.getPosition().addY(20));
    text.draw(renderer);
    text.setString("Выносливость: " + std::to_string(stats.stamina)
        + " +" + std::to_string(bonusStats.stamina));
    text.setPosition(text.getPosition().addY(20));
    text.draw(renderer);
    text.setString("Интеллект: " + std::to_string(stats.intelligence)
        + " +" + std::to_string(bonusStats.intelligence));
    text.setPosition(text.getPosition().addY(20));
    text.draw(renderer);
}

void MainState::updateEnvironment(){
    const std::list<Entity*> entities = game->getEntities();
    const int viewRange = game->getViewRange();
    const int spriteWidth = game->getWindow()->getWidth() / viewRange;
    const int spriteHeight = game->getWindow()->getHeight() / viewRange;
    for(Entity* entity : entities){
        entity->onTurn();
        Vec2i entityCoords = entity->getCoords();
        Vec2i playerCoords = game->getPlayer()->getCoords();
        int distance = entityCoords.distance(playerCoords);
        std::cout << "DISTANCE: " << distance << std::endl;
        if(entityCoords.distance(playerCoords) <= viewRange){
            std::cout << "YES" << std::endl;
            SDL_Rect dstRect{
                x: (entityCoords.x - playerCoords.x + (viewRange / 2) ) * spriteWidth,
                y: (entityCoords.y - playerCoords.y + (viewRange / 2) ) * spriteHeight,
                w: spriteWidth,
                h: spriteHeight
            };
            entity->draw(game->getRenderer(), &dstRect);
        }
    }
}

void MainState::view(){
    drawMap();
    drawPickupInfoIfItemExists();
    drawPlayer();
    updateEnvironment();
    drawStats();
}
