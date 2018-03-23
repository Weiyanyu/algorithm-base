//
// Created by 72419 on 2018/3/20 0020.
//

#include <iostream>
#include <map>
#include <ctime>
#include "Graph/SparseGraph.h"
#include "Graph/ReadGraph.h"
#include "Graph/Component.h"
#include "Graph/Path.h"
#include "Graph/ShortestPath.h"

using namespace std;

int main() {

    SparseGraph sparseGraph = SparseGraph(7, false);
    string filename = "C:\\Users\\72419\\Desktop\\testG2.txt";
    ReadGraph<SparseGraph> readGraph1(sparseGraph, filename);
    Component<SparseGraph> component1(sparseGraph);
    Path<SparseGraph> path1(sparseGraph, 0);
    ShortestPath<SparseGraph> path2(sparseGraph, 0);
    cout << "sparseGraph component counts is : " << component1.count() << endl;
    sparseGraph.show();

    path1.showPath(6);
    path2.showPath(6);

    return 0;
}