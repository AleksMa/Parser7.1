//
// Created by a.mamaev on 09.03.2020.
//

#include "IdentToken.h"

IdentToken::IdentToken(string ident, Position start, Position end): Token(IDENT, start, end), ident(ident) {}

string IdentToken::to_str() {
    return "STRING         " + coords.to_str() + ": " + ident;
}
