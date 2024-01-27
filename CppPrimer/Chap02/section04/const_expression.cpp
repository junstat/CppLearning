#include <iostream>

using namespace std;

// constexpr 变量
//
void test1() {
    constexpr int mf = 20; // 20是常量表达式
    constexpr int limit = mf + 1; // mf+1是常量表达式
}

void test2() {
    const int *p = nullptr; // p是一个指向整型常量的指针
    constexpr int *q = nullptr;  //  q是一个指向整数的常量指针
}


int main() {

    return 0;
}