#include "ResultNode.h"

ResultNode::ResultNode(Node node, string value) : Node(node), value(value), parent(nullptr) {

}

ResultNode::ResultNode(Node node, string value, ResultNode *parent) : Node(node), value(value), parent(parent) {

}
