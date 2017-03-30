#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "tableau.h"


 

typedef struct{ // X => RIGA | Y=>COLONNA
	int x,y;
} coordinates;

coordinates* position(int i,int j); //COSTRUISCE E RESTITUISCE COORDINATES
coordinates* parent(tableau *t,coordinates* i); //RESTITUISCE NULL SE NON ESISTONO, ARRAY di 1 elemento se ce ne è 1, ARRAY di 2 se è figlio di puttana
coordinates* left(tableau *t,coordinates *i);//RESTITUISCE COORDINATE DEL FIGLIO SINISTRO O NULL SE NON ESISTE
coordinates* right(tableau *t,coordinates *i);//RESTITUISCE COORDINATE DEL FIGLIO DESTRO O NULL SE NON ESISTE
void tableaufy(tableau *t,coordinates *cs); //HEAPIFY

coordinates* position(int i,int j){
	coordinates *cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=i;
	cs->y=j;
	
	return cs;
}

coordinates* left(tableau *t,coordinates *i){
	coordinates* cs=NULL;
	if((i->x)+1<=t->n){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=(i->x)+1;
		cs->y=i->y;
	}
	
	return cs;
}

coordinates* right(tableau *t,coordinates *i){
	coordinates* cs=NULL;
	if((i->y)+1<=t->m){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=i->x;
		cs->y=(i->y)+1;
	}
	
	return cs;
}

coordinates* parents(tableau *t,coordinates *i){
	coordinates *cs=NULL;
	if(i->x>1 && i->y>1){ //Ha due padri
		if(t->data[(i->x)-1][i->y]>t->data[i->x][(i->y)-1])
			cs=position((i->x)-1,i->y);
		else
			cs=position(i->x,(i->y)-1);
	}else{ //se ne ha 1
		cs=(coordinates*) malloc(sizeof(coordinates));
		if(i->x>1)
			cs=position((i->x)-1,i->y);
		if(i->y>1)
			cs=position(i->x,(i->y)-1);
	}
	
	return cs;
}

void printTableau(tableau *t){
	int i, j;
	for(i=1; i<=t->n; i++){
		for(j=1; j<=t->data[i][0]; j++)
			printf("%d ", t->data[i][j]);
		printf("\n");
	}
}

void tableaufy(tableau *t,coordinates *i){ //TO DO
	if(!isEmpty(t)){
		int scambio=0;
		coordinates *min = i;
		coordinates *l = left(t,i);
		coordinates *r = right(t,i);
		if(l != NULL && t->data[l->x][l->y]<t->data[i->x][i->y])
			min = l;
		if(r != NULL && t->data[r->x][r->y]<t->data[min->x][min->y])
			min = r;
		if(min!=i){
			scambio = t->data[i->x][i->y];
			t->data[i->x][i->y] = t->data[min->x][min->y];
			t->data[min->x][min->y] = scambio;
			tableaufy(t, min);
		}
		
		free(l);
		free(r);
	}
}

int isEmpty(tableau *t){
	if(t->data[0][0]==0)
		return 1;
	return 0;
}

int size(tableau *t){
	return t->data[0][0];
}
