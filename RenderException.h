#ifndef RENDEREXCEPTION_H_INCLUDED
#define RENDEREXCEPTION_H_INCLUDED

#include <exception>
#include <string>

class RenderException : public std::exception{
private:
    std::string exceptionDescription;
public:
    RenderException(std::string exceptionDescription);
    const char* what() const noexcept override;
};

#endif // RENDEREXCEPTION_H_INCLUDED
