#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 内建函数对象  关系仿函数
// 大于 greater
class MyCompare {
public:
    bool operator()(int v1, int v2) { return v1 > v2; }
};

void test1() {
    vector<int> v = {10, 30, 40, 20, 50};

    for (const auto &item: v)
        cout << item << " ";
    cout << endl;

    // 使用 greater<int>() 函数对象实现从大到小排序
    sort(v.begin(), v.end(), greater<>());

    for (const auto &item: v)
        cout << item << " ";
    cout << endl;
}

int main() {
    test1();
    return 0;
}