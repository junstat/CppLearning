#include <iostream>

using namespace std;

// 1. new的基本语法
int *func() {
    // 在堆区创建整型数据
    // new返回的是 该数据类型的指针
    return new int(10);
}

void test01() {
    auto p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    // 堆区数据 由程序员管理开辟 释放
    delete p;
    cout << *p << endl; // 内存已经被释放，再次访问就是非法操作
}

// 2. 在堆区利用new开辟数组
void test02() {
    auto arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    // 释放堆区数组
    delete[] arr;
}

int main() {
    test02();
    return 0;
}