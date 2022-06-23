#include "Utils.h"

std::vector<std::string> Utils::splitString(std::string src, std::string separator){
    std::vector<std::string> words;
    size_t firstPos = 0;
    size_t secondPos = 0;
    while((secondPos = src.find(separator, firstPos)) != std::string::npos){
        words.push_back(src.substr(firstPos, secondPos - firstPos));
        firstPos = secondPos + 1;
    }
    words.push_back(src.substr(firstPos, secondPos - firstPos));
    return words;
}
