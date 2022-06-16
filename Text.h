#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "ISprite.h"
#include "Font.h"

class Text : public ISprite{
private:
    std::string text;
    Font* font;
    SDL_Color color;
public:
    Text(std::string text, Font* font, SDL_Color = {255, 255, 255});
    void draw(Renderer* renderer, SDL_Rect* dstRect = NULL, SDL_Rect* srcRect = NULL) override;
};

#endif // TEXT_H_INCLUDED
