#ifndef ISTATE_H_INCLUDED
#define ISTATE_H_INCLUDED

#include <SDL2/SDL.h>

class IState{
public:
    virtual void handleEvents() = 0;
    virtual void render() = 0;
    virtual ~IState(){};
};

#endif // ISTATE_H_INCLUDED
