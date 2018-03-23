//
// Created by 72419 on 2018/3/23 0023.
//

#ifndef CPP_COMPONENT_H
#define CPP_COMPONENT_H

#include <cassert>

template <typename Graph>
class Component {
private:
    Graph &G;
    int ccount;
    bool* visited;
    int* id;

    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);

        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

public:
    Component(Graph& graph): G(graph){
        this->ccount = 0;
        visited = new bool[G.v()];
        id = new int[G.v()];
        for (int i = 0; i < G.v(); i++) {
            visited[i] = false;
            id[i] = -1;
        }

        for (int v = 0; v < G.v(); v++) {
            if (!visited[v]) {
                dfs(v);
                ccount++;
            }
        }
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return ccount;
    }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.v());
        assert(w >= 0 && v < G.v());
        return id[v] == id[w];
    }


};

#endif //CPP_COMPONENT_H
