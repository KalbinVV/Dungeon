#include "Armor.h"
#include "Human.h"

Armor::Armor(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Item(name, description, spriteAtlas, spriteX, spriteY){
    setStats(stats);
    setItemType(ItemType::Armor);
}

void Armor::onUse(Entity* entity){
    Human* human = (Human*)entity;
    Equipment* equipment = human->getEquipment();
    if(equipment->getArmor() == this){
        equipment->setArmor(nullptr);
    }else{
        equipment->setArmor(this);
    }
}
