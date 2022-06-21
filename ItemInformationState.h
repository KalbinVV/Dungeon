#ifndef ITEMINFORMATIONSTATE_H_INCLUDED
#define ITEMINFORMATIONSTATE_H_INCLUDED

#include "IState.h"
#include "Item.h"
#include "Game.h"

class ItemInformationState : public IState{
private:
    Item* item;
    Game* game;
    IState* backgroundState;
public:
    ItemInformationState(Item* item, Game* game, IState* backgroundState);
    void render() override;
    void handleEvents() override;
    void view() override;
};

#endif // ITEMINFORMATIONSTATE_H_INCLUDED
