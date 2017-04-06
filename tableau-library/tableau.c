#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "tableau.h"

/*
	THIS STRUCT IS USED TO SAVE THE INDEX OF THE ROW AND THE ONE OF THE COLUMN OF AN ELEMENT IN THE TABLEAU
*/
typedef struct{ 
	int x,y;
} coordinates;

int TABLERROR;
int Dimension(int n); //RETURNS THE SIZE NEEDED FOR A TABLEAU IN ORDER TO ORDER A SEQUENCE OF N*N ELEMENTS
coordinates* position(int i,int j); //RETURNS THE COORDINATES OF AN ELEMENT OF THE TABLEAU
coordinates* parent(tableau *t,coordinates* i); //THIS FUNCTION RETURNS EITHER NULL OR THE COORDINATES OF THE PARENT THAT HAS BEEN CHOSEN
coordinates* left(tableau *t,coordinates *i);//THIS FUNCTION RETURNS THE COORDINATES OF THE LEFT SON OF A FATHER OR NULL IF SUCH ELEMENT DOES NOT EXIST
coordinates* right(tableau *t,coordinates *i);//THIS FUNCTION RETURNS THE COORDINATES OF THE RIGHT SON OF A FATHER OR NULL IF SUCH ELEMENT DOES NOT EXIST
void tableaufy(tableau *t,coordinates *cs); //THIS FUNCTION PERFORMS THE "HEAPIFY" ALGORITHM ADAPTED TO WORK ON A TABLEAU
void climbTableau(tableau *t,coordinates *cs); //THIS FUNCTION CLIMBS THE TABLEAU AS LONG AS THE ELEMENTS MUST BE EXCHANGED IN ORDER TO RESTORE THE TABLEAU PROPERTIES

int Dimension(int n){
	int dimensione = 0;
	dimensione=sqrt(n);
	if(n*n!=dimensione)
		dimensione=dimensione+1;
	return dimensione;
}

coordinates* position(int i,int j){
	coordinates *cs=(coordinates*) malloc(sizeof(coordinates));
	cs->x=i;
	cs->y=j;
	
	return cs;
}

coordinates* left(tableau *t,coordinates *i){
	coordinates* cs=NULL;
	if((i->x)+1<t->properties[0] && t->data[(i->x)+1][i->y]!=INT_MAX){
		cs=(coordinates*) malloc(sizeof(coordinates));
		cs->x=(i->x)+1;
		cs->y=i->y;
	}
	
	return cs;
}

