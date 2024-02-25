#include <iostream>

using namespace std;



class Person {
public:
// 静态成员
//     所有对象共享同一份数据
//     在编译阶段分配内存
//     类内声明，类外初始化
    static int m_A;

private:
    // 静态成员变量也有访问权限
    static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;

void test1() {
    Person p;
    cout << p.m_A << endl;

    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}

void test2() {
    // 静态成员变量 不属于某个对象上，所有对象共享同一份数据
    // 因此静态成员变量有两种访问方式

    // 1. 通过对象进行访问
    // Person p;
    // cout << p.m_A << endl;

    // 2. 通过类名进行访问
    cout << Person::m_A << endl;
    // 类外访问不到私有静态成员
    // cout << Person::m_B << endl;
}

int main() {
    test2();
    return 0;
}