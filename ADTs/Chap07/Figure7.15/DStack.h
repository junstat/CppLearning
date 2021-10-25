#include <iostream>

using namespace std;

#ifndef DATAST
#define DATAST

typedef int StackElement;

class Stack
{
public:
  Stack(int numElements = 128);

  Stack(const Stack &original);

  ~Stack();

  const Stack &operator=(const Stack &rightHandSide);

  bool empty() const;

  void push(const StackElement &value);

  void display(ostream &out) const;

  StackElement top() const;

  void pop();

private:
  int myCapacity,             // capacity of stack
      myTop;                  // top of stack
  StackElement *myArray;      // dynamic array to store elements
};

#endif
