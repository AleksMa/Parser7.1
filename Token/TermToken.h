#ifndef LEXERLAB4_TERMTOKEN_H
#define LEXERLAB4_TERMTOKEN_H

#include <string>
#include "Token.h"

using namespace std;


class TermToken: public Token {
    string ident;

public:
    string to_str() override;

    TermToken(string ident, Position start, Position end);
};


#endif //LEXERLAB4_TERMTOKEN_H
