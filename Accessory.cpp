#include "Accessory.h"
#include "Human.h"

Accessory::Accessory(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Item(name, description, spriteAtlas, spriteX, spriteY){
    setStats(stats);
    setItemType(ItemType::Accessory);
}

void Accessory::onUse(Entity* entity){
    Human* human = (Human*)entity;
    Equipment* equipment = human->getEquipment();
    if(equipment->getAccessory() == this){
        equipment->setAccessory(nullptr);
    }else{
        equipment->setAccessory(this);
    }
}

