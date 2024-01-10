#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Enter two integers: " << endl;
    cin >> a >> b;
    c = a;
    while (c <= b) {
        cout << c++ << endl;
    }
    return 0;
}