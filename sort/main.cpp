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
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "QuickSort3.h"
#include "Inversion.h"
#include "../heap/HeapSort.h"

using namespace std;

int main() {


//    Sort 比较

    int n = 1000000;
    int* arr = SortTestHelper::generateNearlyOrderArray(n, 10);
//    int *insertArr = SortTestHelper::copyArray(arr, n);
//    int *bubbleArr = SortTestHelper::copyArray(arr, n);
//    int *shellArr = SortTestHelper::copyArray(arr, n);
//    int *mergeArr = SortTestHelper::copyArray(arr, n);
//    int *quickArr = SortTestHelper::copyArray(arr, n);
//    int *quick2Arr = SortTestHelper::copyArray(arr, n);
//    int *quick3Arr = SortTestHelper::copyArray(arr, n);
    int *heap1Arr = SortTestHelper::copyArray(arr, n);
    int *heap2Arr = SortTestHelper::copyArray(arr, n);
    int *heap3Arr = SortTestHelper::copyArray(arr, n);


//    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
//    SortTestHelper::testSort("Insertion Sort", insertionSort, insertArr, n);
//    SortTestHelper::testSort("Bubble Sort", bubbleSort, bubbleArr, n);
//    SortTestHelper::testSort("Shell Sort", shellSort, shellArr, n);
//    SortTestHelper::testSort("Merge Sort", mergeSort, mergeArr, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, quickArr, n);
//    SortTestHelper::testSort("Quick2 Sort", quickSort2, quick2Arr, n);
//    SortTestHelper::testSort("Quick3 Sort", quickSort3, quick3Arr, n);
    SortTestHelper::testSort("HeapSort1 : ", HeapSort1, heap1Arr, n);
    SortTestHelper::testSort("HeapSort2 : ", HeapSort2, heap2Arr, n);
    SortTestHelper::testSort("HeapSort3 : ", HeapSort, heap3Arr, n);

    delete[] arr;
//    delete[] insertArr;
//    delete[] bubbleArr;
//    delete[] shellArr;
//    delete[] mergeArr;
//    delete[] quickArr;
//    delete[] quick2Arr;
//    delete[] quick3Arr;
    delete[] heap1Arr;
    delete[] heap2Arr;
    delete[] heap3Arr;



    return 0;
}

