#ifndef LEXERLAB4_RESULTNODE_H
#define LEXERLAB4_RESULTNODE_H


#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class ResultNode : public Node {
public:
    string value;

    ResultNode *parent;
    vector<ResultNode*> children;

    ResultNode(Node node, string value);
    ResultNode(Node node, string value, ResultNode *parent);
};


#endif //LEXERLAB4_RESULTNODE_H
