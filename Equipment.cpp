#include "Equipment.h"

Equipment::Equipment(){
    weapon = nullptr;
}

void Equipment::setWeapon(Weapon* weapon){
    this->weapon = weapon;
}

Weapon* Equipment::getWeapon(){
    return weapon;
}
