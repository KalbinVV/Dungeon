#ifndef CONSOLELOGGER_H_INCLUDED
#define CONSOLELOGGER_H_INCLUDED

#include "ILogger.h"

class ConsoleLogger : public ILogger{
public:
    void warning(std::string str) override;
    void error(std::string str) override;
    void info(std::string str) override;
};

#endif // CONSOLELOGGER_H_INCLUDED
