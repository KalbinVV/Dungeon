#ifndef MAINSTATE_H_INCLUDED
#define MAINSTATE_H_INCLUDED

#include "IState.h"
#include "Game.h"

class MainState : public IState{
private:
    Game* game;
public:
    MainState(Game* game);
    void handleEvents() override;
    void render() override;
};

#endif // MAINSTATE_H_INCLUDED
