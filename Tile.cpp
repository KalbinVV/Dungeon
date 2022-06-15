#include "Tile.h"

Tile::Tile(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY){
    assetSprite = spriteAtlas->getAssetSprite(spriteX, spriteY);
    this->description = description;
    this->name = name;
}

Tile::Tile(Tile* tile){
    this->assetSprite = tile->getAssetSprite();
    this->description = tile->getDescription();
    this->name = tile->getName();
}

AssetSprite Tile::getAssetSprite(){
    return assetSprite;
}

std::string Tile::getDescription(){
    return description;
}

std::string Tile::getName(){
    return name;
}

void Tile::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    assetSprite.draw(renderer, dstRect);
}
