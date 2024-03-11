#include <iostream>

using namespace std;

template<class T>
void sortT(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int max = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[max] < arr[j]) max = j;
        }
        if (max != i) swap(arr[i], arr[max]);
    }
}

template<class T>
void printArr(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test1() {
    char arr[] = "badcfe";
    sortT(arr, 8);
    printArr(arr, 8);

    int iArr[] = {2, 43, 12, 13};
    sortT(iArr, 4);
    printArr(iArr, 4);
}

int main() {
    test1();
    return 0;
}