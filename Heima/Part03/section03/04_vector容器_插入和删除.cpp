#include <iostream>
#include <vector>

using namespace std;

/**
 * vector插入和删除
 * push_back(ele)
 * pop_back()
 * insert(const_iterator pos, ele)
 * insert(const_iterator pos, int count, ele)
 * erase(const_iterator pos)
 * erase(const_iterator start, const_iterator end)
 * clear()
 */

void printVector(const vector<int> &v) {
    for (const auto &item: v)
        cout << item << " ";
    cout << endl;
}

void test1() {
    vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入 第一个参数是迭代器
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 100);
    printVector(v1);

    // 删除 参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);

    v1.erase(v1.begin(), v1.begin() + 3);
    printVector(v1);

    // 清空
    v1.clear();
    printVector(v1);
}

int main() {
    test1();
    return 0;
}