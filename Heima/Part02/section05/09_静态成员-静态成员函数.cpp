#include <iostream>

using namespace std;

// 静态成员函数
//     所有对象共享同一个函数
//     静态成员函数只能访问静态成员
class Person {
public:
    static void func() {
        m_A = 200; // 静态成员函数可以访问静态成员变量
        // m_B = 300; // 静态成员函数不可以访问非静态成员变量
        cout << "static void func调用" << endl;
    }

    static int m_A;
    int m_B;
};

int Person::m_A = 100;

void test1() {
    // 1. 通过对象访问
    Person p;
    p.func();
    // 2. 通过类名访问
    Person::func();
}

int main() {
    test1();
    return 0;
}