#include <iostream>

using namespace std;

int main() {
    int i = 42;
    int *p; // p是一个int型指针
    int *&r = p; // r 是一个对指针p的引用

    r = &i; // r引用了一个指针，因此给r赋值&i就是令p指向i
    *r = 0; // 解引用r得到i，也就是p指向的对象，将i的值改为0
    return 0;
}