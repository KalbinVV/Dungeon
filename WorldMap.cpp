#include "WorldMap.h"
#include "TilesBuilder.h"

WorldMap::WorldMap(SpriteAtlas* spriteAtlas, int width, int height){
    this->width = width;
    this->height = height;
    tiles = new TilePtr*[height];
    for(int i = 0; i < height; i++){
        tiles[i] = new TilePtr[width];
        for(int j = 0; j < width; j++){
            tiles[i][j] = TilesBuilder::genTile(spriteAtlas, "grass0");
        }
    }
}

TilePtr WorldMap::get(int y, int x){
    return tiles[y][x];
}

WorldMap::~WorldMap(){
    if(tiles != nullptr){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                delete tiles[i][j];
            }
        }
        for(int i = 0; i < height; i++){
            delete[] tiles[i];
        }
        delete[] tiles;
    }
}
