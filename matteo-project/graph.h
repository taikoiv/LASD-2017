#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

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

graph* createGraph();
graph* createRandomGraph();
visit* Djikstra(graph* g,int s);
void printGraph(graph* g);
void collapseGraph(graph* g);
void addEdge(graph* g,int s,int d, float w);
void addNode(graph* g,float h);
void deleteEdge(graph* g,int s,int d);
void deleteNode(graph* g,int s);
void freeGraph(graph* g);
void freeVisit(visit* v);
#endif
