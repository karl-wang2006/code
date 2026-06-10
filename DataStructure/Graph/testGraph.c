#include "Graph.h"

// 还有两种链式结构：
// 十字链表，解决有向图中不好找入边的问题；
// 邻接多重表，解决无向图中重复边节点过多的问题。

int main()
{
    char vertices[] = {'A', 'B', 'C', 'D'};
    int edges[4][2] = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}
    };
    int vNum = sizeof(vertices)/sizeof(vertices[0]);
    int eNum = sizeof(edges)/sizeof(edges[0]);
    int Isdirected = 0;

    Mgraph* G = CreateMGraph_Auto(vNum, eNum, vertices, edges, Isdirected=0);
    PrintMGraph(G);

    AdjGraph* G1 = CreateAdjGraph_Auto(vNum, eNum, vertices, edges, Isdirected=0);

    PrintAdjGraph(G1);

    free(G1);
    free(G);
    return 0;
}