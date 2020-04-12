//
// Created by 72419 on 2018/3/20 0020.
//

#include <iostream>
#include <iomanip>
#include "Graph/WeightDanseGraph.h"
#include "Graph/WeightReadGraph.h"
#include "Graph/WeightSparseGraph.h"
#include "Graph/LazyPrim.h"

//test

using namespace std;

int main() {
    //cout << "Hello, World" << endl;
    //cout << "Hello, Github" << endl;
    //cout
    int V = 8;
    cout << setprecision(2);
    string filename = "C:\\Users\\72419\\Desktop\\testG1.txt";
    WeightSparseGraph<double> g = WeightSparseGraph<double>(V, false);
    WeightReadGraph<WeightSparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
    cout<<"Test Lazy Prim MST:"<<endl;
    LazyPrimMST<WeightSparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;

    cout<<endl;

    return 0;
}
