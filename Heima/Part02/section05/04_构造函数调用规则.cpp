#include <iostream>

using namespace std;

// 默认情况下，C++编译器至少给一个类添加3个函数
// 1. 默认构造函数(无参，函数体为空)
// 2. 默认析构函数(无参，函数体为空)
// 3. 默认拷贝构造函数，对属性进行值拷贝

// 构造函数调用规则如下
// 如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
// 如果用户定义拷贝构造，C++不再提供其他构造函数

class Person {
public:
    // Person() {
    //     cout << "Person()" << endl;
    // }

    // Person(int age) {
    //     m_Age = age;
    //     cout << "Person(int age)" << endl;
    // }

    Person(const Person &p) {
        cout << "Person(const Person &p)" << endl;
    }

    ~Person() {
        cout << "~Person()" << endl;
    }

    int m_Age;
};

void test1() {
    // Person p(19);
    // p.m_Age = 19;

    // Person p2(p);
    // cout << "p2.m_Age = " << p2.m_Age << endl;

}

void test2() {
    // Person p(20);
    // Person p1(p);
    // cout << "p1.m_Age = " << p1.m_Age << endl;
}

void test3() {
    // Person p;
}

int main() {
    test2();
    return 0;
}