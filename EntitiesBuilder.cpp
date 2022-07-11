#include "EntitiesBuilder.h"
#include "MeleeEnemy.h"
#include "WorldException.h"

std::map<std::string, int> EntitiesBuilder::entitiesIDs = {
    {"testEnemy", 0}
};

Entity* EntitiesBuilder::genEntity(SpriteAtlas* spriteAtlas, std::string entityID){
    if(entitiesIDs.count(entityID) == 0){
        std::string errorMessage = "Entity " + entityID + " don't exist!";
        throw WorldException(errorMessage);
    }
    Entity* entity = nullptr;
    switch(entitiesIDs[entityID]){
        case 0:{
            entity = new MeleeEnemy("Тестовый враг", "1", spriteAtlas, 0, 1, 40, 5, 15);
            break;
        }
        default:
            std::string errorMessage = "Entity '" + entityID + "' exist, but don't implemented!";
            throw WorldException(errorMessage);
            break;
    }
    return entity;
}
