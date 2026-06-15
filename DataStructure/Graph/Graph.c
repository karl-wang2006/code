#include "Graph.h"
#define MAX __INT32_MAX__
#define MAXSIZE 20

Mgraph* CreateMGraph_Auto(int vNum, int eNum, char vertices[], int edges[][3], int IsDirected)
{
    Mgraph* g = (Mgraph*)malloc(sizeof(Mgraph));
    int i,j,k,t;

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
            if(i == j)
            {
                g->edge[i][j] = 0;
            }
            else
            {
                g->edge[i][j] = MAX;
            }
        }
    }

    for(k = 0; k < eNum; k++)
    {
        i = edges[k][0]; // index of the beginning vertex
        j = edges[k][1]; // index of the end vertex
        t = edges[k][2]; // weight

        g->edge[i][j] = t;

        if(!IsDirected)
        {
            g->edge[j][i] = t;
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
            if(G->edge[i][j] == MAX)
            {
                printf("M   ");
            }
            else
            {
                printf("%-4d", G->edge[i][j]);
            }
        }
        printf("\n");
    }
}


void prim(Mgraph* G)
{
    int i , j , k;
    int min;
    int weight[MAXSIZE]; // 候选边
    int vex_index[MAXSIZE];// 值表示出发点，下标表示到达点

    //从A点开始
    weight[0] = 0; 
    vex_index[0] = 0;

    for(i = 1; i < G->vertex_num; i++)
    {
        weight[i] = G->edge[0][i];
        vex_index[i] = 0;
    }


    for(int i = 1; i < G->vertex_num; i++)
    {
        min = MAX;
        j = 0;
        k = 0;

        while(j < G->vertex_num)
        {
            if(weight[j] != 0 && weight[j] < min)
            {
                min = weight[j]; //最小权重
                k = j; //最小权重对应连接的节点下标
            }
            j++;
        }

        printf("%c<-->%c ",G->vertex[vex_index[k]],G->vertex[k]);
        weight[k] = 0; // 表示已连接过

        // 把新连接上的节点对应的权重和连线加入进待选的路线中
        for(j = 0; j < G->vertex_num; j++)
        {
            if(weight[j] != 0 && G->edge[k][j] < weight[j])
            {
                weight[j] = G->edge[k][j];
                vex_index[j] = k;
            }
        }
    }
}