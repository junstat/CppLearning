#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_LQUEUE_H
#define DATASTRUCTURE_LQUEUE_H

typedef int QueueElement;

class Node {
public:
    QueueElement data;
    Node *next;

    Node(QueueElement value, Node *link = nullptr)
    : data(value), next(link) {}
};

typedef Node *NodePointer;

class Queue {
public:
    Queue();

    Queue(const Queue &original);

    ~Queue();

    const Queue &operator=(const Queue &rightHandSide);

    bool empty() const;

    void enqueue(const QueueElement &value);

    void display(ostream &out) const;

    QueueElement getFront() const;

    void dequeue();

private:
    NodePointer front, rear;
};

#endif //DATASTRUCTURE_LQUEUE_H
