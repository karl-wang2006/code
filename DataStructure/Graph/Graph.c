#include "Graph.h"

Mgraph* CreateMGraph_Auto(int vNum, int eNum, char vertices[], int edges[][2], int IsDirected)
{
    Mgraph* g = (Mgraph*)malloc(sizeof(Mgraph));
    int i,j,k;

    g->vertex_num = vNum;
    g->edge_num = eNum;

    for(int i = 0; i < vNum; i++)
    {
        g->vertex[i] = vertices[i];
    }

    for (i = 0; i < vNum; i++)
     {
        for (j = 0; j < vNum; j++) 
        {
            g->edge[i][j] = 0;
        }
    }

    for(k = 0; k < eNum; k++)
    {
        i = edges[k][0];
        j = edges[k][1];

        g->edge[i][j] = 1;

        if(!IsDirected)
        {
            g->edge[j][i] = 1;
        }
    }
    return g;
}

void PrintMGraph(Mgraph* G)
{
    int i, j;
    printf("Vertices: ");
    for (i = 0; i < G->vertex_num; i++) 
    {
        printf("%c ", G->vertex[i]);
    }
    printf("\nadjacency matrix: \n");
    for (i = 0; i < G->vertex_num; i++)
     {
        for (j = 0; j < G->vertex_num; j++) 
        {
            printf("%d ", G->edge[i][j]);
        }
        printf("\n");
    }
}