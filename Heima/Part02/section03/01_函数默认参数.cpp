#include <iostream>

using namespace std;

// 函数默认参数
int func(int a, int b = 20, int c = 30) {
    return a + b + c;
}

// 注意事项
// 1. 如果某个位置已经有了默认参数，那么这个位置往后，从左到右都必须有默认参数
// int func2(int a = 10, int b, int c, int d) {
// }

// 2. 如果函数声明有默认参数，函数实现就不能有默认参数
// 声明和实现只能有一个有默认参数
// int func2(int a = 10, int b = 20);
//
// int func2(int a  = 10, int b = 20) {
//     return a + b;
// }



int main() {
    cout << func(10) << endl;  // 输出 60
    cout << func(10, 30) << endl; // 输出 60
    cout << func(10, 20, 40) << endl; // 输出 70
    return 0;
}