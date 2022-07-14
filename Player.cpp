#include "Player.h"
#include "Game.h"

Player::Player(SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Human("Человек", "Это - вы", spriteAtlas, spriteX, spriteY, 100) {
    stats = {
        strength: 100,
        dexterity: 2,
        stamina: 3,
        intelligence: 4
    };
}

Stats Player::getStats(){
    return stats;
}

void Player::move(Vec2i coords){
    Game* game = Game::init();
    const int worldWidth = game->getWorldMap()->getWidth();
    const int worldHeight = game->getWorldMap()->getHeight();
    if(coords.x >= 0 && coords.x < worldWidth && coords.y >= 0 && coords.y < worldHeight){
        game->getTileAt(coords.y, coords.x)->onMove(this, coords);
    }
}

void Player::onDefence(int damage){
    setCurrentHp(getCurrentHp() - damage);
}
