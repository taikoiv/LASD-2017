#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct edge{
	int k;
	int weight;
	struct edge* next;
} edge;

typedef struct node{
	int height;
	edge* adj;
} node;

typedef struct graph{
	int n;
	node* nodes;
} graph;

graph* createGraph();
graph* createRandomGraph();
//node* Djikstra(graph* g);
void printGraph(graph* g);
int checkContraints(node* path);
void collapseGraph(graph* g);
void addEdge(graph* g,int s,int d,int w);
void addNode(graph* g,int h);
void deleteEdge(graph* g,int s,int d);
void deleteNode(graph* g,int s);
void freeGraph(graph* g);

#endif
