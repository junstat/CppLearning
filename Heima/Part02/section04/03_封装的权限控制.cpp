#include <iostream>
#include <string>

using namespace std;

// 访问权限
// public: 成员 在类内可以访问，在类外可以访问
// protected: 成员 在类内可以访问，在类外不可以访问 子类中也可以访问父类中的protected成员
// private: 成员 在类内可以访问，在类外不可以访问 子类不可以访问父类中的private成员
class Person {
public:
    string name;
protected:
    string car;
private:
    int password;

public:
    void func() {
        name = "张三";
        car = "特斯拉";
        password = 123456;
    }
};

int main() {
    Person p1;
    p1.func();
    p1.name = "李思";
    // p1.car = "宝马";
    // p1.password = 12356712;
    return 0;
}