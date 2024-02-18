#include <iostream>

using namespace std;

int main() {
    int arr[][3] = {1, 2, 3, 4, 5, 6};
    for (auto &i: arr) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}