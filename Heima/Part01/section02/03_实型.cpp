#include <iostream>

using namespace std;

int main() {
    // 1. float 4Byte  7位有效数字
    // 2. double 8Byte 15~16位有效数字
    // 默认情况下 输出一个小数，会显示6位有效数字
    float f1 = 3.1415926f;
    cout << "f1 = " << f1 << endl;
    double d1 = 3.1415926;
    cout << "d1 = " << d1 << endl;

    // 统计float 和 double占用内存空间
    cout << "float 类型占用内存大小为: " << sizeof(float) << " 字节" << endl;
    cout << "double 类型占用内存大小为: " << sizeof(double) << " 字节" << endl;

    // 科学计数法
    float f2 = 3e2;
    cout << "f2 = " << f2 << endl;

    float f3 = 3e-2;
    cout << "f3 = " << f3 << endl;
    return 0;
}