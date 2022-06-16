#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <SDL2/SDL_ttf.h>
#include <string>

class Font{
private:
    TTF_Font* ttfFont;
public:
    Font();
    void open(std::string fontSrc, int characterSize);
    TTF_Font* getTtfFont();
    ~Font();
};

#endif // FONT_H_INCLUDED
