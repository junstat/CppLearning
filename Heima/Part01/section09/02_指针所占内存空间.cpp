#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    // cout << "指针占用的内存空间为：" << sizeof(p) << "个字节" << endl;
    // 在32位操作系统下，指针是占4个字节，64位系统下占8个字节
    cout << "sizeof (int *) = " << sizeof(int *) << endl;
    cout << "sizeof (double *) = " << sizeof(double *) << endl;
    cout << "sizeof (float *) = " << sizeof(float *) << endl;
    cout << "sizeof (char *) = " << sizeof(char *) << endl;
    return 0;
}