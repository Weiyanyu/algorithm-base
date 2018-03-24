//
// Created by 72419 on 2018/3/23 0023.
//

#ifndef CPP_SPARSEGRAPH_H
#define CPP_SPARSEGRAPH_H

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class SparseGraph {
private:
    int V;
    int E;
    bool directed;
    vector<vector<int>> g;
public:
    SparseGraph(int V, bool directed) {
        this->V = V;
        this->directed = directed;
        for (int i = 0; i < V; i++) {
            g.push_back(vector<int>());
        }
    }

    ~SparseGraph() {

    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);

        g[v].push_back(w);
        if (!directed) {
            g[w].push_back(v);
        }
        E++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);

        for (int i = 0; i < V; i++) {
            if (g[v][i] == w)
                return true;
        }
        return false;
    }
    int v() { return V;}
    int e() { return E;}

    void show() {
        for (int v = 0; v < V; v++) {
            cout << v << " : ";
            for (int w : g[v]) {
                cout << w << " ";
            }
            cout << endl;
        }
    }

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v): G(graph) {
            this->v = v;
            this->index = 0;
        }

        int begin() {
            index = 0;
            if (G.g[v].size()) {
                return G.g[v][index];
            }
            return -1;
        }

        int next() {
            index++;
            if (index < G.g[v].size()) {
                return G.g[v][index];
            }
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif //CPP_SPARSEGRAPH_H
