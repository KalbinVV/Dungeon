#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include "Weapon.h"
#include "Armor.h"
#include "Accessory.h"

class Equipment{
private:
    Weapon* weapon;
    Armor* armor;
    Accessory* accessory;
public:
    Equipment();
    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    void setArmor(Armor* armor);
    Armor* getArmor();
    void setAccessory(Accessory* accessory);
    Accessory* getAccessory();
};

#endif // EQUIPMENT_H_INCLUDED
