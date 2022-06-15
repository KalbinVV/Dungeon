#include "SpriteAtlas.h"
#include <SDL2/SDL_image.h>
#include "RenderException.h"

SpriteAtlas::SpriteAtlas(){
    texture = nullptr;
}

void SpriteAtlas::open(std::string imageSrc, Renderer* renderer, int tileWidth, int tileHeight){
    SDL_Surface* surface = IMG_Load(imageSrc.c_str());
    if(surface == NULL){
        throw RenderException(IMG_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer->getSdlRenderer(), surface);
    SDL_FreeSurface(surface);
    if(texture == NULL){
        throw RenderException(SDL_GetError());
    }
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
}

int SpriteAtlas::getTileWidth(){
    return tileWidth;
}

int SpriteAtlas::getTileHeight(){
    return tileHeight;
}

void SpriteAtlas::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    SDL_RenderCopy(renderer->getSdlRenderer(), texture, srcRect, dstRect);
}

void SpriteAtlas::drawAt(Renderer* renderer, int x, int y, SDL_Rect* dstRect){
    SDL_Rect srcRect{
        x: x * tileWidth,
        y: y * tileHeight,
        w: tileWidth,
        h: tileHeight
    };
    SDL_RenderCopy(renderer->getSdlRenderer(), texture, &srcRect, dstRect);
}

AssetSprite SpriteAtlas::getAssetSprite(int x, int y){
    return AssetSprite(texture, x, y, tileWidth, tileHeight);
}

SpriteAtlas::~SpriteAtlas(){
    if(texture) SDL_DestroyTexture(texture);
}
