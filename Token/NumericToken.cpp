//
// Created by a.mamaev on 09.03.2020.
//

#include "NumericToken.h"

NumericToken::NumericToken(long num, Position start, Position end): Token(NUMBER, start, end), val(num) {}

string NumericToken::to_str() {
    return "NUMBER         " + coords.to_str() + ": " + to_string(val);
}
