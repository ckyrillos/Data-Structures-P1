/*
 * Node.h
 *
 * COSC 160 Fall 2017
 * Project #1
 *
 * Due on: OCT 4, 2017
 * Author: Carl Kyrillos
 *
 *
 * In accordance with the class policies and Georgetown's
 * Honor Code, I certify that, with the exception of the
 * class resources and those items noted below, I have neither
 * given nor received any assistance on this project.
 *
 * References not otherwise commented within the program source code.
 * Note that you should not mention any help from the TAs, the professor,
 * or any code taken from the class textbooks.
 */

#ifndef PROJECT_1_NODE_H
#define PROJECT_1_NODE_H

class Node {
public:
    int data;
    Node * next;

    Node(int, Node *);

};


Node::Node(int value, Node * nextNode) {
    data = value;
    next = nextNode;
}

#endif //PROJECT_1_NODE_H
