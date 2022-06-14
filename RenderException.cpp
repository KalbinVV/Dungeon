#include "RenderException.h"

RenderException::RenderException(std::string exceptionDescription){
    this->exceptionDescription = exceptionDescription;
}

const char* RenderException::what() const noexcept{
    return exceptionDescription.c_str();
}
