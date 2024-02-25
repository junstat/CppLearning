#include <iostream>

using namespace std;

// 1. 值传递
void swap1(int a, int b) {
    int t = a;
    a = b;
    b = a;
}

// 2. 地址传递
void swap2(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 3. 引用传递
void swap3(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 1, y = 2;
    swap1(x, y);
    cout << "x = " << x << ", y = " << y << endl;
    swap2(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;
    swap3(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}