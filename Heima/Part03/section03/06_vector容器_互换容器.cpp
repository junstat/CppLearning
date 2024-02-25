#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &v) {
    for (const auto &item: v)
        cout << item << " ";
    cout << endl;
}

// 1. 基本使用
void test1() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(i);
    cout << "交换前: \n";
    cout << "v1: ";
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; --i)
        v2.push_back(i);
    cout << "v2: ";
    printVector(v2);
    cout << "交换后: \n";
    v1.swap(v2);
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);
}

// 2. 实际用途
// 巧用swap可以收缩内存空间
void test2() {
    vector<int> v;
    for (int i = 0; i < 100000; ++i)
        v.push_back(i);
    cout << "vector capacity: " << v.capacity() << endl;
    cout << "vector size: " << v.size() << endl;

    v.resize(3);
    cout << "vector capacity: " << v.capacity() << endl;
    cout << "vector size: " << v.size() << endl;

    // 巧用swap收缩内存
    // vector<int>(v) 匿名对象
    // vector<int>(v).swap(v);
    v.shrink_to_fit();
    cout << "vector capacity: " << v.capacity() << endl;
    cout << "vector size: " << v.size() << endl;
}

int main() {
    test2();
    return 0;
}