#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d) {
    for (const auto &item: d)
        cout << item << " ";
    cout << endl;
}

void test1() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);

    // 排序 默认排序规则 从小到大 排序
    // 对于支持随机访问的迭代器容器，都可以利用sort算法进行排序
    sort(d.begin(), d.end());
    cout << "排序后: " << endl;
    printDeque(d);
}

int main() {
    test1();
    return 0;
}