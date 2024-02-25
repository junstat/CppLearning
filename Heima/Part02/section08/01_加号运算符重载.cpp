#include <iostream>

using namespace std;

class Person {
public:
    Person(int a, int b) : a(a), b(b) {}

    int a;
    int b;

    // 成员函数重载+
    // Person operator+(Person &p) {
    //     return Person(a + p.a, b + p.b);
    // }

};

// 2. 全局函数重载+
Person operator+(Person &p1, Person &p2) {
    return Person(p1.a + p2.a, p1.b + p2.b);
}

Person operator+(Person &p1, int n) {
    return Person(p1.a + n, p1.b + n);
}

void test1() {
    Person p1(1, 2), p2(3, 4);
    auto p3 = p1 + p2;
    // 成员函数重载本质调用
    // auto p3 = p1.operator+(p2);
    // 全局重载本质调用
    // auto p3 = operator+(p1, p2);
    cout << p3.a << ", " << p3.b << endl; // 输出 4,6

    auto p4 = p3 + 10;
    cout << p4.a << ", " << p4.b << endl; // 输出 14,16


}

int main() {
    test1();
    return 0;
}