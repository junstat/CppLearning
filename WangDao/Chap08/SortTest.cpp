#include <iostream>
#include "Figure8.4/MergeSort.h"

using namespace std;

void printNums(int nums[], int n) {
    for (int i = 0; i < n; i++)
        cout << nums[i] << "  ";
    cout << endl;
}

int main() {
    int nums[] = {49, 38, 65, 97, 76, 13, 27, 49, 10};
    int len = sizeof(nums) / sizeof(nums[0]);
    cout << "len = " << len << endl;
    cout << "Before sorting:\n";
    printNums(nums, len);
    mergeSort<int>(nums, len);
    cout << "After sorting:\n";
    printNums(nums, len);
}