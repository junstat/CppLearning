#include <iostream>

using namespace std;

int main() {
    // 指针和数组
    // 利用指针访问数组中的元素
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *ptr = arr;
    for (int i = 0; i < 10; ++i)
        cout << *(ptr + i) << " ";
    cout << endl;
    return 0;
}