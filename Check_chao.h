//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_CHECK_CHAO_H
#define ELEC2645CW2_2_CHECK_CHAO_H

/*
#include <queue>
#include <iostream>
#include "Node_chao.h"

void depthsearchFirst(int** &checkgraph, int* &checknode, int graphwidth, int node) {
    checknode[node]=1;
    for (int j=0;j<graphwidth;j++) {
        if (checkgraph[node][j])
            depthsearchFirst(checkgraph, checknode, graphwidth, j);
    }
}

void depthsearchFirstTraverse(int** &checkgraph, int* &checknode, int graphwidth) {
    for (int i=0;i<graphwidth;i++) {
        if (checknode[i]==0)
            depthsearchFirst(checkgraph,checknode,graphwidth,i);
    }
}

void connectivityCheck(GraphNode** &graph, int graphwidth) {
    int* checknode=new int[graphwidth];
    for (int i=0;i<graphwidth;i++){
        checknode[i]=0;
    }
    int** checkgraph=new int*[graphwidth];
    for (int i=0;i<graphwidth;i++) {
        checkgraph[i]=new int[graphwidth];
    }

    for (int i=0; i<graphwidth; i++)
        for (int j=i; j<graphwidth;j++) {
            if (graph[i][j]._flag||graph[j][i]._flag)
                checkgraph[i][j]=1;
            else
                checkgraph[i][j]=0;
        }
    depthsearchFirst(checkgraph,checknode,graphwidth,0);
    for (int i=0;i<graphwidth;i++) {
        if (checknode[i]==0)
            std::cout << "this is not a connected graph, at least through node 0 we can't find all nodes" << std::endl;
    }

    for (int i=0; i<graphwidth; i++) {
        delete[] checkgraph[i];
    }
    delete[] checkgraph;
    delete[] checknode;
}
*/

#endif //ELEC2645CW2_2_CHECK_CHAO_H
