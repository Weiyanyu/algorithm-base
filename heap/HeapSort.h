//
// Created by 72419 on 2018/3/18 0018.
//

#ifndef CPP_HEAPSORT_H
#define CPP_HEAPSORT_H

#include "MaxHeap.h"

template <typename T>
void __shiftDown(T arr[], int n, int k) {

    while (2*k+1 < n) {
        int j = 2*k+1;
        if (j + 1 < n && arr[j+1] > arr[j])
            j++;

        if (arr[k] >= arr[j]) break;
        swap(arr[k], arr[j]);
        k = j;
    }

}

template <typename T>
void HeapSort1(T arr[], int n) {

    MaxHeap<T> maxHeap = MaxHeap<T>(n);

    for (int i = 0; i < n; i++) {
        maxHeap.insert(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxHeap.exractMax();
    }

}
template <typename T>
void HeapSort2(T arr[], int n) {

    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxHeap.exractMax();
    }

}

template <typename T>
void HeapSort(T arr[], int n) {

    //建堆
    for (int i = (n-1)/2; i >= 0; i--) {
        __shiftDown(arr, n, i);
    }

    //排序
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }

}

#endif //CPP_HEAPSORT_H
