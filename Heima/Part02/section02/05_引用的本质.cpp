#include <iostream>

using namespace std;

// 引用的本质: 在C++内部是实现是一个指针常量
// 指针的指向不可以修改，指针指向的值可以修改
// 发现是引用，转换为 int * const ref = &a;
void func(int &ref) {
    ref = 100; // ref是引用，转换为*ref = 100;
}

int main() {
    int a = 10;

    // 自动转换为 int * const ref = &a;
    // 指针常量指针指向不可改，也说明为什么引用不可改
    int &ref = a;
    ref = 20;  // 内部发现是引用，自动转换为 *ref = 20;
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    func(a);
    // 结论: C++推荐引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器帮我们做了
    return 0;
}