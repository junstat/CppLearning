#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_DOUBLYLINKEDLIST_H
#define DATASTRUCTURE_DOUBLYLINKEDLIST_H

typedef int ElementType;

class DNode {
public:
    ElementType data;
    DNode *prior, *next;
};

typedef DNode *DNodePointer;

class DoublyLinkedList {

};

#endif //DATASTRUCTURE_DOUBLYLINKEDLIST_H
