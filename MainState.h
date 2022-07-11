#ifndef MAINSTATE_H_INCLUDED
#define MAINSTATE_H_INCLUDED

#include "IState.h"
#include "Game.h"
#include <iostream>

class MainState : public IState{
private:
    Game* game;
    void updateScreen();
    void drawMap();
    void drawPickupInfoIfItemExists();
    void drawPlayer();
    void drawStats();
    void updateEnvironment();
public:
    MainState(Game* game);
    void handleEvents() override;
    void render() override;
    void view() override;
    virtual ~MainState(){};
};

#endif // MAINSTATE_H_INCLUDED
