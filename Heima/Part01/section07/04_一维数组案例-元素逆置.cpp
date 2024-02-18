#include <iostream>

using namespace std;

int main() {
    int arr[5] = {1, 3, 2, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        swap(arr[i], arr[j]);
    }
    for (const auto &item: arr)
        cout << item << " ";
    cout << endl;
    return 0;
}