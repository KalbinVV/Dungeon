#include "Text.h"
#include "RenderException.h"
#include "Game.h"
#include <iostream>

Text::Text(std::string text, Font* font, TextRenderType textRenderType , SDL_Color color){
    this->text = text;
    this->font = font;
    this->textRenderType = textRenderType;
    this->color = color;
    this->characterSize = 12;
    position.y = 0;
    position.x = 0;
    charPerLine = -1;
    textAlign = TextAlign::normal;
    consideredByScreenResolution = true;
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
    if(isConsideredByScreenResolution()){
        Window* window = Game::init()->getWindow();
        return characterSize * (static_cast<float>(window->getWidth()) / 1300.0);
    }
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
        int height = 0;
        int times = text.size() / charPerLine;
        while(times > 0){
            height += characterSize;
            times--;
        }
        return height;
    }
}

int Text::getWidth(){
    return getCharacterSize() * static_cast<int>(text.size()) / 2;
}

int Text::getX(){
    if(textAlign == TextAlign::center){
        return Game::init()->getWindow()->getWidth() / 2;
    }
    return position.x;
}

bool Text::isConsideredByScreenResolution(){
    return consideredByScreenResolution;
}

void Text::setConsideredByScreenResolution(bool consideredByScreenResolution){
    this->consideredByScreenResolution = consideredByScreenResolution;
}

void Text::setAlign(TextAlign textAlign){
    this->textAlign = textAlign;
}

TextAlign Text::getAlign(){
    return textAlign;
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
            w: getCharacterSize() * static_cast<int>(text.size()) / 2,
            h: characterSize
        };
        if(textAlign != TextAlign::normal){
            if(textAlign == TextAlign::center){
                textDstRect.x = Game::init()->getWindow()->getWidth() / 2 - textDstRect.w / 2;
            }
        }
        if(charPerLine < 0){
            SDL_RenderCopy(renderer->getSdlRenderer(), texture, srcRect, &textDstRect);
        }else{
            std::string textCopy = text;
            Vec2i linePosition = position;
            int lineCharacterSize = getCharacterSize();
            while(textCopy.size() > 0){
                Text lineText(textCopy.substr(0, charPerLine), font, TextRenderType::Quality);
                lineText.setPosition(linePosition);
                lineText.setCharacterSize(lineCharacterSize);
                lineText.draw(renderer);
                textCopy.erase(0, charPerLine);
                linePosition = linePosition.addY(20);
            }
        }
    }else{
        SDL_RenderCopy(renderer->getSdlRenderer(), texture, srcRect, dstRect);
    }
    SDL_DestroyTexture(texture);
}
