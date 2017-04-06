#ifndef TABLEAU_H
#define TABLEAU_H

typedef struct {
	int properties[6]; // DO NOT TOUCH THIS VALUES, PLEASE
	/*
	properties[0] : row number
	properties[1] : column number
	properties[2] : tableau size
	properties[3] : anti-diagonal index 
	properties[4] : last leaf row index
	properties[5] : last leaf column index
	*/
	
	int **data;
} tableau;

extern int TABLERROR;
/*
	ERROR CODES:
	-1 : FULL TABLEAU
	-2 : EMPTY TABLEAU
*/

tableau* createTableau(int *data, int n,int m, int tot);
int extractMin(tableau *t);
void insert(tableau *t,int k);
void printTableau(tableau *t);
void freetableau(tableau *t);
int *youngSort(int *sequenza, int n);
int isEmpty(tableau *t);
int size(tableau *t);
#endif
