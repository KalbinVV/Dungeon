#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::warning(std::string str){
    std::cout << "[WARNING] " << str << std::endl;
}

void ConsoleLogger::error(std::string str){
    std::cout << "[ERROR] " << str << std::endl;
}

void ConsoleLogger::info(std::string str){
    std::cout << "[INFO] " << str << std::endl;
}
