#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED

#include "Tile.h"

typedef Tile* TilePtr;

class WorldMap{
private:
    TilePtr** tiles;
    int width;
    int height;
public:
    WorldMap(int width, int height);
    TilePtr get(int y, int x);
    void set(int y, int x, Tile* tile);
    int getWidth();
    int getHeight();
    ~WorldMap();
};

#endif // WORLDMAP_H_INCLUDED
