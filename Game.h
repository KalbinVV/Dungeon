#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Window.h"
#include "Renderer.h"
#include "IState.h"

class Game{
private:
    Window window;
    Renderer renderer;
    IState* state;
public:
    static void initModules();
    static void unInitModules();
    Game(const char*, int width, int height);
    Window* getWindow();
    Renderer* getRenderer();
    void setState(IState* newState);
    void run();
};

#endif // GAME_H_INCLUDED
