#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int GRAPH_ERROR;

graph* createRandomGraph(){
	graph *g=NULL;
	int n,i,max=-1;
	g=(graph*) malloc(sizeof(graph));
	if(g==NULL){
		GRAPH_ERROR==-2;
	} else {
		n=rand()%20;
		g->nodes=(node*) calloc(n,sizeof(node));
		if(g->nodes==NULL){
			GRAPH_ERROR==-3;
			g->n=0;
		} else {
			g->n=n;
			//GENERAZIONE DEI NODI
			for(i=1;i<n-1;i++){
				g->nodes[i].height=rand();
				if(g->nodes[i].height>max)
					max=g->nodes[i].height;
			}
			printf("MAX:%d",max);
			//GENERAZIONE DI SORGENTE E DESTINAZIONE IN MODO DA NON ESSERE I PUNTI CON ALTEZZA MASSIMA
			g->nodes[n-1].height=max+1;
			while(g->nodes[n-1].height>=max){
				g->nodes[n-1].height=rand();
			}
			g->nodes[0].height=max+1;
			while(g->nodes[0].height>=max){
				g->nodes[0].height=rand();
			}
			//GENERAZIONE DEGLI ARCHI
		}
		
	}
	return g;
}

void printGraph(graph* g){
	if(g!=NULL){
		int i;
		edge *l=NULL;
		for(i=0;i<g->n;i++){
			printf("%d - %d |",i,g->nodes[i].height);
			l=g->nodes[i].adj;
			while(l!=NULL){
				printf("(%d , %d)",l->k,l->weight);
				l=l->next;
				if(l!=NULL){
					printf(" -> ");
				}
			}
			printf("\n");
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

void addEdge(graph* g,int s,int d,int w){
	edge* e=NULL;
	if(g!=NULL){
		if(s>0 && s<g->n && d>0 && d<g->n){
			e=(edge*) malloc(sizeof(edge));
			if(e!=NULL){
				e->k=d;
				e->weight=w;
				e->next=g->nodes[s].adj;
				g->nodes[s].adj=e;
			} else {
				GRAPH_ERROR=-2;
			}
		}else{
			GRAPH_ERROR=-4;
		}
	} else {
		GRAPH_ERROR=-1;
	}
}

/*
//node* Djikstra(graph* g);
int checkContraints(node* path);
void collapseGraph(graph* g);
void addNode(graph* g,int h);
void deleteEdge(graph* g,int s,int d);
void deleteNode(graph* g,int s);*/
