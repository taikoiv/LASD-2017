#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tableau.h"

typedef struct{ // X => RIGA | Y=>COLONNA
	int x,y;
} coordinates;

coordinates* position(int i,int j); //COSTRUISCE E RESTITUISCE COORDINATES
coordinates* parent(tableau *t,coordinates* i); //RESTITUISCE NULL SE NON ESISTONO, ARRAY di 1 elemento se ce ne è 1, ARRAY di 2 se è figlio di puttana
coordinates* left(tableau *t,coordinates *i);//RESTITUISCE COORDINATE DEL FIGLIO SINISTRO O NULL SE NON ESISTE
coordinates* right(tableau *t,coordinates *i);//RESTITUISCE COORDINATE DEL FIGLIO DESTRO O NULL SE NON ESISTE

coordinates* position(int i,int j){
	coordinates *cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=i;
	cs->y=j;
	
	return cs;
}

coordinates* left(tableau *t,coordinates *i){
	int dim=sqrt(t->size);
	coordinates* cs=NULL;
	if((i->x)+1<=dim){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=(i->x)+1;
		cs->y=i->y;
	}
	return cs;
}

coordinates* right(tableau *t,coordinates *i){
	int dim=sqrt(t->size);
	coordinates* cs=NULL;
	if((i->y)+1<=dim){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=i->x;
		cs->y=(i->y)+1;
	}
	return cs;
}

coordinates* parents(tableau *t,coordinates *i){
	coordinates *cs=NULL;
	int dim=sqrt(t->size);
	if(i->x>1 && i->y>1){
		cs=(coordinates*) malloc(2*sizeof(coordinates));
		cs[0]=position((i->x)-1,i->y);
		cs[1]=position(i->x,(i->y)-1);
	}else{
		cs=(coordinates*) malloc(sizeof(coordinates))
		if(i->x>1)
			cs=position((i->x)-1,i->y);
		if(i->y>1)
			cs=position(i->x,(i->y)-1);
	}
	
	return cs;
}

