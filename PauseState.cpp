#include "PauseState.h"
#include "Text.h"

PauseState::PauseState(Game* game, IState* backgroundState){
    this->game = game;
    this->backgroundState = backgroundState;
    view();
}

void PauseState::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) game->getWindow()->close();
        else if(event.type == SDL_WINDOWEVENT){
            if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                Window* window = game->getWindow();
                window->setWidth(event.window.data1);
                window->setHeight(event.window.data2);
                view();
            }
        }else if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.scancode){
                case SDL_SCANCODE_ESCAPE:
                    backgroundState->view();
                    game->getRenderer()->update();
                    game->setState(backgroundState);
                    break;
                case SDL_SCANCODE_Q:
                    delete backgroundState;
                    game->getWindow()->close();
                    break;
                default:
                    break;
            }
        }
    }
}

void PauseState::view(){
    backgroundState->view();
    Renderer* renderer = game->getRenderer();
    SDL_SetRenderDrawColor(renderer->getSdlRenderer(), 0, 0, 0, 210);
    SDL_RenderFillRect(renderer->getSdlRenderer(), NULL);
    Text titleText("Пауза", game->getFont(), TextRenderType::Quality);
    SDL_Rect dstRect{
        x: game->getWindow()->getWidth() / 2,
        y: game->getWindow()->getHeight() / 2 - 24,
        w: static_cast<int>(titleText.getString().size()) * 8,
        h: 16
    };
    dstRect.x -= dstRect.w / 2;
    titleText.draw(renderer, &dstRect);
    Text quitText("Q - Выйти", game->getFont(), TextRenderType::Quality);
    SDL_Rect quitTextDstRect{
        x: 10,
        y: game->getWindow()->getHeight() - 40,
        w: static_cast<int>(quitText.getString().size()) * 5,
        h: 14
    };
    quitText.draw(renderer, &quitTextDstRect);
    renderer->update();
}

void PauseState::render(){}
