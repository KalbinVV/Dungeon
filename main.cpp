#include <iostream>
#include "InitException.h"
#include "Game.h"

int main(){
    try{
        Game::initModules();
        Game game("Dungeon", 800, 600);
        game.run();
        Game::unInitModules();
    }catch(const InitException& ex){
        std::cerr << "Error when init: " << ex.what() << std::endl;
    }
    return 0;
}
