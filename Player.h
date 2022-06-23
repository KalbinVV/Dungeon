#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Human.h"
#include "Stats.h"

class Player : public Human{
private:
    Stats stats;
public:
    Player(SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    Stats getStats();
    void move(Vec2i coords);
};

#endif // PLAYER_H_INCLUDED
