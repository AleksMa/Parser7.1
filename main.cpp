#include <iostream>
#include <fstream>
#include <sstream>
#include "Compiler/Compiler.h"

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

    Compiler compiler;

    Scanner lex = compiler.get_scanner(source);

    Token *t;
    while(true) {
        t = lex.next_token();
        cout << t->to_str() << endl;
        if (t->tag == END_OF_PROGRAM){
            delete t;
            break;
        }
        delete t;
    }

    cout << endl << "Messages:" << endl;

    compiler.output_messages();

    return 0;
}
