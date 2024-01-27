#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {}

    virtual void Print() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    void Print() { cout << "Derived" << endl; }
};

void Test1(Base &base) { base.Print(); }

void Test2(Base base) { base.Print(); }

int main() {
    Base *p = new Derived();
    Test1(*p);
    Test2(*p);
    delete p;
    return 0;
}