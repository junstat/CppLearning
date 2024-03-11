#include <iostream>
#include <list>

using namespace std;

void test1() {
    list<int> l1 = {10, 20, 30, 40};

    // l1[0];  // 不可以用[]访问list容器中的元素
    // l1.at(0);  // 不可以用at方式访问list容器中的元素
    // 原因是list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
    cout << "第一个元素为: " << l1.front() << endl;
    cout << "最后一个元素为: " << l1.back() << endl;

    // 验证迭代器是不支持随机访问的
    auto it = l1.begin();
    it++;
    it--;
    // it = it + 1; // 不支持随机访问
}

int main() {
    test1();
    return 0;
}