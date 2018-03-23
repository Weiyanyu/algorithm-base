//
// Created by 72419 on 2018/3/23 0023.
//

#ifndef CPP_DANSEGRAPH_H
#define CPP_DANSEGRAPH_H

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class DanseGraphe {
private:
    int V;
    int E;
    vector<vector<bool>> g;
    bool directed;
public:
    DanseGraphe(int V, bool directed) {
        this->V = V;
        this->directed = directed;
        for (int i = 0; i < V; i++) {
            g.push_back(vector<bool>(V, false));
        }
    }

    ~DanseGraphe() {

    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);

        if (hasEdge(v, w))
            return;

        g[v][w] = true;
        if (!directed) {
            g[w][v] = true;
        }
        E++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);
        return g[v][w];
    }

    int v() { return V;}
    int e() { return E;}


    void show() {
        for (int v = 0; v < V; v++) {
            for (int w = 0; w < V; w++) {
                cout << g[v][w] << " ";
            }
            cout << endl;
        }
    }

    class adjIterator {
    private:
        DanseGraphe &G;
        int v;
        int index;

    public:
        adjIterator(DanseGraphe &graph, int v): G(graph) {
            this->v = v;
            this->index = -1;
        }

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for (index += 1; index < G.v(); index) {
                if (G.g[v][index]) {
                    return index;
                }
            }
            return -1;
        }

        bool end() {
            return index >= G.v();
        }
    };
};

#endif //CPP_DANSEGRAPH_H
