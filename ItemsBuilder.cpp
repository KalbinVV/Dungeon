#include "ItemsBuilder.h"
#include "WorldException.h"
#include "Weapon.h"
#include "MessagesStorage.h"
#include "Armor.h"

std::map<std::string, int> ItemsBuilder::itemIDs = {
    {"testSword", 0},
    {"testArmor", 1}
};

Item* ItemsBuilder::genItem(SpriteAtlas* spriteAtlas, std::string itemID){
    if(itemIDs.count(itemID) == 0){
        std::string errorMessage = "Item " + itemID + " don't exist!";
        throw WorldException(errorMessage);
    }
    Item* item = nullptr;
    switch(itemIDs[itemID]){
        case 0:{
            item = new Weapon("Тестовый меч",
                MessagesStorage::getMessage("testSword"),
                {strength: 1,
                dexterity: 2,
                stamina: 3,
                intelligence: 4},
                spriteAtlas, 0, 0);
            break;
        }
        case 1:{
            item = new Armor("Тестовая броня",
                MessagesStorage::getMessage("testSword"),
                {strength: -1,
                dexterity:0,
                stamina: 3,
                intelligence: 4},
                spriteAtlas, 0, 0);
            break;
        }
        default:
            std::string errorMessage = "Item '" + itemID + "' exist, but don't implemented!";
            throw WorldException(errorMessage);
            break;
    }
    return item;
}
