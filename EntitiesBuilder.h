#ifndef ENTITIESBUILDER_H_INCLUDED
#define ENTITIESBUILDER_H_INCLUDED

#include <map>
#include <string>
#include "Entity.h"

class EntitiesBuilder{
private:
    static std::map<std::string, int> entitiesIDs;
public:
    static Entity* genEntity(SpriteAtlas* spriteAtlas, std::string entityID);
};

#endif // ENTITIESBUILDER_H_INCLUDED
