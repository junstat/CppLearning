#include <iostream>

using namespace std;

// 继承中的构造和析构顺序
class Base {
public:
    Base() { cout << "Base constructor" << endl; }

    ~Base() { cout << "Base destructor" << endl; }
};

class Son : public Base {
public:
    Son() { cout << "Son constructor" << endl; }

    ~Son() { cout << "Son destructor" << endl; }
};

int main() {
    // 继承中的构造和析构的顺序如下:
    // 先构造父类，再构造子类，析构的顺序与构造的顺序相反
    Son s;

    return 0;
}