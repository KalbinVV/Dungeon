#include "MessageException.h"

MessageException::MessageException(std::string exceptionDescription){
    this->exceptionDescription = exceptionDescription;
}

const char* MessageException::what() const noexcept{
    return exceptionDescription.c_str();
}

