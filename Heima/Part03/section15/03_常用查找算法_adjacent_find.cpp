#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1() {
    vector<int> v = {0, 2, 0, 3, 1, 4, 3, 3};
    auto pos = adjacent_find(v.begin(), v.end());

    if (pos == v.end()) {
        cout << "未找到相邻重复元素" << endl;
    } else {
        cout << "找到相邻重复元素: " << *pos << endl;
    }
}

int main() {
    test1();
    return 0;
}