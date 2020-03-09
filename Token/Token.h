#ifndef LAB5_TOKEN_H
#define LAB5_TOKEN_H

#include <string>
#include "../Position/Fragment.h"

using namespace std;

enum domain {
    STRING,
    NUMBER,
    EoF,
    SERR,
};


class Token {
private:
    domain type;
    string value;
    Position fragment;

public:
    string to_str() const;

    Token();
    Token(domain type, string value,
          int pos, int col, int row,
          int new_pos, int new_col, int new_row);

    domain get_type();
};


#endif //LAB5_TOKEN_H
