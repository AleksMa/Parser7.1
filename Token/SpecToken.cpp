//
// Created by a.mamaev on 09.03.2020.
//

#include "SpecToken.h"

SpecToken::SpecToken(domain_tag tag, Position start, Position end): Token(tag, start, end) {}

string SpecToken::to_str() {
    string type = "END OF PROGRAM";
    switch(tag) {
        case DECREMENT:
            type = "DECREMENT     ";
            break;
        case LESS:
            type = "LESS          ";
            break;
        case LESS_EQUAL:
            type = "LESS OR EQUAL ";
            break;
    }
    return type + " " + coords.to_str();
}
