#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include "Entity.h"
#include "InventoryHolder.h"
#include "Equipment.h"

//TODO: INVENTORY
class Human : public Entity, public InventoryHolder{
private:
    std::vector<Item*> inventory;
    Equipment equipment;
public:
    Human(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    void addItem(Item* item) override;
    void removeItem(Item* item) override;
    std::vector<Item*> getInventory() override;
    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    int getStrengthBonus();
    int getDexterityBonus();
    int getStaminaBonus();
    int getIntelligenceBonus();
    Stats getBonusStats();
};

#endif // HUMAN_H_INCLUDED
