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

    if (v1.empty()) {
        cout << "v1 is empty" << endl;
    } else {
        cout << "v1 is not empty" << endl;
        cout << "v1 capacity: " << v1.capacity() << endl;
        cout << "v1 size: " << v1.size() << endl;
    }

    // 重新指定大小
    // 如果重新指定的比原来长了，默认用0填充新的位置
    // v1.resize(15);
    // 利用重载版本，可以指定默认填充值
    v1.resize(15, 100);
    printVector(v1);

    // 如果重新指定的比原来短了，那么末尾超出部分会被删除
    v1.resize(5);
    printVector(v1);
}

int main() {
    test1();
    return 0;
}