#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include "Item.h"
#include "EquipmentItem.h"

class Weapon : public Item, public EquipmentItem{
public:
    Weapon(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    virtual void onUse(Entity* entity) override;
};

#endif // WEAPON_H_INCLUDED
