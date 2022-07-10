#include "Armor.h"
#include "Human.h"

Armor::Armor(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Item(name, description, spriteAtlas, spriteX, spriteY){
    setStats(stats);
    setItemType(ItemType::Armor);
}

void Armor::onUse(Entity* entity){
    Human* human = (Human*)entity;
    if(human->getArmor() == this){
        human->setArmor(nullptr);
    }else{
        human->setArmor(this);
    }
}
