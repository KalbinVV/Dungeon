#ifndef ILOGGER_H_INCLUDED
#define ILOGGER_H_INCLUDED

#include <string>

class ILogger{
public:
    virtual void warning(std::string str) = 0;
    virtual void error(std::string str) = 0;
    virtual void info(std::string str) = 0;
};

#endif // ILOGGER_H_INCLUDED
