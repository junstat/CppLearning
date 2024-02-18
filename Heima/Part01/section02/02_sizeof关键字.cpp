#include <iostream>

using namespace std;

// 可以利用sizeof求出数据类型占用内存大小
int main() {
    // 语法: sizeof(数据类型 / 变量)
    cout << "short 类型占用内存大小为: " << sizeof(short) << " 字节" << endl;
    cout << "int 类型占用内存大小为: " << sizeof(int) << " 字节" << endl;
    cout << "long 类型占用内存大小为: " << sizeof(long) << " 字节" << endl;
    cout << "long long 类型占用内存大小为: " << sizeof(long long) << " 字节" << endl;

    // 整型结论: short < int <= long <= long long
    return 0;
}