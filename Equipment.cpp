#include "Equipment.h"

Equipment::Equipment(){
    weapon = nullptr;
    armor = nullptr;
    accessory = nullptr;
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

void Equipment::setAccessory(Accessory* accessory){
    this->accessory = accessory;
}

Accessory* Equipment::getAccessory(){
    return accessory;
}
