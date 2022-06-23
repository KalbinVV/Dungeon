#include "Item.h"

Item::Item(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY){
    assetSprite = spriteAtlas->getAssetSprite(spriteX, spriteY);
    this->name = name;
    this->description = description;
    setItemType(ItemType::Undefined);
}

std::string Item::getName(){
    return name;
}

std::string Item::getDescription(){
    return description;
}

void Item::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    assetSprite.draw(renderer, dstRect);
}

void Item::setItemType(ItemType itemType){
    this->itemType = itemType;
}

ItemType Item::getItemType(){
    return itemType;
}
