#ifndef LEXERLAB4_SCANNER_H
#define LEXERLAB4_SCANNER_H

#include <string>
#include <set>
#include "../Token/Token.h"


using namespace std;

class Compiler;

class Scanner {
private:
    string program;
    Position cur;
    Compiler *compiler;



    long parse_val();

public:
    Scanner(string source, Compiler *compiler);
    Token *next_token();

    bool parse_axiom();

    bool parse_kw(string keyword);
};

#endif //LEXERLAB4_SCANNER_H
