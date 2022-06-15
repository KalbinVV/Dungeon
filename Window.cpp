#include "Window.h"
#include "InitException.h"

Window::Window(){
    sdlWindow = nullptr;
}

void Window::open(const char* title, int width, int height){
    sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
        SDL_WINDOW_SHOWN);
    if(sdlWindow == NULL){
        throw InitException(SDL_GetError());
    }
    windowIsOpen = true;
    this->width = width;
    this->height = height;
}

SDL_Window* Window::getSdlWindow(){
    return sdlWindow;
}

int Window::getWidth(){
    return width;
}

int Window::getHeight(){
    return height;
}

bool Window::isOpen(){
    return windowIsOpen;
}

void Window::close(){
    windowIsOpen = false;
    SDL_DestroyWindow(sdlWindow);
    sdlWindow = nullptr;
}

Window::~Window(){
    close();
}
