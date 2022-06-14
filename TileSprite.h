#ifndef TILESPRITE_H_INCLUDED
#define TILESPRITE_H_INCLUDED

#include "ISprite.h"
#include <SDL2/SDL.h>

class TileSprite : public ISprite{
private:
    SDL_Texture* texture;
    int x;
    int y;
    int tileWidth;
    int tileHeight;
public:
    TileSprite();
    TileSprite(SDL_Texture* texture, int x, int y, int tileWidth, int tileHeight);
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL) override;
};

#endif // TILESPRITE_H_INCLUDED
