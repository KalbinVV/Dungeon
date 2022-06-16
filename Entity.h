#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "AssetSprite.h"
#include "SpriteAtlas.h"
#include "ISprite.h"
#include "Vec2i.h"
#include <string>

class Entity : public ISprite{
private:
    AssetSprite assetSprite;
    std::string name;
    std::string description;
    Vec2i coords;
public:
    Entity(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    std::string getName();
    std::string getDescription();
    Vec2i getCoords();
    void setCoords(Vec2i coords);
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL) override;
};

#endif // ENTITY_H_INCLUDED
