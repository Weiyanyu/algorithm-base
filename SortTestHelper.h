//
// Created by 72419 on 2018/3/15 0015.
//

#ifndef CPP_SORTTESTHELPER_H
#define CPP_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

namespace SortTestHelper {

    int* generateRandomArray(int n, int rangeL, int rangeR) {
        int* arr = new int[n];

        assert(rangeL <= rangeR);

        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int* generateNearlyOrderArray(int n, int swapTimes) {
        int* arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int x = rand() % n;
            int y = rand() % n;
            swap(arr[x], arr[y]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i-1])
                return false;
        }
        return true;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " need  " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    template <typename T>
    T* copyArray(T odlArr[], int n) {
        T* newArr = new T[n];
        copy(odlArr, odlArr + n, newArr);
        return newArr;
    }
}


#endif //CPP_SORTTESTHELPER_H
