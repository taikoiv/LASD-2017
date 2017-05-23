#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "graph.h"

int GRAPH_ERROR;
float RANDOM_SUCC=0.33;

void freeEdges(edge* l);
edge* removeEdge(edge* l, int k);
void initializeBFS(int* col,int n,queue* q,int s);
void DFSVisit(graph* g,int* col,int s);
void debugBFS(int *col,int n,queue* q,int k);
edge* addAdj(edge* l,int k);

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

graph* createORandomGraph(){
	graph* g=(graph*) malloc(sizeof(graph));
	int i,j,n=rand()%50;
	float p;
	if(g==NULL){
		GRAPH_ERROR=-1;
		return g;
	}
	g->adj=calloc(n,sizeof(edge));
	g->n=n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			p=(float)((rand()%n)+1)/n;
			if(p<=RANDOM_SUCC){
				addOEdge(g,i,j);
			}
		}
	return g;
}

void insertNode(graph* g){
	int i;
	for(i=0;i<g->n;i++){
		if(g->adj[i]!=NULL && g->adj[i]->node==-1){
			g->adj[i]=NULL;
			return;
		}
	}
	g->adj=realloc(g->adj,((g->n)+1)*sizeof(edge*));
	if(g->adj==NULL){
		GRAPH_ERROR=-1;
		g->n=0;
		return;
	}
	g->n++;
	g->adj[g->n-1]=NULL;
}

void deleteNode(graph* g,int node){
	int i;
	for(i=0;i<g->n;i++){
		deleteEdge(g, i, node);
	}
	freeEdges(g->adj[i]);
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
	g->adj[s]=addAdj(g->adj[s],d);
}
   
void deleteOEdge(graph* g,int s, int d){
	if(s>g->n || s<0 || d>g->n || d<0){
		GRAPH_ERROR=-2;
		return;
	}
	g->adj[s]=removeEdge(g->adj[s],d);
}

void BFS(graph* g,int s){
	int k,*col=(int*)malloc(g->n*sizeof(int));
	queue *q=newQueue();
	edge* l=NULL;
	initializeBFS(col,g->n,q,s);
	while(!isEmpty(q)){
		k=dequeue(q);
		printf(" %d ",k);
		if(g->adj[k]!=NULL && g->adj[k]->node==-1){
			col[k]=2;
			break;
		}
		l=g->adj[k];
		while(l!=NULL){
			if(col[l->node]==0){
				enqueue(q,l->node);
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
			l=l->next;
		}
	}
	return tg;
}

void freeEdges(edge* l){
	if(l!=NULL){
		freeEdges(l->next);
		free(l);
	}
}

edge* removeEdge(edge* l, int k){
	if(l!=NULL){
		if(l->node==k){
			edge* temp=l;
			l=l->next;
			free(temp);
		}
		else l->next=removeEdge(l->next,k);
	}
	return l;		
}

edge* addAdj(edge* l,int k){
	if(l!=NULL){
		if(l->node!=k)
			l->next=addAdj(l->next,k);
	}else{
		l=(edge*) malloc(sizeof(edge));
		l->node=k;
		l->next=NULL;
	}	
	return l;
}

void initializeBFS(int* col,int n,queue* q,int s){
	int i;
	for(i=0;i<=n;i++)
		col[i]=0;
	col[s]=1;
	enqueue(q,s);
	
}

void DFSVisit(graph* g,int* col,int s){
	col[s]=1;
	printf(" %d ",s);
	edge* l=g->adj[s];
	if(l!=NULL && l->node==-1){
			col[s]=2;
			return;
	}
	while(l!=NULL){
		if(col[l->node]==0){
			DFSVisit(g,col,l->node);
		}
		l=l->next;
	}
	col[s]=2;
}

void freeGraph(graph* g){
	while(g->n>0){
		printf("CANCELLO LISTA IN POSIZIONE %d\n",g->n-1);
		freeEdges(g->adj[g->n-1]);
		g->adj[g->n-1]=NULL;
		g->n--;
	}
	free(g->adj);
	free(g);
}

void printGraph(graph *g){
	int i;
	for(i=0;i<g->n;i++){
		printf("%d : ",i);
		edge* l=g->adj[i];
		while(l!=NULL){
			printf("%d ",l->node);
			l=l->next;
			if(l!=NULL){
				printf("-> ");
			}
		}
		printf("\n");
	}
}

graph* createRandomGraph(){
	graph* g=(graph*) malloc(sizeof(graph));
	int i,j,n=rand()%10;
	float p;
	if(g==NULL){
		GRAPH_ERROR=-1;
		return g;
	}
	g->adj=calloc(n,sizeof(edge*));
	g->n=n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i!=j){
				p=(float)((rand()%n)+1)/n;
				if(p<=RANDOM_SUCC){
					addOEdge(g,i,j);
					addOEdge(g,j,i);
				}
			}
		}
	return g;
}

int isConnected(graph *g,int* col){
	if(g->n>1){
		int k;
		queue *q=newQueue();
		edge* l=NULL;
		initializeBFS(col,g->n,q,0);
		while(!isEmpty(q)){
			k=dequeue(q);
			if(g->adj[k]!=NULL && g->adj[k]->node==-1){
				col[k]=2;
				break;
			}
			l=g->adj[k];
			while(l!=NULL){
				if(col[l->node]==0){
					enqueue(q,l->node);
					col[l->node]=1;
				}
				l=l->next;
			}
			col[k]=2;
		}
		for(k=0;k<g->n;k++){
			switch(col[k]){
				case 0 : printf("%d : BIANCO\n",k);
						 break;
				case 1 : printf("%d : GRIGIO\n",k);
						 break;
				case 2 : printf("%d : NERO\n",k);
						 break;
			}
		}
		for(k=0;k<g->n;k++)
			if(col[k]!=2) return 0;
	}
	return 1;
}

void connectGraph(graph *g,int* col){
	
}
