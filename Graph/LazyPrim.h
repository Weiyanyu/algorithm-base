//
// Created by 72419 on 2018/3/24 0024.
//

#ifndef CPP_LAZYPRIM_H
#define CPP_LAZYPRIM_H

#include <vector>
#include "../heap/MinHeap.h"
#include "Edge.h"

template <typename Graph, typename Weight>
class   LazyPrimMST {
private:
    Graph &G;
    bool* marked;
    MinHeap<Edge<Weight>> pq;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
            if (!marked[e->other(v)]) {
                pq.insert(*e);
            }
        }
    }

public:
    LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.e())) {

        marked = new bool[G.v()];
        for (int i = 0; i < G.v(); i++) {
            marked[i] = false;
        }

        mst.clear();

        visit(0); //初始化
        while (!pq.isEmpty()) {
            Edge<Weight> e = pq.extractMin();

            if (marked[e.v()] == marked[e.w()]) {
                continue;
            }
            mst.push_back(e);

            if (!marked[e.v()]) {
                visit(e.v());
            } else {
                visit(e.w());
            }
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); i++) {
            mstWeight += mst[i].wt();
        }
    }

    ~LazyPrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //CPP_LAZYPRIM_H
