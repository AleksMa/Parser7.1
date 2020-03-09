#ifndef LAB4_LEXER_H
#define LAB4_LEXER_H

#include <regex>
#include "../Token/Token.h"

using namespace std;


class Scanner {
private:
    int pos, col, row;
    bool finish;

    string source;

    string strings_re = R"(^("([^"\\]|\\.)*"))";
    string nums_re = R"(^([0-9][_0-9]*))";

    regex tokens_regex = regex(strings_re + "|" + nums_re);
    regex spaces_regex = regex("^([ \t]+)|^(\n)");

    void remove_spaces();

public:
    Scanner(string source);
    Token next_token();
};


#endif //LAB4_LEXER_H
