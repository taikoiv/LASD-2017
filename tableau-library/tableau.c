#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

typedef struct{
	int x,y;
} coordinates;

coordinates* position(int i,int j);
coordinates* parent(tableau *t,coordinates* i);
coordinates* left(coordinates *i);
coordinates* right(coordinates *i);

coordinates* position(int i,int j){
	coordinates *cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=i;
	cs->y=j;
	
	return cs;
}

coordinates* left(coordinates *i){
	coordinates* cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=(i->x)+1;
	cs.y=i->y;
	
	return cs;
}

coordinates* right(coordinates *i){
	coordinates* cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=i->x;
	cs->y=(i->y)+1;
	
	return cs;
}


