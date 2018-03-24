//
// Created by 72419 on 2018/3/24 0024.
//

#ifndef CPP_WEIGHTDANSEGRAPH_H
#define CPP_WEIGHTDANSEGRAPH_H

#include <vector>
#include <cassert>
#include <iostream>

#include "Edge.h"

using namespace std;

template <typename Weight>
class WeightDanseGraphe {
private:
    int V;
    int E;
    vector<vector<Edge<Weight> *>> g;
    bool directed;
public:
    WeightDanseGraphe(int V, bool directed) {
        this->V = V;
        this->directed = directed;
        for (int i = 0; i < V; i++) {
            g.push_back(vector<Edge<Weight> *>(V, nullptr));
        }
    }

    ~WeightDanseGraphe() {
        for (int v = 0; v < V; v++) {
            for (int w = 0; w < V; w++) {
                if (g[v][w] != nullptr) {
                    delete g[v][w];
                }
            }
        }
    }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);

        if (hasEdge(v, w)) {
            delete g[v][w];
            if (!directed) {
                delete g[w][v];
            }
            E--;
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if (!directed) {
            g[w][v] = new Edge<Weight>(w, v, weight);
        }
        E++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);
        return g[v][w] != nullptr;
    }

    int v() { return V;}
    int e() { return E;}


    void show() {
        for (int v = 0; v < V; v++) {
            for (int w = 0; w < V; w++) {
                if (g[v][w]) {
                    cout << g[v][w]->wt() << "\t";
                } else {
                    cout << "NULL\t";
                }
            }
            cout << endl;
        }
    }

    class adjIterator {
    private:
        WeightDanseGraphe &G;
        int v;
        int index;

    public:
        adjIterator(WeightDanseGraphe &graph, int v): G(graph) {
            this->v = v;
            this->index = -1;
        }

        Edge<Weight>* begin() {
            index = -1;
            return next();
        }

        Edge<Weight>* next() {
            for (index += 1; index < G.v(); index) {
                if (G.g[v][index]) {
                    return G.g[v][index];
                }
            }
            return nullptr;
        }

        bool end() {
            return index >= G.v();
        }
    };
};

#endif //CPP_WEIGHTDANSEGRAPH_H
