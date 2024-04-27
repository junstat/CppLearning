#pragma once
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (const auto &item: lst)
        cout << item << " ";
    cout << endl;
}
