#include "TilesBuilder.h"
#include "WorldException.h"
#include "Wall.h"

std::map<std::string, int> TilesBuilder::tilesID = {
    {"empty", 0},
    {"grass0",1},
    {"wall0", 2},
    {"floor0",3}
};

Tile* TilesBuilder::genTile(SpriteAtlas* spriteAtlas, std::string tileID){
    Tile* tile = nullptr;
    if(tilesID.count(tileID) == 0){
        std::string errorMessage = tileID + " don't exist!";
        throw WorldException(errorMessage);
    }
    switch(tilesID[tileID]){
        case 0:{
            tile = new Tile("Пустота", "!", spriteAtlas, 0, 0);
            break;
        }
        case 1:{
            tile = new Tile("Трава", "!", spriteAtlas, 1, 1);
            break;
        }
        case 2:{
            tile = new Wall("Стена", "!", spriteAtlas, 14, 31);
            break;
        }
        case 3:{
            tile = new Tile("Пол", "!", spriteAtlas, 14, 30);
            break;
        }
    }
    return tile;
}
