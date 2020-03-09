#include "Compiler.h"
#include "../Token/IdentToken.h"
#include "../Token/NumericToken.h"
#include "../Token/SpecToken.h"

#include <iostream>
#include <string>
#include <set>

using namespace std;

Scanner::Scanner(string source, Compiler *compiler) : program(source + char(-1)), cur(source + char(-1)),
                                                     compiler(compiler) {}

long Scanner::parse_val() {
    long val = cur.cp() - '0';
    while ((++cur).is_digit()) {
        val = val * 10 + cur.cp() - '0';
    }
    return val;
}

Token *Scanner::next_token() {
    set<char> vowel{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    while (cur.cp() != -1) {
        while (cur.is_whitespace() || cur.is_newline())
            cur++;
        Position start = cur;

        switch (cur.cp()) {
            case '-':
                cur++;
                if (cur.is_digit()) {
                    long val = parse_val();
                    return new NumericToken(-val, start, cur);
                } else if (cur.cp() == '-') {
                    return new SpecToken(DECREMENT, start, ++cur);
                }
                compiler->add_message(true, cur++, "Unexpected character");
                break;
            case '<':
                cur++;
                if (cur.cp() == '=') {
                    return new SpecToken(LESS_EQUAL, start, ++cur);
                }
                return new SpecToken(LESS, start, cur);
            default:
                char c = cur.cp();
                if (vowel.find(c) != vowel.end()) {
                    do {
                        cur++;
                    } while (cur.is_letter());
                    string ident = program.substr(start.index, cur.index - start.index);
                    return new IdentToken(ident, start, cur);
                } else if (cur.is_digit()) {
                    long val = parse_val();
                    return new NumericToken(val, start, cur);
                } else {
                    compiler->add_message(true, cur++, "Unexpected character");
                    break;
                }
        }
    }
    return new SpecToken(END_OF_PROGRAM, cur, cur);
}

//    string cur_source = program.substr(pos);
//    smatch match;
//
//    if (regex_search(cur_source, match, tokens_regex)) {
//        string matched_substr = match[0];
//
//        int old_pos = pos;
//        int old_col = col;
//
//        pos += matched_substr.length();
//        col += matched_substr.length();
//
//        if (match[1] != "") {
//            return Token(STRING, matched_substr,
//                         old_pos, old_col, row,
//                         pos, col, row);
//        }
//
//        return Token(NUMBER, matched_substr,
//                     old_pos, old_col, row,
//                     pos, col, row);
//    }
//
//    if (finish) {
//        return Token(EoF, "",
//                     pos, col, row,
//                     pos, col, row);
//    }
//
//    return Token(SERR, "",
//                 pos, col, row,
//                 pos, col, row);




//
//    if (regex_search(cur_source, match, strings)) {
//        string matched_substr = match[0];
//
//        index += matched_substr.length();
//        line += matched_substr.length();
//
//        found = true;
//        return Token(STRING, matched_substr, index, line, pos);
//    }
//
//    if (regex_search(cur_source, match, nums)) {
//        string matched_substr = match[0];
//
//        index += matched_substr.length();
//        line += matched_substr.length();
//
//        found = true;
//        return Token(NUMBER, matched_substr, index, line, pos);
//    }
