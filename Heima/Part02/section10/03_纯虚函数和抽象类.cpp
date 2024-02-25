#include <iostream>

using namespace std;

// 纯虚函数语法: virtual  返回类型 函数名(参数列表) = 0;
// 当类中有了纯虚函数，这个类也称为抽象类
// 抽象类特点:
// 1. 不能实例化对象
// 2. 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class Base {
public:
    virtual void func() = 0; // 纯虚函数
};

class Son : public Base {
public:
    void func() override {
        cout << "Son::func()" << endl;
    }
};

void test1() {
    // Base b;  // 抽象类无法实例化对象
    // new Base; //  抽象类无法实例化对象

    // Son s; // 子类必须重写纯虚函数，否则也属于抽象类

    Base *base = new Son;
    base->func();

}

int main() {
    test1();
    return 0;
}