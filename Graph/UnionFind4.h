//
// Created by 72419 on 2018/3/22 0022.
//

#ifndef CPP_UNIONFIND4_H
#define CPP_UNIONFIND4_H

#include <cassert>

class UF4 {
private:
    int* parent;
    int count;
    int* rank;

public:
    UF4(int n) {
        count = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UF4() {
        delete[] parent;
        delete[] rank;
    }

    int find(int p) {
        assert(p >= 0 && p < count);

        //路径压缩算法V1，每次跳两步去查找父亲节点，因为根节点的指针指向自己，所以不可能存在越界问题
//        while (p != parent[p]) {
//            parent[p] = parent[parent[p]];
//            p = parent[p];
//        }
//
//        return p;

        //路径压缩算法V2，节点更加接近根节点
        if (p != parent[p]) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;

        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[qRoot]){
            parent[qRoot] = pRoot;
        } else {
            parent[pRoot] = qRoot;
            rank[qRoot] ++;
        }
    }
};

#endif //CPP_UNIONFIND4_H
