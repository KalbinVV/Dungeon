#ifndef ASSETSPRITE_H_INCLUDED
#define ASSETSPRITE_H_INCLUDED

#include "ISprite.h"
#include <SDL2/SDL.h>

class AssetSprite : public ISprite{
private:
    SDL_Texture* texture;
    int x;
    int y;
    int tileWidth;
    int tileHeight;
public:
    AssetSprite();
    AssetSprite(SDL_Texture* texture, int x, int y, int tileWidth, int tileHeight);
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL) override;
};

#endif // ASSETSPRITE_H_INCLUDED
