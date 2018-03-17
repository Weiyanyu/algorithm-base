//
// Created by 72419 on 2018/3/17 0017.
//

#ifndef CPP_INVERSION_H
#define CPP_INVERSION_H

#include <vector>

using std::vector;

int mergeWays(vector<int> &data, vector<int> &aux, int start, int end) {

    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int leftCount = mergeWays(data, aux, start, mid);
    int rightCount = mergeWays(data, aux, mid + 1, end);

    int i = mid;
    int j = end;
    int index = end;
    int count = 0;
    while (i >= start && j > mid) {
        if (data[i] > data[j]) {
            count += (j - mid);
            aux[index--] = data[i--];
        } else {
            aux[index--] = data[j--];
        }
    }

    while (i >= start) {
        aux[index--] = data[i--];
    }
    while (j > mid) {
        aux[index--] = data[j--];
    }

    for (int k = start; k <= end; k++) {
        data[k] = aux[k];
    }

    return (leftCount + rightCount + count);
}

int easyWays(vector<int> &data) {

    int count = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i+1; j < data.size(); j++) {
            if (data[i] > data[j])
                count++;
        }
    }
    return count;

}

#endif //CPP_INVERSION_H
