#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL2/SDL.h>

class Window{
private:
    SDL_Window* sdlWindow;
    bool windowIsOpen;
public:
    Window();
    void open(const char* title, int width, int height);
    SDL_Window* getSdlWindow();
    bool isOpen();
    void close();
    ~Window();
};

#endif // WINDOW_H_INCLUDED
