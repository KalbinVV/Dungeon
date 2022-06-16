#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "Tile.h"

class Wall : public Tile{
public:
    Wall(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    void onMove(Player* player, Vec2i coords) override {};
};

#endif // WALL_H_INCLUDED
