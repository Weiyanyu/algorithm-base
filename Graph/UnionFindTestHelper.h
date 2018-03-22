//
// Created by 72419 on 2018/3/22 0022.
//

#ifndef CPP_UNIONFINDTESTHELPER_H
#define CPP_UNIONFINDTESTHELPER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"

using std::cout;
using std::endl;

namespace UnionFindTestHelper {

    void testUF1(int n) {
        srand(time(NULL));
        UF1 uf1 = UF1(n);

        time_t startTime = clock();
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf1.unionElements(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf1.isConnected(a, b);
        }
        time_t endTime = clock();

        cout<<"UnionFind 1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    }

    void testUF2(int n) {
        srand(time(NULL));
        UnionFind2 uf2 = UnionFind2(n);

        time_t startTime = clock();
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf2.unionElements(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf2.isConnected(a, b);
        }
        time_t endTime = clock();

        cout<<"UnionFind 2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    }

    void testUF3(int n) {
        srand(time(NULL));
        UF3 uf3 = UF3(n);

        time_t startTime = clock();
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf3.unionElements(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf3.isConnected(a, b);
        }
        time_t endTime = clock();

        cout<<"UnionFind 3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    }

    void testUF4(int n) {
        srand(time(NULL));
        UF4 uf4 = UF4(n);

        time_t startTime = clock();
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf4.unionElements(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf4.isConnected(a, b);
        }
        time_t endTime = clock();

        cout<<"UnionFind 4, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

    }
}

#endif //CPP_UNIONFINDTESTHELPER_H
