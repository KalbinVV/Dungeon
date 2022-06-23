#include "Weapon.h"

Weapon::Weapon(std::string name, std::string description, Stats stats, SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Item(name, description, spriteAtlas, spriteX, spriteY){
    this->stats = stats;
    setItemType(ItemType::Weapon);
}

Stats Weapon::getStats(){
    return stats;
}
