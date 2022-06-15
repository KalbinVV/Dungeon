#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Window.h"
#include "Renderer.h"
#include "SpriteAtlas.h"
#include "IState.h"
#include "WorldMap.h"
#include <string>
#include <memory>

class Game{
private:
    Window window;
    Renderer renderer;
    SpriteAtlas spriteAtlas;
    std::unique_ptr<WorldMap> worldMap;
    IState* state;
public:
    static void initModules();
    static void unInitModules();
    Game(const char*, int width, int height);
    Window* getWindow();
    Renderer* getRenderer();
    void setState(IState* newState);
    void openTilesSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    void genWorld(int width, int height);
    Tile* getTileAt(int y, int x);
    SpriteAtlas* getTilesSpriteAtlas();
    void run();
};

#endif // GAME_H_INCLUDED
