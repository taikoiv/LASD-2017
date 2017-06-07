#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "graph.h"

void loseWeightPathPrinter(graph *g,int s,int d); //PRINT THE PATH CALCULATED BY MATTEO'S CRITERIA

int main(int argc, char *argv[]) {
	srand(time(NULL));
	graph* g=createGraph();
	addNode(g,20);
	addNode(g,50);
	addNode(g,47);
	addNode(g,72);
	addNode(g,30);
	addNode(g,15);
	addNode(g,26);
	addNode(g,16);
	addNode(g,10);
	printGraph(g);
	addEdge(g,0,1,100);
	addEdge(g,0,4,26);
	addEdge(g,1,3,55);
	addEdge(g,1,2,72);
	addEdge(g,4,6,12);
	addEdge(g,3,5,46);
	addEdge(g,2,5,200);
	addEdge(g,5,8,33);
	addEdge(g,6,8,20);
	addEdge(g,6,7,56);
	addEdge(g,7,8,37);
	printGraph(g);
	loseWeightPathPrinter(g,0,g->n-1);
	freeGraph(g);
	return 0;
}

void loseWeightPathPrinter(graph *g,int s,int d){
	if(s<0 || s>g->n-1 || d<0 || s>g->n-1)
		return;
	visit *upHill=NULL , *downHill=NULL;
	int i , maxWeightPoint=-1;
	float min=FLT_MAX;
	list* path=NULL;
	
	upHill=uphillVisit(g,s);
	downHill=uphillVisit(g,d);
	if(GRAPH_ERROR==0){
		for(i=0;i<g->n;i++){
			if(upHill->pred[i]!=-1 && downHill->pred[i]!=-1){
				if(upHill->dist[i]+downHill->dist[i]<min){
					min=upHill->dist[i]+downHill->dist[i];
					maxWeightPoint=i;
				}
			}
		}
		if(maxWeightPoint!=-1){
			printf("PATH TO LOSE WEIGHT FOUND :\n");
			path=pathGenerator(g,upHill,maxWeightPoint);
			path=pathExtender(g,path,downHill,maxWeightPoint);
			printList(path);
		} else {
			printf("PATH TO LOSE WEIGHT NOT EXISTS\n");
		}	
	}
	freeVisit(upHill);
	freeVisit(downHill);
	freeList(path);
}
