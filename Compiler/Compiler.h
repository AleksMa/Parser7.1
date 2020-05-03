#ifndef LEXERLAB4_COMPILER_H
#define LEXERLAB4_COMPILER_H

#include "Scanner.h"
#include <vector>
#include <map>
#include "../Token/Token.h"
#include "../Message/Message.h"

using namespace std;

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

#endif //LEXERLAB4_COMPILER_H
