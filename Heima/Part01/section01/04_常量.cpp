#include <iostream>

using namespace std;

// 常量的定义方式
// 1. #define 定义宏
#define Day 7


int main() {
    cout << "一周总共有: " << Day << " 天." << endl;
    // 2. const修饰变量
    const int month = 12;
    cout << "一年总共有: " << month << "个月." << endl;
    return 0;
}