#include "print.h"

void test1() {
    list<int> l1 = {10, 20, 30, 40};
    printList(l1);

    if (l1.empty()) {
        cout << "l1 is empty" << endl;
    } else {
        cout << "l1 is not empty" << endl;
        cout << "l1 size is " << l1.size() << endl;
    }

    l1.resize(10, 10000);
    printList(l1);

    l1.resize(2);
    printList(l1);
}

int main() {
    test1();
    return 0;
}