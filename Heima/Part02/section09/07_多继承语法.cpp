#include <iostream>

using namespace std;

class Base1 {
public :
    Base1() {
        a = 100;
    }

    int a;
};

class Base2 {
public:
    Base2() {
        a = 200;
    }

    int a;
};

class Son : public Base1, public Base2 {
public:
    Son() {
        c = 300;
        d = 400;
    }

    int c;
    int d;
};

void test1() {
    Son s;
    cout << "sizeof(Son) = " << sizeof(s) << endl; // 16

    // 当父类中出现了同名成员，需要加作用域区分
    cout << "Base1::a = "<< s.Base1::a << endl; // 100
    cout << "Base2::a = "<< s.Base2::a << endl; // 200
}

int main() {
    test1();
    return 0;
}