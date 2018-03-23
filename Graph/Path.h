//
// Created by 72419 on 2018/3/23 0023.
//

#ifndef CPP_PATH_H
#define CPP_PATH_H

#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

template <typename Graph>
class Path {
private:
    Graph &G;
    bool* visited;
    int* from;
    int s;

    void dfs(int v) {
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            if (!visited[w]) {
                from[w] = v;
                dfs(w);
            }
        }
    }

    void path(int w, vector<int> &vec) {

        for (int p = w; p != -1; p = from[p]) {
            vec.insert(vec.begin(), p);
        }
    }

public:

    Path(Graph &graph, int s):G(graph) {
        visited = new bool[G.v()];
        from = new int[G.v()];
        this->s = s;
        for (int i = 0; i < G.v(); i++) {
            from[i] = -1;
            visited[i] = false;
        }
        dfs(this->s);
    }

    bool hasPath(int w) {
        assert(w > 0 && w < G.v());
        return visited[w];
    }

    void showPath(int w) {
        vector<int> vec;
        path(w, vec);

        cout << this->s << " to " << w << " : ";

        for (int i = 0; i < vec.size(); i++) {
            if (i == vec.size() - 1)
                cout << vec[i] << endl;
            else
                cout << vec[i] << " --> ";
        }
    }

};

#endif //CPP_PATH_H
