#ifndef SPRITEATLAS_H_INCLUDED
#define SPRITEATLAS_H_INCLUDED

#include <SDL2/SDL.h>
#include <string>
#include "ISprite.h"
#include "Renderer.h"
#include "AssetSprite.h"

class SpriteAtlas : public ISprite{
private:
    SDL_Texture* texture;
    int tileWidth;
    int tileHeight;
public:
    SpriteAtlas();
    void open(std::string imageSrc, Renderer* renderer, int tileWidth, int tileHeight);
    int getTileWidth();
    int getTileHeight();
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL);
    void drawAt(Renderer* renderer, int x, int y, SDL_Rect* dstRect);
    AssetSprite getAssetSprite(int x, int y);
    ~SpriteAtlas();
};

#endif // SPRITEATLAS_H_INCLUDED
