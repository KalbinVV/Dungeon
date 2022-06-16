#ifndef ERRORSTATE_H_INCLUDED
#define ERRORSTATE_H_INCLUDED

#include "IState.h"
#include <string>

class ErrorState{
private:
    std::string errorStr;
public:
    ErrorState(std::string errorStr);
};

#endif // ERRORSTATE_H_INCLUDED
