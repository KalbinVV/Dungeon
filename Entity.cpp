#include "Entity.h"

Entity::Entity(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY, int maxHp){
    assetSprite = spriteAtlas->getAssetSprite(spriteX, spriteY);
    this->name = name;
    this->description = description;
    this->maxHp = maxHp;
    this->currentHp = maxHp;
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

int Entity::getCurrentHp(){
    return currentHp;
}

int Entity::getMaxHp(){
    return maxHp;
}

void Entity::setCurrentHp(int currentHp){
    this->currentHp = currentHp;
}

void Entity::setMaxHp(int maxHp){
    this->maxHp = maxHp;
}
