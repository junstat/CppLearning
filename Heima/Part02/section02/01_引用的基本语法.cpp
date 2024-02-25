#include <iostream>

using namespace std;

int main() {
    // 引用的基本语法
    // 数据类型 &引用名 = 变量名;
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl; // 输出 a = 10
    cout << "b = " << b << endl; // 输出 b = 10

    b = 100;
    cout << "a = " << a << endl; // 输出 a = 10
    cout << "b = " << b << endl; // 输出 b = 10
    return 0;
}