coordinates* right(tableau *t,coordinates *i){
	coordinates* cs=NULL;
	if((i->y)+1<t->properties[1] && t->data[i->x][(i->y)+1]!=INT_MAX){
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

/* FUNCTION USED TO PRINT A TABLEAU */
void printTableau(tableau *t){
	int i, j;
	printf("\n");
	for(i=0; i<t->properties[0]; i++){
		for(j=0; j<t->properties[1]; j++)
			if(t->data[i][j]!=INT_MAX)
				printf("%d\t", t->data[i][j]);
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

/* CHECKS WHETHER A TABLEAU IS EMPTY */

int isEmpty(tableau *t){
	if(t->properties[2]==0)
		return 1;
	return 0;
}

/* RETURNS THE NUMBER OF ELEMENTS CURRENTLY STORED IN A TABLEAU */

int size(tableau *t){
	return t->properties[2];
}

/* FUNCTION THAT CREATES A NEW TABLEAU */

tableau* createTableau(int *data, int n,int m,int tot){
    int i,j;
    int **r;
	r = (int **)malloc(n*sizeof(int*));
    for(i = 0; i<n; i++){
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
    t->properties[5] = 0;

    for(i = 0;i<tot;i++){
        insert(t, data[i]);
    }
    return t;
}

/* FUNCTION THAT INSERTS A NEW ELEMENT IN AN ALREADY FILLED TABLEAU MAKING SURE THAT THE PROPERTIES OF SUCH STRUCTURE ARE KEPT */

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
            
            //MOVING THROUGH THE ANTIDIAGONALS
			i--; 
	        j++;
			
			if(t->properties[3]<t->properties[0]){ // IF THE ELEMENT IS STILL BETWEEN THE FIRST ELEMENT OF THE TABLEAU AND THE ELEMENTS OF THE MAIN ANTIDIAGONAL
	            if(t->properties[4]==0){
					t->properties[3]++;
	        		if(t->properties[3]<t->properties[0]){ //IF AFTER CHANGING ANTIDIAGONAL IS STILL BEFORE THE MAIN ONE
						i=t->properties[3];
	        			j=0;
					} else { //IF IS THE ANTIDIAGONAL RIGHT NEXT TO THE MAIN ONE
						i=t->properties[0]-1;
						j=t->properties[3]-t->properties[0]+1;
					}
				} else if(j>=t->properties[1]){
						t->properties[3]++;
						if(t->properties[3]<t->properties[0]){
							i=t->properties[3];
							j=0;
						} else {
							i=t->properties[0]-1;
							j=t->properties[3]-t->properties[0]+1;
						}
					}
						
			}else{ //IF IT IS PAST THE MAIN ANTIDIAGONAL
				if(j>=t->properties[1] || i<0){ //INDEXS OF NEXT ELEMENT TO INSERT ARE OVER THE TABLEAU LIMITS
					t->properties[3]++;
					i=t->properties[0]-1;
					j=t->properties[3]-t->properties[0]+1;
				}
			}
    }
    t->properties[4]=i;
    t->properties[5]=j;
    
    //printf("PROSSIMO IN %d | %d DIAGONALE = %d \n",i,j,t->properties[3]);
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

/* RETURNS THE SMALLEST ELEMENT OF THE TABLEAU, DELETES IT FROM THE STRUCTURE AND RESTORES THE TABLEAU PROPERTIES */

int extractMin(tableau *t){
	int min = t->data[0][0];
	int i=t->properties[4]+1; //ROW INDEX OF THE LAST INSERTED ELEMENT
	int j=t->properties[5]-1; //COLUMN INDEX OF THE LAST INSERTED ELEMENT
	coordinates *cs=NULL;
	if(isEmpty(t)){
		TABLERROR=-2;
		return INT_MAX;
	}
    
    //CASES TO FIND THE LAST INSERTED ELEMENT
	if(i==2&&j==-1){ // IF THE TABLEAU ONLY HAS ONE ELEMENT
		t->properties[4]--;
		printf("caso base %d\n", t->properties[4]);
		t->data[i][j]=INT_MAX;
		t->properties[2]--;
		return min;
	}
	
	if(i<=t->properties[0]-1 && j>0){ // GENERAL CASE
		printf("caso generale\n");
		t->data[0][0]=t->data[i][j];
		t->data[i][j]=INT_MAX;
		t->properties[4]=i;
		t->properties[5]=j;
		t->properties[2]--;
		
	} else if(i>=t->properties[0]-1 && j>0){ //IF THE ELEMENT IS ON THE LAST ROW
		printf("last row\n");
		j=t->properties[5]=t->properties[1]-1;
		i=t->properties[4]=t->properties[0]-1;
		t->data[0][0]=t->data[i][j];
		t->data[i][j]=INT_MAX;
		t->properties[2]--;
		
	} else if(i<t->properties[0]-1 && j<=0){ //IF THE ELEMENT IS ON THE FIRST COLUMN
		printf("last column\n");
		j=t->properties[5]=i-1;
		i=t->properties[4]=0;
		t->data[0][0]=t->data[i][j];
		t->data[i][j]=INT_MAX;
		t->properties[2]--;
		
	}
	
	//RESTORES TABLEAU PROPERTIES
	cs=position(0,0);
	tableaufy(t, cs);
	
	free(cs);
	return min;	
}

/* FUNCTION THAT DELETES A WHOLE TABLEAU */

void freetableau(tableau *t){
    free(t->data);
    free(t);
}

/* SORTING ALGORTHM FOR A SEQUENCE OF NUMBERS THAT USES THE TABLEAU PROPERTIES */

int *YoungSort(int *sequenza, int n){
	int i=0, dimensione=0;
	tableau *t;
	dimensione=Dimension(n);
	t=createTableau(sequenza, dimensione, dimensione, n);
	for(; i<n; i++)
		sequenza[i]=extractMin(t);
	return sequenza;
}
