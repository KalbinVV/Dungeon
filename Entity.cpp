#include "Entity.h"

Entity::Entity(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY){
    assetSprite = spriteAtlas->getAssetSprite(spriteX, spriteY);
    this->name = name;
    this->description = description;
}

std::string Entity::getName(){
    return name;
}

std::string Entity::getDescription(){
    return description;
}

Vec2i Entity::getCoords(){
    return coords;
}

void Entity::setCoords(Vec2i coords){
    this->coords = coords;
}

void Entity::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    assetSprite.draw(renderer, dstRect);
}
