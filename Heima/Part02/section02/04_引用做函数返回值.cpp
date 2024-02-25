#include <iostream>

using namespace std;

// 引用做函数返回值
// 1. 不要返回局部变量的引用
int &test1() {
    int a = 10;
    return a;
}

// 2. 函数的调用可以做为左值
int &test2() {
    static int a = 10;
    return a;
}

int main() {
    // auto ref = test1();
    // cout << ref << endl;

    int &ref2 = test2();
    cout << ref2 << endl;
    cout << ref2 << endl;
    cout << ref2 << endl;
    cout << "------------------" << endl;
    test2() = 1000;
    cout << ref2 << endl;
    cout << ref2 << endl;

    return 0;
}