#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test1() {
    vector<int> v = {10, 40, 20, 30, 50};
    sort(v.begin(), v.end());

    for (const auto &item: v)
        cout << item << " ";
    cout << endl;

    // 使用函数对象 改变算法策略，变为排序规则为从大到小
    sort(v.begin(), v.end(), MyCompare());

    for (const auto &item: v)
        cout << item << " ";
    cout << endl;
}

int main() {
    test1();
    return 0;
}