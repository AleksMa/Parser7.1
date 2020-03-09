//
// Created by a.mamaev on 09.03.2020.
//

#ifndef LEXERLAB3_NUMERICTOKEN_H
#define LEXERLAB3_NUMERICTOKEN_H


#include "Token.h"

class NumericToken: public Token {
public:
    long val;

    NumericToken(long num, Position start, Position end);

    string to_str();
};


#endif //LEXERLAB3_NUMERICTOKEN_H
