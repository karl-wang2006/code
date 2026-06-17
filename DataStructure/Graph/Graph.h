#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

// type of the vertex
typedef char VertexType;

// type of the edge
typedef int EdgeType;

//define a Adjacency Matrix
typedef struct Mgraph
{
    VertexType vertex[MAX];
    EdgeType edge[MAX][MAX];
    int vertex_num;
    int edge_num;
}Mgraph;


//adjacency list

typedef struct EdgeNode
{
    int weight; 
    int adj_idx;//current index of the element
    struct EdgeNode* next;//pointer to the next node
}EdgeNode;

typedef struct VertexNode
{
    char vertex;
    struct EdgeNode* firstedge;
}VertexNode;

typedef struct AdjGraph
{
    VertexNode adjlist[MAX];
    int vertex_num;
    int edge_num;
}AdjGraph;

AdjGraph* CreateAdjGraph_Auto(int vNum,int eNum,char* vertices,int edges[][3],int Isdirected);

PrintAdjGraph(AdjGraph* G);

/**
 * @brief  Automatically creates an adjacency matrix graph (directed or undirected)
 * @param  vNum       Total number of vertices in the graph
 * @param  eNum       Total number of edges in the graph
 * @param  vertices   the character vertices array
 * @param  edges      2D array storing all edges, each element is [u, v, t] representing an edge from u to v and the weight is t
 * @param  IsDirected 1 for directed graph, 0 for undirected graph
 * @return Mgraph*
 */
Mgraph* CreateMGraph_Auto(int vNum, int eNum, char vertices[], int edges[][3],int IsDirected);

/** 
 * @brief print the vertex array and adjacency matrix
 * @param G           Pointer to the adjacency matrix graph structure  
 * @return None          
*/
void PrintMGraph(Mgraph* G);

void prim(Mgraph* G);

void dfs(Mgraph* G, int i,int* visited);

void dfs_traverse(Mgraph* G);

void bfs_traverse(Mgraph* G);


#endif