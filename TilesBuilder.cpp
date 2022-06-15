#include "TilesBuilder.h"
#include "WorldException.h"

std::map<std::string, int> TilesBuilder::tilesID = {
    {"grass0",0}
};

Tile* TilesBuilder::genTile(SpriteAtlas* spriteAtlas, std::string tileID){
    Tile* tile = nullptr;
    if(tilesID.count(tileID) == 0){
        std::string errorMessage = tileID + " don't exist!";
        throw WorldException(errorMessage);
    }
    switch(tilesID[tileID]){
        case 0:{
            tile = new Tile("Трава", "!", spriteAtlas, 2, 2);
            break;
        }
    }
    return tile;
}
