#include <iostream>

using namespace std;

int main() {
    // 整型
    // 1. short   2个Byte
    short num1 = 10;
    // 2. int     4个Byte
    int num2 = 10;
    // 3. long    win 4个Byte Linux 4个Byte 8个Byte
    long num3 = 10;
    // 4. long long 8个Byte
    long long num4 = 10;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;
    return 0;
}