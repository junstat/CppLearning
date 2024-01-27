#include <iostream>

using namespace std;

int main() {
    int i = 5, j = 10;
    int *p = &i;
    cout << p << " " << *p << endl; // p指向i地址，*p=5
    p = &j;
    cout << p << " " << *p << endl; // p指向j地址，*p=10
    *p = 20;
    cout << p << " " << *p << endl; // p指向j地址，*p=20
    j = 30;
    cout << p << " " << *p << endl;  // p指向j地址，*p=30
    return 0;
}