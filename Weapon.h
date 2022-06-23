#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include "Item.h"
#include "Stats.h"

class Weapon : public Item{
private:
    Stats stats;
public:
    Weapon(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    Stats getStats();
};

#endif // WEAPON_H_INCLUDED
