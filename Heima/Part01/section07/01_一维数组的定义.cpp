#include <iostream>

using namespace std;

int main() {
    int arr[5] = {10, 20, 30};
    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {10, 20, 30, 40, 50};
    for (const auto &item: arr2)
        cout << item << " ";
    cout << endl;
    return 0;
}