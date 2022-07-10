#include "Equipment.h"

Equipment::Equipment(){
    weapon = nullptr;
    armor = nullptr;
}

void Equipment::setWeapon(Weapon* weapon){
    this->weapon = weapon;
}

Weapon* Equipment::getWeapon(){
    return weapon;
}

void Equipment::setArmor(Armor* armor){
    this->armor = armor;
}

Armor* Equipment::getArmor(){
    return armor;
}
