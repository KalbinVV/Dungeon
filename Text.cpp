#include "Text.h"
#include "RenderException.h"

Text::Text(std::string text, Font* font, TextRenderType textRenderType , SDL_Color color){
    this->text = text;
    this->font = font;
    this->textRenderType = textRenderType;
    this->color = color;
    this->characterSize = 12;
    position.y = 0;
    position.x = 0;
    charPerLine = -1;
}

void Text::setPosition(Vec2i position){
    this->position = position;
}

Vec2i Text::getPosition(){
    return position;
}

void Text::setCharacterSize(int characterSize){
    this->characterSize = characterSize;
}

int Text::getCharacterSize(){
    return characterSize;
}

void Text::setCharPerLine(int charPerLine){
    this->charPerLine = charPerLine;
}

int Text::getCharPerLine(){
    return charPerLine;
}

int Text::getHeight(){
    if(charPerLine < 0){
        return characterSize;
    }else{
        std::string textCopy = text;
        int height = 0;
        while(textCopy.size() > 0){
            height += Text(textCopy.substr(0, charPerLine), font, textRenderType).getHeight();
            textCopy.erase(0, charPerLine);
        }
        return height;
    }
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
    if(dstRect == NULL){
        SDL_Rect textDstRect{
            x: position.x,
            y: position.y,
            w: characterSize * static_cast<int>(text.size()) / 2,
            h: characterSize
        };
        if(charPerLine < 0){
            SDL_RenderCopy(renderer->getSdlRenderer(), texture, srcRect, &textDstRect);
        }else{
            std::string textCopy = text;
            while(textCopy.size() > 0){
                Text lineText(textCopy.substr(0, charPerLine), font, TextRenderType::Quality);
                lineText.setPosition(getPosition());
                lineText.setCharacterSize(characterSize);
                lineText.draw(renderer);
                textCopy.erase(0, charPerLine);
                setPosition(getPosition().addY(20));
            }
        }
    }else{
        SDL_RenderCopy(renderer->getSdlRenderer(), texture, srcRect, dstRect);
    }
    SDL_DestroyTexture(texture);
}
