#ifndef PUNTATORISTATICI_H
#define PUNTATORISTATICI_H


struct Tree{
	int info;
	struct Tree *sonone;
	struct Tree *sontwo;
	struct Tree *sonthree;
	struct Tree *sonfour;		
};

typedef struct Tree tree;

tree *newRandomTree();
void print(tree *head);





#endif	
