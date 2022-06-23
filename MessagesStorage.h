#ifndef MESSAGESSTORAGE_H_INCLUDED
#define MESSAGESSTORAGE_H_INCLUDED

#include <map>
#include <string>

class MessagesStorage{
private:
    static std::map<std::string, std::string> messages;
public:
    static void loadMessages(std::string fileSrc);
    static std::string getMessage(std::string messageType);
};

#endif // MESSAGESSTORAGE_H_INCLUDED
