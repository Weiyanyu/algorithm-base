//
// Created by 72419 on 2018/3/17 0017.
//

#ifndef CPP_QUICKSORT2_H
#define CPP_QUICKSORT2_H
#include <algorithm>
#include <ctime>


template <typename T>
int __partition2(T arr[], int l, int r) {


    std::swap(arr[l], arr[(rand() % (r-l+1)) + l]);

    T v = arr[l];
    int i = l+1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l+1 && arr[j] > v) j--;
        if (i > j)
            break;
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    std::swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort2(T arr[], int l, int r) {
    if (l >= r)
        return;
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n) {

    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

#endif //CPP_QUICKSORT2_H
