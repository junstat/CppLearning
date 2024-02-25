#include <iostream>

using namespace std;

// 函数占位参数，占位参数也可以有默认值

// 目前阶段的占位参数，我们还用不到，后面课程会用到
// 占位参数 还可以有默认值
void func(int a, int = 10) {
    cout << "this is func" << endl;
}

int main() {
    func(10, 20); // 占位参数，必须填补
    return 0;
}