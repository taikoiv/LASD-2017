#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "graph.h"
#include "list.h"

#define RANDOM_SUCC 0.33

int GRAPH_ERROR=0;
/* ------LEGENDA ERRORI------
-1 : IMPOSSIBILE ESEGUIRE LA FUNZIONE SU DI UN GRAFO NULLO
-2 : IMPOSSIBILE ALLOCARE MEMORIA
-5 : SUPPORT DATA STRUCTURE ERROR
*/

void freeEdges(edge* l);
edge* insertEdge(edge* l,int d, float w);
int isConnected(graph *g,int* col);
void DFSVisitColors(graph* g,int* col,int s);
void connectGraph(graph *g);
edge* removeEdge(edge* l,int k);
visit* initializeVisit(graph* g);
list* DFSVisitUphillList(graph* g,visit* v,int s);

edge* insertEdge(edge* l,int d,float w){
	if(l!=NULL){
		if(l->k==d) return l;
		l->next=insertEdge(l->next,d,w);
	} else {
		edge* e=(edge*)malloc(sizeof(edge));
		if(e!=NULL){
			e->k=d;
			e->weight=w;
			e->next=NULL;
			l=e;
		} else {
			GRAPH_ERROR=-2;
		}
	}
	return l;
}


graph* createRandomGraph(){
	graph *g=NULL;
	int n,i,j,max=INT_MIN;
	float p;
	
	g=(graph*) malloc(sizeof(graph));
	if(g==NULL){
		GRAPH_ERROR==-2;
	} else {
		n=rand()%20;
		g->nodes=(node*) calloc(n,sizeof(node));
		if(g->nodes==NULL){
			GRAPH_ERROR==-2;
			g->n=0;
		} else {
			g->n=n;
			printf("N RANDOM = %d\n",n);
			//GENERAZIONE DEI NODI
			for(i=1;i<n-1;i++){
				j=0;
				g->nodes[i].height=rand();
				if(g->nodes[i].height>max)
					max=g->nodes[i].height;
			}
			//GENERAZIONE DI SORGENTE E DESTINAZIONE IN MODO DA NON ESSERE I PUNTI CON ALTEZZA MASSIMA
			g->nodes[n-1].height=rand()%max;
			g->nodes[0].height=rand()%max;
			//GENERAZIONE DEGLI ARCHI
			for(i=0;i<g->n;i++){
				for(j=0;j<g->n;j++){
					if(i!=j){
						p=(float)((rand()%n)+1)/n;
						if(p<=RANDOM_SUCC){
							addEdge(g,i,j,rand()%20);
						}
					}
				}
			}
			connectGraph(g);
		}
		
	}
	return g;
}

void printGraph(graph* g){
	if(g!=NULL){
		int i;
		edge *l=NULL;
		for(i=0;i<g->n;i++){
			if(g->nodes[i].height!=INT_MIN){ //NON STAMPO I NODI SENTINELLA
				printf("%d - %f |",i,g->nodes[i].height);
				l=g->nodes[i].adj;
				while(l!=NULL){
					printf("(%d , %f)",l->k,l->weight);
					l=l->next;
					if(l!=NULL){
						printf(" -> ");
					}
				}
				printf("\n");
			}
		}
	} else {
		GRAPH_ERROR=-1;
	}
}

graph* createGraph(){
	graph *g=NULL;
	g=(graph*) malloc(sizeof(graph));
	if(g==NULL){
		GRAPH_ERROR==-2;
	} else {
		g->nodes=(node*) calloc(0,sizeof(node));
		g->n=0;	
	}
	return g;
}

void addEdge(graph* g,int s,int d,float w){
	edge* e=NULL;
	if(g!=NULL){
		if(s>=0 && s<g->n && g->nodes[s].height!=INT_MIN && d>=0 && d<g->n && g->nodes[d].height!=INT_MIN){
			g->nodes[s].adj=insertEdge(g->nodes[s].adj,d,w);
			g->nodes[d].adj=insertEdge(g->nodes[d].adj,s,w);
		}else{
			GRAPH_ERROR=-4;
		}
	} else {
		GRAPH_ERROR=-1;
	}
}

void freeEdges(edge* l){
	if(l!=NULL){
		freeEdges(l->next);
		free(l);
	}
}

void freeGraph(graph* g){
	while(g->n>0){
		freeEdges(g->nodes[g->n-1].adj);
		g->n--;
	}
	free(g->nodes);
	free(g);
}

int isConnected(graph *g,int* col){
	int k;
	if(g->n>1){
		DFSVisitColors(g,col,0);
		for(k=0;k<g->n;k++)
			if(col[k]!=2) return 0;
	}
	return 1;
}

void connectGraph(graph *g){
	int i;
	int *col=(int*) calloc(g->n,sizeof(int));
	if(col!=NULL){
		if(!isConnected(g,col))
			for(i=1;i<g->n;i++)
				if(col[i]==0){
					addEdge(g,0,i,rand());
					DFSVisitColors(g,col,i);
				}
		free(col);
	}
}

