//
// Created by 72419 on 2018/3/23 0023.
//

#ifndef CPP_SHORTESTPATH_H
#define CPP_SHORTESTPATH_H

#include <vector>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;


template <typename Graph>
class ShortestPath {
private:
    Graph& G;
    int* from;
    bool* visited;
    int* order;
    int s;

    void path(int w, vector<int> &vec) {

        for (int p = w; p != -1; p = from[p]) {
            vec.insert(vec.begin(), p);
        }
    }

public:
    ShortestPath(Graph& graph, int s) : G(graph) {

        assert(s >= 0 && s < G.v());

        from = new int[G.v()];
        visited = new bool[G.v()];
        order = new int[G.v()];

        for (int i = 0; i < G.v(); i++) {
            from[i] = -1;
            visited[i] = false;
            order[i] = -1;
        }
        this->s = s;

        queue<int> q;
        visited[s] = true;
        order[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i]) {
                    q.push(i);
                    from[i] = v;
                    visited[i] = true;
                    order[i] = order[v] + 1;
                }
            }
        }
    }

    ~ShortestPath() {
        delete[] from;
        delete[] order;
        delete[] visited;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.v());
        return visited[w];
    }

    void showPath(int w) {
        assert(w >= 0 && w < G.v());

        assert(hasPath(w));

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

#endif //CPP_SHORTESTPATH_H
