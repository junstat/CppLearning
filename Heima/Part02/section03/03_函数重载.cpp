#include <iostream>

using namespace std;

// 作用: 函数名可以相同，提高复用性
// 重载满足的条件:
// 1. 同一个作用域下
// 2. 函数名称相同
// 3. 函数参数类型不同，或者参数数量不同，或者参数顺序不同
// 注意: 重载和返回值类型无关

void func() {
    cout << "func的调用" << endl;
}

void func(int a) {
    cout << "func(" << a << ")的调用" << endl;
}

void func(double a) {
    cout << "func(" << a << ")的调用" << endl;
}

void func(int a, double b) {
    cout << "func(" << a << ", " << b << ")的调用" << endl;

}

int main() {
    func();
    func(10);
    func(20.2);
    func(10, 3.14);
    return 0;
}