void DFSVisitColors(graph* g,int* col,int s){
	col[s]=1;
	edge* l=g->nodes[s].adj;
	while(l!=NULL){
		if(col[l->k]==0){
			DFSVisitColors(g,col,l->k);
		}
		l=l->next;
	}
	col[s]=2;
}

void deleteEdge(graph* g,int s,int d){
	if(g!=NULL){
		if(s>=0 && s<g->n && g->nodes[s].height!=INT_MIN && d>=0 && d<g->n && g->nodes[d].height!=INT_MIN){
			g->nodes[s].adj=removeEdge(g->nodes[s].adj,d);
			g->nodes[d].adj=removeEdge(g->nodes[d].adj,s);
		}else GRAPH_ERROR=-4;
	} else GRAPH_ERROR=-1;
}

edge* removeEdge(edge* l,int k){
	if(l!=NULL){
		if(l->k==k){
			edge* temp=l;
			l=l->next;
			free(temp);
		}
		else l->next=removeEdge(l->next,k);
	}
	return l;
}

void addNode(graph* g,float h){
	if(g!=NULL){
		if(h>=0){
			int i=0;
			while(i<g->n && g->nodes[i].height!=INT_MIN)
				i++;
			if(i==g->n){
				g->nodes=realloc(g->nodes,g->n+1);
				if(g->nodes!=NULL){
					g->nodes[g->n].height=h;
					g->nodes[g->n].adj=NULL;
					g->n++;
				} else GRAPH_ERROR==-2;
			} else g->nodes[i].height=h;
		} else GRAPH_ERROR=-4;
	} else GRAPH_ERROR=-1;
}

void deleteNode(graph* g,int s){
	if(g!=NULL){
		if(s>=0 && s<g->n){
			int i=0;
			while(i<g->n){
				g->nodes[i].adj=removeEdge(g->nodes[i].adj,s);
				i++;
			}
			g->nodes[s].height=INT_MIN;
			freeEdges(g->nodes[s].adj);
			g->nodes[s].adj=NULL;
		} GRAPH_ERROR=-4;
	} GRAPH_ERROR=-1;
}

visit* initializeVisit(graph* g){
	visit *ret=NULL;
	int i=0;
	ret= (visit*) malloc(sizeof(visit));
	if(ret!=NULL){
		ret->col=(int*)calloc(g->n,sizeof(int));
		ret->dist=(float*)malloc(g->n*sizeof(float));
		ret->pred=(int*)malloc(g->n*sizeof(int));
		if(ret->col!=NULL && ret->dist!=NULL && ret->pred!=NULL){
			for(i=0;i<g->n;i++){
				ret->dist[i]=FLT_MAX;
				ret->pred[i]=-1;
			}
		}else{
			freeVisit(ret);
			GRAPH_ERROR=-2;
		}
	} else GRAPH_ERROR=-2;
	return ret;
}

void freeVisit(visit* v){
	if(v!=NULL){
		if(v->col!=NULL) free(v->col);
		if(v->dist!=NULL) free(v->dist);
		if(v->pred!=NULL) free(v->pred);
		free(v);
	}
}

visit* uphillVisit(graph* g,int s){
	visit* v=NULL;
	edge* adj=NULL;
	list* l=NULL , *head=NULL;
	int i;
	if(g!=NULL){
		v=initializeVisit(g);
		if(GRAPH_ERROR==0){
			head=l=DFSVisitUphillList(g,v,s);
			if(GRAPH_ERROR==0){
				v->dist[s]=0;
				while(l!=NULL){
					adj=g->nodes[l->k].adj;
					while(adj!=NULL){
						if(v->dist[adj->k]>v->dist[l->k]+adj->weight)
							v->dist[adj->k]=v->dist[l->k]+adj->weight;
						adj=adj->next;
					}
					l=l->next;
				}
			}
			freeList(head);
		}
	} else GRAPH_ERROR=-1;
	return v;
}

list* DFSVisitUphillList(graph* g,visit* v,int s){
	list* l=NULL;
	edge* adj=NULL;
	v->col[s]=1;
	adj=g->nodes[s].adj;
	while(adj!=NULL){
		if(g->nodes[adj->k].height > g->nodes[s].height && v->col[adj->k]==0){
			l=DFSVisitUphillList(g,v,adj->k);
			v->pred[adj->k]=s;
		}
		l=insertTop(l,s);
		if(LIST_ERROR!=0){
			GRAPH_ERROR=-5;
		}
		v->col[s]=2;
		adj=adj->next;
	}
	return l;
}

void printPath(visit* v,int s){
	if(v!=NULL && v->pred!=NULL){
		if(v->pred[s]!=-1){
			printPath(v,v->pred[s]);
		} 
		printf("%d ",s);
	}	
}

/*
void collapseGraph(graph* g);
*/
