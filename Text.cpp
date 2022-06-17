#include "Text.h"
#include "RenderException.h"

Text::Text(std::string text, Font* font, TextRenderType textRenderType, SDL_Color color){
    this->text = text;
    this->font = font;
    this->textRenderType = textRenderType;
    this->color = color;
}

void Text::setString(std::string text){
    this->text = text;
}

std::string Text::getString(){
    return text;
}

void Text::draw(Renderer* renderer, SDL_Rect* dstRect, SDL_Rect* srcRect){
    SDL_Surface* surface = NULL;
    if(textRenderType == TextRenderType::Speed){
        surface = TTF_RenderUTF8_Solid(font->getTtfFont(), text.c_str(), color);
    }else{
        surface = TTF_RenderUTF8_Blended(font->getTtfFont(), text.c_str(), color);
    }
    if(surface == NULL){
        throw RenderException(SDL_GetError());
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer->getSdlRenderer(), surface);
    SDL_FreeSurface(surface);
    if(texture == NULL){
        throw RenderException(SDL_GetError());
    }
    SDL_RenderCopy(renderer->getSdlRenderer(), texture, srcRect, dstRect);
    SDL_DestroyTexture(texture);
}
