#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "ISprite.h"
#include "SpriteAtlas.h"
#include <string>

class Tile : public ISprite{
private:
    TileSprite tileSprite;
    std::string description;
    std::string name;
public:
    Tile(SpriteAtlas* spriteAtlas, int spriteX, int spriteY, std::string description, std::string name);
    virtual std::string getDescription();
    virtual std::string getName();
    virtual void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL);
    virtual void onMove() {};
    virtual void onInteract() {};
};

#endif // TILE_H_INCLUDED
