#include "print.h"

// 赋值
void test1() {
    list<int> l1 = {10, 20, 30, 40};
    printList(l1);

    list<int> l2 = l1; // operator=
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    list<int> l4;
    l4.assign(10, 100);
    printList(l4);
}

// 交换
void test2() {
    list<int> l1 = {10, 20, 30, 40};
    list<int> l2;
    l2.assign(10, 100);
    cout << "交换前: " << endl;
    printList(l1);
    printList(l2);

    l1.swap(l2);
    cout << "交换后: " << endl;
    printList(l1);
    printList(l2);
}

int main() {
    test2();
    return 0;
}