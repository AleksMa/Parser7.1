#include "Scanner.h"

#include <utility>
#include <string>


Scanner::Scanner(string source) : source(std::move(source)) {
    finish = false;
    pos = 0, col = 1, row = 1;
    remove_spaces();
}

void Scanner::remove_spaces() {
    string cur_source = source.substr(pos);
    smatch cur_space_match;

    while (regex_search(cur_source, cur_space_match, spaces_regex)) {
        if (cur_space_match[1] != "") {
            pos += cur_space_match[0].length();
            col += cur_space_match[0].length();
        } else {
            col = 1;
            row++;
            pos++;
        }
        cur_source = source.substr(pos);
    }
    if (pos >= source.size() - 1)
        finish = true;
}

Token Scanner::next_token() {
    remove_spaces();
    string cur_source = source.substr(pos);
    smatch match;

    if (regex_search(cur_source, match, tokens_regex)) {
        string matched_substr = match[0];

        int old_pos = pos;
        int old_col = col;

        pos += matched_substr.length();
        col += matched_substr.length();

        if (match[1] != "") {
            return Token(STRING, matched_substr,
                         old_pos, old_col, row,
                         pos, col, row);
        }

        return Token(NUMBER, matched_substr,
                     old_pos, old_col, row,
                     pos, col, row);
    }

    if (finish) {
        return Token(EoF, "",
                     pos, col, row,
                     pos, col, row);
    }

    return Token(SERR, "",
                 pos, col, row,
                 pos, col, row);
}



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
