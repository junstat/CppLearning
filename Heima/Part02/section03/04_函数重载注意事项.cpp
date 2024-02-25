#include <iostream>

using namespace std;
// 函数重载注意事项
// 1. 引用作为重载条件

void func(int &a) {
    cout << "func(int&)" << endl;
}

void func(const int &a) {
    cout << "func(const int&)" << endl;
}

// 2. 函数重载碰到函数默认值
void func2(int a) {
    cout << "func2(int)" << endl;
}

void func2(int a, int b = 10) {
    cout << "func2(int, int)" << endl;
}

int main() {
    // int a = 10;
    // func(a); // 调用func(int&)
    // func(10);

    // func2(10); // 当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
    func2(10, 20);
    return 0;
}