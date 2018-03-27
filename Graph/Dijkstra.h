//
// Created by 72419 on 2018/3/27 0027.
//

#ifndef CPP_DIJKSTRA_H
#define CPP_DIJKSTRA_H

#include <vector>
#include <stack>
#include "Edge.h"
#include "../heap/IndexMinHeap.h"

using namespace std;

template <typename Graph, typename Weight>
class Dijkstra {
private:
    Graph &G;
    int s;
    Weight* distTo;
    vector<Edge<Weight> *> from;
    bool* marked;
public:
    Dijkstra(Graph &graph, int s) : G(graph) {
        this->s = s;
        distTo = new Weight[graph.v()];
        marked = new bool[graph.v()];
        for (int i = 0; i < graph.v(); i++) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(nullptr);
        }

        IndexMinHeap<Weight> ipq(G.v());

        marked[s] = true;
        distTo[s] = Weight();
        ipq.insert(s, distTo[s]);

        //relax
        while (!ipq.isEmpty()) {
            int v = ipq.exractMinIndex();

            marked[v] = true;
            typename Graph::adjIterator adj(G, v);
            for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);
                if (!marked[w]) {
                    if (from[w] == nullptr || distTo[v] + e->wt() < distTo[w]) {
                        from[w] = e;
                        distTo[w] = distTo[v] + e->wt();
                        if (ipq.contain(w)) {
                            ipq.change(w, distTo[w]);
                        } else {
                            ipq.insert(w, distTo[w]);
                        }
                    }
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] distTo;
        delete[] marked;
    }

    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < G.v());
        return distTo[w];
    }

    bool hasPathTo(int w) {
        assert(w >= 0 && w < G.v());
        return marked[w];
    }

    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }
};

#endif //CPP_DIJKSTRA_H
