#ifndef GRAPH_H
#define GRAPH_H

struct edge{
	int weight;
	int node;
	struct edge* next;
};

typedef struct edge edge;

struct graph {
	edge** adj;
	int n; 
};

typedef struct graph graph;

graph* createGraph();
graph* createRandomGraph();
void insertNode(graph* g);				 //NOT ORIDENTED MODE
void deleteNode(graph* g,int node);		 //NOT ORIENTED MODE
void addEdge(graph* g,int s, int d);     //NOT ORIENTED MODE
void deleteEdge(graph* g,int s, int d);  //NOT ORIENTED MODE
void addOEdge(graph* g,int s, int d);    //ORIENTED MODE
void deleteOEdge(graph* g,int s, int d); //ORIENTED MODE
void BFS(graph* g,int* s);
void DFS(graph* g);
graph* transpose(graph* g);

#endif
