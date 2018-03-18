//
// Created by 72419 on 2018/3/18 0018.
//

#ifndef CPP_HEAPSORT_H
#define CPP_HEAPSORT_H

#include "MaxHeap.h"

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

#endif //CPP_HEAPSORT_H
