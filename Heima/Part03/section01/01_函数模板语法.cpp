#include <iostream>

using namespace std;

template<typename T>
void swapNumber(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

void test1() {
    int x = 1, y = 2;
    double m = 1.1, n = 2.2;
    swapNumber(x, y);
    swapNumber(m, n);
    cout << "x = " << x << ", y = " << y << endl;
    cout << "m = " << m << ", n = " << n << endl;
}

int main() {
    test1();
    return 0;
}