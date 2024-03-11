#include <iostream>

using namespace std;

// 普通函数与函数模板调用规则
// 1. 如果函数模板和普通函数都可以实现，优先调用普通函数
// 2. 可以通过空模板参数列表强 制调用 函数模板
// 3. 函数模板可以发生函数重载
// 4. 如果函数模板可以产生更好的匹配，优先调用函数模板

void print(int a, int b) {
    cout << "调用的普通函数" << endl;
}

template<class T>
void print(T a, T b) {
    cout << "调用的函数模板" << endl;
}

int main() {
    print(10, 20); // 调用普通函数
    print<>(10, 20); // 强制调用函数模板
    print(10.5, 20.5); // 调用函数模板
    return 0;
}