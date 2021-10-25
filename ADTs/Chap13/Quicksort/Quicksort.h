#include <iostream>

using namespace std;

#ifndef QUICKSORT
#define QUICKSORT

template<typename ElementType>
int split(ElementType x[], int first, int last) {
    ElementType pivot = x[first];
    int left = first, right = last;
    while (left < right) {
        while (pivot < x[right])
            right--;

        while (left < right && pivot >= x[left])
            left++;

        if (left < right)
            swap(x[left], x[right]);
    }
    // End of searches; place pivot in correct place
    int pos = right;
    x[first] = x[pos];
    x[pos] = pivot;
    return pos;
}

template<typename ElementType>
void quicksortAux(ElementType x[], int first, int last) {
    int pos;                                // pivot's final position
    if (first < last) {                     // list size is > 1
        pos = split(x, first, last);        // Split into 2 sublist
        quicksortAux(x, first, pos - 1);    // Sort left sublist
        quicksortAux(x, pos + 1, last);     // Sort right sublist
    }
    // else list has 0 or 1 element and requires no sorting
}

template<typename ElementType>
void quicksort(ElementType x[], int n) {
    quicksortAux(x, 0, n - 1);
}

#endif
