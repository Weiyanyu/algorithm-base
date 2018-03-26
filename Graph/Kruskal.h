//
// Created by 72419 on 2018/3/25 0025.
//

#ifndef CPP_KRUSKAL_H
#define CPP_KRUSKAL_H

#include "Edge.h"
#include "../heap/MinHeap.h"
#include "UnionFind4.h"
#include <vector>

using namespace std;

template <typename Graph, typename Weight>
class KruskalMST {
private:

    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph) {
        MinHeap<Edge<Weight>> pq(graph.v());
        for (int i = 0; i < graph.v(); i++) {
            typename Graph::adjIterator adj(graph, i);
            for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
                if (e->v() < e->w()) {
                    pq.insert(*e);
                }
            }
        }

        UF4 uf4(graph.v());
        while (!pq.isEmpty() && mst.size() < graph.v() - 1) {
            Edge<Weight> e = pq.extractMin();

            if (uf4.isConnected(e.w(), e.v()))
                continue;

            mst.push_back(e);
            uf4.unionElements(e.w(), e.v());
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); i++) {
            mstWeight += mst[i].wt();
        }
    }

    ~KruskalMST() {

    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };

};

#endif //CPP_KRUSKAL_H
