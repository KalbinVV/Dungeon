#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Entity.h"

class Enemy{
public:
    virtual void onAttack(Entity* entity) = 0;
};

#endif // ENEMY_H_INCLUDED
