#include "LQueue.h"

Queue::Queue()
        : front(nullptr), rear(nullptr) {}

Queue::Queue(const Queue &original) {
    front = rear = nullptr;
    if (!original.empty()) {
        front = rear = new Node(original.getFront());

        NodePointer origPtr = original.front->next;

        while (origPtr) {
            rear->next = new Node(origPtr->data);
            rear = rear->next;
            origPtr = origPtr->next;
        }
    }
}

Queue::~Queue() {
    NodePointer prev = front, ptr;

    while (prev) {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

const Queue &Queue::operator=(const Queue &rightHandSide) {
    if (this != &rightHandSide) {
        this->~Queue();
        if (rightHandSide.empty())
            front = rear = nullptr;
        else {
            // copy first node
            front = rear = new Node(rightHandSide.getFront());

            // Set pointer to run through rightHandSide's linked list
            NodePointer rhsPtr = rightHandSide.front->next;

            while (rhsPtr) {
                rear->next = new Node(rhsPtr->data);
                rear = rear->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

bool Queue::empty() const {
    return (front == nullptr);
}

void Queue::enqueue(const QueueElement &value) {
    NodePointer newPtr = new Node(value);
    if (empty())
        front = rear = newPtr;
    else {
        rear->next = newPtr;
        rear = rear->next;
    }
}

void Queue::display(ostream &out) const {
    NodePointer ptr;
    for (ptr = front; ptr != nullptr; ptr = ptr->next)
        out << ptr->data << "  ";
    out << endl;
}

QueueElement Queue::getFront() const {
    if (!empty())
        return front->data;
    else {
        cerr << "*** Queue is empty "
                "-- returning garbage ***\n";
        QueueElement *temp = new (QueueElement);
        QueueElement garbage = *temp;
        delete temp;
        return garbage;
    }
}

void Queue::dequeue() {
    if (!empty()) {
        NodePointer ptr = front;
        front = front->next;
        delete ptr;
        if (front == nullptr)   // queue is now empty
            rear = nullptr;
    } else
        cerr << "*** Queue is empty -- can't remove a value ***\n";
}