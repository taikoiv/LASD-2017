#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

typedef struct{
	int x,y;
} coordinates;

coordinates left(coordinates i){
	coordinates cs;
	cs.x=i.x+1;
	cs.y=i.y;
	
	return cs;
}

coordinates right(coordinates i){
	coordinates cs;
	cs.x=i.x;
	cs.y=i.y+1;
	
	return cs;
}

coordinates parent(tableau *t,coordinates i);
