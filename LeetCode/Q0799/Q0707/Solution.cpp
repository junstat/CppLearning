#include "ListNode.h"

class MyLinkedList {
public:
    MyLinkedList() {
        head = new ListNode(0);
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index > length) return -1;
        auto p = head->next;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p->val;
    }

    void addAtHead(int val) {
        auto newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        length++;
    }

    void addAtTail(int val) {
        auto p = head;
        while (p->next) p = p->next;
        auto newNode = new ListNode(val);
        newNode->next = p->next;
        p->next = newNode;
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        auto p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        auto newNode = new ListNode(val);
        newNode->next = p->next;
        p->next = newNode;
        length++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > length) return;
        auto p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        auto q = p->next;
        p->next = q->next;
        delete q;
        length--;
    }

    void display(ostream &out) const {
        for (auto p = head->next; p; p = p->next)
            out << p->val << "  ";
        cout << endl;
    }

private:
    ListNode *head;
    int length;
};
