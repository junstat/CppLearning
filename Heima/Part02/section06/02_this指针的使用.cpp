#include <iostream>

using namespace std;

// 1. 解决名称冲突

// 2. 返回对象本身用 *this

class Person {
public:
    Person(int age) : age(age) {}

    Person &setAge(int age) {
        this->age = age;
        return *this;
    }

    int age;
};

int main() {
    Person p(30);
    auto p1 = p.setAge(20);
    cout << &p << endl;
    cout << &p1 << endl;
    return 0;
}