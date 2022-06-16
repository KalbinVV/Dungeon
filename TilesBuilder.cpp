#include "TilesBuilder.h"
#include "WorldException.h"

std::map<std::string, int> TilesBuilder::tilesID = {
    {"empty", 0},
    {"grass0",1},
    {"wall0", 2},
    {"skull0",3}
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
            tile = new Tile("Стена", "!", spriteAtlas, 14, 31);
            break;
        }
        case 3:{
            tile = new Tile("Череп", "!", spriteAtlas, 2, 2);
            break;
        }
    }
    return tile;
}
