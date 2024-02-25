#include <iostream>

using namespace std;

class Base {
public:
    static int a;

    static void func() {
        cout << "Base func" << endl;
    }
};

int Base::a = 10;


class Son : public Base {
public:
    static int a;

    static void func() {
        cout << "Son func" << endl;
    }
};

int Son::a = 20;


void test1() {
    // 1. 通过对象访问
    Son s;
    cout << "Base::a = " << s.Base::a << endl;
    cout << "Son::a = " << s.a << endl;
    s.func();
    s.Base::func();

    // 2. 通过类名访问
    cout << "Son::Base::a = " << Son::Base::a << endl;
    cout << "Son::a = " << Son::a << endl;
    // 子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
    // 如果想访问父类中被隐藏同名成员函数，需要加作用域
    Son::func();
    Son::Base::func();
}

int main() {
    test1();
    return 0;
}