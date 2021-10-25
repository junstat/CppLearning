#include "Queue.h"

Queue::Queue()
        : front(0), rear(0) {}

bool Queue::empty() const {
    return front == rear;
}

void Queue::enqueue(const QueueElement &value) {
    int newRear = (rear + 1) % MaxSize;
    if (newRear != front) {
        data[newRear] = value;
        rear = newRear;
    } else {
        cerr << "*** Queue full -- can't add new value ***\n"
                "Must increase value of MaxSize in Queue.h\n";
        exit(1);
    }
}

void Queue::display(ostream &out) const {
    for (int i = front; i != rear; i = (i + 1) % MaxSize)
        out << data[i] << "  ";
    cout << endl;
}

QueueElement Queue::getFront() const {
    if (!empty())
        return data[front];
    else {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}

void Queue::dequeue() {
    if (!empty())
        front = (front + 1) % MaxSize;
    else {
        cerr << "*** Queue is empty -- "
                "can't remove a value ***\n";
        exit(1);
    }
}
