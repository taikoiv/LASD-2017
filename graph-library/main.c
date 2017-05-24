#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int i;
	graph *g=createRandomGraph();
	int* col=(int *) calloc(g->n,sizeof(int));
	printGraph(g);
	if(!isConnected(g,col)) {
		connectGraph(g);
	}
	printf("----------------------------------------------------------------------------------------\n");
	printGraph(g);
	free(col);
	freeGraph(g);
	return 0;
}
