#include <iostream>
#include <utility>

using namespace std;

template<class T, class U>
class Person {
public:
    Person(T name, U age) : name(std::move(name)), age(age) {}

    void showPerson() {
        cout << "name: " << name << " age: " << age << endl;
    }

    T name;
    U age;
};

// 1、指定传入类型
void printPerson(Person<string, int> &p) {
    p.showPerson();
}

void test1() {
    Person<string, int> p("孙悟空", 100);
    printPerson(p);
}

// 2、参数模板化
template<class T, class U>
void printPerson2(Person<T, U> &p) {
    p.showPerson();
    cout << "T的类型为: " << typeid(T).name()
         << "， U的类型为: " << typeid(U).name() << endl;
}

void test2() {
    Person<string, int> p("猪八戒", 20);
    printPerson2(p);
}

// 3、整个类模板化
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T的类型为:"
         << typeid(T).name() << endl;
}

void test3() {
    Person<string, int> p("沙悟净", 30);
    printPerson3(p);
}

int main() {
    test3();
    return 0;
}