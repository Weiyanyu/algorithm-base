//
// Created by 72419 on 2018/3/24 0024.
//

#ifndef CPP_EDGE_H
#define CPP_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Weight>
class Edge {
private:
    int a, b;
    Weight weight;
public:
    Edge(int a, int b, Weight weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge() {}

    ~Edge() {}

    int v() {
        return a;
    }
    int w() {
        return b;
    }
    Weight wt() {
        return this->weight;
    }

    int other(int v) {
        assert(v == a || v == b);
        return v == a ? b : a;
    }

    friend ostream& operator<<(ostream &os, const Edge &edge) {
        os << edge.a << "-" << edge.b << ": " << edge.weight;
        return os;
    }

    bool operator<(const Edge<Weight> &edge) {
        return weight < edge.weight;
    }
    bool operator<=(const Edge<Weight> &edge) {
        return weight <= edge.weight;
    }
    bool operator>(const Edge<Weight> &edge) {
        return weight > edge.weight;
    }
    bool operator>=(const Edge<Weight> &edge) {
        return weight >= edge.weight;
    }
    bool operator==(const Edge<Weight> &edge) {
        return weight == edge.weight;
    }




};

#endif //CPP_EDGE_H
