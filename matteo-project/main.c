#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(NULL));
	graph* g=createRandomGraph();
	printGraph(g);
	int i;
	for(i=0;i<g->n;i++){
		//printf("NODO %d { COL : %d  |  DIST : %f | PRED : %d}\n",i,v->col[i],v->dist[i],v->pred[i]);
	}
		
	freeGraph(g);
	return 0;
}
