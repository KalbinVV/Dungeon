#include "Font.h"
#include "InitException.h"

Font::Font(){
    ttfFont = nullptr;
}

void Font::open(std::string fontSrc, int characterSize){
    ttfFont = TTF_OpenFont(fontSrc.c_str(), characterSize);
    if(ttfFont == NULL){
        throw InitException(TTF_GetError());
    }
}

TTF_Font* Font::getTtfFont(){
    return ttfFont;
}

Font::~Font(){
    if(ttfFont) TTF_CloseFont(ttfFont);
}
