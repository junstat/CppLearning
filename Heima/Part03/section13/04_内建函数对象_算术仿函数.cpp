#include <iostream>
#include <functional>  // 内建函数对象头文件

using namespace std;

// negate 一元仿函数 取反
void test1() {
    negate<int> n;
    cout << n(50) << endl;
}

// plus 二元仿函数 加法
void test2() {
    plus<int> p;
    cout << p(10, 20) << endl;
}

int main() {
    test1();
    test2();
    return 0;
}