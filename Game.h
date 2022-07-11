#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Window.h"
#include "Renderer.h"
#include "SpriteAtlas.h"
#include "IState.h"
#include "WorldMap.h"
#include "Player.h"
#include "Font.h"
#include "ConsoleLogger.h"
#include <string>
#include <memory>

class Game{
private:
    Window window;
    Renderer renderer;
    Font font;
    SpriteAtlas tilesSpriteAtlas;
    SpriteAtlas peopleSpriteAtlas;
    SpriteAtlas weaponsSpriteAtlas;
    SpriteAtlas armorsSpriteAtlas;
    SpriteAtlas jewelrySpriteAtlas;
    std::unique_ptr<WorldMap> worldMap;
    std::unique_ptr<Player> player;
    IState* state;
    int viewRange;
    static Game* uniquePtr;
    ConsoleLogger logger;
    Game();
public:
    static void initModules();
    static void unInitModules();
    static Game* init();
    static void unInit();
    ILogger* getLogger();
    Window* getWindow();
    Renderer* getRenderer();
    void openFont(std::string fontSrc, int characterSize);
    Font* getFont();
    void setState(IState* newState);
    void setStateWithoutMemoryFree(IState* newState);
    void openTilesSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    SpriteAtlas* getTilesSpriteAtlas();
    void openPeopleSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    SpriteAtlas* getPeopleSpriteAtlas();
    void openWeaponsSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    SpriteAtlas* getWeaponsSpriteAtlas();
    void openArmorsSpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    SpriteAtlas* getArmorsSpriteAtlas();
    void openJewelrySpriteAtlas(std::string imageSrc, int tileWidth, int tileHeight);
    SpriteAtlas* getJewerlySpriteAtlas();
    void genWorld(int width, int height);
    void setViewRange(int viewRange);
    int getViewRange();
    void initPlayer(int spriteX, int spriteY);
    Player* getPlayer();
    Tile* getTileAt(int y, int x);
    int getWorldWidth();
    int getWorldHeight();
    void run();
};

#endif // GAME_H_INCLUDED
