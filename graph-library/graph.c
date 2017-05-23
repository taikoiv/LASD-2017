#include <stdio.h>
#include "graph.h"

#define RANDOM_SUCC 0,33

int GRAPH_ERROR;

edge* freeEdges(edge* l);

graph* createGraph(){
	graph* g=(graph*) malloc(sizeof(graph));
	if(g==NULL){
		GRAPH_ERROR=-1;
		return g;
	}
	g->n=0;
	g->adj=NULL;
	return g;
}

graph* createRandomGraph();

void insertNode(graph* g){
	int i;
	for(i=0;i<g->n;i++){
		if(g->adj[i]!=NULL && g->adj[i]->node==-1){
			g->adj[i]->NULL;
			return;
		}
	}
	g->adj=realloc(g->adj,(n+1)*sizeof(edge));
	if(g->adj==NULL){
		GRAPH_ERROR=-1;
		g->n=0;
		return;
	}
	g->n++;
}

void deleteNode(graph* g,int node){
	int i;
	for(i=0;i<g->n;i++){
		deleteEdge(graph* g,int i, int d);
	}
	g->adj[i]=freeEdges(g->adj[i]);
	g->adj[i]=(edge*) calloc(1,sizeof(edge));
	g->adj[i]->node=-1;
}

void addEdge(graph* g,int s, int d){
	addOEdge(g,s,d);
	addOEdge(g,d,s);
}

void deleteEdge(graph* g,int s, int d){
	deleteOEdge(g,s,d);
	deleteOEdge(g,d,s);
}

void addOEdge(graph* g,int s, int d);    
void deleteOEdge(graph* g,int s, int d);
void BFS(graph* g,int* s);
void DFS(graph* g);
graph* transpose(graph* g);

edge* freeEdges(edge* l){
	if(l!=NULL){
		freeEdges(l->next);
		free(l);
	}
	return NULL;	
}
