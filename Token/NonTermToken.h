#ifndef LEXERLAB4_NONTERMTOKEN_H
#define LEXERLAB4_NONTERMTOKEN_H

#include <string>
#include "Token.h"

using namespace std;


class NonTermToken: public Token {
    string ident;

public:
    string to_str() override;

    NonTermToken(string ident, Position start, Position end);
};


#endif //LEXERLAB4_NONTERMTOKEN_H
