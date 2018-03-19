//
// Created by 72419 on 2018/3/19 0019.
//

#ifndef CPP_INDEXMAXHEAP_H
#define CPP_INDEXMAXHEAP_H

#include <cassert>
#include <cmath>
#include <iostream>


using std::string;
using std::cout;
using std::cin;
using std::endl;

template <typename Item>
class IndexMaxHeap {
private:
    Item* data;
    int* indexes;
    int* reverse;  //反向索引
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k/2]] < data[indexes[k]]) {
            std::swap(indexes[k/2], indexes[k]);
            reverse[indexes[k/2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (k * 2 <= count) {
            int j = 2*k;
            if (j + 1 <= count && data[indexes[j]] < data[indexes[j+1]])
                j++;

            if (data[indexes[k]] >= data[indexes[j]])
                break;

            std::swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }


public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; i++) {
            reverse[i] = 0;
        }

        count = 0;
        this->capacity = capacity;
    }


    void insert(int i, Item item) {
        assert(count + 1 <= capacity);
        assert(i+1 >= 1 && i+1 <= capacity);
        i += 1;
        data[i] = item;
        indexes[count + 1] = i;
        reverse[i] = count + 1;
        count++;
        shiftUp(count);
    }

    Item exractMax() {
        assert(count > 0);
        Item ret = data[indexes[1]] - 1;
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    int exractMaxIndex() {
        assert(count > 0);
        Item ret = indexes[1];
        std::swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    bool contain(int i) {
        assert(i+1 >= 1 && i+1 <= capacity);
        return reverse[i+1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i+1];
    }

    void change(int i, Item newItem) {

        assert(contain(i));
        i += 1;
        data[i] = newItem;

        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);

    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }



    ~MaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

};

#endif //CPP_INDEXMAXHEAP_H
