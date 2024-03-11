#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 逻辑非 logical_not
void test1() {
    vector<bool> v = {true, false, true, false};

    for (const auto &item: v)
        cout << item << " ";
    cout << endl;

    // 利用逻辑非 将容器v 搬运到 容器v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.cbegin(), v.cend(), v2.begin(), logical_not<>());

    for (const auto &item: v2)
        cout << item << " ";
    cout << endl;
}

int main() {
    test1();
    return 0;
}