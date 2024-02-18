#include <iostream>

using namespace std;

int main() {
    // 在程序中，尽量避免出现野指针
    int *p = (int *) 0x1100;
    cout << *p << endl;
    // 空指针和野指针都不是我们申请的内存空间，因此不要访问
    return 0;
}