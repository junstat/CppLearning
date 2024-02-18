#include <iostream>

using namespace std;

// 实现两个数字进行交换
void swap01(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void swap02(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int main() {
    int a = 10, b = 20;
    swap02(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}