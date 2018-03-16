//
// Created by 72419 on 2018/3/15 0015.
//

#include <iostream>

#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;

int main() {

    int n = 100000;
    int* arr = SortTestHelper::generateNearlyOrderArray(n, 100);
    int *insertArr = SortTestHelper::copyArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, insertArr, n);

    delete[] arr;
    delete[] insertArr;



    return 0;
}

