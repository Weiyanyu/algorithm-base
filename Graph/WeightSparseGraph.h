//
// Created by 72419 on 2018/3/24 0024.
//

#ifndef CPP_WEIGHTSPARSEGRAPH_H
#define CPP_WEIGHTSPARSEGRAPH_H


#include <vector>
#include <cassert>
#include <iostream>
#include "Edge.h"

using namespace std;

template <typename Weight>
class WeightSparseGraph {
private:
    int V;
    int E;
    bool directed;
    vector<vector<Edge<Weight> *>> g;
public:
    WeightSparseGraph(int V, bool directed) {
        this->V = V;
        this->directed = directed;
        for (int i = 0; i < V; i++) {
            g.push_back(vector<Edge<Weight> *>());
        }
    }

    ~WeightSparseGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                    delete g[i][j];
            }
        }
    }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);

        g[v].push_back(new Edge<Weight>(v, w, weight));
        if (!directed) {
            g[w].push_back(new Edge<Weight>(w, v, weight));
        }
        E++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < V);
        assert(w >= 0 && w < V);

        for (int i = 0; i < V; i++) {
            if (g[v][i]->other(v) == w)
                return true;
        }
        return false;
    }
    int v() { return V;}
    int e() { return E;}

    void show() {
        for( int i = 0 ; i < V ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }

    class adjIterator {
    private:
        WeightSparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(WeightSparseGraph &graph, int v): G(graph) {
            this->v = v;
            this->index = 0;
        }

        Edge<Weight>* begin() {
            index = 0;
            if (G.g[v].size()) {
                return G.g[v][index];
            }
            return nullptr;
        }

        Edge<Weight>* next() {
            index++;
            if (index < G.g[v].size()) {
                return G.g[v][index];
            }
            return nullptr;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif //CPP_WEIGHTSPARSEGRAPH_H
