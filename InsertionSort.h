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

#endif //CPP_INSERTIONSORT_H
