#include <iostream>

using namespace std;

// typename 可以替换成 class
template<class T>
void swapN(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

// 1、自动类型 推导，必须推导出一致的数据类型T才可以使用
void test1() {
    int a = 10, b = 20;
    swapN(a, b);
    cout << "a = " << a << ", b = " << b << endl;
}

// 2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
    cout << "func调用" << endl;
}

void test2() {
    // func();  // 错误
    func<int>();  // 显式指定模板类型
}

int main() {
    test2();
    return 0;
}