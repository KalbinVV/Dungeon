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
    titleText.setCharacterSize(14);
    titleText.setAlign(TextAlign::center);
    titleText.setPosition(Vec2i(0, game->getWindow()->getHeight() / 2));
    titleText.draw(renderer);
    Text quitText("Q - Выйти", game->getFont(), TextRenderType::Quality);
    quitText.setCharacterSize(12);
    quitText.setPosition(Vec2i(0, game->getWindow()->getHeight() - 40));
    quitText.setAlign(TextAlign::center);
    quitText.draw(renderer);
    renderer->update();
}

void PauseState::render(){}
