//
// Created by Carl on 10/2/17.
//

#ifndef PROJECT_1_NODE_H
#define PROJECT_1_NODE_H

//Begin Node class declaration.
class Node {
public:
    int info;
    Node * next;

    Node(int, Node * = NULL);

};//End Node class declaration


//Begin Node class implementation.
Node::Node(int value, Node * nextNode) {
    info = value;
    next = nextNode;
}//END Node class implementation.

#endif //PROJECT_1_NODE_H
