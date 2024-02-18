#include <iostream>

using namespace std;

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {21, 3, 5, 23, 67};
    cout << "排序前: ";
    for (const auto &item: arr)
        cout << item << " ";
    cout << endl;
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "排序后: ";
    for (const auto &item: arr)
        cout << item << " ";
    cout << endl;
    return 0;
}