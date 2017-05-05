#ifndef ABR_H
#define ABR_H


struct Tree{
	int info;
	struct Tree *right;
	struct Tree *left; 		
};

typedef struct Tree tree;

tree *newRandomTree(int nNodes);
tree *insertNode(tree *head, int val);
tree *merge(tree* head, tree* other);
void print(tree *head, int enters);
tree *deleteNode(tree *head, int val);
int height(tree* t);
tree *rotation(tree* t,int n,int direction);




#endif	
