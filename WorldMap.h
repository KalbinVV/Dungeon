#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED

#include "Tile.h"
#include <list>
#include "Entity.h"

typedef Tile* TilePtr;

class WorldMap{
private:
    TilePtr** tiles;
    int width;
    int height;
    std::list<Entity*> entities;
public:
    WorldMap(int width, int height);
    TilePtr get(int y, int x);
    void set(int y, int x, Tile* tile);
    int getWidth();
    int getHeight();
    const std::list<Entity*>& getEntities();
    void spawnEntity(Entity* entity);
    void removeEntity(Entity* entity);
    ~WorldMap();
};

#endif // WORLDMAP_H_INCLUDED
