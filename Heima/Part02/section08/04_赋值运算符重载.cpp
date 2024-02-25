#include <iostream>

using namespace std;

/**
 * C++ 编译器至少给一个类添加4个函数
 * 1. 默认够造函数
 * 2. 默认析构函数
 * 3. 默认拷贝构造函数，对属性值进行拷贝
 * 4. 复制运算符 operator=，对属性值进行拷贝
 * 如果类中有属性指向堆区，做复制操作时也会出现深浅拷贝问题
 */

class Person {
public:
    Person(int age) {
        this->age = new int(age);
    }

    ~Person() {
        if (this->age != nullptr) {
            delete age;
            age = nullptr;
        }
    }

    Person &operator=(const Person &p) {
        if (this->age != nullptr) {
            delete age;
            this->age = nullptr;
        }
        this->age = new int(*p.age);
        return *this;
    }

    int *age;
};

void test1() {
    Person p1(18);
    Person p2(20);
    p2 = p1;  // 赋值操作
    cout << "p1的年龄为: " << *p1.age << endl;
    cout << "p2的年龄为: " << *p2.age << endl;
}

int main() {
    test1();
    return 0;
}