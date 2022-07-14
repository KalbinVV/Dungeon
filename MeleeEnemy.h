#ifndef MELEEENEMY_H_INCLUDED
#define MELEEENEMY_H_INCLUDED

#include "Entity.h"
#include "Enemy.h"

class MeleeEnemy : public Entity, public Enemy{
private:
    int minDamage;
    int maxDamage;
public:
    MeleeEnemy(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY,
        int maxHp, int minDamage, int maxDamage);
    virtual void onTurn() override;
    virtual void onAttack(Entity* entity) override;
    virtual void onDefence(int damage) override;
};

#endif // MELEEENEMY_H_INCLUDED
