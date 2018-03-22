//
// Created by 72419 on 2018/3/22 0022.
//

#ifndef CPP_UF2_H
#define CPP_UF2_H

#include <cassert>

class UnionFind2 {
private:
    int* parent;
    int count;
public:
    UnionFind2(int n) {
        count = n;
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    ~UnionFind2() {
        delete[] parent;
    }

    int find(int p) {
        assert(p >= 0 && p < count);
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;

        parent[pRoot] = qRoot;
    }
};

#endif //CPP_UF2_H
