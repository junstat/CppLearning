#include <iostream>

using namespace std;

bool T(char c) {
    cout << c;
    return true;
}

bool F(char c) {
    cout << c;
    return false;
}

int main() {
    T('A') && F('B');
    F('C') && T('D');
    return 0;
}