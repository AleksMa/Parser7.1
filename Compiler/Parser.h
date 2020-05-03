#ifndef LEXERLAB4_PARSER_H
#define LEXERLAB4_PARSER_H


#include <vector>
#include <map>
#include <stack>
#include "../Token/Token.h"
#include "Scanner.h"
#include "../Node/Node.h"
#include "../Node/ResultNode.h"

using namespace std;

enum rule {
    GRAMMAR,
    NT_DEC,
    NT_LIST,
    NT_TAIL,

    T_DEC,
    T_LIST,
    T_TAIL,

    R_LIST,
    RULE,
    RIGHT_SEC,
    RIGHT_SUB,
    RIGHT_TAIL,
    RULE_TAIL,
    A,

    EMPTY,

    ROOT
};

class Parser {
private:
    map<pair<rule, domain_tag>, vector<Node>> D;

    map<rule, string> rule_names = {
            {GRAMMAR,    "GRAMMAR"},
            {NT_DEC,     "NT_DEC"},
            {NT_LIST,    "NT_LIST"},
            {NT_TAIL,    "NT_TAIL"},

            {T_DEC,      "T_DEC"},
            {T_LIST,     "T_LIST"},
            {T_TAIL,     "T_TAIL"},

            {R_LIST,     "R_LIST"},
            {RULE,       "RULE"},
            {RIGHT_SEC,  "RIGHT_SEC"},
            {RIGHT_SUB,  "RIGHT_SUB"},
            {RIGHT_TAIL, "RIGHT_TAIL"},
            {RULE_TAIL,  "RULE_TAIL"},
            {A,          "A"},

            {EMPTY,      "EMPTY"},

            {ROOT,      "ROOT"}
    };

    stack<ResultNode*> S;
    vector<pair<rule, vector<Node>>> result;

    Scanner L;

    ResultNode *root = nullptr;

    Node GRAMMAR_NODE = Node(false, GRAMMAR);

    Node NT_DEC_NODE = Node(false, NT_DEC);
    Node NT_LIST_NODE = Node(false, NT_LIST);
    Node NT_TAIL_NODE = Node(false, NT_TAIL);

    Node T_DEC_NODE = Node(false, T_DEC);
    Node T_LIST_NODE = Node(false, T_LIST);
    Node T_TAIL_NODE = Node(false, T_TAIL);

    Node R_LIST_NODE = Node(false, R_LIST);
    Node RULE_NODE = Node(false, RULE);
    Node RIGHT_SEC_NODE = Node(false, RIGHT_SEC);
    Node RIGHT_SUB_NODE = Node(false, RIGHT_SUB);
    Node RIGHT_TAIL_NODE = Node(false, RIGHT_TAIL);
    Node RULE_TAIL_NODE = Node(false, RULE_TAIL);

    Node A_NODE = Node(false, A);
    Node EMPTY_NODE = Node(false, EMPTY);


    void print_node(ResultNode *node, int level);
    void delete_node(ResultNode *node);

    void print_result();
    string get_name(Node node);

public:
    Parser(Scanner L);
    ~Parser();

    void parse();
    void print_tree();
};


#endif //LEXERLAB4_PARSER_H
