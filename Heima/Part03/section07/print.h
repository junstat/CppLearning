#ifndef CPPLEARNING_PRINT_H
#define CPPLEARNING_PRINT_H

#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (const auto &item: lst)
        cout << item << " ";
    cout << endl;
}


#endif //CPPLEARNING_PRINT_H
