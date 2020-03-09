#include <string>

using namespace std;

struct Position {
    int index;
    int line;
    int pos;

    string source;

    Position(string source);

    Position &operator++();
    Position operator++(int);

    char cp();
    bool is_whitespace();
    bool is_letter();
    bool is_digit();
    bool is_newline();


    string to_str();
};