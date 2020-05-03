#ifndef LEXERLAB4_SPECTOKEN_H
#define LEXERLAB4_SPECTOKEN_H

#include "Token.h"

class SpecToken: public Token {
public:
    string to_str() override;

    SpecToken(domain_tag tag, Position start, Position end);
};


#endif //LEXERLAB4_SPECTOKEN_H
