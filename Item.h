#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "ISprite.h"
#include "SpriteAtlas.h"
#include "ItemType.h"
#include "Entity.h"

class Item : public ISprite{
private:
    AssetSprite assetSprite;
    std::string name;
    std::string description;
    ItemType itemType;
public:
    Item(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    std::string getName();
    std::string getDescription();
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL);
    void setItemType(ItemType itemType);
    ItemType getType();
    virtual void onUse(Entity* entity) = 0;
};

#endif // ITEM_H_INCLUDED
