#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "graph.h"

void clearBuffer();
int hasDuplicates(graph *g);
void loseWeightPathPrinter(graph *g,int s,int d, int hasDup); //PRINT THE PATH CALCULATED BY MATTEO'S CRITERIA

int main(int argc, char *argv[]) {
	srand(time(NULL));
	graph* g=NULL;
	int input=-1;
	while(input < 0 || input > 3){
		system("cls");
		printf("------------------------------------------------------------------\n");
		printf("Welcome to the lose weight path calculator\n");
		printf("It's easy! Using a graph representation of your city, it calculates the best path that you must follow from a source point to a destination point and let you lose weight\n");
		printf("------------------------------------------------------------------\n");
		printf("1) Test this software using a random graph\n");
		printf("2) Create a new graph step-by-step\n");
		printf("\n0) Exit\n");
		scanf("%d",&input);
		if(input==1){
			g=createRandomGraph();
			printf("************************  RANDOM GRAPH   **********************\n");
			printGraph(g);
			loseWeightPathPrinter(g,0,g->n-1,hasDuplicates(g));
			freeGraph(g);
			if(GRAPH_ERROR == 0) input=-1;
			else input=0;
			system("pause");
		} else if(input==0) {
			return GRAPH_ERROR;
		}
		clearBuffer();
	}
	g=createGraph();
	input=-1;
	while(input < 0 || input > 5){
		system("cls");
		if(g->n>0) printGraph(g);
		printf("--------------------------------------------------------------------\n");
		printf("1) ADD A NODE\n");
		printf("2) ADD AN EDGE\n");
		printf("3) DELETE A NODE");
		printf("4) DELETE AN EDGE\n");
		printf("5) PRINT THE BEST PATH TO LOSE WEIGHT\n");
		printf("\n0) EXIT\n");
		scanf("%d",&input);
		switch(input){
			case 1 : break;
			case 2 : break;
			case 3 : break;
			case 4 : break;
			case 5 : break;
			default: if(input==0){
					 	freeGraph(g);
					 	return GRAPH_ERROR;
					 }
					 break;
		}
	}
/*	int i;
	addNode(g,20);
	addNode(g,50);
	addNode(g,47);
	addNode(g,72);
	addNode(g,30);
	addNode(g,15);
	addNode(g,26);
	addNode(g,16);
	addNode(g,10);
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
	addEdge(g,7,8,37);*/
	printGraph(g);

	loseWeightPathPrinter(g,0,g->n-1,hasDuplicates(g));
	freeGraph(g);
	return 0;
}

void loseWeightPathPrinter(graph *g,int s,int d, int hasDup){
	if(s<0 || s>g->n-1 || d<0 || s>g->n-1)
		return;
	visit *upHill=NULL , *downHill=NULL;
	int i , maxWeightPoint=-1;
	float min=FLT_MAX;
	list* path=NULL;
	if(hasDuplicates(g)){
		upHill=Djikstra(g,s);
		downHill=Djikstra(g,d);
	} else {
		upHill=uphillVisit(g,s);
		downHill=uphillVisit(g,d);
	}
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
			printf("\n");
		} else {
			printf("SORRY MATTEO, PATH TO LOSE WEIGHT DOESN'T EXIST\n");
		}	
	}
	freeVisit(upHill);
	freeVisit(downHill);
	freeList(path);
}

int hasDuplicates(graph* g){
	float *x=(float*)malloc((g->n)*sizeof(float));
	int ret=0, i=0;
	heapSort(g,x);
	for(i=1;i<g->n;i++){
		if(x[i-1]==x[i]){
			ret=1;
			break;
		}
	}
	return ret;
}

void clearBuffer(){ //clear the stdin when user write an invalid input data
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { };
}
