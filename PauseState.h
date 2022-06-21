#ifndef PAUSESTATE_H_INCLUDED
#define PAUSESTATE_H_INCLUDED

#include "IState.h"
#include "Game.h"

class PauseState : public IState{
private:
    IState* backgroundState;
    Game* game;
public:
    PauseState(Game* game, IState* backgroundState);
    void handleEvents() override;
    void render() override;
    void view() override;
};

#endif // PAUSESTATE_H_INCLUDED
