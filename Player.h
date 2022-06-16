#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Human.h"

class Player : public Human{
public:
    Player(SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    void move(Vec2i coords);
};

#endif // PLAYER_H_INCLUDED
