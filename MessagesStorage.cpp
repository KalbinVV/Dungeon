#include "MessagesStorage.h"
#include <fstream>
#include "Utils.h"
#include "MessageException.h"

std::map<std::string, std::string> MessagesStorage::messages = {};

void MessagesStorage::loadMessages(std::string fileSrc){
    std::ifstream inputFile(fileSrc);
    std::string line;
    while(std::getline(inputFile, line)){
        std::vector<std::string> params = Utils::splitString(line, ": ");
        messages[params[0]] = params[1];
    }
    inputFile.close();
}

std::string MessagesStorage::getMessage(std::string messageType){
    if(messages.count(messageType) == 0){
        std::string errorStr = "Message '" + messageType + "' not exists!";
        throw MessageException(errorStr);
    }
    return messages[messageType];
}
