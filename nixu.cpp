//
// Created by 72419 on 2018/3/17 0017.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int merge(vector<int> &data, vector<int> &aux, int start, int end) {
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    int leftCount = merge(data, aux, start, mid);
    int rightCount = merge(data, aux, mid+1, end);


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

int main1() {


    vector<int> data = {1,2,3,4,5,6,7,0};
    vector<int> aux;
    for (int n : data) {
        aux.push_back(n);
    }

    int res = merge(data, aux, 0, data.size()-1);
    cout << res << endl;

    return 0;
}

