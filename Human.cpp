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

Equipment* Human::getEquipment(){
    return &equipment;
}

int Human::getStrengthBonus(){
    int strengthBonus = 0;
    if(equipment.getWeapon() != nullptr){
        strengthBonus += equipment.getWeapon()->getStats().strength;
    }
    if(equipment.getArmor() != nullptr){
        strengthBonus += equipment.getArmor()->getStats().strength;
    }
    if(equipment.getAccessory() != nullptr){
        strengthBonus += equipment.getAccessory()->getStats().strength;
    }
    return strengthBonus;
}

int Human::getDexterityBonus(){
    int dexterityBonus = 0;
    if(equipment.getWeapon() != nullptr){
        dexterityBonus += equipment.getWeapon()->getStats().dexterity;
    }
    if(equipment.getArmor() != nullptr){
        dexterityBonus += equipment.getArmor()->getStats().dexterity;
    }
    if(equipment.getAccessory() != nullptr){
        dexterityBonus += equipment.getAccessory()->getStats().dexterity;
    }
    return dexterityBonus;
}

int Human::getStaminaBonus(){
    int staminaBonus = 0;
    if(equipment.getWeapon() != nullptr){
        staminaBonus += equipment.getWeapon()->getStats().stamina;
    }
    if(equipment.getArmor() != nullptr){
        staminaBonus += equipment.getArmor()->getStats().stamina;
    }
    if(equipment.getAccessory() != nullptr){
        staminaBonus += equipment.getAccessory()->getStats().stamina;
    }
    return staminaBonus;
}

int Human::getIntelligenceBonus(){
    int intelligenceBonus = 0;
    if(equipment.getWeapon() != nullptr){
        intelligenceBonus += equipment.getWeapon()->getStats().intelligence;
    }
    if(equipment.getArmor() != nullptr){
        intelligenceBonus += equipment.getArmor()->getStats().intelligence;
    }
    if(equipment.getAccessory() != nullptr){
        intelligenceBonus += equipment.getAccessory()->getStats().intelligence;
    }
    return intelligenceBonus;
}

Stats Human::getBonusStats(){
    return {getStrengthBonus(), getDexterityBonus(), getStaminaBonus(), getIntelligenceBonus()};
}
