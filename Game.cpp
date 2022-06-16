#include "Game.h"
#include "InitException.h"
#include "MainState.h"

Game* Game::uniquePtr = nullptr;

void Game::initModules(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) throw InitException(SDL_GetError());
    if(TTF_Init() == -1) throw InitException(TTF_GetError());
}

void Game::unInitModules(){
    SDL_Quit();
}

Game* Game::init(){
    if(!uniquePtr){
        uniquePtr = new Game();
    }
    return uniquePtr;
}

void Game::unInit(){
    if(uniquePtr) delete uniquePtr;
}

Game::Game(){
    std::string windowTitle = "Dungeon";
    int windowWidth = 800;
    int windowHeight = 600;
    state = nullptr;
    worldMap = nullptr;
    player = nullptr;
    viewRange = 11;
    window.open(windowTitle.c_str(), windowWidth, windowHeight);
    renderer.init(&window);
}

Window* Game::getWindow(){
    return &window;
}

Renderer* Game::getRenderer(){
    return &renderer;
}

void Game::openFont(std::string fontSrc, int characterSize){
    font.open(fontSrc, characterSize);
}

Font* Game::getFont(){
    return &font;
}

void Game::setState(IState* newState){
    state.reset(newState);
}

void Game::openTilesSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight){
    tilesSpriteAtlas.open(imageSrc, &renderer, tileWidth, tileHeight);
}

SpriteAtlas* Game::getTilesSpriteAtlas(){
    return &tilesSpriteAtlas;
}

void Game::openPeopleSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight){
    peopleSpriteAtlas.open(imageSrc, &renderer, tileWidth, tileHeight);
}

SpriteAtlas* Game::getPeopleSpriteAtlas(){
    return &peopleSpriteAtlas;
}

void Game::genWorld(int width, int height){
    worldMap = std::make_unique<WorldMap>(width, height);
}

void Game::setViewRange(int viewRange){
    this->viewRange = viewRange;
}

int Game::getViewRange(){
    return viewRange;
}

void Game::initPlayer(int spriteX, int spriteY){
    player = std::make_unique<Player>(getPeopleSpriteAtlas(), spriteX, spriteY);
}

Player* Game::getPlayer(){
    return player.get();
}

Tile* Game::getTileAt(int y, int x){
    return worldMap->get(y,x);
}

int Game::getWorldWidth(){
    return worldMap->getWidth();
}

int Game::getWorldHeight(){
    return worldMap->getHeight();
}

void Game::run(){
    setState(new MainState(this));
    while(window.isOpen()){
        state->handleEvents();
        state->render();
    }
}
