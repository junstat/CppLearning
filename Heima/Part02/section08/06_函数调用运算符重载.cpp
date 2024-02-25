#include <iostream>
#include <string>

using namespace std;

// 打印输出类
class MyPrint {
public:
    // 重载函数调用运算符
    void operator()(const string &text) {
        cout << text << endl;
    }
};

// 仿函数非常灵活，没有固定的写法
class MyAdd {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

void test1() {
    MyPrint myPrint;
    // 由于使用起来非常类似函数调用，因此成为仿函数
    myPrint("Hello, world!"); // 输出 "Hello, world!"

    // MyAdd add;
    // cout << "10 + 20 = " << add(10, 20) << endl;

    // 匿名函数对象
    cout << "10 + 20 = " << MyAdd()(10, 20) << endl;
}

int main() {
    test1();
    return 0;
}