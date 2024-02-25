#include <iostream>

using namespace std;

int *func() {
    // 利用new关键字，可以讲数据开辟到堆区
    //
    auto p = new int(10);
    return p;
}

int main() {
    // 在堆区开辟空间
    auto p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}