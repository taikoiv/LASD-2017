#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "list.h"

typedef struct edge{
	int k;
	float weight;
	struct edge* next;
} edge;

typedef struct node{
	float height;
	edge* adj;
} node;

typedef struct graph{
	int n;
	node* nodes;
} graph;

typedef struct visit{
	int* col;
	int* pred;
	float* dist;
} visit;

extern int GRAPH_ERROR;

graph* createGraph(); //CREATE EMPTY GRAPH
graph* createRandomGraph(); //CREATE RANDOM GRAPH
visit* uphillVisit(graph* g,int s);
void printGraph(graph* g); //GRAPH PRINTER$
void addEdge(graph* g,int s,int d, float w); //ADD WEIGHTED EDGE TO THE GRAPH
void addNode(graph* g,float h); //ADD NODE WITH THE HEIGHT PROPERTY IN THE GRAPH
void deleteEdge(graph* g,int s,int d); //DELETE THE EDGE BETWEEN S AND D
void deleteNode(graph* g,int s); //DELETE THE NODE
void freeGraph(graph* g); //FREE A GRAPH
void freeVisit(visit* v); //FREE A VISIT
void printPath(visit* v,int s); //PRINT A PATH AFTER A VISIT
list* pathGenerator(graph* g,visit* v,int s);
list* pathExtender(graph* g,list* path,visit* v,int s);
visit* Dijkstra(graph* g,int s);

#endif
