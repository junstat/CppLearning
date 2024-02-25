#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void visit(int &item) {
    cout << item << endl;
}

void test1() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 第一种遍历方式
    // auto itbBegin = v.begin();
    // auto itEnd = v.end();
    //
    // while (itbBegin != itEnd) {
    //     cout << *itbBegin++ << endl;
    // }

    // 第二种遍历方式
    // for (auto it = v.begin(); it != v.end(); it++) {
    //     cout << *it << endl;
    // }

    // 第三种遍历方式
    // for (auto e: v) {
    //     cout << e << endl;
    // }

    for_each(v.begin(), v.end(), visit);
}

int main() {
    test1();
    return 0;
}