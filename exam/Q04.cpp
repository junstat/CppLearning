#include <iostream>

using namespace std;

int counter = 10;
namespace ManControl {
    int counter = 1;

    int GetCounter() {
        ::counter++;
        return counter;
    }
}

int main() {
    int counter = 2;
    counter = ManControl::GetCounter();
    cout << counter << "," << ::counter << endl;
    return 0;
}