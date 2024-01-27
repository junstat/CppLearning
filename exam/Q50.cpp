#include <iostream>

using namespace std;

struct A {
    A() = default;

    A(const A &r) {
        cout << "copy constructor" << endl;
    }
};


void testA() {
    A a, b;
    b = a;
    cout << "end A .........." << endl;
}

void testB() {
    A a;
    A b(a);
    cout << "end B .........." << endl;
}

void testC() {
    A a;
    A b = a;
    cout << "end C .........." << endl;
}

void testD() {
    A a = A();
    cout << "end D .........." << endl;
}

int main() {
    testA();
    testB();
    testC();
    testD();
    return 0;
}