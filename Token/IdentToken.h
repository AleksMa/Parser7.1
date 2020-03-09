//
// Created by a.mamaev on 09.03.2020.
//

#ifndef LEXERLAB3_IDENTTOKEN_H
#define LEXERLAB3_IDENTTOKEN_H

#include <string>
#include "Token.h"

using namespace std;


class IdentToken: public Token {
public:
    string ident;

    string to_str();

    IdentToken(string ident, Position start, Position end);
};


#endif //LEXERLAB3_IDENTTOKEN_H
