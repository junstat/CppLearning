#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

//const int MaxSize = 128;

typedef int QueueElement;

class Queue {
public:
    Queue();

    bool empty() const;

    void enqueue(const QueueElement &value);

    void display(ostream &out) const;

    QueueElement getFront() const;

    void dequeue();

private:
    int front, rear;
    QueueElement data[MaxSize];
};


#endif //DATASTRUCTURE_QUEUE_H
