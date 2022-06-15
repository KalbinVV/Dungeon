#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "ISprite.h"
#include "SpriteAtlas.h"
#include <string>

class Tile : public ISprite{
private:
    AssetSprite assetSprite;
    std::string description;
    std::string name;
public:
    Tile(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    Tile(Tile* tile);
    virtual std::string getDescription();
    virtual std::string getName();
    virtual AssetSprite getAssetSprite();
    virtual void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL);
    virtual void onMove() {};
    virtual void onInteract() {};
    virtual ~Tile() {};
};

#endif // TILE_H_INCLUDED
