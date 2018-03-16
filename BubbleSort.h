//
// Created by 72419 on 2018/3/16 0016.
//

#ifndef CPP_BUBBLESORT_H
#define CPP_BUBBLESORT_H

#include <algorithm>

template <typename T>
void bubbleSort(T arr[], int n) {

    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                std::swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }

    } while (swapped);
}

#endif //CPP_BUBBLESORT_H
