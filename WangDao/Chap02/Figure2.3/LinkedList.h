#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

typedef int ElementType;

class Node {
public:
    ElementType data;
    Node *next;

    Node(ElementType value, Node *link = nullptr)
            : data(value), next(link) {}
};

typedef Node *NodePointer;

class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    LinkedList(const LinkedList &origList);

    int getLength() const;

    const LinkedList &operator=(const LinkedList &rightHandSide);

    void insertHead(ElementType value);

    void insertTail(ElementType value);

    bool empty() const;

    void display(ostream &out) const;

    Node *getElement(int pos) const;

    Node *locateElem(ElementType item) const;

    void insert(ElementType item, int pos);

    void erase(int pos);

public:
    NodePointer head;
    int length;
};

ostream &operator<<(ostream &out, const LinkedList &list);

#endif //DATASTRUCTURE_LINKLIST_H
