#include <iostream>

using namespace std;

// 对象的初始化和清理
class Person {
public:
    // 1. 构造函数 进行初始化操作
    Person() {
        cout << "Person()" << endl;
    }

    // 2. 析构函数 进行清理工作
    ~Person() {
        cout << "~Person()" << endl;
    }

};

// 构造和析构函数都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test1() {
    Person p; // 在栈上的数据，test1执行完之后，释放这个对象
}

int main() {
    // test1();
    Person p;
    system("pause");
    return 0;
}