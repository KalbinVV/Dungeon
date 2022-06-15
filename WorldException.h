#ifndef WORLDEXCEPTION_H_INCLUDED
#define WORLDEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

class WorldException : public std::exception{
private:
    std::string exceptionDescription;
public:
    WorldException(std::string exceptionDescription);
    const char* what() const noexcept override;
};


#endif // WORLDEXCEPTION_H_INCLUDED
