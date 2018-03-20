//
// Created by 72419 on 2018/3/20 0020.
//

#include <iostream>
#include "tree/BinarySearch.h"
#include "sort/QuickSort3.h"
#include "sort/SortTestHelper.h"

using namespace std;

int main() {

    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("Quick three ways : ", quickSort3, arr, n);

    int ans = binarySearch(arr, n, 233);
    if (ans != -1) {
        cout << "found target : " << ans << endl;
    } else {
        cout << "not found target" << endl;
    }

    return 0;
}