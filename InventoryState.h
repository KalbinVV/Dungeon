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
public:
    InventoryState(Game* game, Player* player, IState* backgroundState);
    void handleEvents() override;
    void render() override;
    void view() override;
    virtual ~InventoryState(){
        std::cout << "Inventory state cleared!" << std::endl;
    }
};

#endif // INVENTORYSTATE_H_INCLUDED
