#include "MeleeEnemy.h"
#include "Game.h"
#include <random>

MeleeEnemy::MeleeEnemy(std::string name, std::string description, SpriteAtlas* spriteAtlas, int spriteX, int spriteY,
    int maxHp, int minDamage, int maxDamage) : Entity(name, description, spriteAtlas, spriteX, spriteY, maxHp){
    this->minDamage = minDamage;
    this->maxDamage = maxDamage;
}

void MeleeEnemy::onTurn(){
    Vec2i enemyCoords = getCoords();
    Vec2i playerCoords = Game::init()->getPlayer()->getCoords();
    int distance = enemyCoords.distance(playerCoords);
    if(distance > 1){
        if(enemyCoords.x < playerCoords.x){
            enemyCoords.x++;
        }else if(enemyCoords.x > playerCoords.x){
            enemyCoords.x--;
        }
        if(enemyCoords.y < playerCoords.y){
            enemyCoords.y++;
        }else if(enemyCoords.y > playerCoords.y){
            enemyCoords.y--;
        }
        Game::init()->getTileAt(enemyCoords.y, enemyCoords.x)->onMove(this, enemyCoords);
    }
}

void MeleeEnemy::onAttack(Entity* entity){
    int damage = minDamage + (rand() % (maxDamage - minDamage + 1));
    entity->setCurrentHp(entity->getCurrentHp() - damage);
}
