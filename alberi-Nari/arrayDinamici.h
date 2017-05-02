#ifndef ARRAYDINAMICI_H
#define ARRAYDINAMICI_H

typedef struct{
	int info; 
	tree *brothers;
	tree *sons;
} tree;

tree *newTree(tree *head);
tree *print(tree *head);






#endif	
