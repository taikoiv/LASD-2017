#ifndef TABLEAU_H
#define TABLEAU_H

typedef struct {
	int n,m;
	int **data;
} tableau;

tableau* createTableau(); // BOH FAI TU
int extractMin(tableau *t);
void insert(tableau *t,int k);
void printTableau(tableau *t);
int isEmpty(tableau *t);
int size(tableau *t);
#endif
