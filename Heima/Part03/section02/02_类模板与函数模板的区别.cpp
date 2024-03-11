#include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType=int>
class Person {
public:

    Person(NameType name, AgeType age) : name(name), age(age) {}

    void showPerson() {
        cout << "name: " << name << " age: " << age << endl;
    }

    NameType name;
    AgeType age;
};

// 1. 类模板没有自动类型推导方式
void test1() {
    // Person p("张山", 20);
    Person<string, int> p("张山", 20);
    p.showPerson();
}

// 2. 类模板在模板参数列表中可以有默认参数
void test2() {
    Person<string> p("张山", 20);
    p.showPerson();
}

int main() {
    test2();
    return 0;
}