//
// Created by 72419 on 2018/3/22 0022.
//

#ifndef CPP_UNIONFIND1_H
#define CPP_UNIONFIND1_H

#include <cassert>

class UF1 {
private:
    int* id;
    int count;
public:
    UF1(int n) {
        count = n;
        id = new int[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    ~UF1() {
        delete[] id;
    }
    //quick find
    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pId = find(p);
        int qId = find(q);
        if (pId == qId) return;
        for (int i = 0; i < count; i++) {
            if (id[i] == pId)
                id[i] = qId;
        }
    }
};

#endif //CPP_UNIONFIND1_H
