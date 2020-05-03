#ifndef LEXERLAB4_NODE_H
#define LEXERLAB4_NODE_H


class Node {
public:
    bool is_terminal;
    int tag;

    Node(bool is_terminal, int tag);
    Node(int tag);
};


#endif //LEXERLAB4_NODE_H
