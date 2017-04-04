#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "tableau.h"

int TABLERROR=0;

typedef struct{ // X => RIGA | Y=>COLONNA
	int x,y;
} coordinates;

coordinates* position(int i,int j); //COSTRUISCE E RESTITUISCE COORDINATES
coordinates* parent(tableau *t,coordinates* i); //RESTITUISCE NULL SE NON ESISTONO, ARRAY di 1 elemento se ce ne � 1, ARRAY di 2 se � figlio di puttana
coordinates* left(tableau *t,coordinates *i);//RESTITUISCE COORDINATE DEL FIGLIO SINISTRO O NULL SE NON ESISTE
coordinates* right(tableau *t,coordinates *i);//RESTITUISCE COORDINATE DEL FIGLIO DESTRO O NULL SE NON ESISTE
void tableaufy(tableau *t,coordinates *cs); //HEAPIFY
void climbTableau(tableau *t,coordinates *cs); //CLIMBHEAP

coordinates* position(int i,int j){
	coordinates *cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=i;
	cs->y=j;
	
	return cs;
}

coordinates* left(tableau *t,coordinates *i){
	coordinates* cs=NULL;
	if((i->x)+1<=t->properties[0] && t->data[(i->x)+1][i->y]!=INT_MAX){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=(i->x)+1;
		cs->y=i->y;
	}
	
	return cs;
}

coordinates* right(tableau *t,coordinates *i){
	coordinates* cs=NULL;
	if((i->y)+1<=t->properties[1] && t->data[i->x][(i->y)+1]!=INT_MAX){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=i->x;
		cs->y=(i->y)+1;
	}
	
	return cs;
}

coordinates* parent(tableau *t,coordinates *i){
	coordinates *cs=NULL;
	if(i->x>0 && i->y>0){ //Ha due padri
		if(t->data[(i->x)-1][i->y]>t->data[i->x][(i->y)-1])
			cs=position((i->x)-1,i->y);
		else
			cs=position(i->x,(i->y)-1);
	}else{ //se ne ha 1
		if(i->x>0)
            cs = position((i->x) - 1, i->y);
		if(i->y>0)
            cs = position(i->x, (i->y) - 1);

	}
	return cs;
}

void printTableau(tableau *t){
	int i, j;
	for(i=0; i<t->properties[0]; i++){
		for(j=0; j<t->properties[1]; j++)
			if(t->data[i][j]!=INT_MAX)
				printf("%d ", t->data[i][j]);
		printf("\n");
	}
}

void tableaufy(tableau *t,coordinates *i){
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
	if(t->properties[2]==0)
		return 1;
	return 0;
}

int size(tableau *t){
	return t->properties[2];
}
tableau* createTableau(int *data, int n,int m,int tot){
    int i,j;
    int **r = (int **)malloc(n*sizeof(int*));
    for(i = 0;i<n;i++){
        r[i]=(int*)malloc(m*sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            r[i][j] = INT_MAX;
        }
    }

    tableau *t = (tableau *)malloc(sizeof(tableau));
    t->data = r;
    t->properties[0] = n;
    t->properties[1] = m;
    t->properties[2] = 0;
    t->properties[3] = 0;
    t->properties[4] = 0;

    for(i = 0;i<tot;i++){
        insert(t,data[i]);
    }
    return t;
}

void insert(tableau *t,int k){// forse funziona
    if(size(t)==(t->properties[0])*(t->properties[1])){
		TABLERROR=-1;
        return;
	}	
	int i,j=0;
	coordinates* cs=NULL;
	for(i=t->properties[4];i>=t->properties[3];i--){
        if(t->data[i][j]==INT_MAX){
            t->data[i][j]=k;
            t->properties[2]++;
            cs=position(i,j);
            if(i==t->properties[4]) {
                if (t->properties[3] < t->properties[1]) {
                    t->properties[3]++;
                }else {
                    t->properties[4]++;
                }
            }
        }
        if(j==t->properties[1]){
            j=0;
        }else{
            j++;
        }
	}
    climbTableau(t,cs);
	free(cs);
}

void climbTableau(tableau *t,coordinates *cs){
	coordinates *dad=parent(t,cs);
	int scambio;
	if(dad!=NULL){
		if(t->data[dad->x][dad->y]>t->data[cs->x][cs->y]){
			scambio=t->data[dad->x][dad->y];
			t->data[dad->x][dad->y]=t->data[cs->x][cs->y];
			t->data[cs->x][cs->y]=scambio;

			climbTableau(t,dad);
		}
		free(dad);
	}
}

int extractMin(tableau *t){
	int min = t->data[0][0], i=t->properties[4],j;
	coordinates *cs;
	if(size(t)==0){
		TABLERROR=-2;
		return INT_MAX;
	}
	for(j=t->properties[3];j>=0;j--, i++)
		if(t->data[i][j]!=INT_MAX){
			t->data[0][0]=t->data[i][j];
			t->data[i][j]=INT_MAX;
			t->properties[2]--;
			if(i==t->properties[4])
				if(t->properties[4]!=0)
					t->properties[4]--;
				else if(t->properties[3]!=0)
					t->properties[3]--;
					 
			break;
		}
		
	cs=position(0,0);
	tableaufy(t, cs);
	
	free(cs);
	return min;	
}

void freetableau(tableau *t){
    free(t->data);
    free(t);
}
