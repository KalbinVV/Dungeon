#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include "Entity.h"
#include "InventoryHolder.h"

//TODO: INVENTORY
class Human : public Entity, public InventoryHolder{
private:
    std::vector<Item*> inventory;
public:
    Human(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    void addItem(Item* item) override;
    void removeItem(Item* item) override;
    std::vector<Item*> getInventory() override;
};

#endif // HUMAN_H_INCLUDED
