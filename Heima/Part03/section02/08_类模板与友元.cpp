#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person;

// 2. 全局函数类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    cout << "name: " << p.name << ",age: " << p.age << endl;
}

// 通过全局函数 打印Person信息
template<class T1, class T2>
class Person {
    friend void printPerson(Person<T1, T2> &p) {
        cout << "name: " << p.name << ", age: " << p.age << endl;
    }

    // 全局函数 类外实现
    // 加空模板参数列表
    // 如果全局函数 是类外函数 需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> &p);


public:
    Person(T1 name, T2 age) : name(name), age(age) {}

private:
    T1 name;
    T2 age;
};

// 1. 全局函数在类内实现
void test1() {

    Person<string, int> p("Tom", 18);
    printPerson(p);
}


void test2() {
    Person<string, int> p("Jerry", 19);
    printPerson2(p);
}

int main() {
    test2();
    return 0;
}