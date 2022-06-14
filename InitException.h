#ifndef INITEXCEPTION_H_INCLUDED
#define INITEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

class InitException : public std::exception{
private:
    std::string exceptionDescription;
public:
    InitException(std::string exceptionDescription);
    const char* what() const noexcept override;
};

#endif // INITEXCEPTION_H_INCLUDED
