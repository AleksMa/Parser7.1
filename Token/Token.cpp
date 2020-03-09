//
// Created by alexey on 22.12.2019.
//

#include "Token.h"

#include <utility>


//string Token::to_str() const {
//    string stype = "EOF";
//    if (tag == STRING)
//        stype = "STRING";
//    if (tag == NUMBER)
//        stype = "NUMBER";
//    if (tag == SERR)
//        stype = "syntax error";
//
//    string t = stype + " (" + to_string(coords.start.row) + ", " + to_string(coords.start.col) + ")";
//    if (tag != EoF && tag != SERR)
//        t += ": " + value;
//    return t;
//}

Token::Token(domain_tag type, Position start, Position end) :
        tag(type), coords(start, end) {}

string Token::to_str() {
    return to_string(tag) + " " + coords.to_str();
}
