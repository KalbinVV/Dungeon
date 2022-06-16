#ifndef ITEMSBUILDER_H_INCLUDED
#define ITEMSBUILDER_H_INCLUDED

#include "Item.h"
#include "SpriteAtlas.h"
#include <map>
#include <string>

class ItemsBuilder{
private:
    static std::map<std::string, int> itemIDs;
public:
    static Item* genItem(SpriteAtlas* spriteAtlas, std::string itemID);
};

#endif // ITEMSBUILDER_H_INCLUDED
