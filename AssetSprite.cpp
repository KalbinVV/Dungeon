#include "AssetSprite.h"

AssetSprite::AssetSprite(){
    this->texture = nullptr;
}

AssetSprite::AssetSprite(SDL_Texture* texture, int x, int y, int tileWidth, int tileHeight){
    this->texture = texture;
    this->x = x;
    this->y = y;
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
}

void AssetSprite::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    SDL_Rect spriteSrcRect{
        x: x * tileWidth,
        y: y * tileHeight,
        w: tileWidth,
        h: tileHeight
    };
    SDL_RenderCopy(renderer->getSdlRenderer(), texture, &spriteSrcRect, dstRect);
}
