#ifndef TILESBUILDER_H_INCLUDED
#define TILESBUILDER_H_INCLUDED

#include <map>
#include <string>
#include "Tile.h"
#include "Renderer.h"
#include "SpriteAtlas.h"

class TilesBuilder{
private:
    static std::map<std::string, int> tilesIDs;
public:
    static Tile* genTile(SpriteAtlas* spriteAtlas, std::string tileID);
};

#endif // TILESBUILDER_H_INCLUDED
