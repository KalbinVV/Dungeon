#include <iostream>
#include "InitException.h"
#include "RenderException.h"
#include "WorldException.h"
#include "Game.h"
#include "ErrorState.h"

int main(){
    try{
        Game::initModules();
        Game* game = Game::init();
        game->openTilesSpriteAtlas("assets/Tiles.png", 10, 10);
        game->openPeopleSpriteAtlas("assets/People.png", 10, 10);
        game->initPlayer(1, 0);
        game->genWorld(50, 50);
        game->run();
        Game::unInit();
        Game::unInitModules();
    }catch(const InitException& ex){
        std::cerr << "Error when init: " << ex.what() << std::endl;
    }catch(const RenderException& ex){
        std::string errorStr = "Error when render: ";
        errorStr += ex.what();
        Game::init()->getWindow()->close();
        Game::unInit();
        Game::unInitModules();
        new ErrorState(errorStr);
    }catch(const WorldException& ex){
        std::string errorStr = "World exception: ";
        errorStr += ex.what();
        Game::init()->getWindow()->close();
        Game::unInit();
        Game::unInitModules();
        new ErrorState(errorStr);
    }
    return 0;
}
