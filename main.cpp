//
// Created by 72419 on 2018/3/15 0015.
//

#include <iostream>

#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

using namespace std;

int main() {

    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *insertArr = SortTestHelper::copyArray(arr, n);
    int *bubbleArr = SortTestHelper::copyArray(arr, n);
    int *shellArr = SortTestHelper::copyArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, insertArr, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, bubbleArr, n);
    SortTestHelper::testSort("Shell Sort", shellSort, shellArr, n);

    delete[] arr;
    delete[] insertArr;



    return 0;
}

