#include "Graph.h"

// 还有两种链式结构：
// 十字链表，解决有向图中不好找入边的问题；
// 邻接多重表，解决无向图中重复边节点过多的问题。

int main()
{
    char vertices[] = {'A', 'B', 'C', 'D', 'E','F','G','H','I'};
    int edges[][3] = {
        {0, 1, 8},
        {0, 2, 11},
        {1, 5, 1},
        {2, 3, 9},
        {3, 4, 2},
        {4, 5, 7},
        {5, 7, 2},
        {7, 6, 76},
        {4, 6, 50},
        {4, 8, 6},
        {7, 8, 3},
        {6, 8, 43}
    };
    int vNum = sizeof(vertices)/sizeof(vertices[0]);
    int eNum = sizeof(edges)/sizeof(edges[0]);
    int Isdirected = 0;

    //Mgraph* G = CreateMGraph_Auto(vNum, eNum, vertices, edges, 0);
    // PrintMGraph(G);


    // prim(G);
    // dfs_traverse(G);
    // bfs_traverse(G);
    AdjGraph* G1 = CreateAdjGraph_Auto(vNum, eNum, vertices, edges, Isdirected=0);

    PrintAdjGraph(G1);

    free(G1);
    //free(G);
    return 0;
}