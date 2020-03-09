#include <iostream>
#include <fstream>
#include <sstream>
#include "Scanner/Scanner.h"

string read_file(const string &path) {
    ifstream source_stream(path);
    ostringstream string_stream;

    string_stream << source_stream.rdbuf();
    source_stream.close();

    return string_stream.str();
}

int main(int argc, char* argv[]) {

    if (argc < 2)
        cout << "Expected: input file" << endl;
    string input_file = argv[1];
    string source = read_file(input_file);

    Scanner lex(source);

    Token t;
    do {
        t = lex.next_token();
        cout << t.to_str() << endl;
    } while (t.get_type() != EoF && t.get_type() != SERR);

    return 0;
}
