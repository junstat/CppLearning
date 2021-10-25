#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_EXCHANGESORT_H
#define DATASTRUCTURE_EXCHANGESORT_H

/*-------------------------------------------------------------------------
 1. 冒泡排序
 空间效率: O(1)
 时间效率: O(n^2)
 稳定性: 稳定
 ------------------------------------------------------------------------*/
template<typename ElementType>
void bubbleSort(ElementType x[], int n) {
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--)
            if (x[j - 1] > x[j]) {
                swap(x[j - 1], x[j]);
                flag = true;
            }
        if (!flag) return;
    }
}

template<typename ElementType>
int partition(ElementType x[], int low, int high) {
    ElementType pivot = x[low];
    while (low < high) {
        while (low < high && x[high] >= pivot) --high;
        x[low] = x[high];
        while (low < high && x[high] <= pivot) ++low;
        x[high] = x[low];
    }
    x[low] = pivot;
    return low;
}

/*-------------------------------------------------------------------------
 2. 快速排序
 空间效率: 由于快速排序是递归的，需要借助一个递归工作栈来保存每层递归调用的必要信息，其容量
 应与递归调用的最大深度一致。平均 O(logn)
 时间效率: 最坏O(n^2)，平均O(nlogn)
 稳定性: 不稳定。
 ------------------------------------------------------------------------*/
template<typename ElementType>
int quickSort(ElementType x[], int low, int high) {
    if (low < high) {
        int pivotPos = partition(x, low, high);
        quicksort(x, low, pivotPos - 1);
        quicksort(x, pivotPos + 1, high);
    }
}

#endif //DATASTRUCTURE_EXCHANGESORT_H
