#ifndef LEXERLAB4_MESSAGE_H
#define LEXERLAB4_MESSAGE_H

#include <string>
#include <utility>

using namespace std;


class Message {
private:
    bool is_error;
    string text;

public:
    Message(bool is_error, string text);
    bool get_error();
    string get_text();
};


#endif //LEXERLAB4_MESSAGE_H
