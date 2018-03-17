//
// Created by 72419 on 2018/3/16 0016.
//

#ifndef CPP_INSERTIONSORT_H
#define CPP_INSERTIONSORT_H

#include <algorithm>

template <typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; i++) {
        T temp = arr[i];
        int j;
        for (j = i; j > 0 && temp < arr[j-1]; j--) {
                arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

/**
 * 重载插入排序，可指定范围的插入排序，范围是[l ....r](左闭右闭)
 */
template <typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l; i <= r; i++) {
        T temp = arr[i];
        int j;
        for (j = i; j > l && temp < arr[j-1]; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

#endif //CPP_INSERTIONSORT_H
