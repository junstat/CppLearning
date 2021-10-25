#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_INSERTIONSORT_H
#define DATASTRUCTURE_INSERTIONSORT_H

/*-------------------------------------------------------------------------
 1. 直接插入排序
 性能分析:
 1) 空间效率: O(1)
 2) 时间效率: 在排序过程中，向有序子表中逐个地插入元素的操作进行了n-1趟，每趟操作都分为
 比较关键字和移动关键字，而比较次数和移动次数取决于待排序表的初始状态。在最好情况下，表中
 元素已经有序，此时每插入一个元素，都只需比较一次而不用移动元素，时间复杂度为O(n)。
 在最坏情况下，表中元素顺序刚好与排序结果中的元素顺序相反(逆序)，总的比较次数达到最大，为
 sum i: 1->(n-1), 总的移动次数也达到最大为 sum (i+1): 1 -> (n-1)。平均情况下，时间
 复杂度为O(n^2)。
 3) 稳定性: 稳定
 ------------------------------------------------------------------------*/
template<typename ElementType>
void insertionSort(ElementType x[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--)
            if (x[j] < x[j - 1])
                swap(x[j], x[j - 1]);
    }
}

/*-------------------------------------------------------------------------
 2. 折半插入排序
 从直接插入排序算法中，看出每趟插入的过程中都进行了两项工作: ① 从前面的有序子表中查找出
 待插入元素的应该被插入的位置；② 给插入位置腾出空间，将待插入元素复制到表中的插入位置。
 注意到在该算法中，总是边比较边移动元素。下面将比较和移动操作分离，即先折半查找出元素的待
 插入元素的位置，然后统一地移动待插入位置之后的所有元素。
 性能分析:
 1) 空间效率: O(1)
 2) 时间效率: O(n^2)  折半插入排序减少了比较元素的次数，约为O(nlogn)，元素移动次数未改变。
 3) 稳定性: 稳定
 ------------------------------------------------------------------------*/
template<typename ElementType>
void insertionSortWithBinarySearch(ElementType x[], int n) {
    int low, high, mid;
    ElementType num;        // 暂存当前元素
    for (int i = 1; i < n; i++) {
        num = x[i];
        low = 0, high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (x[mid] > num) high = mid - 1;
            else low = mid + 1;
        }
        for (int j = i - 1; j >= high + 1; --j)
            x[j + 1] = x[j];
        x[high + 1] = num;
    }
}

/*-------------------------------------------------------------------------
 3. 希尔排序
 性能分析:
 1) 空间效率: O(1)
 2) 时间效率: 当n在某个特定范围时，希尔排序的时间复杂度为O(n^1.3)，在最坏情况下希尔排序
 的时间复杂度为O(n^2)。
 3) 稳定性: 不稳定
 ------------------------------------------------------------------------*/
template<typename ElementType>
void shellSort(ElementType x[], int n) {
    for (int step = n / 2; step; step /= 2)
        for (int i = step; i < n; i++)
            for (int j = i; j >= step && x[j] < x[j - step]; j -= step)
                swap(x[j], x[j - step]);
}


#endif //DATASTRUCTURE_INSERTIONSORT_H
