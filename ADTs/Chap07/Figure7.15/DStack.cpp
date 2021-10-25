#include <cassert>
#include <new>
#include "DStack.h"

Stack::Stack(int numElements)
{
  assert(numElements > 0);
  myCapacity = numElements;

  myArray = new(nothrow) StackElement[myCapacity];
  if (myArray != 0)
    myTop = -1;
  else
  {
    cerr << "Inadequate memory to allocate stack \n"
            " -- terminating execution\n";
    exit(1);
  }
}

Stack::Stack(const Stack &original)
    : myCapacity(original.myCapacity), myTop(original.myTop)
{
  myArray = new(nothrow) StackElement[myCapacity];
  if (myArray != 0)
    for (int pos = 0; pos <= myTop; pos++)
      myArray[pos] = original.myArray[pos];
  else
  {
    cerr << "*Inadequate memory to allocate stack ***\n";
    exit(1);
  }
}

Stack::~Stack()
{
  delete[] myArray;
}

const Stack &Stack::operator=(const Stack &rightHandSide)
{
  if (this != &rightHandSide)
  {
    if (myCapacity != rightHandSide.myCapacity)
    {
      delete[] myArray;
      myCapacity = rightHandSide.myCapacity;
      myArray = new StackElement[myCapacity];
      if (myArray == 0)
      {
        cerr << "*** Inadequate memory ***\n";
        exit(1);
      }
    }
    myTop = rightHandSide.myTop;
    for (int pos = 0; pos <= myTop; pos++)
      myArray[pos] = rightHandSide.myArray[pos];
  }
  return *this;
}

bool Stack::empty() const
{
  return (myTop == -1);
}

void Stack::push(const StackElement &value)
{
  if (myTop < myCapacity - 1)
  {
    ++myTop;
    myArray[myTop] = value;
  }
  else
  {
    cerr << "*** Stack full -- can't add new value ***\n"
            "Must increase the stack's capacity.\n";
    exit(1);
  }
}

void Stack::display(ostream &out) const
{
  for (int i = myTop; i >= 0; i--)
    out << myArray[i] << endl;
}

StackElement Stack::top() const
{
  if (!empty())
    return (myArray[myTop]);
  else
  {
    cerr << "*** Stack is empty -- returning garbage value ***\n";
    StackElement garbage;
    return garbage;
  }
}

void Stack::pop()
{
  if (!empty())
    myTop--;
  else
    cerr << "*** Stack is empty -- can't remove a value ***\n";
}
