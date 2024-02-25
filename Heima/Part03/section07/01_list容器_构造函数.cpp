#include <list>
#include "print.h"

using namespace std;

void test1() {
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printList(l1);

    // 区间方式构造
    list<int> l2(l1.begin(), l1.end());
    printList(l2);

    // 拷贝构造
    list<int> l3(l2);
    printList(l3);

    // n个elem
    list<int> l4(10, 100);
    printList(l4);
}

int main() {
    test1();
    return 0;
}