#include "Tile.h"

Tile::Tile(SpriteAtlas* spriteAtlas, int spriteX, int spriteY,
std::string description, std::string name){
    tileSprite = spriteAtlas->getTileSprite(spriteX, spriteY);
    this->description = description;
    this->name = name;
}

std::string Tile::getDescription(){
    return description;
}

std::string Tile::getName(){
    return name;
}

void Tile::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    tileSprite.draw(renderer, dstRect);
}
