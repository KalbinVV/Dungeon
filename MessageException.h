#ifndef MESSAGEEXCEPTION_H_INCLUDED
#define MESSAGEEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

class MessageException : public std::exception{
private:
    std::string exceptionDescription;
public:
    MessageException(std::string exceptionDescription);
    const char* what() const noexcept override;
};

#endif // MESSAGEEXCEPTION_H_INCLUDED
