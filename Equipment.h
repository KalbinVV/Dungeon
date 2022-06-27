#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include "Weapon.h"

class Equipment{
private:
    Weapon* weapon;
public:
    Equipment();
    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
};

#endif // EQUIPMENT_H_INCLUDED
