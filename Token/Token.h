#ifndef LAB5_TOKEN_H
#define LAB5_TOKEN_H

#include <string>
#include "../Position/Fragment.h"

using namespace std;

enum domain_tag {
    NON_TERM,       // 0
    AXIOM,          // 1
    SEMICOLON,      // 2
    OR,             // 3
    ID_EST,         // 4
    COMMA,          // 5
    EPSILON,        // 6
    NT_KW,          // 7
    T_KW,           // 8
    TERM,           // 9
    END_OF_PROGRAM, // 10
};


class Token {
public:
    virtual string to_str();
    domain_tag get_tag();

protected:
    domain_tag tag;
    Fragment coords;

    Token(domain_tag type, Position start, Position end);

    //domain_tag get_type();
};


#endif //LAB5_TOKEN_H
