#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include "graph.h"
#include "utils.h"


int hasDuplicates(graph *g);

void loseWeightPathPrinter(graph *g,int s,int d, int hasDup); //PRINT THE PATH CALCULATED BY MATTEO'S CRITERIA

int main(int argc, char *argv[]) {
	srand(time(NULL));
	graph* g=NULL;
	int input=-1, app;
	float hw;
	lkTable* tbl = NULL;
    char *data = malloc(sizeof(char) * 128);;
    tbl = createAliasTable();
	while(input < 0 || input > 2){
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
			if(GRAPH_ERROR == 0) break;
			else return GRAPH_ERROR;
			system("pause");
		} else if(input==0) {
			return GRAPH_ERROR;
		}
		clearBuffer();
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
		printf("6) ADD AN ALIAS TO A NODE\n");
		printf("\n0) EXIT\n");
		scanf("%d",&input);
		clearBuffer();
		printf("\n");
		switch(input){
			case 0 :freeGraph(g);
					return GRAPH_ERROR;
			
			case 1 :printf("Insert the height : ");
					scanf("%f",&hw);
					clearBuffer();
					addNode(g,hw);
					break;
			
			case 2 :if(g->n>0){
						do{
							printf("Insert the edge source point : ");
							scanf("%d",&input);
							clearBuffer();
						}while(input>g->n || input<0);
						do{
							printf("\nInsert the edge destination point : ");
							scanf("%d",&app);
							clearBuffer();
						}while(app>g->n || input<0);
						do{
							printf("\nInsert the edge weight : ");
							scanf("%f", &hw);
							clearBuffer();
						}while(hw<=0);
						addEdge(g,input,app,hw);	
					} else printf("You can't add an edge in an empty graph\n");
					break;
			
			case 3 :if(g->n>0){	
						do{
							printf("Insert the node you want to delete : ");
							scanf("%d",&input);
							clearBuffer();
						}while(input < 0 || input > g->n);
						deleteNode(g,input);
					} else printf("You can't delete a node in an empty graph\n");
					break;
			
			case 4 :if(g->n>0){
						do{
							printf("Insert the edge source point : ");
							scanf("%d",&input);
							clearBuffer();
						}while(input>g->n || input<0);
						do{
							printf("\nInsert the edge destination point : ");
							scanf("%d",&app);
							clearBuffer();
						}while(app>g->n || input<0);
						deleteEdge(g,input,app);
					} else printf("You can't delete an edge in an empty graph\n");
					break;
					
			case 5 :if(g->n>1){
						do{
							printf("Insert the edge source point : ");
							scanf("%d",&input);
							clearBuffer();
						}while(input>g->n || input<0);
						do{
							printf("\nInsert the edge destination point : ");
							scanf("%d",&app);
							clearBuffer();
						}while(app>g->n || input<0);
						
						loseWeightPathPrinter(g,input,app,hasDuplicates(g));
					} else printf("This functions needs more nodes\n");
					break;
			case 6:
				do{
					printf("Insert the node to add an Alias : ");
					scanf("%d",&input);
					clearBuffer();
				}while(input < 0 || input > g->n);
				do{
					printf("Insert the Alias to add : ");
					scanf("%126s",data);
					clearBuffer();
                }while(data==NULL);
				addAlias(tbl,input,data);
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

void loseWeightPathPrinter(graph *g,int s,int d, int hasDup){
	if(s<0 || s>g->n-1 || d<0 || s>g->n-1)
		return;
	visit *upHill=NULL , *downHill=NULL;
	int i , maxWeightPoint=-1;
	float min=FLT_MAX;
	list* path=NULL , head;

	if(hasDuplicates(g)){
		upHill=Djikstra(g,s);
		downHill=Djikstra(g,d);
	} else {
		upHill=uphillVisit(g,s);
		downHill=uphillVisit(g,d);
	}
	/* TEST VISISTS
	printf("ID\tCOL1\tCOL2\tPRED1\tPRED2\tDIST1\tDIST2\n");
	for(i=0;i<g->n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n",i,upHill->col[i],downHill->col[i],upHill->pred[i],downHill->pred[i],upHill->dist[i],downHill->dist[i]);
	}*/
	if(GRAPH_ERROR==0){
		if(upHill->col[d]!=2 || downHill->col[s]!=2){
			for(i=0;i<g->n;i++){
				if(upHill->col[i]==2 && upHill->col[i]==2 && i!=s && i!=d){
					if(upHill->dist[i]+downHill->dist[i]<min){
						min=upHill->dist[i] + downHill->dist[i];
						maxWeightPoint=i;
						printf("INTERSECT POINT : %d",i);
					}
				}
			}
		}
		if(maxWeightPoint!=-1){
			printf("PATH TO LOSE WEIGHT FOUND :\n");
			path=pathGenerator(g,upHill,maxWeightPoint);
			path=pathExtender(g,path,downHill,maxWeightPoint);
			printList(path);
			
			printf("DISTANCE TO COVER : %f\n",min);
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

