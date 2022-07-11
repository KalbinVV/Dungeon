#include <iostream>
#include "InitException.h"
#include "RenderException.h"
#include "WorldException.h"
#include "Game.h"
#include "ErrorState.h"
#include "MessagesStorage.h"
#include "MessageException.h"

void initErrorState(std::string errorStr){
    Game::init()->getWindow()->close();
    Game::unInit();
    Game::unInitModules();
    ErrorState* errorState = new ErrorState(errorStr);
    delete errorState;
}

int main(){
    try{
        MessagesStorage::loadMessages("assets/strings.txt");
        Game::initModules();
        Game* game = Game::init();
        game->openTilesSpriteAtlas("assets/Tiles.png", 10, 10);
        game->openPeopleSpriteAtlas("assets/People.png", 10, 10);
        game->openWeaponsSpriteAtlas("assets/Weapons.png", 10, 10);
        game->openArmorsSpriteAtlas("assets/Armors.png", 10, 10);
        game->openJewelrySpriteAtlas("assets/Jewelry.png", 10, 10);
        game->openFont("assets/font.ttf", 64);
        game->initPlayer(1, 0);
        game->genWorld(50, 50);
        game->setViewRange(21);
        game->run();
        Game::unInit();
        Game::unInitModules();
    }catch(const InitException& ex){
        std::cerr << "Error when init: " << ex.what() << std::endl;
    }catch(const RenderException& ex){
        std::string errorStr = "Error when render: ";
        errorStr += ex.what();
        initErrorState(errorStr);
    }catch(const WorldException& ex){
        std::string errorStr = "World exception: ";
        errorStr += ex.what();
        initErrorState(errorStr);
    }catch(const MessageException& ex){
        std::string errorStr = "Message exception: ";
        errorStr += ex.what();
        initErrorState(errorStr);
    }catch(std::exception& ex){
        std::string errorStr = "Exception: ";
        errorStr += ex.what();
        initErrorState(errorStr);
    }
    return 0;
}
