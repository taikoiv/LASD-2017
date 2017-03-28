#ifndef TABLEAU_H
#define TABLEAU_H

typedef struct {
	int size;
	int **data;
} tableau;

createTableau();
extractMin();
insert();
void printTableau();

#endif
