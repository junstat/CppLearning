#include <iostream>

using namespace std;

int main() {
    int var = 5;
    static int base = 3;
    auto func = [=]() mutable {
        ++base;
        ++var;
    };
    func();
    cout << var << " " << base << endl;
    return 0;
}