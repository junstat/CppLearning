#include "print.h"
#include <list>

void test1() {
    list<int> l1 = {20, 10, 50, 40, 30};

    cout << "反转前: " << endl;
    printList(l1);

    l1.reverse();
    cout << "反转后: " << endl;
    printList(l1);
}

void test2() {
    list<int> l1 = {20, 10, 50, 40, 30};
    cout << "排序前: " << endl;

    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // 不支持随机访问迭代器的容器，内部会提供对应一些算法
    // sort(l1.begin(), l1.end());

    l1.sort();
    cout << "排序后: " << endl;
    printList(l1);

    l1.sort([](int a, int b) {return a > b;});
    cout << "排序后: " << endl;
    printList(l1);
}


int main() {
    test2();
    return 0;
}