#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        a = 100;
    }

    void func() {
        cout << "Base func()" << endl;
    }

    int a;
};

class Son : public Base {
public:
    Son() {
        a = 200;
    }

    void func() {
        cout << "Son func()" << endl;
    }

    int a;
};

void test1() {
    Son s;
    cout << "Son 中的a = " << s.a << endl;
    // 如果通过子类对象，放到父类中同名成员，需要加作用域
    cout << "Base 中的a = " << s.Base::a << endl;

    // 如果子类中出现和父类同名的成员函数，子类的同名成员会覆盖父类的同名成员
    // 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    s.func();
    s.Base::func();
}

int main() {
    test1();
    return 0;
}