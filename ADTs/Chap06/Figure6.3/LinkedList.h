#include <iostream>

using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

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

    const LinkedList &operator=(const LinkedList &rightHandSide);

    void insertHead(ElementType value);

    void insertTail(ElementType value);

    int getSize() const;

    bool empty() const;

    void display(ostream &out) const;

private:
    NodePointer first;    // points to first node
    int mySize;           // number of nodes
};

ostream &operator<<(ostream &out, const LinkedList &aList);

#endif