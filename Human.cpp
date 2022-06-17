#include "Human.h"

Human::Human(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
:Entity(name, description, spriteAtlas, spriteX, spriteY) {}

void Human::addItem(Item* item){
    inventory.push_back(item);
}

void Human::removeItem(Item* item){
    auto it = inventory.begin();
    for(Item* i : inventory){
        if(i == item) break;
        it++;
    }
    inventory.erase(it);
}

std::vector<Item*> Human::getInventory(){
    return inventory;
}
