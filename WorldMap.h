#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED

#include "Tile.h"
#include "SpriteAtlas.h"

typedef Tile* TilePtr;

class WorldMap{
private:
    TilePtr** tiles;
    int width;
    int height;
public:
    WorldMap(SpriteAtlas* spriteAtlas, int width, int height);
    TilePtr get(int y, int x);
    ~WorldMap();
};

#endif // WORLDMAP_H_INCLUDED
