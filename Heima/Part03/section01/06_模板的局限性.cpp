#include <iostream>
#include <string>

using namespace std;

// 模板的局限性
// 模板并不是万能的，有些特定数据类型， 需要用具体化方式做特殊实现
class Person {
public:
    Person(string name, int age) : name(name), age(age) {}

    string name;
    int age;
};

// 对比两个数据是否相等
template<class T>
bool compare(T &a, T &b) {
    return a == b;
}

// 利用具体化Person的版本实现，具体化优先调用
template<>
bool compare(Person &p1, Person &p2) {
    return p1.name == p2.name && p1.age == p2.age;
}

void test1() {
    int a = 10;
    int b = 20;
    cout << compare(a, b) << endl;
}

void test2() {
    Person p1("Tom", 10);
    Person p2("Tom", 10);

    cout << compare(p1, p2) << endl;
}

int main() {
    test2();
    return 0;
}