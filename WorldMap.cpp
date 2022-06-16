#include "WorldMap.h"
#include "TilesBuilder.h"
#include <vector>
#include "Game.h"

WorldMap::WorldMap(int width, int height){
    Game* game = Game::init();
    SpriteAtlas* spriteAtlas = game->getTilesSpriteAtlas();
    this->width = width;
    this->height = height;
    tiles = new TilePtr*[height];
    for(int i = 0; i < height; i++){
        tiles[i] = new TilePtr[width];
        for(int j = 0; j < width; j++){
            tiles[i][j] = TilesBuilder::genTile(spriteAtlas, "empty");
        }
    }
    std::vector<SDL_Rect> rects;
    for(int i = 0; i < 5; i++){
        SDL_Rect newRect{
            x: rand() % width,
            y: rand() % height,
            w: rand() % 20 + width / 5,
            h: rand() % 20 + height / 5
        };
        if(newRect.x + newRect.w >= width || newRect.y + newRect.h >= height){
            i--;
            continue;
        }
        bool isIntersect = false;
        for(SDL_Rect rect : rects){
            if(SDL_HasIntersection(&rect, &newRect) == SDL_TRUE){
                isIntersect = true;
                break;
            }
        }
        if(isIntersect){
            i--;
            continue;
        }
        rects.push_back(newRect);
    }
    for(SDL_Rect rect : rects){
        for(int i = rect.y; i <= rect.y + rect.h; i++){
            for(int j = rect.x; j <= rect.x + rect.w; j++){
                if(i == rect.y || i == rect.y + rect.h || j == rect.x || j == rect.x + rect.w){
                    set(i, j, TilesBuilder::genTile(spriteAtlas, "wall0"));
                }else{
                    set(i, j, TilesBuilder::genTile(spriteAtlas, "grass0"));
                }
            }
        }
    }
    for(SDL_Rect rect : rects){
        int y = rect.y + rect.h;
        int x = (rect.x + rect.w) / 2;
        set(y, x, TilesBuilder::genTile(spriteAtlas, "empty"));
    }
    SDL_Rect randRect = rects[rand() % rects.size()];
    Vec2i coords;
    coords.x = randRect.x + 1;
    coords.y = randRect.y + 1;
    game->getPlayer()->setCoords(&coords);
}

TilePtr WorldMap::get(int y, int x){
    return tiles[y][x];
}

void WorldMap::set(int y, int x, Tile* tile){
    if(tiles[y][x]) delete tiles[y][x];
    tiles[y][x] = tile;
}

int WorldMap::getWidth(){
    return width;
}

int WorldMap::getHeight(){
    return height;
}

WorldMap::~WorldMap(){
    if(tiles != nullptr){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                delete tiles[i][j];
            }
        }
        for(int i = 0; i < height; i++){
            delete[] tiles[i];
        }
        delete[] tiles;
    }
}
