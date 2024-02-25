#include <iostream>
#include <deque>

using namespace std;

/**
 * deque& operator=(const deque &deq);  // 重载等号操作符
 * assign(beg, end);  // 将[beg, end)区间中的元素赋值给本身。
 * assign(n, elem); // 将n个elem赋值给本身。
 */

void printDeque(const deque<int> &d) {
    for (const auto &item: d)
        cout << item << " ";
    cout << endl;
}

int main() {
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
    return 0;
}