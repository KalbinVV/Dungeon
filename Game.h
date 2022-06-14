#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Window.h"
#include "Renderer.h"
#include "SpriteAtlas.h"
#include "IState.h"
#include <string>

class Game{
private:
    Window window;
    Renderer renderer;
    SpriteAtlas spriteAtlas;
    IState* state;
public:
    static void initModules();
    static void unInitModules();
    Game(const char*, int width, int height);
    Window* getWindow();
    Renderer* getRenderer();
    void setState(IState* newState);
    void openSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    SpriteAtlas* getSpriteAtlas();
    void run();
};

#endif // GAME_H_INCLUDED
