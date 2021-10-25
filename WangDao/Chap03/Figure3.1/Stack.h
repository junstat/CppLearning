#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

const int MaxSize = 128;
typedef int StackElement;

class Stack {
public:
    Stack();

    bool empty() const;

    void push(const StackElement &value);

    void display(ostream &out) const;

    StackElement getTop() const;

    void pop();

private:
    StackElement data[MaxSize];
    int top;
};


#endif //DATASTRUCTURE_STACK_H
