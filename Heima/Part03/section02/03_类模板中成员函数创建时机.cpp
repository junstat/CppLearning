#include <iostream>

using namespace std;

// 类模板中成员函数在调用时才创建

class Person1 {

public:
    void showPerson1() {
        cout << "showPerson1" << endl;
    }
};

class Person2 {

public:
    void showPerson2() {
        cout << "showPerson2" << endl;
    }
};


template<class T>
class MyClass {
public:
    T obj;

    void func1() {
        obj.showPerson1();
    }

    void func2() {
        obj.showPerson2();
    }
};

void test1() {
    MyClass<Person1> m;
    m.func1();
    // m.func2();
}

int main() {
    test1();
    return 0;
}