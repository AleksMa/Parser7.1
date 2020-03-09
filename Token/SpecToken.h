//
// Created by a.mamaev on 09.03.2020.
//

#ifndef LEXERLAB3_SPECTOKEN_H
#define LEXERLAB3_SPECTOKEN_H

#include "Token.h"

class SpecToken: public Token {
public:
    string to_str();

    SpecToken(domain_tag tag, Position start, Position end);
};


#endif //LEXERLAB3_SPECTOKEN_H
