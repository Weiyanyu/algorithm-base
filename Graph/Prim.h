//
// Created by 72419 on 2018/3/25 0025.
//

#ifndef CPP_PRIM_H
#define CPP_PRIM_H

#include <vector>
#include "Edge.h"
#include "../heap/IndexMinHeap.h"


using namespace std;

template <typename Graph, typename Weight>
class PrimMst {
private:
    Graph &G;
    vector<Edge<Weight>> mst;

    bool* marked;
    IndexMinHeap<Weight> ipq;
    vector<Edge<Weight>*> edgeTo;
    Weight mstWeight;

    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
            int w = e->other(v);
            if (!marked[w]) {
                if (!edgeTo[w]) {
                    edgeTo[w] = e;
                    ipq.insert(w, e->wt());
                } else if (e->wt() < edgeTo[w]->wt()){
                    edgeTo[w] = e;
                    ipq.change(w, e->wt());
                }
            }
        }
    }
public:
    PrimMst(Graph &graph) : G(graph), ipq(IndexMinHeap<Weight>(graph.v())){
        assert(graph.e() >= 1);
        marked = new bool[graph.v()];
        for (int i = 0; i < graph.v(); i++) {
            marked[i] = false;
            edgeTo.push_back(nullptr);
        }

        mst.clear();

        visit(0);
        while (!ipq.isEmpty()) {
            int v = ipq.exractMinIndex();
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            visit(v);
        }
        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); i++) {
            mstWeight += mst[i].wt();
        }
    }

    ~PrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //CPP_PRIM_H
