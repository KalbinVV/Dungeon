#include "InitException.h"

InitException::InitException(std::string exceptionDescription){
    this->exceptionDescription = exceptionDescription;
}

const char* InitException::what() const noexcept{
    return exceptionDescription.c_str();
}
