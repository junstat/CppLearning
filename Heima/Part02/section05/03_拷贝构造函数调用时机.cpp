#include <iostream>

using namespace std;

// C++中拷贝构造函数调用时机通常有三种情况:
class Person {
public:
    Person() {
        cout << "默认构造函数调用" << endl;
    }

    Person(int age) : m_Age(age) {
        cout << "有参构造函数调用" << endl;
    }

    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person() {
        cout << "析构函数调用" << endl;
    }

    int m_Age;
};


// 1. 使用一个已经创建的对象来初始化一个新创建的对象
void test1() {
    Person p1(10);
    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << endl;
}

// 2. 值传递的方式给函数传值
void doSomething(Person p) {
    cout << p.m_Age << endl;
}

void test2() {
    Person p(20);
    doSomething(p);
}

// 3. 以值方式返回局部对象
// 在优化情况下，编译器可能会进行返回值优化（Return Value Optimization，简称 RVO），
// 这是一种常见的优化技术，用于避免不必要的对象拷贝。
// 在这种情况下，编译器可能会在调用 doSomething2 函数时，
// 直接在调用 test3 函数的上下文中创建 Person 对象，
// 而不是在 doSomething2 函数内部创建，然后将其拷贝给 test3 函数内的局部变量 p。
Person doSomething2() {
    Person p;
    cout << &p << endl;
    return p;
}

void test3() {
    Person p = doSomething2();
    cout << &p << endl;
}

int main() {
    test3();
    return 0;
}