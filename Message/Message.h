//
// Created by a.mamaev on 09.03.2020.
//

#ifndef LEXERLAB3_MESSAGE_H
#define LEXERLAB3_MESSAGE_H

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


#endif //LEXERLAB3_MESSAGE_H
