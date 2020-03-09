#ifndef LAB5_TOKEN_H
#define LAB5_TOKEN_H

#include <string>
#include "../Position/Fragment.h"

using namespace std;

enum domain_tag {
    IDENT,
    NUMBER,
    DECREMENT,
    LESS,
    LESS_EQUAL,
    END_OF_PROGRAM,
};


class Token {
public:
    domain_tag tag;
    Fragment coords;

    virtual string to_str();

protected:
    Token(domain_tag type, Position start, Position end);

    //domain_tag get_type();
};


#endif //LAB5_TOKEN_H
