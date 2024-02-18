#include <iostream>

using namespace std;

int main() {
    // 1、const修饰指针  常量指针
    int a = 10, b = 20;
    const int *p = &a;
    // 指针指向的值不可以修改，指针的指向可以修改
    // *p = 30; // 错误，不能修改指针指向的值
    p = &b; // 正确，可以修改指针的指向

    // 2、const修饰常量  指针常量
    // 指针的指向不可以修改，指针指向的值可以修改
    int *const p2 = &a;
    *p2 = 100; //  正确，可以修改指针指向的值
    // p2 = &b;  //  错误，不能修改指针的指向

    // 3、const修饰指针和常量
    const int *const p3 = &a;
    // 指针的指向不可以修改，指针指向的值不可以修改
    // *p3 = 100;
    // p3 = &b;

    return 0;
}