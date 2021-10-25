#include "Stack.h"

Stack::Stack()
        : top(-1) {}

bool Stack::empty() const { return (top == -1); }

void Stack::push(const StackElement &value) {
    if (top < MaxSize - 1)
        data[++top] = value;
    else {
        cerr << "*** Stack full -- can't add new value ***\n"
                "Must increase value of MaxSize in Stack.h\n";
        exit(1);
    }
}

void Stack::display(ostream &out) const {
    for (int i = top; i >= 0; i--)
        out << data[top] << "  ";
}

StackElement Stack::getTop() const {
    if (!empty())
        return data[top];
    else {
        cerr << "*** Stack is empty -- returning garbage value ***\n";
        return data[MaxSize - 1];
    }
}

void Stack::pop() {
    if (!empty()) top--;
    else cerr << "*** Stack is empty -- can't remove a value ***\n";
}

