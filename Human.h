#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include "Entity.h"

//TODO: INVENTORY
class Human : public Entity{
public:
    Human(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
};

#endif // HUMAN_H_INCLUDED
