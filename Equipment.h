#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include "Weapon.h"
#include "Armor.h"

class Equipment{
private:
    Weapon* weapon;
    Armor* armor;
public:
    Equipment();
    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    void setArmor(Armor* armor);
    Armor* getArmor();
};

#endif // EQUIPMENT_H_INCLUDED
