#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "ISprite.h"
#include "Font.h"
#include "TextRenderType.h"
#include "Vec2i.h"

class Text : public ISprite{
private:
    std::string text;
    Font* font;
    TextRenderType textRenderType;
    SDL_Color color;
    int characterSize;
    Vec2i position;
    int charPerLine;
public:
    Text(std::string text, Font* font, TextRenderType textRenderType, SDL_Color = {255, 255, 255});
    void setPosition(Vec2i position);
    Vec2i getPosition();
    void setCharacterSize(int characterSize);
    int getCharacterSize();
    void setCharPerLine(int charPerLine);
    int getCharPerLine();
    int getHeight();
    void setString(std::string text);
    std::string getString();
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL) override;
};

#endif // TEXT_H_INCLUDED
