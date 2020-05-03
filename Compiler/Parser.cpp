#include <iostream>
#include "Parser.h"

Parser::Parser(Scanner L) : L(L) {
    D[{GRAMMAR, NT_KW}] = {NT_DEC_NODE, T_DEC_NODE, R_LIST_NODE, A_NODE, Node(END_OF_PROGRAM)};

    D[{NT_DEC, NT_KW}] = {Node(NT_KW), NT_LIST_NODE, Node(SEMICOLON)};
    D[{NT_LIST, NON_TERM}] = {Node(NON_TERM), NT_TAIL_NODE};
    D[{NT_TAIL, COMMA}] = {Node(COMMA), Node(NON_TERM), NT_TAIL_NODE};
    D[{NT_TAIL, SEMICOLON}] = {EMPTY_NODE};

    D[{T_DEC, T_KW}] = {Node(T_KW), T_LIST_NODE, Node(SEMICOLON)};
    D[{T_LIST, TERM}] = {Node(TERM), T_TAIL_NODE};
    D[{T_TAIL, COMMA}] = {Node(COMMA), Node(TERM), T_TAIL_NODE};
    D[{T_TAIL, SEMICOLON}] = {EMPTY_NODE};

    D[{R_LIST, NON_TERM}] = {RULE_NODE, RULE_TAIL_NODE};
    D[{RULE, NON_TERM}] = {Node(NON_TERM), Node(ID_EST), RIGHT_SEC_NODE, RIGHT_TAIL_NODE, Node(SEMICOLON)};
    D[{RIGHT_SEC, EPSILON}] = {Node(EPSILON)};
    D[{RIGHT_SEC, NON_TERM}] = {Node(NON_TERM), RIGHT_SUB_NODE};
    D[{RIGHT_SEC, TERM}] = {Node(TERM), RIGHT_SUB_NODE};

    D[{RIGHT_SUB, NON_TERM}] = {Node(NON_TERM), RIGHT_SUB_NODE};
    D[{RIGHT_SUB, TERM}] = {Node(TERM), RIGHT_SUB_NODE};
    D[{RIGHT_SUB, EPSILON}] = {Node(EPSILON)};
    D[{RIGHT_SUB, OR}] = {EMPTY_NODE};
    D[{RIGHT_SUB, SEMICOLON}] = {EMPTY_NODE};

    D[{RIGHT_TAIL, OR}] = {Node(OR), RIGHT_SEC_NODE, RIGHT_TAIL_NODE};
    D[{RIGHT_TAIL, SEMICOLON}] = {EMPTY_NODE};

    D[{RULE_TAIL, NON_TERM}] = {RULE_NODE, RULE_TAIL_NODE};
    D[{RULE_TAIL, AXIOM}] = {EMPTY_NODE};

    D[{A, AXIOM}] = {Node(AXIOM), Node(NON_TERM), Node(SEMICOLON)};

}

void Parser::parse() {
    root = new ResultNode(Node(ROOT, false), rule_names[ROOT]);

    S.push(new ResultNode(GRAMMAR_NODE, rule_names[GRAMMAR], root));

    Token *token = L.next_token();
    do {
        ResultNode *top = S.top();

        if (top->is_terminal) {
            if (top->tag == token->get_tag()) {
                top->parent->children.push_back(top);
                top->value = token->to_str();
                S.pop();
                token = L.next_token();
            } else {
                cout << "Unexpected token: " << token->to_str() << endl;
                return;
            }
        } else if (D.find({static_cast<rule>(top->tag), token->get_tag()}) != D.end()) {
            rule r = static_cast<rule>(top->tag);
            vector<Node> right = D[{r, token->get_tag()}];
            if (right.size() == 1 && right[0].tag == EMPTY) {
                S.pop();
            } else {
                S.top()->parent->children.push_back(top);
                S.pop();
                for (int i = right.size() - 1; i >= 0; --i) {
                    Node child = right[i];
                    S.push(new ResultNode(right[i], rule_names[static_cast<rule>(right[i].tag)], top));
                }
                result.push_back({r, right});
            }
        } else {
            cout << "Unexpected: " << token->to_str() << endl;
            return;
        }
    } while (!S.empty());
}

void Parser::print_result() {
    for (auto &i : result) {
        cout << rule_names[i.first] << " => ";
        for (auto e : i.second) {
            cout << get_name(e) << ", ";
        }
        cout << endl;
    }
}

string Parser::get_name(Node node) {
    return node.is_terminal ? to_string(node.tag) : rule_names[static_cast<rule>(node.tag)];
}


void Parser::print_tree() {
    print_node(root->children[0], 0);
}

void Parser::print_node(ResultNode *node, int level) {
    string prefix;
    for (int i = 0; i < level; ++i) {
        prefix += "  ";
    }
    cout << prefix << "> " << node->value << endl;
    for (auto & i : node->children) {
        print_node(i, level + 1);
    }
}

Parser::~Parser() {
    delete_node(root);
}

void Parser::delete_node(ResultNode *node) {
    for (auto & i : node->children) {
        delete_node(i);
    }
    delete node;
}


