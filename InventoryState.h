#ifndef INVENTORYSTATE_H_INCLUDED
#define INVENTORYSTATE_H_INCLUDED

#include "IState.h"
#include "Game.h"
#include <memory>
#include <iostream>

class InventoryState : public IState{
private:
    Game* game;
    Player* player;
    IState* backgroundState;
    int currentItemIndex;
    void updateMenu();
public:
    InventoryState(Game* game, Player* player, IState* backgroundState);
    void handleEvents() override;
    void render() override;
    void view() override;
    virtual ~InventoryState(){};
};

#endif // INVENTORYSTATE_H_INCLUDED
