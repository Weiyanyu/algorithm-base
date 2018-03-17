//
// Created by 72419 on 2018/3/17 0017.
//

#ifndef CPP_QUICKSORT3_H
#define CPP_QUICKSORT3_H

#include <algorithm>
#include <ctime>



template <typename T>
void __quickSort3(T arr[], int l, int r) {
    if (l >= r)
        return;

    std::swap( arr[l], arr[rand()%(r-l+1)+l ] );

    T v = arr[l];

    int lt = l;
    int gt = r+1;
    int i = l + 1;
    while (i < gt) {
        if (arr[i] < v) {
            std::swap(arr[lt+1], arr[i]);
            lt++;
            i++;
        } else if (arr[i] > v) {
            std::swap(arr[i], arr[gt-1]);
            gt--;
        }
        else {
            i++;
        }
    }
    std::swap(arr[l], arr[lt]);

    __quickSort3(arr, l, lt-1);
    __quickSort3(arr, gt, r);
}

template <typename T>
void quickSort3(T arr[], int n) {

    srand(time(NULL));
    __quickSort3(arr, 0, n-1);
}

#endif //CPP_QUICKSORT3_H
