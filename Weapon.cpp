#include "Weapon.h"
#include "Human.h"

Weapon::Weapon(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Item(name, description, spriteAtlas, spriteX, spriteY){
    setStats(stats);
    setItemType(ItemType::Weapon);
}

void Weapon::onUse(Entity* entity){
    Human* human = (Human*)entity;
    Equipment* equipment = human->getEquipment();
    if(equipment->getWeapon() == this){
        equipment->setWeapon(nullptr);
    }else{
        equipment->setWeapon(this);
    }
}
