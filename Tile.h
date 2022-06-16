#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "ISprite.h"
#include "SpriteAtlas.h"
#include "Player.h"
#include "Item.h"
#include <string>
#include <vector>

class Tile : public ISprite{
private:
    AssetSprite assetSprite;
    std::string description;
    std::string name;
    std::vector<Item*> items;
public:
    Tile(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY);
    Tile(Tile* tile);
    virtual std::string getDescription();
    virtual std::string getName();
    virtual AssetSprite getAssetSprite();
    virtual void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL);
    virtual std::vector<Item*> getItems();
    virtual void addItem(Item* item);
    virtual void removeItem(Item* item);
    virtual void onMove(Player* player, Vec2i coords);
    virtual void onInteract() {};
    virtual ~Tile() {};
};

#endif // TILE_H_INCLUDED
