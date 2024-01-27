#include <iostream>

using namespace std;

void Func(void *t) {
    cout << "func1" << endl;
}

void Func(int i) {
    cout << "func2" << endl;
}

int main() {
    Func(0);
    Func(nullptr);
    return 0;
}