#include <iostream>
#include "InitException.h"
#include "RenderException.h"
#include "WorldException.h"
#include "Game.h"

int main(){
    try{
        Game::initModules();
        Game game("Dungeon", 800, 600);
        game.openTilesSpriteAtlas("assets/tiles.png", 10, 10);
        game.genWorld(20, 20);
        game.run();
        Game::unInitModules();
    }catch(const InitException& ex){
        std::cerr << "Error when init: " << ex.what() << std::endl;
    }catch(const RenderException& ex){
        std::cerr << "Error when render: " << ex.what() << std::endl;
    }catch(const WorldException& ex){
        std::cerr << "World exception: " << ex.what() << std::endl;
    }
    return 0;
}
