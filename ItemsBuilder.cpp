#include "ItemsBuilder.h"
#include "WorldException.h"

std::map<std::string, int> ItemsBuilder::itemIDs = {
    {"testSword", 0}
};

Item* ItemsBuilder::genItem(SpriteAtlas* spriteAtlas, std::string itemID){
    if(itemIDs.count(itemID) == 0){
        std::string errorMessage = "Item " + itemID + " don't exist!";
        throw WorldException(errorMessage);
    }
    Item* item = nullptr;
    switch(itemIDs[itemID]){
        case 0:{
            item = new Item("Тестовый меч", "!", spriteAtlas, 0, 0);
            break;
        }
        default:
            std::string errorMessage = "Item '" + itemID + "' exist, but don't implemented!";
            throw WorldException(errorMessage);
            break;
    }
    return item;
}
