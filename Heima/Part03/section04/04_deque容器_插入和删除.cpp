#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d) {
    for (const auto &item: d)
        cout << item << " ";
    cout << endl;
}

// 两端操作
void test1() {
    deque<int> d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);

    // 头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    // 尾插
    d1.pop_back();
    printDeque(d1);

    // 头插
    d1.pop_front();
    printDeque(d1);
}

void test2() {
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    // insert插入
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    // 按照区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}

void test3() {
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    // 删除
    auto it = d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);

    // 按区间方式删除
    d1.erase(d1.begin(), d1.end());
    // 清空
    d1.clear();
    printDeque(d1);
}

int main() {
    test3();
    return 0;
}