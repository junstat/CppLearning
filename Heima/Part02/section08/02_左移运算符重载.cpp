#include <iostream>

using namespace std;

class Person {
    friend ostream &operator<<(ostream &os, const Person &p);

public:
    Person(int a, int b) : a(a), b(b) {}

    // 利用成员函数重载左移运算符 p.operator<<(cout) 简化版本 p << cout
    // 不会利用成员函数重载<<，因为无法实现 cout

private:
    int a;
    int b;
};

// 只能利用全局函数重载左移运算符
ostream &operator<<(ostream &os, const Person &p) {
    os << "Person [a=" << p.a << ", b=" << p.b << "]";
    return os;
}

int main() {
    Person p(10, 20);
    cout << p << endl;
    return 0;
}