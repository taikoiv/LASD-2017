#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "tableau.h"

int TABLERROR=0;
/*
	ERROR CODES:
	-1 : FULL TABLEAU
	-2 : EMPTY TABLEAU
*/


typedef struct{ // X => RIGA | Y=>COLONNA
	int x,y;
} coordinates;

coordinates* position(int i,int j); //COSTRUISCE E RESTITUISCE COORDINATES
coordinates* parent(tableau *t,coordinates* i); //RESTITUISCE NULL SE NON ESISTONO, ARRAY di 1 elemento se ce ne ï¿½ 1, ARRAY di 2 se ï¿½ figlio di puttana
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

void insert(tableau *t,int k){
    if(size(t)==(t->properties[0])*(t->properties[1])){
		TABLERROR=-1;
        return;
	}	
	int i=t->properties[4];
	int j=t->properties[5];
	coordinates* cs=NULL;
    if(t->data[i][j]==INT_MAX){
            t->data[i][j]=k;
            t->properties[2]++;
            cs=position(i,j);
            
            //SCALO SULL'ANTIDIAGONALE
			t->properties[4]--; 
	        t->properties[5]++;
			
			if(t->properties[3]<t->properties[0]){ // SE NON SFORA ANTIDIAGONALE MAGGIORE
	            if(j==0){
					t->properties[3]++;
	        		if(t->properties[3]<t->properties[0]){ //SE CONTINUA A NON SFORARE DOPO AVER SCALATO ANTIDIAGONALE
	        			t->properties[4]=t->properties[3];
	        			t->properties[5]=0;
					} else { //SE SFORA LA PRIMA VOLTA l'ANTIDIAGONALE MAGGIORE
						t->properties[4]=t->properties[0]-1;
						t->properties[5]=t->properties[3]-t->properties[0];
					}
				}
			}else{ //SFORATA ANTIDIAGONALE MAGGIORE
				if(t->properties[5]>=t->properties[1]){
					t->properties[3]++;
					t->properties[4]=t->properties[0]-1;
					t->properties[5]=t->properties[3]-t->properties[0];
				}
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
	int min = t->data[0][0];
	int i=t->properties[4]+1; //INDICE RIGA ULTIMO ELEMENTO INSERITO
	int j=t->properties[5]-1; //INDICE COLONNA ULTIMO ELEMENTO INSERITO
	coordinates *cs=NULL;
	
	if(isEmpty(t)){
		TABLERROR=-2;
		return INT_MAX;
	}
    
    //POSSIBILI CASI ULTIMO ELEMENTO INSERITO
	if(i==2&&j==-1){ // CASO BASE 1 ELEMENTO
		t->properties[4]--;
		t->properties[2]--;
		t->data[i][j]=INT_MAX;
		return min;
	}
	
	t->properties[2]--;
	
	if(i<t->properties[0]-1 && j>0){ // CASO GENERICO PROSSIMO ELEMENTO
	
		t->data[0][0]=t->data[i][j];
		t->data[i][j]=INT_MAX;
		t->properties[4]=i;
		t->properties[5]=j;
		
	} else if(i>=t->properties[0]-1 && j>0){ //CASO PARTICOLARE PROSSIMO ELEMENTO SU ULTIMA RIGA
		
		j=t->properties[5]=t->properties[1]-1;
		i=t->properties[4]=t->properties[0]-1;
		t->data[0][0]=t->data[i][j];
		t->data[i][j]=INT_MAX;
		
	} else if(i<t->properties[0]-1 && j<=0){ //CASO PARTICOLARE PROSSIMO ELEMENTO SU PRIMA COLONNA
	
		j=t->properties[5]=i-1;
		i=t->properties[4]=0;
		t->data[0][0]=t->data[i][j];
		t->data[i][j]=INT_MAX;
		
	}
	
	//RISTABILISCO PROPRIETà TABLEAU
	cs=position(0,0);
	tableaufy(t, cs);
	
	free(cs);
	return min;	
}

void freetableau(tableau *t){
    free(t->data);
    free(t);
}
