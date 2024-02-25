#include <iostream>

using namespace std;

// 全局变量
int g_a = 30;
int g_b = 40;

// const修饰的全局变量, 全局常量
const int g_c = 50;

int main() {

    // 全局区: 全局变量、静态变量、常量
    // 创建普通局部变量
    int a = 10, b = 20;
    cout << "局部变量a的地址:" << &a << endl;
    cout << "局部变量b的地址:" << &b << endl;
    cout << "全局变量g_a的地址:" << &g_a << endl;
    cout << "全局变量g_b的地址:" << &g_b << endl;

    // 静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址:" << &s_a << endl;
    cout << "静态变量s_b的地址:" << &s_b << endl;

    // 常量
    // 字符串常量
    cout << "字符串常量的地址:" << &"jun" << endl;

    // const修饰的变量
    // const修饰的全局变量，const修饰的局部变量
    const int g_d = 100;
    cout << "全局常量g_c的地址:" << &g_c << endl;
    cout << "局部常量g_d的地址:" << &g_d << endl;

    // 总结:
    // 不在全局区: 局部变量、const修饰的局部变量(局部常量)
    // 在全局区: 全局变量、静态变量、const修饰的全局常量
    return 0;
}