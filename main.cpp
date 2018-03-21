//
// Created by 72419 on 2018/3/20 0020.
//

#include <iostream>
#include "sort/QuickSort3.h"
#include "tree/BST.h"

using namespace std;

int main() {

    BST<int, string> bst = BST<int, string>();

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        bst.loopInsert(rand() % 20, "yeonon");
    }

    bst.inOrder();

    return 0;
}