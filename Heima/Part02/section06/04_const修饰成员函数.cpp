#include <iostream>

using namespace std;

// 常函数:
// 成员函数后加const
// 常函数内不可以修改成员属性
// 成员属性声明时加关键字mutable，在常函数中可以修改

// 常对象:
// 声明对象前加const
// 常对象只能调用常函数

class Person {
public:

    Person() {}

    // this指针的本质是指针常量 指针的指向是不可以修改的
    // Person * const this
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const { // <=>  const Person * const this
        // this = nullptr; //  错误，不能修改this指针
        // this->m_A = 100;
        this->m_B = 100;
        cout << "A = " << this->m_A << endl;
    }

    void func() {

    }

    int m_A;
    mutable int m_B;
};


int main() {
    const Person p;
    // p.m_B = 200;
    // 常对象只能调用常函数
    p.showPerson();
    // p.func();
    return 0;
}