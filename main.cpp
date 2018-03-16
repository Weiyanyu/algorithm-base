//
// Created by 72419 on 2018/3/15 0015.
//

#include <iostream>

#include "SortTestHelper.h"
#include "Student.h"

using namespace std;


template <typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}




int main() {

    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("Selection Sort", selectSort, arr, n);

    delete[] arr;



    return 0;
}

