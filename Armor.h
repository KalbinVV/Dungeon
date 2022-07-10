#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include "Item.h"
#include "Stats.h"
#include "EquipmentItem.h"

class Armor : public Item, public EquipmentItem{
public:
    Armor(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    virtual void onUse(Entity* entity) override;
};

#endif // ARMOR_H_INCLUDED
