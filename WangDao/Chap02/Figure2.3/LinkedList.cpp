#include "LinkedList.h"

LinkedList::LinkedList()
        : length(0) {
    head = new Node(0);
}

LinkedList::LinkedList(const LinkedList &origList)
        : length(origList.length), head(nullptr) {
    if (!origList.empty()) {
        head = new Node(origList.head->data);
        NodePointer lastPtr = head, origPtr = origList.head->next;

        while (origPtr) {
            lastPtr->next = new Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}

LinkedList::~LinkedList() {
    NodePointer currPtr = head, nextPtr;
    while (currPtr) {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

int LinkedList::getLength() const {
    return length;
}

const LinkedList &LinkedList::operator=(const LinkedList &rightHandSide) {
    if (this != &rightHandSide) {
        this->~LinkedList();
        if (rightHandSide.empty())
            head = nullptr;
        else {
            head = new Node(rightHandSide.head->data);

            // Set pointers to run through the link lists
            NodePointer lastPtr = head, rhsPtr = rightHandSide.head->next;

            while (rhsPtr) {
                lastPtr->next = new Node(rhsPtr->data);
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

void LinkedList::insertHead(ElementType value) {
    auto ptr = new Node(value);
    ptr->next = head->next;
    head->next = ptr;
    length++;
}

void LinkedList::insertTail(ElementType value) {
    auto ptr = new Node(value);
    auto prev = head;
    while (prev->next)
        prev = prev->next;
    prev->next = ptr;
    length++;
}

bool LinkedList::empty() const {
    return head->next == nullptr;
}

void LinkedList::display(ostream &out) const {
    NodePointer ptr;
    for (ptr = head->next; ptr != nullptr; ptr = ptr->next)
        cout << ptr->data << "  ";
    cout << endl;
}

ostream &operator<<(ostream &out, const LinkedList &list) {
    list.display(out);
    return out;
}

// 按序号查找结点值
Node *LinkedList::getElement(int pos) const {
    int count = 1;      // 计数器，初始为1
    NodePointer ptr = head->next;
    if (pos == 0)
        return head;    // 若pos等于0，则返回头结点
    if (pos < 1)
        return nullptr; // 若i无效，则返回nullptr
    while (ptr && count < pos) {
        ptr = ptr->next;
        count++;
    }
    return ptr;
}

// 按值查找表结点
Node *LinkedList::locateElem(ElementType item) const {
    Node *ptr = head->next;
    while (ptr && ptr->data != item)
        ptr = ptr->next;
    return ptr;
}

// 插入结点操作
void LinkedList::insert(ElementType item, int pos) {
    NodePointer prev = getElement(pos - 1);
    if (prev) {
        auto newNode = new Node(item);
        newNode->next = prev->next;
        prev->next = newNode;
    } else {
        cerr << "*** Not found No." << pos << " Node in list. List unchanged.\n";
        exit(1);
    }
}

// 删除结点操作
void LinkedList::erase(int pos) {
    NodePointer prev = getElement(pos - 1);
    NodePointer q = prev->next;
    prev->next = q->next;
    delete q;
}

