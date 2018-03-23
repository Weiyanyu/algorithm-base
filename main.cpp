//
// Created by 72419 on 2018/3/20 0020.
//

#include <iostream>
#include <map>
#include <ctime>
#include "Graph/SparseGraph.h"
#include "Graph/ReadGraph.h"

using namespace std;

int main() {

    SparseGraph sparseGraph = SparseGraph(13, false);
    string filename = "testG1.txt";
    ReadGraph<SparseGraph> readGraph1 = ReadGraph<SparseGraph>(sparseGraph, filename);
    sparseGraph.show();

    return 0;
}