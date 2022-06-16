#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Human.h"

class Player : public Human{
public:
    Player(SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
};

#endif // PLAYER_H_INCLUDED
