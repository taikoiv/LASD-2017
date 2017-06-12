#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "graph.h"
#include "utils.h"
#include "queue.h"

void loseWeightPathPrinter(graph *g,int s,int d); //PRINT THE PATH CALCULATED BY MATTEO'S CRITERIA

int main(int argc, char *argv[]) {
	srand(time(NULL));
	graph* g=NULL;
	int input=-1, app;
	float hw;
	lkTable* tbl = NULL;
    char *data = malloc(sizeof(char) * 128);
	while(input < 0 || input > 2){
		system("cls");
		printf("------------------------------------------------------------------\n");
		printf("Welcome to the lose weight path calculator\n");
		printf("It's easy! Using a graph representation of your city, it calculates the best path that you must follow from a source point to a destination point and let you lose weight\n");
		printf("------------------------------------------------------------------\n");
		printf("1) Test this software using a random graph\n");
		printf("2) Create a new graph step-by-step\n");
		printf("\n0) Exit\n");
		while(!getIntFromInput(&input)){
			printf("WRONG INPUT DATA\n");
		};
		if(input==1){
			g=createRandomGraph();
			if(GRAPH_ERROR == 0) break;
			else return GRAPH_ERROR;
			system("pause");
		} else if(input==0) {
			return GRAPH_ERROR;
		}
	}
	if(g==NULL)	g=createGraph();
	input=-1;
	while(input < 0 || input > 5){
		system("cls");
		printf("********************** MAIN MENU ***********************************\n");
		if(g->n>0) printGraph(g);
		printf("--------------------------------------------------------------------\n");
		printf("1) ADD A NODE\n");
		printf("2) ADD AN EDGE\n");
		printf("3) DELETE A NODE\n");
		printf("4) DELETE AN EDGE\n");
		printf("5) PRINT THE BEST PATH TO LOSE WEIGHT\n");
		printf("\n0) EXIT\n");
		while(!getIntFromInput(&input)){
			printf("WRONG INPUT DATA\n");
		};
		printf("\n");
		switch(input){
			case 0 :freeGraph(g);
					return GRAPH_ERROR;
			
			case 1 :do{
					printf("Insert the height : ");
					}while(!getFloatFromInput(&hw));
					addNode(g,hw);
					break;
			
			case 2 :if(g->n>0){
						do{
							printf("Insert the edge source point : ");
						}while(!getIntFromInput(&input) || input>g->n-1);
						do{
							printf("\nInsert the edge destination point : ");
						}while(!getIntFromInput(&app) || app>g->n-1);
						do{
							printf("\nInsert the edge weight : ");
						}while(!getFloatFromInput(&hw) || hw<=0);
						addEdge(g,input,app,hw);	
					} else printf("You can't add an edge in an empty graph\n");
					break;
			
			case 3 :if(g->n>0){	
						do{
							printf("Insert the node you want to delete : ");
						}while(!getIntFromInput(&input) || input > g->n-1);
						deleteNode(g,input);
					} else printf("You can't delete a node in an empty graph\n");
					break;
			
			case 4 :if(g->n>0){
						do{
							printf("Insert the edge source point : ");
						}while(!getIntFromInput(&input) || input>g->n-1);
						do{
							printf("\nInsert the edge destination point : ");
						}while(!getIntFromInput(&app) || app>g->n-1);
						deleteEdge(g,input,app);
					} else printf("You can't delete an edge in an empty graph\n");
					break;
					
			case 5 :if(g->n>1){
						do{
							printf("Insert the path source point : ");
						}while(!getIntFromInput(&input) || input>g->n-1);
						do{
							printf("\nInsert the path destination point : ");
						}while(!getIntFromInput(&app) || app>g->n-1 || app==input);
						
						loseWeightPathPrinter(g,input,app);
					} else printf("This function needs more nodes\n");
					break;
			default:printf("Not a valid action\n");
					break;
		}
		if(GRAPH_ERROR==0){
			system("pause");
			input=-1;
		} else break;
	}
	freeGraph(g);
	return GRAPH_ERROR;
}

void loseWeightPathPrinter(graph *g,int s,int d){
	if(s<0 || s>g->n-1 || d<0 || s>g->n-1 || s==d)
		return;
	visit *upHill=NULL , *downHill=NULL;
	int i , maxWeightPoint=-1;
	float min=FLT_MAX;
	list* path=NULL;
	
	upHill=uphillVisit(g,s);
	if(GRAPH_ERROR==-6){ //SE NON ESISTE ORDINAMENTO TOPOLOGICO NELLA VISITA DALLA SORGENTE
		GRAPH_ERROR=0;
		freeVisit(upHill);
		upHill=Dijkstra(g,s);
		downHill=Dijkstra(g,d);
	} else if(GRAPH_ERROR==0) downHill=uphillVisit(g,d);
	
	if(GRAPH_ERROR==-6){ //SE NON ESISTE ORDINAMENTO TOPOLOGICO NELLA VISITA DALLA DESTINAZIONE
		GRAPH_ERROR=0;
		freeVisit(upHill);
		freeVisit(downHill);
		upHill=Dijkstra(g,s);
		downHill=Dijkstra(g,d);
	}
	if(GRAPH_ERROR==0){ //TUTTO A BUON FINE
		if(upHill->col[d]!=2 && downHill->col[s]!=2){
			for(i=0;i<g->n;i++){
				if(upHill->col[i]==2 && downHill->col[i]==2){
					if(upHill->dist[i]+downHill->dist[i]<min){
						min=upHill->dist[i] + downHill->dist[i];
						maxWeightPoint=i; //PUNTO MIGLIORE DI INCROCIO DELLE VISITE
					}
				}
			}
		}
		if(maxWeightPoint!=-1){
			printf("PATH TO LOSE WEIGHT FOUND :\n");
			path=pathGenerator(g,upHill,maxWeightPoint);
			path=pathExtender(g,path,downHill,maxWeightPoint);
			printList(path);
			
			printf("DISTANCE TO COVER : %.2f\n",min);
		} else {
			printf("PATH TO LOSE WEIGHT DOESN'T EXIST BETWEEN %d AND %d WITH THIS CONFIGURATION\n",s,d);
		}	
	}
	freeVisit(upHill);
	freeVisit(downHill);
	freeList(path);
}
