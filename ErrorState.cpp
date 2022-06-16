#include "ErrorState.h"
#include "Game.h"
#include "Text.h"
#include "Window.h"
#include "Renderer.h"

ErrorState::ErrorState(std::string errorStr){
    Font font;
    font.open("assets/font.ttf", 24);
    Window window;
    window.open("Error", 800, 200);
    Renderer renderer;
    renderer.init(&window);
    Text text(errorStr, &font);
    renderer.clear(SDL_Color{
        r: 0,
        g: 0,
        b: 0
    });
    SDL_Rect dstRect{
        x: 0,
        y: 0,
        w: static_cast<int>(errorStr.size()) * 16,
        h: 24
    };
    text.draw(&renderer, &dstRect);
    renderer.update();
    while(window.isOpen()){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                window.close();
            }
        }
    }
}
