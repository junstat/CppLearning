#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_CIRCULARLINKEDLIST_H
#define DATASTRUCTURE_CIRCULARLINKEDLIST_H

typedef int ElementType;

class Node {
public:
    ElementType data;
    Node *next;

    Node(ElementType value, Node *link = nullptr)
            : data(value), next(link) {}
};

typedef Node *NodePointer;

class CircularLinkedList {

public:
    NodePointer head;
    int length;
};


#endif //DATASTRUCTURE_CIRCULARLINKEDLIST_H
