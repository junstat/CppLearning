#include <iostream>

using namespace std;

// 浅拷贝: 简单的赋值拷贝操作
// 深拷贝: 在堆区重新申请空间，进行拷贝操作

class Person {
public:
    Person() {
        cout << "无参构造函数调用" << endl;
    }

    Person(int age, int height) {
        m_Age = age;
        m_Height = new int(height);
        cout << "有参构造函数调用" << endl;
    }

    Person(const Person &p) {
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person() {
        if (m_Height != nullptr) {
            delete m_Height;
            m_Height = nullptr;
        }
        cout << "析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height;
};

// 浅拷贝带来的问题，堆区内存重复释放 -- 使用深拷贝解决
// 如果属性有在堆区开辟的，需要自己提供拷贝构造函数和赋值运算符
void test1() {
    Person p1(18, 168);
    cout << "p1的年龄为：" << p1.m_Age << ", p1的身高为: " << *p1.m_Height << endl;

    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_Age << ", p2的身高为: " << *p2.m_Height << endl;
}

int main() {
    test1();
    return 0;
}