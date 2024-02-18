#include <iostream>

using namespace std;

int main() {
    // 1> 定义指针
    int a = 10;
    // 指针定义的语法: 数据类型 * 指针变量名;
    int *p;
    // 让指针记录变量a的地址
    p = &a;
    cout << "a的地址为: " << &a << endl;
    cout << "指针p为: " << p << endl;

    // 2> 使用指针
    *p = 100;
    cout << "a的值为: " << a << endl;
    return 0;
}