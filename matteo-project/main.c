#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(NULL));
	graph* g=createRandomGraph();
	printGraph(g);
	uphillVisit(g,0);
	uphillVisit(g,g->n-1);	
	freeGraph(g);
	return 0;
}
