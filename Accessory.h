#ifndef ACCESSORY_H_INCLUDED
#define ACCESSORY_H_INCLUDED

#include "Item.h"
#include "EquipmentItem.h"

class Accessory : public Item, public EquipmentItem{
public:
    Accessory(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    virtual void onUse(Entity* entity) override;
};

#endif // ACCESSORY_H_INCLUDED
