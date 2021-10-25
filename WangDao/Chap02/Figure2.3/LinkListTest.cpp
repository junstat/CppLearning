#include "LinkedList.h"

int main() {
    LinkedList la, lb, lc;
    la.insertHead(1);
    la.insertHead(2);
    la.insertTail(5);
    cout << "la: \n";
    cout << la;

    lb = LinkedList(la);
    cout << "lb: \n";
    cout << lb;

    lc = la;
    cout << "lc: \n";
    cout << lc;
    return 0;
}