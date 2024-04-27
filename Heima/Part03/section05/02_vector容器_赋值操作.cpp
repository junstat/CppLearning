#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (const auto &item: v)
        cout << item << " ";
    cout << endl;
}

void test1() {
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i);

    printVector(v1);

    // 赋值
    vector<int> v2 = v1;
    printVector(v2);

    // assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    // n个element方式赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main() {
    test1();
    return 0;
}