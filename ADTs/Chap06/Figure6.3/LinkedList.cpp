
#include "LinkedList.h"

LinkedList::LinkedList()
        : mySize(0) {
    first = new Node(0);
}

void LinkedList::insertHead(ElementType value) {
    auto ptr = new Node(value);
    ptr->next = first->next;
    first->next = ptr;
    mySize++;
}

void LinkedList::insertTail(ElementType value) {
    auto ptr = new Node(value);
    auto prev = first;
    while (prev->next)
        prev = prev->next;
    prev->next = ptr;
    mySize++;
}

int LinkedList::getSize() const {
    return mySize;
}

bool LinkedList::empty() const {
    // or
    // return mySize == 0;
    return first->next == nullptr;
}


void LinkedList::display(ostream &out) const {
    NodePointer ptr;
    for (ptr = first->next; ptr != nullptr; ptr = ptr->next)
        cout << ptr->data << " ";
    cout << endl;
}

ostream &operator<<(ostream &out, const LinkedList &aList) {
    aList.display(out);
    return out;
}