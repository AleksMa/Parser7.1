//
// Created by alexey on 22.12.2019.
//

#include "Token.h"

#include <utility>


Token::Token() = default;

string Token::to_str() const {
    string stype = "EOF";
    if (type == STRING)
        stype = "STRING";
    if (type == NUMBER)
        stype = "NUMBER";
    if (type == SERR)
        stype = "syntax error";

    string t = stype + " (" + to_string(fragment.start.row) + ", " + to_string(fragment.start.col) + ")";
    if (type != EoF && type != SERR)
        t += ": " + value;
    return t;
}

Token::Token(domain type, string value, int pos, int col, int row, int new_pos, int new_col, int new_row) :
        type(type), value(value) {
    fragment.start = {
            pos,
            col,
            row,
    };
    fragment.end = {
            new_pos,
            new_col,
            new_row,
    };
}

domain Token::get_type() {
    return type;
}
