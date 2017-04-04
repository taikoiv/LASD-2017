#ifndef TABLEAU_H
#define TABLEAU_H

typedef struct {
	int properties[5]; // DO NOT TOUCH THIS VALUES PLEASE
	/*
	properties[0] : row number
	properties[1] : column number
	properties[2] : tableau size
	properties[3] : last anti-diagonal column index fatti i cazzi tuoi bastardo
	properties[4] : last anti-diagonal row index fatti i cazzi tuoi bastardo
	*/
	
	int **data;
} tableau;

tableau* createTableau(); // BOH FAI TU
int extractMin(tableau *t);
void insert(tableau *t,int k);
void printTableau(tableau *t);
int isEmpty(tableau *t);
int size(tableau *t);
#endif
