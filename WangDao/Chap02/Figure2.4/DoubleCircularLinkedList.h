#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_DOUBLECIRCULARLINKEDLIST_H
#define DATASTRUCTURE_DOUBLECIRCULARLINKEDLIST_H

typedef int ElementType;

class DNode {
public:
    ElementType data;
    DNode *prior, *next;

    DNode(ElementType value, DNode *prior = nullptr, DNode *next = nullptr)
            : data(value), prior(prior), next(next) {}
};

typedef DNode *DNodePointer;

#endif //DATASTRUCTURE_DOUBLECIRCULARLINKEDLIST_H
