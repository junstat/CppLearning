#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_SELECTIONSORT_H
#define DATASTRUCTURE_SELECTIONSORT_H

template<typename ElementType>
void headAdjust(ElementType x[], int k, int n);

/*-------------------------------------------------------------------------
 1. 简单选择排序
 性能分析:
 1) 空间效率: O(1)
 2) 时间效率: O(n^2)
 3) 稳定性: 不稳定
 ------------------------------------------------------------------------*/
template<typename ElementType>
void selectionSort(ElementType x[], int n) {
    for (int i = 0; i < n; i++) {
        int curMinIndex = i;
        for (int j = i + 1; j < n; j++)
            if (x[j] < x[curMinIndex]) curMinIndex = j;
        if (curMinIndex != i) swap(x[i], x[curMinIndex]);
    }
}


template<typename ElementType>
void buildMaxHeap(ElementType x[], int n) {
    // 建立大根堆
    for (int i = n / 2 - 1; i >= 0; i--)
        headAdjust(x, i, n);
}

template<typename ElementType>
void headAdjust(ElementType x[], int k, int n) {
    // 将元素k为根的子树进行调整
    for (int i = 2 * k + 1; i < n; i = 2 * i + 1) {
        if (i < n && x[i] < x[i + 1]) i++;
        if (x[k] >= x[i]) break;
        else {
            swap(x[k], x[i]);
            k = i;
        }
    }
}

/*-------------------------------------------------------------------------
 2. 堆排序
 性功能分析
 1) 空间效率: O(1)
 2) 时间效率: O(nlogn)
 3) 稳定性: 不稳定
 ------------------------------------------------------------------------*/
template<typename ElementType>
void heapSort(ElementType x[], int n) {
    buildMaxHeap(x, n);
    for (int i = n - 1; i > 0; i--) {
        swap(x[i], x[0]);
        headAdjust(x, 0, i - 1);
    }
}


template<typename DataType>
void displayTree(DataType x[], int n) {
    int beginIndex = 0, endIndex = 0, rowLength, numLevels = int(ceil(log(double(n)) / log(2.0)));

    for (int level = 0; level < numLevels; level++) {
        displayOneLevel(x, numLevels, level, beginIndex, endIndex);
        rowLength = endIndex - beginIndex + 1;
        beginIndex = endIndex + 1;
        endIndex = min(endIndex + 2 * rowLength, n - 1);
    }
}

template<typename DataType>
void displayOneLevel(DataType x[], int numRows,
                     int level, int beginIndex, int endIndex) {
    int skip = int(pow(2.0, numRows - level) - 1);

    for (int i = beginIndex; i <= endIndex; i++) {
        cout << setw(skip) << " ";
        cout << setw(2) << x[i];
        cout << setw(skip) << " ";
    }
    cout << "\n\n";
}

#endif //DATASTRUCTURE_SELECTIONSORT_H
