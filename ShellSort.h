//
// Created by 72419 on 2018/3/16 0016.
//

#ifndef CPP_SHELLSORT_H
#define CPP_SHELLSORT_H

#include <algorithm>

template <typename T>
void shellSort(T arr[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j > 0 && temp < arr[j-1]; j -= h) {
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
        }

        h /= 3;
    }
}

#endif //CPP_SHELLSORT_H
