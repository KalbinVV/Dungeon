#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL2/SDL.h>

class Window{
private:
    SDL_Window* sdlWindow;
    bool windowIsOpen;
    int width;
    int height;
public:
    Window();
    void open(const char* title, int width, int height);
    SDL_Window* getSdlWindow();
    void setWidth(int width);
    int getWidth();
    void setHeight(int height);
    int getHeight();
    bool isOpen();
    void close();
    ~Window();
};

#endif // WINDOW_H_INCLUDED
