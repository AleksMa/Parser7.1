//
// Created by a.mamaev on 09.03.2020.
//

#ifndef LEXERLAB3_COMPILER_H
#define LEXERLAB3_COMPILER_H

#include <vector>
#include <map>
#include "../Token/Token.h"
#include "../Message/Message.h"

using namespace std;

class Scanner;

class Compiler {
private:
    vector<pair<Position, Message>> messages;

    vector<string> names;
    map<string, int> name_codes;

public:
    Compiler();

    int add_name(string name);
    string get_name(int code);

    void add_message(bool is_error, Position c, string text);
    void output_messages();

    Scanner get_scanner(string program);
};


class Scanner {
private:
    string program;
    Position cur;
    Compiler *compiler;

    long parse_val();

public:
    Scanner(string source, Compiler *compiler);
    Token *next_token();
};

#endif //LEXERLAB3_COMPILER_H
