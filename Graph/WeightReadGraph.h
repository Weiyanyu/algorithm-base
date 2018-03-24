//
// Created by 72419 on 2018/3/24 0024.
//

#ifndef CPP_WEIGHTREADGRAPH_H
#define CPP_WEIGHTREADGRAPH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template <typename Graph, typename Weight>
class WeightReadGraph {
public:
    WeightReadGraph(Graph &graph, const string& filename) {
        ifstream file;
        file.open(filename);
        string line;
        int V,E;

        assert(file.is_open());

        assert(getline(file, line));

        stringstream ss(line);
        ss >> V >> E;

        assert(graph.v() == V);
        for (int i = 0; i < E; i++) {
            assert(getline(file, line));
            stringstream ss(line);
            int a, b;
            Weight weight;
            ss >> a >> b >> weight;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            graph.addEdge(a, b, weight);
        }
    }
};
#endif //CPP_WEIGHTREADGRAPH_H
