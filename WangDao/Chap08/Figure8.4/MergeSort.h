#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_MERGESORT_H
#define DATASTRUCTURE_MERGESORT_H

template<typename ElementType>
void merge(ElementType x[], ElementType aux[], int low, int mid, int high);

template<typename ElementType>
void mergeSortAux(ElementType x[], ElementType aux[], int low, int high);


template<typename ElementType>
void mergeSort(ElementType x[], int n) {
    ElementType aux[n];
    mergeSortAux(x, aux, 0, n - 1);
}

template<typename ElementType>
void mergeSortAux(ElementType x[], ElementType aux[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSortAux(x, aux, low, mid);
        mergeSortAux(x, aux, mid + 1, high);
        merge(x, aux, low, mid, high);
    }
}

template<typename ElementType>
void merge(ElementType x[], ElementType aux[], int low, int mid, int high) {
    int i, j, k;
    for (i = low; i <= high; i++)
        aux[i] = x[i];

    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
        if (aux[i] <= aux[j]) x[k] = aux[i++];
        else x[k] = aux[j++];

    while (i <= mid) x[k++] = aux[i++];
    while (j <= high) x[k++] = aux[j++];
}


#endif //DATASTRUCTURE_MERGESORT_H
