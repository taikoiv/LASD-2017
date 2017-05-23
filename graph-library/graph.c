#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "graph.h"

#define RANDOM_SUCC 0,33

int GRAPH_ERROR;

edge* freeEdges(edge* l);
edge* removeEdge(edge* l, int k);
void initializeBFS(int* col,int* s);
void DFSVisit(graph* g,int* col,int s);

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
			g->adj[i]=NULL;
			return;
		}
	}
	g->adj=realloc(g->adj,((g->n)+1)*sizeof(edge));
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
		deleteEdge(g, i, node);
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

void addOEdge(graph* g,int s, int d){
	if(s>g->n || s<0 || d>g->n || d<0){
		GRAPH_ERROR=-2;
		return;
	}
	edge* e=(edge*) calloc(1,sizeof(edge));
	e->node=d;
	e->next=g->adj[s];
	g->adj[s]=e;
}
   
void deleteOEdge(graph* g,int s, int d){
	if(s>g->n || s<0 || d>g->n || d<0){
		GRAPH_ERROR=-2;
		return;
	}
	g->adj[s]=removeEdge(g->adj[s],d);
}

void BFS(graph* g,int* s){
	int k,*col=(int*)malloc(g->n*sizeof(int))
	queue *q=newQueue();
	edge* l=NULL;
	initializeBFS(col,q,s);
	while(!isEmpty(q)){
		k=dequeue(q);
		printf(" %d ",k);
		if(g->adj[k]!=NULL && g->adj[k]->node==-1){
			col[k]=2
			break;
		}
		l=adj[k];
		while(l!=NULL){
			if(col[l->node]==0){
				q=enqueue(q,l->node);
				col[l->node]=1;
			}
			l=l->next;
		}
		col[k]=2;
	}
}

void DFS(graph* g){
	int i,*col=(int*) calloc(g->n,sizeof(int));
	for(i=0;i<g->n;i++){
		if(col[i]==0){
			DFSVisit(g,col,i);
		}
	}
}

graph* transpose(graph* g){
	int i;
	edge* l=NULL;
	graph* tg=createGraph();
	tg->adj=(edge**) calloc(g->n,sizeof(edge*));
	tg->n=g->n;
	for(i=0;i<g->n;i++){
		l=g->adj[i];
		while(l!=NULL){
			if(l->node!=-1){
				addOEdge(tg,l->node,i);
			}
		}
	}
	return tg;
}

edge* freeEdges(edge* l){
	if(l!=NULL){
		freeEdges(l->next);
		free(l);
	}
	return NULL;	
}

edge* removeEdge(edge* l, int k){
	if(l!=NULL){
		if(l->node==k){
			edge* temp=l;
			l=l->next;
			free(temp);
		}
		l->next=removeEdge(l->next,k);
	}
	return l;		
}

void initializeBFS(int* col,queue* q,int* s){
	int i,n=sizeof(col)/sizeof(int);
	for(i=0;i<n;i++)
		col[i]=0;
	n=sizeof(s)/sizeof(int);
	for(i=0;i<n;i++){
		col[s[i]]=1;
		q=enqueue(q,s[i]);
	}
}

void DFSVisit(graph* g,int* col,int s){
	col[s]=1;
	edge* l=g->adj[s];
	if(l!=NULL && l->node==-1){
			col[s]=2;
			return;
	}
	while(l!=NULL){
		if(col[l->node]==0){
			DFSVisit(g,col,l->node);
		}
	}
	printf(" %d ",s);
	col[s]=2;
}
