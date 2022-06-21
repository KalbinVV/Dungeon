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
            item = new Item("Тестовый меч", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa quiofficia deserunt mollit anim id est laborum.", spriteAtlas, 0, 0);
            break;
        }
        default:
            std::string errorMessage = "Item '" + itemID + "' exist, but don't implemented!";
            throw WorldException(errorMessage);
            break;
    }
    return item;
}
