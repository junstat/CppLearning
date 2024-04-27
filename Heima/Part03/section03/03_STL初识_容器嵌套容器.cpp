#include <iostream>
#include <vector>

using namespace std;

// 容器嵌套容器
void test1() {
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; ++i) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (const auto &row: v) {
        for (const auto &item: row) {
            cout << item << " ";
        }
        cout << endl;
    }
}

int main() {
    test1();
    return 0;
}