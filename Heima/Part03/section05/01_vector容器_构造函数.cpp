#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
    for (const auto &item: v)
        cout << item << " ";
    cout << endl;
}

// vector容器构造
void test1() {
    vector<int> v1; // 默认构造
    for (int i = 0; i < 10; i++)
        v1.push_back(i);
    print(v1);

    // 通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    print(v2);

    // n个element方式构造
    vector<int> v3(10, 100);
    print(v3);

    // copy构造
    vector<int> v4(v3);
    print(v4);
}

int main() {
    test1();
    return 0;
}