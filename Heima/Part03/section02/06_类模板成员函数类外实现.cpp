#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age);

    void show() ;

    T1 name;
    T2 age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
    this->name = name;
    this->age = age;
}

template<class T1, class T2>
void Person<T1, T2>::show() {
    cout << "name:" << this->name << " age:" << this->age << endl;
}

void test01() {
    Person<string, int> p("Tom", 10);
    p.show();
}


int main() {
    test01();
    return 0;
}