#include <iostream>

using namespace std;

class Person {
    int m_A; // 非静态成员变量 属于类对象上
    static int m_B;  // 静态成员变量 不属于类对象上

    // 非静态成员函数，不属于类对象上
    void func() {
        cout << "func()" << endl;
    }

    // 静态成员函数，不属于类对象上
    static void func2() {
        cout << "func2()" << endl;
    }
};

void test1() {
    Person p;
    // 空对象占用内存空间: 1
    // C++编译器会给每个空对象分配1字节的内存空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    // 加上非静态成员 m_A后，占用内存空间为 4
    cout << sizeof(p) << endl;
}

int main() {
    test1();
    return 0;
}