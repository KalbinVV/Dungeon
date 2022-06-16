#include "Player.h"
#include "Game.h"

Player::Player(SpriteAtlas* spriteAtlas, int spriteX, int spriteY)
: Human("Человек", "Это - вы", spriteAtlas, spriteX, spriteY) {}

void Player::move(Vec2i coords){
    Game* game = Game::init();
    int worldWidth = game->getWorldWidth();
    int worldHeight = game->getWorldHeight();
    if(coords.x >= 0 && coords.x < worldWidth && coords.y >= 0 && coords.y < worldHeight){
        game->getTileAt(coords.y, coords.x)->onMove(this, coords);
    }
}
