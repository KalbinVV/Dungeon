#include "WorldException.h"

WorldException::WorldException(std::string exceptionDescription){
    this->exceptionDescription = exceptionDescription;
}

const char* WorldException::what() const noexcept{
    return exceptionDescription.c_str();
}
