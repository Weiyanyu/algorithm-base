//
// Created by 72419 on 2018/3/20 0020.
//

#ifndef CPP_BINARYSEARCH_H
#define CPP_BINARYSEARCH_H

template <typename T>
T binarySearch(T arr[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {

        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

#endif //CPP_BINARYSEARCH_H
